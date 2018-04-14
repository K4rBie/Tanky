#include "naped.h"

// koncepcja jest taka -- koszt rośnie liniowo, za to efekty odwrotnie eksponencjalnie (czy cokolwiek) ło tak o: e^10 - e^-(x-10)

Naped::Naped()
{
    //te zmienne nie mają wartości początkowej. 2 możliwości; - pobrać je z głównego okna (zawsze poprawne ale wymaga specjalnej funkcji)
    // - hardkodować (wady, wiadomo. ale obędzie się bez żadnych funkjci)
    Proj = new double;
    Skala = new double;
    Wykon = new double;

    *Proj = 10;
    *Skala = 10;
    *Wykon = 10;
}

Naped::~Naped()
{
    delete Proj;
    delete Skala;
    delete Wykon;
}

double Naped::slope(double max, double nachyl, double co){
    //nachylenie w okolicach 0.025-0.04 ma największy sens. Właściwie tylko to wchodzi w grę. 92% 95% 98%
    return max*(1 - exp(-nachyl*co));
}

double Naped::zawez(double co, double wokol, double wzakrplusminus){
    return wokol + (co - 55)/45*wzakrplusminus;
}


/*NAPĘD GĄSIENNICOWY*/

double nap_gasiennicowy::get_KosztProd(){
    return get_Skala()*get_Wykon()/(30 + (get_Proj() - 50)/5); //tylko dzielnik jest ruchomy (mała liczba -> duże zmiany)
}

double nap_gasiennicowy::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double nap_gasiennicowy::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double nap_gasiennicowy::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double nap_gasiennicowy::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double nap_gasiennicowy::get_CzasProj(){
    return get_Skala()*get_Proj();
}
// pamiętaj cały czas, że koszt produkcji jest liniowy -- więc np to powinno być do pot 1/3 a nie 3, bo odwrotnie
double nap_gasiennicowy::get_Masa(){
    return pow(get_Skala()/15,0.333)/(5 + (get_Proj() - 50)/25);
}

double nap_gasiennicowy::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}

double nap_gasiennicowy::get_Udzwig(){
    return pow(10000*get_Skala(), 0.333);
}


/*NAPĘD KOŁOWY*/

double nap_kolowy::get_KosztProd(){
    return get_Skala()*get_Wykon()/(50 + (get_Proj() - 50)/15);
}

double nap_kolowy::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double nap_kolowy::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double nap_kolowy::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double nap_kolowy::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double nap_kolowy::get_CzasProj(){
    return get_Skala()*get_Proj();
}

double nap_kolowy::get_Masa(){
    return pow(get_Skala()/15 , 0.333)/(10 + (get_Proj() - 50)/50);
}

double nap_kolowy::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}

double nap_kolowy::get_Udzwig(){
    return pow(10000*get_Skala(), 0.333);
} // niech udźwig decyduje jaką szansę ma pojazd zakopać się przy swojej masie -- wtedy to powinno trafić do klasy pojazd


/*NAPĘD PÓŁGĄSIENNICOWY*/

double nap_polgasiennicowy::get_KosztProd(){
    //return 0.01*pow(Skala/10,3)*exp(Wykon/15);
    return get_Skala()*get_Wykon()/(40 + (get_Proj() - 50)/10);
}

double nap_polgasiennicowy::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double nap_polgasiennicowy::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double nap_polgasiennicowy::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double nap_polgasiennicowy::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double nap_polgasiennicowy::get_CzasProj(){
    return get_Skala()*get_Proj();
}

double nap_polgasiennicowy::get_Masa(){
    return pow(get_Skala()/15,0.333)/(7 + (get_Proj() - 50)/25);
}

double nap_polgasiennicowy::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}

double nap_polgasiennicowy::get_Udzwig(){
    return pow(10000*get_Skala(), 0.333);
}
