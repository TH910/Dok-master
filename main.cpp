#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QLocale>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <vector>
#include <signal.h>
#include <semaphore.h>
#include <chrono>
#include "messpunkt.h"
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "sample.h"
#include <QLCDNumber>
#include "calculation.h"
#include "helpfunctions.h"


#define PORT     5000
#define MAXLINE 1024

//Semaphoren
sem_t mutex;
sem_t empty;
sem_t full;


void producer(std::vector<messpunkt> &vec, unsigned int size,calculation &c,double toleranz, const char *ip){
  int sockfd;
  char buffer[MAXLINE];
  struct sockaddr_in servaddr, cliaddr;

  //IP für die Verwendung Daheim und an der Hochschule
  //char ip[]="192.168.188.41";
  //char ip[]="192.168.0.138";


  // Creating socket file descriptor
  if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      perror("socket creation failed");
      exit(EXIT_FAILURE);
    }

  memset(&servaddr, 0, sizeof(servaddr));
  memset(&cliaddr, 0, sizeof(cliaddr));

  // Filling server information
  servaddr.sin_family    = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = inet_addr(ip);
  servaddr.sin_port = htons(PORT);

  // Bind the socket with the server address
  if ( bind(sockfd, (const struct sockaddr *)&servaddr,
            sizeof(servaddr)) < 0 )
    {
      perror("bind failed");
      exit(EXIT_FAILURE);
    }

  socklen_t len;
  int n;
  len = sizeof(cliaddr);  //len is value/result

  //Initialisierung der benötigten Variablen
  std::vector<messpunkt> vecbuf;
  messpunkt actual_mp, last_mp;
  
  //warten bis der Anwender den Start-Knop drückt
  while(c.start==false){
    }

  while(1){
      n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                   MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                   &len);
      buffer[n] = '\0';

      //UDP stream in Messpunkt-Objekt umwandeln
      actual_mp=messpunkt(buffer);

      // Grün/Rot Mechnismus
      if(((actual_mp.sx-last_mp.sx)<=toleranz) &&((actual_mp.sy-last_mp.sy)<=toleranz)&&((actual_mp.sz-last_mp.sz)<=toleranz)){
          c.ampel_status(1);
        }else {
          c.ampel_status(0);
        }

      //Aktualisierung der Koordinaten-Anzeige
      c.track_koords_anzeigen(actual_mp.sx,actual_mp.sy,actual_mp.sz);
      c.robo_koords_anzeigen(actual_mp.sx,actual_mp.sy,actual_mp.sz);
      //hinzufügen des aktuellen Messpunkts zu vecbuf, sobald alle Punkte erfasst und gemittelt wurden flag=1
      if(c.status_mp_track==0){
          vecbuf.push_back(actual_mp);
          //Kopieren des vecbuf Objekts in gemeinsam genutzte Varibale vec
          if(size==vecbuf.size()){
              sem_wait(&empty);
              sem_wait(&mutex);

              vec=vecbuf;

              sem_post(&mutex);
              sem_post(&full);

              vecbuf.clear();
            }
        }

      last_mp=actual_mp;
    }
}




void consumer(std::vector<messpunkt> &vec,std::vector<messpunkt> &vecmittel,double toleranz, unsigned int anzahl_punkte,calculation &c){

  std::vector<messpunkt> vecbuf2;


  while(1){
      if(c.status_mp_track==0){
          if(c.reset_kalib==true){
              vecmittel.clear();
              c.mp_track_vorhanden=false;
              c.anzahl_mp_anzeigen(0);
              c.reset_kalib=false;
            }

          //herauskopieren der Daten aus dem gemeinsam genutzten Speicherbereich
          sem_wait(&full);
          sem_wait(&mutex);

          vecbuf2=vec;
          vec.clear();

          sem_post(&mutex);
          sem_post(&empty);

          //Umwandlung der einzelenen Messpunkte in Klasse Sample
          if(vecbuf2.size()!=0){
              sample test=sample(vecbuf2);

              /**
              //Verwendung des Span
              if((test.xmax-test.xmin<= toleranz)&&(test.ymax-test.ymin<= toleranz) &&(test.zmax-test.zmin<= toleranz)){
                  vecmittel.push_back(messpunkt(test.xmittel,test.ymittel,test.zmittel));
                  p.receive_data(vecmittel.size());
                  std::cout<< "###########"<< std::endl;
                  std::cout<<" Wert gespeichert"<<"  Größe des Vector: "<< vecmittel.size()<<std::endl;
                  std::cout<<"X: "<<test.xmittel<<" Y: "<<test.ymittel<< " Z: "<< test.zmittel<< std::endl;
                  std::cout<< "###########"<< std::endl;
                }
              */

              //Verwendung der Varianz
              if((test.xvar<= toleranz)&&(test.yvar<= toleranz) &&(test.zvar<= toleranz)){
                  // vecmittel enthält alle gemittelten Messpunkte der Datensätze, die eine geringere Varianz als die Toleranz aufweisen
                  vecmittel.push_back(messpunkt(test.xmittel,test.ymittel,test.zmittel));
                  c.anzahl_mp_anzeigen(vecmittel.size());
                  std::cout<< "###########"<< std::endl;
                  std::cout<<" Wert gespeichert"<<"  Größe des Vector: "<< vecmittel.size()<<std::endl;
                  std::cout<<"X: "<<test.xmittel<<" Y: "<<test.ymittel<< " Z: "<< test.zmittel<< std::endl;
                  std::cout<< "###########"<< std::endl;
                }

              if(vecmittel.size()==anzahl_punkte){
                  std::cout<<"Alle Werte wurden abgespeichert"<<std::endl;
                  //flag=1;
                  c.status_mp_track=1;
                  //data.setValues_tast(vecmittel);
                  c.track_mp_einlesen(vecmittel);
                  //break;
                  std::cout<<"Read Schleife beendet"<<std::endl;
                  std::cout<<"Die abgespeicherten Mittelwerte lauten"<<std::endl;
                  for (auto ele: vecmittel){
                      ele.anzeigen();
                    }
                  vecmittel.clear();
                }

            }
        }else{

          //leere loop
        }



    }

}


