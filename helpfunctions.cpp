#include "helpfunctions.h"
#include <vector>
#include <iostream>
#include "rapidcsv.h"
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>
#include <QtGui>


std::vector<messpunkt> csv_einlesen(const char *path)
{

  rapidcsv::Document doc(path,rapidcsv::LabelParams(0,0));
  std::vector<messpunkt> mpl;
  std::vector<double> row;
  for(unsigned int i=0; i<doc.GetRowCount();i++){
      row=doc.GetRow<double>(i);
      //qDebug()<<row[0]<<" : "<<row[1]<<" : "<<row[2]<< "\n";
      mpl.push_back(messpunkt(row[0],row[1],row[2]));
    }

  return mpl;

}

void csv_schreiben(double csv_data)
{
  /**
  const char *path="/home/timohin/Documents/Tranfomatrix.csv" ;
  rapidcsv::Document doc(path,rapidcsv::LabelParams(0,0));
  doc.SetCell(0,0,"Trafo-Matrix [4]x[4]");
  for
  doc.Save(path);
*/
}







void conv_vec_to_arr(std::vector<messpunkt> data, double array[3][3])
{
  for(unsigned int i=0; i<=data.size();i++){
    array[i][0]=data[i].sx;
    array[i][1]=data[i].sy;
    array[i][2]=data[i].sz;
    }
}


