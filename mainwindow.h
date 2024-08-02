#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "messpunkt.h"
#include <vector>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  Ui::MainWindow *ui;
  bool exit=false;

signals:
  void trafom_einlesen_sig(void);
  void robo_mp_einlesen_sig(std::vector<messpunkt> csv_data);
  void trafom_berechnen_sig();
  void start_sig(bool strt);
  void status_mp_einlesen_sig(bool state);
  void reset_sig(bool rst);

public slots:
  void track_koords(double x,double y,double z);
  void robo_koords(double x,double y, double z);
  void ampel(bool state);
  void anzahl_mp(int counter);
  void meldung(const char* message);

private slots:
  void on_start_btn_clicked();
  void on_reset_btn_clicked();
  void on_robo_mp_einlesen_btn_clicked();
  void on_trafom_berechnen_btn_clicked();
  void on_trafom_einlesen_btn_clicked();
  void on_prog_beenden_btn_clicked();
};

#endif // MAINWINDOW_H