int main(int argc, char *argv[])
{
  //Initialisierung der relevanten Klassen und Variablen
  QApplication a(argc, argv);
  MainWindow w;
  calculation c;
  std::vector<messpunkt> vec;
  std::vector<messpunkt> vecmittel;


  // Hier muss beim Setup der Pfad des csv-Files Ordner angepasst werden
  char path[500]="/home/timohin/Documents/tracking/csv-Files";
  w.ui->lineEdit->setText(QString::asprintf(path));


  char config_path[500];
  strcpy(config_path, path);
  strcat(config_path, "/config.csv");
  char csv_path[500];
  strcpy(csv_path, path);
  strcat(csv_path, "/trafomatrix.csv");
  c.path=csv_path;

  rapidcsv::Document config_doc(config_path,rapidcsv::LabelParams(0,0));

  unsigned int size=config_doc.GetCell<unsigned int>("Daten","Größe Sample");
  double toleranz=config_doc.GetCell<double>("Daten","Toleranz in mm");
  unsigned int anzahl_punkte=config_doc.GetCell<unsigned int >("Daten","Anzahl der Messpunkte");

  std::string testip=config_doc.GetCell<std::string>("Daten","IP-Adresse");

  const char *ip=testip.c_str();
  /**

  int size=150;
  double toleranz=2;
  unsigned int anzahl_punkte=6;
  char ip[]="192.168.0.138";

*/

  //Signal Slot Connection aufbauen
  QObject::connect(&w, &MainWindow::trafom_einlesen_sig,&c, &calculation::trafom_einlesen);
  QObject::connect(&w, &MainWindow::robo_mp_einlesen_sig,&c, &calculation::robo_mp_einlesen);
  QObject::connect(&w, &MainWindow::trafom_berechnen_sig,&c, &calculation::trafom_berechnen);
  QObject::connect(&w, &MainWindow::start_sig,&c, &calculation::starten);
  QObject::connect(&w, &MainWindow::status_mp_einlesen_sig,&c, &calculation::status_mp_einlesen);
  QObject::connect(&w, &MainWindow::reset_sig,&c, &calculation::reset);

  QObject::connect(&c, &calculation::track_koords_sig,&w, &MainWindow::track_koords);
  QObject::connect(&c, &calculation::robo_koords_sig,&w, &MainWindow::robo_koords);
  QObject::connect(&c, &calculation::ampel_sig,&w, &MainWindow::ampel);
  QObject::connect(&c, &calculation::anzahl_mp_sig,&w, &MainWindow::anzahl_mp);
  QObject::connect(&c, &calculation::meldung_sig,&w, &MainWindow::meldung);

  std::setlocale(LC_ALL,"en_US.UTF-8");
  w.show();

  //Threads starten mit writefunction und readfunction
  std::thread t1(producer, std::ref(vec),size,std::ref(c),toleranz,ip);
  std::thread t2(consumer, std::ref(vec),std::ref(vecmittel),toleranz, anzahl_punkte,std::ref(c));

  //Initialisierung der Semaphoren
  if (sem_init(&mutex, 0, 1) == -1)
    std::cerr << "Error: semaphore" << std::endl;

  if (sem_init(&empty, 0, 1) == -1)
    std::cerr << "Error: semaphore" << std::endl;

  if (sem_init(&full, 0, 0) == -1)
    std::cerr << "Error: semaphore" << std::endl;

  //Main loop
  while(1){
      a.processEvents();
      usleep(15000);
      if(w.exit==true){
          return 0;
        }
    }


  t1.join();
  t2.join();
  // return a.exec();
}
