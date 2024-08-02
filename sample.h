#ifndef SAMPLE_H
#define SAMPLE_H
#include"messpunkt.h"

/**
 * @brief stellt einen Datensatz aus messpunkt-Objekten dar und enthält die wichtigsten statistischen Größen des Datensatzes
 * 
 */
class sample
{
public:
  std::vector <messpunkt> daten;
  int anzahl_mp;
  double xmax;
  double xmin;
  double ymax;
  double ymin;
  double zmax;
  double zmin;
  double xmittel;
  double ymittel;
  double zmittel;
  double xvar;
  double yvar;
  double zvar;
 /**
  * @brief Construct a new sample object
  * 
  * @param daten repräsentiert den Datensatz, der analysiert werdne soll
  */
  sample(std::vector <messpunkt> daten);
  //Destruktor
  ~sample();
};

#endif // SAMPLE_H
