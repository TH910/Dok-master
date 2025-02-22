#include "sample.h"
#include "math.h"

sample::sample(std::vector<messpunkt> daten)
  : daten(daten){
  xmax=daten[0].sx;
  xmin=daten[0].sx;
  ymax=daten[0].sy;
  ymin=daten[0].sy;
  zmax=daten[0].sz;
  zmin=daten[0].sz;
  double xmean=0;
  double ymean=0;
  double zmean=0;
  for (unsigned int i=1; daten.size()>i;i++){
      if(xmax<daten[i].sx){
          xmax=daten[i].sx;
        }else{
          if(xmin>daten[i].sx){
              xmin=daten[i].sx;
            }
        }
      if(ymax<daten[i].sy){
          ymax=daten[i].sy;
        }else{
          if(ymin>daten[i].sy){
              ymin=daten[i].sy;
            }
        }
      if(zmax<daten[i].sz){
          zmax=daten[i].sz;
        }else{
          if(zmin>daten[i].sz){
              zmin=daten[i].sz;
            }
        }
    }


  for (unsigned int k=0; daten.size()>k;k++){
      xmean+=daten[k].sx;
      ymean+=daten[k].sy;
      zmean+=daten[k].sz;
    }
  xmean= xmean/daten.size();
  ymean= ymean/daten.size();
  zmean= zmean/daten.size();

  double xsum=0;
  double ysum=0;
  double zsum=0;

  for(unsigned int j=0; j<daten.size();j++){
      xsum=xsum+pow((daten[j].sx-xmean),2);
      ysum=ysum+pow((daten[j].sy-ymean),2);
      zsum=zsum+pow((daten[j].sz-zmean),2);
    }
  anzahl_mp=daten.size();
  std::cout << "Anzahl Messpunkte: "<< anzahl_mp<< std::endl;
  std::cout << "Xmax: "<< xmax<< " Xmin: "<< xmin<<" Ymax: "<< ymax<< " Ymin: "<< ymin<< " Zmax: "<< zmax<< " Zmin: "<< zmin<< std::endl;
  std::cout << "Xmean: "<< xmean<< " Ymean: "<< ymean<< " Zmean: "<< zmean<< std::endl;
  xmittel=xmean;
  ymittel=ymean;
  zmittel=zmean;
  xvar=sqrt(xsum/daten.size());
  yvar=sqrt(ysum/daten.size());
  zvar=sqrt(zsum/daten.size());
}




sample::~sample(){}




