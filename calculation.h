#ifndef CALCULATION_H
#define CALCULATION_H

#include <QMainWindow>
#include <QObject>
#include "messpunkt.h"
#include <vector>
#include "rapidcsv.h"
#include "track_local.h"

/**
 * @brief die Klasse calculation speichert die benötigten Daten zur Berechnung der Transformationsmatrix als Attribute ab und führt die Berechnung durch
 *
 */
class calculation : public QObject
{
  Q_OBJECT

  /**
   * @brief die Signale geben Daten an die Klasse mainwindow (GUI) weiter und werden von Methoden dieser Klasse emittiert
   *
   */
signals:
  void track_koords_sig(double x, double y, double z);
  void robo_koords_sig(double x, double y, double z);
  void ampel_sig(bool state);
  void anzahl_mp_sig(int counter);
  void meldung_sig(const char *message);

  /**
   * @brief die Slots werden von  Signalen getriggert, die von Buttons auf der GUI ausgesendet werden
   *
   */
public slots:
  void trafom_berechnen(void);
  void robo_mp_einlesen(std::vector<messpunkt> mp_robo);
  void track_mp_einlesen(std::vector<messpunkt> mp_track);
  void starten();
  void status_mp_einlesen(bool state);
  void reset();
  void trafom_einlesen();

public:
  /**
   * @brief Zeigt die  umgerechenten x-,y- und z-Koordinaten aus Sicht des lokalen Robotersystems auf der GUI an
   *
   * @param x x-Koordinate aus sicht des lokalen Robotersystems
   * @param y y-Koordinate aus sicht des lokalen Robotersystems
   * @param z z-Koordinate aus sicht des lokalen Robotersystems
   */
  void track_koords_anzeigen(double x, double y, double z);

  /**
   * @brief Zeigt die x-,y- und z-Koordinaten aus Sicht des Trackingsystems auf der GUI an
   *        Roboter-Koordinaten = Trafomatrix* Tracking-Koordinaten
   * @param x x-Koordinate aus sicht des globalen Trackingsystems
   * @param y y-Koordinate aus sicht des globalen Trackingsystems
   * @param z z-Koordinate aus sicht des globalen Trackingsystems
   */
  void robo_koords_anzeigen(double x, double y, double z);

  /**
   * @brief zeigt an der GUI an, ob die der Messtaster zu stark bewegt wird
   *
   * @param state true= grün, Bewegung liegt unterhalb der Toleranz
   *              false= rot, Bewegung liegt oberhalb der Toleranz
   */
  void ampel_status(bool state);

  /**
   * @brief aktualisiert die Anzahl der Messpunkte aus Sicht des Trackingsystems
   *
   * @param counter entspricht der Anzahl der bisher erfassten Messpunkte (diese Zahl wird auf GUI angezeigt)
   */
  void anzahl_mp_anzeigen(int counter);

  /**
   * @brief gibt Statusmeldungen auf der GUI aus, falls GUI falsch verwendet wurde
   *
   * @param message sring der der Fehlermeldun entspricht
   */
  void meldung_anzeigen(const char *message);

  /**
   * @brief Construct a new calculation object
   *
   */
  calculation() {}

  /**
   * @brief Destroy the calculation object
   *
   */
  ~calculation() {}

  std::vector<messpunkt> mp_robo;  // entspricht den Messpunkten aus Sicht des Robo-Koordinatensystem
  std::vector<messpunkt> mp_track; // entspricht den Messpunkten aus Sicht des Tracking-Koordinatensystems
  double trafomatrix[4][4] = {0};  // entspricht der berechneten homogenen 4x
  bool mp_robo_vorhanden = false;  // Flag um zu Signalisieren, dass Messpunkte von lok. Roboterkoordsys. vorhanden sind
  bool mp_track_vorhanden = false; // Flag um zu Signalisieren, dass Messpunkte von glob. Trackingsys. vorhanden sind
  bool start = false;              // wird geändert, wenn Start Button gedrückt wurde (dadurch wird Endlos-Schleife bei producer-Funktion verlassen)
  bool status_mp_track = false;                  // Anzahl der bisher erfassten Messpunkte des Tracking-Koordinatensystems
  bool reset_kalib = false;        // wird geändert, wenn Reset Button gedrückt wurde
  char *path;                      // Datei-Pfad zu den csv-Files
};

#endif // CALCULATION_H
