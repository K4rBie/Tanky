#include "pancerz.h"


Pancerz::Pancerz()
{
    // PANC:: to już jest potrzebne:
    Proj = 10;
    Skala = 10;
    Wykon = 10;
}

Pancerz::~Pancerz()
{

}

void Pancerz::set_Proj(int n) //PANC::check
{
    Proj = n;
}

void Pancerz::set_Skala(int n) //PANC::check
{
    Skala = n;
}

void Pancerz::set_Wykon(int n) //PANC::check
{
    Wykon = n;
}

//QTextStream out(stdout);
//out << "wejsciowy wektor listy:\n";

double Pancerz::slope(double max, double nachyl, double co){
    //nachylenie w okolicach 0.025-0.04 ma największy sens. Właściwie tylko to wchodzi w grę. 92% 95% 98%
    return max*(1 - exp(-nachyl*co));
}

double Pancerz::zawez(double co, double wokol, double wzakrplusminus){
    return wokol + (co - 55)/45*wzakrplusminus;
}
// 100^1/3 = 4,64


/* pancerz stalowy */

double pan_stalowy::get_KosztProd()
{
    return get_Skala()*get_Wykon()/(30 + (get_Proj() - 50)/5); //tylko dzielnik jest ruchomy (mała liczba -> duże zmiany)
}

double pan_stalowy::get_KosztProj()
{
    return get_Skala()*get_Proj();
}

double pan_stalowy::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double pan_stalowy::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double pan_stalowy::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double pan_stalowy::get_CzasProj(){
    return get_Skala()*get_Proj();
}
// pamiętaj cały czas, że koszt produkcji jest liniowy -- więc np to powinno być do pot 1/3 a nie 3, bo odwrotnie
double pan_stalowy::get_Masa(){
    return pow(get_Skala()/15,0.333)/(5 + (get_Proj() - 50)/25);
}

double pan_stalowy::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}

double pan_stalowy::get_Skutecznosc(){
    return pow(10000*get_Skala(), 0.333);
}


/* pancerz aluminiowy */

double pan_aluminiowy::get_KosztProd(){
    return get_Skala()*get_Wykon()/(30 + (get_Proj() - 50)/5); //tylko dzielnik jest ruchomy (mała liczba -> duże zmiany)
}

double pan_aluminiowy::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double pan_aluminiowy::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double pan_aluminiowy::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double pan_aluminiowy::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double pan_aluminiowy::get_CzasProj(){
    return get_Skala()*get_Proj();
}
// pamiętaj cały czas, że koszt produkcji jest liniowy -- więc np to powinno być do pot 1/3 a nie 3, bo odwrotnie
double pan_aluminiowy::get_Masa(){
    return pow(get_Skala()/15,0.333)/(5 + (get_Proj() - 50)/25);
}

double pan_aluminiowy::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}

double pan_aluminiowy::get_Skutecznosc(){
    return pow(10000*get_Skala(), 0.333);
}


/* pancerz tytanowy */

double pan_tytanowy::get_KosztProd(){
    return get_Skala()*get_Wykon()/(30 + (get_Proj() - 50)/5); //tylko dzielnik jest ruchomy (mała liczba -> duże zmiany)
}

double pan_tytanowy::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double pan_tytanowy::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double pan_tytanowy::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double pan_tytanowy::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double pan_tytanowy::get_CzasProj(){
    return get_Skala()*get_Proj();
}
// pamiętaj cały czas, że koszt produkcji jest liniowy -- więc np to powinno być do pot 1/3 a nie 3, bo odwrotnie
double pan_tytanowy::get_Masa(){
    return pow(get_Skala()/15,0.333)/(5 + (get_Proj() - 50)/25);
}

double pan_tytanowy::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}

double pan_tytanowy::get_Skutecznosc(){
    return pow(10000*get_Skala(), 0.333);
}


/* pancerz ze zubożonego uranu */

double pan_DU::get_KosztProd(){
    return get_Skala()*get_Wykon()/(30 + (get_Proj() - 50)/5); //tylko dzielnik jest ruchomy (mała liczba -> duże zmiany)
}

double pan_DU::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double pan_DU::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double pan_DU::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double pan_DU::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double pan_DU::get_CzasProj(){
    return get_Skala()*get_Proj();
}
// pamiętaj cały czas, że koszt produkcji jest liniowy -- więc np to powinno być do pot 1/3 a nie 3, bo odwrotnie
double pan_DU::get_Masa(){
    return pow(get_Skala()/15,0.333)/(5 + (get_Proj() - 50)/25);
}

double pan_DU::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}

double pan_DU::get_Skutecznosc(){
    return pow(10000*get_Skala(), 0.333);
}


/* pancerz ceramiczny */

double pan_ceramiczny::get_KosztProd(){
    return get_Skala()*get_Wykon()/(30 + (get_Proj() - 50)/5); //tylko dzielnik jest ruchomy (mała liczba -> duże zmiany)
}

double pan_ceramiczny::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double pan_ceramiczny::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double pan_ceramiczny::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double pan_ceramiczny::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double pan_ceramiczny::get_CzasProj(){
    return get_Skala()*get_Proj();
}
// pamiętaj cały czas, że koszt produkcji jest liniowy -- więc np to powinno być do pot 1/3 a nie 3, bo odwrotnie
double pan_ceramiczny::get_Masa(){
    return pow(get_Skala()/15,0.333)/(5 + (get_Proj() - 50)/25);
}

double pan_ceramiczny::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}

double pan_ceramiczny::get_Skutecznosc(){
    return pow(10000*get_Skala(), 0.333);
}
