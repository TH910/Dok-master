#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "helpfunctions.h"
#include "rapidcsv.h"
#include "messpunkt.h"
#include <vector>
#include <boost/circular_buffer.hpp>
#include <iostream>
#include <unistd.h>
#include "calculation.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}


MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::track_koords(double x, double y, double z)
{
  ui->lcdNumber_x->display(x);
  ui->lcdNumber_y->display(y);
  ui->lcdNumber_z->display(z);
}

void MainWindow::robo_koords(double x, double y, double z)
{
  ui->lcdNumber_x_2->display(x);
  ui->lcdNumber_y_2->display(y);
  ui->lcdNumber_z_2->display(z);
}

void MainWindow::ampel(bool state)
{
  QPalette palette;
  if(state==true){
      palette.setColor(QPalette::Base,Qt::green);
    }else{
      palette.setColor(QPalette::Base,Qt::red);
    }
  ui->lineEdit_2->setPalette(palette);
}

void MainWindow::anzahl_mp(int counter)
{
  ui->lineEdit_3->setText(QString::number(counter));
}

void MainWindow::meldung(const char *message)
{
  ui->lineEdit_message->setText(QString::asprintf(message));
}

void MainWindow::on_start_btn_clicked()
{
    emit start_sig(true);
}

void MainWindow::on_reset_btn_clicked()
{
    emit status_mp_einlesen_sig(false);
    emit reset_sig(true);
}

void MainWindow::on_robo_mp_einlesen_btn_clicked()
{
    QString s=ui->lineEdit->text();
    QByteArray ba = s.toLatin1();
    char *path_folder= ba.data();
    char data_path[100];
    strcpy(data_path, path_folder);
    strcat(data_path, "/messpunkte.csv");
    std::vector<messpunkt> mpl=csv_einlesen(data_path);
    for(size_t i=0; i<mpl.size(); ++i){
        mpl[i].anzeigen();
      }
    emit robo_mp_einlesen_sig(mpl);
}

void MainWindow::on_trafom_berechnen_btn_clicked()
{
 emit trafom_berechnen_sig();
}

void MainWindow::on_trafom_einlesen_btn_clicked()
{
   emit trafom_einlesen_sig();
}

void MainWindow::on_prog_beenden_btn_clicked()
{
    exit=true;
}
