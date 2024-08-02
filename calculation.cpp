#include "calculation.h"

// Methoden
void calculation::track_koords_anzeigen(double x, double y, double z)
{
  emit track_koords_sig(x, y, z); // Koordinaten werden an MainWindow geschickt
}

void calculation::robo_koords_anzeigen(double x, double y, double z)
{
  double ci[1][3] = {0}; // Koordinaten aus Sich der Tracking-Koordinatensys.
  double co[1][3] = {0}; // Koordinaten aus Sicht des lok. Robotersys.
  ci[0][0] = x;
  ci[0][1] = y;
  ci[0][2] = z;
  trafo3d_perform(co, trafomatrix, ci, 1); // Punkte mit 4x4-Trafomatrix transformieren
  emit robo_koords_sig(co[0][0], co[0][1], co[0][2]);
}

void calculation::ampel_status(bool state)
{
  emit ampel_sig(state); // Ampel von UI umschalten grün=1, 0=rot
}

void calculation::anzahl_mp_anzeigen(int counter)
{
  emit anzahl_mp_sig(counter); // Anzahl erfasster Messpunkte von tracking Sys.
}

void calculation::meldung_anzeigen(const char *message)
{
  emit meldung_sig(message); // Statusmeldung anzeigen
}

// Slots
void calculation::trafom_berechnen()
{
  // Fehlermeldungen werden angezeigt, wenn Messpunkte von Robosys oder Tracksys. nicht vorhanden sind
  if (mp_robo_vorhanden == false || mp_track_vorhanden == false)
  {
    if (mp_robo_vorhanden == false)
    {
      this->meldung_anzeigen("Messpunkte von lokalem Robotersystem nicht vorhanden");
    }
    else
    {
      this->meldung_anzeigen("Messpunkte von Tracking-System noch nicht vorhanden");
    }
  }
  else
  {
    double mp_robo_init[3][3] = {0};
    double mp_track_init[3][3] = {0};
    double mp_robo_opt[3][3] = {0};
    double mp_track_opt[3][3] = {0};
    double residual = 0;

    // csv-Datei in der die wird geleert
    rapidcsv::Document doc1(path, rapidcsv::LabelParams(0, 0));
    doc1.Clear();

    // Umwandlung der st::vector Container in 2D-double Arrays
    for (unsigned int i = 0; i < (mp_robo.size() / 2); i++)
    {
      mp_robo_init[i][0] = mp_robo[i].sx;
      mp_robo_init[i][1] = mp_robo[i].sy;
      mp_robo_init[i][2] = mp_robo[i].sz;
      mp_robo_opt[i][0] = mp_robo[i + 3].sx;
      mp_robo_opt[i][1] = mp_robo[i + 3].sy;
      mp_robo_opt[i][2] = mp_robo[i + 3].sz;
    }
    for (unsigned int j = 0; j < (mp_track.size() / 2); j++)
    {
      mp_track_init[j][0] = mp_track[j].sx;
      mp_track_init[j][1] = mp_track[j].sy;
      mp_track_init[j][2] = mp_track[j].sz;
      mp_track_opt[j][0] = mp_track[j + 3].sx;
      mp_track_opt[j][1] = mp_track[j + 3].sy;
      mp_track_opt[j][2] = mp_track[j + 3].sz;
    }
    // Durchführung der groben Berechnung der Trafomatrix
    if (trafo3d_3trafo(trafomatrix, mp_robo_init, mp_track_init))
    {
      this->meldung_anzeigen("Trafomatrix konnte nicht berechnet werden");
    }
    // Optimierung der Trafomatrix
    if (trafo3d_opttrafo(trafomatrix, mp_robo_opt, mp_track_opt, 3, &residual))
    {
      this->meldung_anzeigen("Trafomatrix konnte nicht optimiert werden");
    }
    // Optimierung der Trafomatrix
    if (trafo3d_opttrafo(trafomatrix, mp_robo_init, mp_track_init, 3, &residual))
    {
      this->meldung_anzeigen("Trafomatrix konnte nicht optimiert werden");
    }

    // Abspeichern der Trafomatrix in eine csv-Datei
    for (int a = 0; a < 4; a++)
    {
      std::cout << trafomatrix[a][0] << "  " << trafomatrix[a][1] << "  " << trafomatrix[a][2] << "  " << trafomatrix[a][3] << std::endl;
      doc1.SetCell(0, a, trafomatrix[a][0]);
      doc1.SetCell(1, a, trafomatrix[a][1]);
      doc1.SetCell(2, a, trafomatrix[a][2]);
      doc1.SetCell(3, a, trafomatrix[a][3]);
    }
    std::cout << "Residual: " << residual << std::endl;
    doc1.SetCell(5, 0, residual);
        doc1.Save(path);
    this->meldung_anzeigen("Trafo-Matrix wurde berechnet und ist bereit");
  }
}

void calculation::robo_mp_einlesen(std::vector<messpunkt> robo)
{
  mp_robo = robo; // abspeichern der Messpunkte des lok. Robotersys.
  mp_robo_vorhanden = true;
}

void calculation::track_mp_einlesen(std::vector<messpunkt> track)
{
  mp_track = track; // abspeichern der Messpunkte des glob. Trackingsys.
  mp_track_vorhanden=true;
}

void calculation::starten()
{
  start = true;
}

void calculation::status_mp_einlesen(bool state)
{
  status_mp_track = state;
}

void calculation::reset()
{

  reset_kalib = true;
}

void calculation::trafom_einlesen()
{
  // öffnet die csv_Datei in der die Trafomatrix abgespeichert wurde
  rapidcsv::Document doc_trafomatrix(path, rapidcsv::LabelParams(0, 0));
  std::vector<double> row;
  for (unsigned int i = 0; i < doc_trafomatrix.GetRowCount(); i++)
  {
    row = doc_trafomatrix.GetRow<double>(i);
    trafomatrix[i][0] = row[0];
    trafomatrix[i][1] = row[1];
    trafomatrix[i][2] = row[2];
    trafomatrix[i][3] = row[3];
  }
  for (int r = 0; r < 4; r++)
  {
    std::cout << trafomatrix[r][0] << "  " << trafomatrix[r][1] << "  " << trafomatrix[r][2] << "  " << trafomatrix[r][3] << " Reihe " << r << std::endl;
  }
  this->meldung_anzeigen("Trafo-Matrix wurde von csv-Datein eingelesen und ich bereit");
}
