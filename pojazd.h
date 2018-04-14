/**
 * @file pojazd.h
 * @brief Ta głowa zawiera klasę pojazdu.
 * @author Karol Bieńkowski
 * @date 2018-03-05
 */

#ifndef POJAZD_H
#define POJAZD_H

#include "naped.h"
#include "silnik.h"
#include "pancerz.h"

#include <QMainWindow>
#include <cmath>
#include <QTextStream>
#include <vector>

using namespace std;
/**
 * @brief Ta klasa oblicza właściwości pojazdu i komunikuje je innym klasom.
 *
 * W domyśle, komunikuje je do GUI. Zawiera obiekty klas odpowiadających za podzespoły pojazdu i pobiera ich właściwości w celu policzenia właściwości całego pojazdu.
 */
class Pojazd
{
public:
    Pojazd();
    ~Pojazd();

    void set_Naped (int n); //1 -- kolowy; 2 -- gąsiennicowy; 3 -- półgąsiennicowy
    void set_Silnik (int n); //1 -- sil_diesel; 2 -- sil_elektryczny; 3 -- sil_turbina
    void set_Pancerz (int n);

    void set_ProjSlnk (double proj);
    void set_WykSlnk (double wyk);
    void set_SkSlnk (double NSkala);

    void set_ProjNapd (double proj);
    void set_WykNapd (double NWyk);
    void set_SkNapd (double skala);

    void set_ProjPanc (int proj, unsigned int index); //najpewniej nie bierzesz doubla tylko cały vector, albo nic i sam sobie pobierasz wektor
    void set_ProjPanc (unsigned int n);
    void set_WykPanc (int wyk, unsigned int index);
    void set_WykPanc (unsigned int n);
    void set_SkPanc (int skala, unsigned int index);
    void set_SkPanc (unsigned int n);

    void set_typPancerza (unsigned int index, int pancerz);
    void add_vPancerze (); //PANC:: pod warunkiem że się zawsze dodaje jako ostatni
    void del_vPancerze (unsigned int index);

    double get_Mob_Twa (); // może warto Mobilność zrobić varem
    double get_Mob_Sre ();
    double get_Mob_Mie ();
    double get_Mobilnosc ();

    double get_Masa ();
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztExpl ();
    double get_Wytrzymal ();
    double get_Trwalosc ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_ObrMie ();
    double get_ObrTwa ();
    double get_Rozmiar ();


private:

    double slope (double max, double nachyl, double co);
    double zawez(double co, double wokol, double wzakrplusminus);

    Naped *Napd; /**< Ogólny napęd pojazdu. Służy w polimorfizmie do szczególnego napędu.*/
    nap_kolowy kolo; /**< Domyślny napęd kołowy pojazdu*/
    nap_gasiennicowy gasi; /**< Domyślny napęd gąsiennicowy pojazdu*/
    nap_polgasiennicowy polg; /**< Domyślny napęd gąsiennicowy pojazdu*/

    Silnik *Slnk; /**< Ogólny silnik pojazdu. Służy w polimorfizmie do szczególnego silnika.*/
    sil_diesel dies; /**< Domyślny silnik diesla pojazdu*/
    sil_elektryczny elek; /**< Domyślny silnik elektryczny pojazdu*/
    sil_turbina turb; /**< Domyślny silnik turbowałowy pojazdu*/

//niepotrzebne
    Pancerz *Panc;
    pan_aluminiowy alum; // czy będę potrzebował wektorów niżej?
    pan_ceramiczny cera;
    pan_DU uran;
    pan_stalowy stal;
    pan_tytanowy tyta;
//niepotrzebne

    std::vector <Pancerz *> Pancerze;

};

#endif // POJAZD_H
