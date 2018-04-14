/**
 * @file pojazd.cpp
 * @brief To ciało zawiera klasę Pojazd .
 * @author Karol Bieńkowski
 * @date 2018-03-05
 */

#include "pojazd.h"
#include <QDebug>
#include <iostream>
#include <QtDebug>

/**
 * @brief Kostruktor klasy Pojazd
 * Przyjmuje początkowe wartości dla napędu i silnika.
 */
Pojazd::Pojazd(): Napd(&kolo), Slnk(&dies) {
    Pancerze.push_back(new pan_stalowy);
} //PANC::check

Pojazd::~Pojazd(){
    for (unsigned int i=0; i<Pancerze.size(); i++) delete Pancerze.at(i);
}

double Pojazd::slope(double max, double nachyl, double co){
    //nachylenie w okolicach 0.025-0.04 ma największy sens. Właściwie tylko to wchodzi w grę. 92% 95% 98%
    return max*(1 - exp(-nachyl*co));
}

double Pojazd::zawez(double co, double wokol, double wzakrplusminus){ //pomyśl czy da się to zrobić tak żeby nie kopiować 100razy tej funkcji
    return wokol + (co - 55)/45*wzakrplusminus;
}

/*PUBLIC*/

/**
 * @brief Podaje obiektowi klasy Silnik wartość do wpisania jako projekt silnika.
 * @param proj Podawana dalej wartość projektu silnika.
 */
void Pojazd::set_ProjSlnk(double proj){
    Slnk->set_Proj(proj);
}

/**
 * @brief Podaje obiektowi klasy Silnik wartość do wpisania jako jakość wykonania silnika.
 * @param wyk Podawana dalej wartość jakości wykonania silnika.
 */
void Pojazd::set_WykSlnk(double wyk){
    Slnk->set_Wyk(wyk);
}

void Pojazd::set_SkSlnk(double NSkala){
    Slnk->set_Skal(NSkala);
}


void Pojazd::set_ProjNapd(double proj){
    Napd->set_Proj(proj);
}

void Pojazd::set_WykNapd(double NWyk){
    Napd->set_Wyk(NWyk);
}

void Pojazd::set_SkNapd(double skala){
    Napd->set_Skal(skala);
}

void Pojazd::set_ProjPanc(int proj, unsigned int index) //slajdery są intami dopóki nie dotrą do Pancerza //PANC::check
{
    //Panc->set_Proj(proj, index);
    Pancerze.at(index)->set_Proj(proj);
}

void Pojazd::set_WykPanc(int wyk, unsigned int index) //PANC::check
{
    //Panc->set_Wykon(wyk, n);
    Pancerze.at(index)->set_Wykon(wyk);
}

void Pojazd::set_SkPanc(int skala, unsigned int index) //PANC::check
{
    //Panc->set_Skala(skala, n);
    Pancerze.at(index)->set_Skala(skala);
}

void Pojazd::set_typPancerza(unsigned int index, int pancerz) //PANC:: czy int pancerz ma być unsigned? dodaj test żeby się upewnić //PANC::check
{
    //Panc->set_vec_Lista(index, pancerz);
    int Proj = Pancerze.at(index)->get_Proj();
    int Skala = Pancerze.at(index)->get_Skala();
    int Wykon = Pancerze.at(index)->get_Wykon();

    delete Pancerze.at(index);

    if (pancerz == 0){
        Pancerze.at(index) = new pan_stalowy;
    }else if (pancerz == 1){
        Pancerze.at(index) = new pan_aluminiowy;
    }else if (pancerz == 2){
        Pancerze.at(index) = new pan_tytanowy;
    }else if (pancerz == 3){
        Pancerze.at(index) = new pan_DU;
    }else if (pancerz == 4){
        Pancerze.at(index) = new pan_ceramiczny;
    }else{
        QTextStream out(stdout);
        out << "błędny index typu pancerza; wybór rodzaju pancerza z listy";
    }

    Pancerze.at(index)->set_Proj(Proj);
    Pancerze.at(index)->set_Skala(Skala);
    Pancerze.at(index)->set_Wykon(Wykon);

}

void Pojazd::add_vPancerze()
{
    Pancerze.push_back(new pan_stalowy);
}

void Pojazd::del_vPancerze(unsigned int index)
{
    //Panc->set_vec_Lista(index);
    delete Pancerze.at(index);
    Pancerze.erase(Pancerze.begin()+index);
}


void Pojazd::set_Naped(int n){
    if(n==0){Napd = &kolo;}
    else if(n==1){Napd = &gasi;}
    else if(n==2){Napd = &polg;};
}

void Pojazd::set_Silnik(int n){
    if(n==0){Slnk = &dies;}
    else if(n==1){Slnk = &turb;}
    else if(n==2){Slnk = &elek;};
}


//-------------- ODTĄD ------------------------
double Pojazd::get_Mob_Twa(){
    return get_Mobilnosc()*Napd->get_ModMobiTwa();
}

double Pojazd::get_Mob_Sre(){
    return get_Mobilnosc()*Napd->get_ModMobiSre();
}

double Pojazd::get_Mob_Mie(){
    return get_Mobilnosc()*Napd->get_ModMobiMie();
}

double Pojazd::get_Mobilnosc(){ //niezależna od rodzaju napędu, bo on ma znaczenie dopiero przy rodzaju terenu
    return Slnk->get_Moc() / (10 + 0.1*abs( Napd->get_Skala()-Slnk->get_Skala() ) ) / get_Masa();
}
//-------------- DOTĄD ------------------------
//przeanalizuj jak powinna być wyliczana na wysokim poziomie mobilność pojazdu

double Pojazd::get_Masa()
{
    return Napd->get_Masa() + Slnk->get_Masa();
}

double Pojazd::get_KosztProd() //PANC::check
{
    double KosztPanc = 0;

    for (unsigned int i = 0; i<Pancerze.size(); i++) // nie wykonuje się tyle razy ile trzeba PANC:: upewnij się że tak jest, czy to przez unsigned?
    {
        //Koszt += Panc->get_Proj().at(i) * Panc->get_Wykon().at(i) / zawez(Panc->get_Proj().at(i),30,10);
        KosztPanc += Pancerze.at(i)->get_KosztProd()*(i+1); //ta fcja powinna wolniej rosnąć
    }

    return Napd->get_KosztProd() + Slnk->get_KosztProd() + KosztPanc;
}

double Pojazd::get_KosztProj()
{
    return Napd->get_KosztProj() + Slnk->get_KosztProj();
}

double Pojazd::get_KosztExpl()
{
    return Napd->get_KosztUtrz() + Slnk->get_KosztUtrz();
}

double Pojazd::get_Wytrzymal()
{
    return Napd->get_Wytrzymal() + Slnk->get_Wytrzymal();
}

double Pojazd::get_Trwalosc()
{
    return 303;
}

double Pojazd::get_CzasProd() // to kiedyś zostanie rozwinięte o o koncepcje fabryk, które produkują te części w różnym tempie
{
    return std::min({Napd->get_CzasProd(), Slnk->get_CzasProd()});
}

double Pojazd::get_CzasProj()
{
    return Napd->get_CzasProj() + Slnk->get_CzasProj();
}

double Pojazd::get_ObrMie()
{
    return 66;
}

double Pojazd::get_ObrTwa()
{
    return 88;
}

double Pojazd::get_Rozmiar()
{
    return 420;
}


/*PRIVATE*/




