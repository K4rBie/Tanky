/**
 * @file glowneokno.h
 * @brief ta głowa zawiera wszystkie funkcje odpowiedzialne za komunikację pomiędzy GUI i obiektem klasy pojazd.
 * @author Karol Bieńkowski
 * @date 2018-03-05
 */

#ifndef GLOWNEOKNO_H
#define GLOWNEOKNO_H

#include <QMainWindow>
#include <QListWidget>
#include <QFileDialog>
#include <sstream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <QTextStream>

#include "pojazd.h"
#include "cl_tabpancerz.h"


namespace Ui {
class GlowneOkno;
}

/**
 * @brief Ta klasa odpowiada za komunikację pomiędzy GUI i obiektem klasy pojazd
 *
 * Pozwala na wprowadzanie danych wejściowych z GUI do obiektu, wyprowadzanie danych wyjściowych do GUI, oraz zapis/wczytywanie danych do/z pliku
 */

class GlowneOkno : public QMainWindow
{Q_OBJECT

public:
    explicit GlowneOkno(QWidget *parent = 0);
    ~GlowneOkno();

    Pojazd *pojazd; /**< Pojazd, na którym operuje program. */

private slots:
    void ProjPanc_valChanged(const int &value);
    void SkPanc_valChanged(const int &value);
    void WykPanc_valChanged(const int &value);

    void on_ProjNapd_valueChanged(int value);
    void on_SkNapd_valueChanged(int value);
    void on_WykNapd_valueChanged(int value);

    void on_ProjSlnk_valueChanged(int value);
    void on_SkSlnk_valueChanged(int value);
    void on_WykSlnk_valueChanged(int value);

    void on_lista_podwozie_itemClicked(); //wybór podwozia i silnika
    void on_lista_Silnik_itemClicked();
    void ListaPanc_Changed(const int &n); // EKSP: unsig

    void on_actionZapisz_triggered();
    void zapisz();

    void on_actionWczytaj_triggered();
    void wczytaj();

    void on_dodaj_warstwe_clicked();

    void on_usun_warstwe_clicked();

private:
    cl_TabPancerz *tab1;
    Ui::GlowneOkno *ui;
    template<class TYPE>
    QString doQstr(TYPE x);
    void aktualizuj();   
    void wpisz();
};



#endif // GLOWNEOKNO_H
