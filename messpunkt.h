#ifndef MESSPUNKT_H
#define MESSPUNKT_H

#include <iostream>
#include <QDebug>
/**
 * @brief Klasse messpunkt zur einfacheren Handhabung von 3D-Raumkoordinaten
 *
 */
class messpunkt
{
public:
  double sx;
  double sy;
  double sz;
  /**
   * @brief Construct a new messpunkt object
   *
   * @param tx  x-Koordinate
   * @param ty  y-Koordinate
   * @param tz  z-Koordinate
   */
  messpunkt(double tx, double ty, double tz);
  /**
   * @brief Construct a new messpunkt object
   *
   * @param stream   extrahiert die x-, y- und z-Koordinate aus dem über UDP übermittelten char-Array des ART-Trackingsystems
   */
  messpunkt(char *stream);
  messpunkt();
  /**
   * @brief Destroy the messpunkt object
   *
   */
  ~messpunkt();
  /**
   * @brief Ausgabe der x- y- und z-Koordinaten über die Kommandozeile
   *
   */
  void anzeigen();
};

#endif // MESSPUNKT_H
