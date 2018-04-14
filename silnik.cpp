#include "silnik.h"
//zapomnij o klasie obiekt -- nie ma sensu na tym etapie zawracać sobie głowy takim 'ulepszeniem'

Silnik::Silnik()
{
    Proj = new double;
    Skala = new double;
    Wykon = new double;

    *Proj = 10;
    *Skala = 10;
    *Wykon = 10;
}

Silnik::~Silnik()
{
    delete Proj;
    delete Skala;
    delete Wykon;
}

double Silnik::slope(double max, double nachyl, double co){
    return max*(1 - exp(-nachyl*co));
}

double Silnik::zawez(double co, double wokol, double wzakrplusminus){
    return wokol + (co - 55)/45*wzakrplusminus;
}

/*SILNIK DIESLA*/

double sil_diesel::get_Moc(){
    return slope(150,0.02,get_Skala()) + slope(8,0.01,get_Wykon()) + slope(8,0.02,get_Proj());
}

double sil_diesel::get_KosztProd(){
    return 1*get_Skala()*get_Wykon()/(50 + (get_Proj() - 50)/10);
}

double sil_diesel::get_Masa(){
    return pow(get_Skala()/25,1/3)/zawez(get_Proj(),5,1);
}

double sil_diesel::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double sil_diesel::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double sil_diesel::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double sil_diesel::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double sil_diesel::get_CzasProj(){
    return get_Skala()*get_Proj();
}

double sil_diesel::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}


/*SILNIK ELEKTRYCZNY*/

double sil_elektryczny::get_Moc(){
    return slope(150,0.04,get_Skala()) + slope(8,0.01,get_Wykon()) + slope(8,0.02,get_Proj());
}

double sil_elektryczny::get_KosztProd(){
    return 2*get_Skala()*get_Wykon()/(50 + (get_Proj() - 50)/10);
}

double sil_elektryczny::get_Masa(){
    return pow(get_Skala()/25,3)/(10 + (get_Proj() - 50)/25);
}
double sil_elektryczny::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double sil_elektryczny::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double sil_elektryczny::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double sil_elektryczny::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double sil_elektryczny::get_CzasProj(){
    return get_Skala()*get_Proj();
}

double sil_elektryczny::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}


/*SILNIK TURBOWAŁOWY*/

double sil_turbina::get_Moc(){
    return slope(150,0.04,get_Skala()) + slope(8,0.01,get_Wykon()) + slope(8,0.02,get_Proj());
}

double sil_turbina::get_KosztProd(){
    return 1.5*get_Skala()*get_Wykon()/(50 + (get_Proj() - 50)/10); //tylko dzielnik jest ruchomy (mała liczba -> duże zmiany)
}

double sil_turbina::get_Masa(){
    return pow(get_Skala()/25,3)/(15 + (get_Proj() - 50)/25);
}

double sil_turbina::get_KosztProj(){
    return get_Skala()*get_Proj();
}

double sil_turbina::get_KosztUtrz(){
    return 10*get_Skala()/(30 + (get_Proj() - 50)/5)/(20 + (get_Wykon() - 50)/5);
}

double sil_turbina::get_Wytrzymal(){
    return pow(get_Skala(), 0.333)*(20 + (get_Proj() - 50)/5)*(20 + (get_Wykon() - 50)/5);
}

double sil_turbina::get_CzasProd(){
    return pow(get_Skala(), 0.333)*get_Wykon();
}

double sil_turbina::get_CzasProj(){
    return get_Skala()*get_Proj();
}

double sil_turbina::get_Trwalosc(){
    return get_Proj()*get_Wykon();
}
