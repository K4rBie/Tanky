#ifndef PANCERZ_H
#define PANCERZ_H

#include "cmath"
#include <vector>
#include <QTextStream>

class Pancerz
{
public:
    Pancerz();
    virtual ~Pancerz();
    //potrzebna funkcja która wyciągnie dane z pancerza do pojazdu i dalej

    virtual double get_KosztProd (){return 1;}
    virtual double get_KosztProj (){return 1;}
    virtual double get_KosztUtrz (){return 1;}
    virtual double get_Wytrzymal (){return 1;}
    virtual double get_CzasProd (){return 1;}
    virtual double get_CzasProj (){return 1;}
    virtual double get_Masa (){return 1;}
    virtual double get_Trwalosc (){return 1;}
    virtual double get_Skutecznosc (){return 1;}

    void set_Proj (int n);
    void set_Skala (int n);
    void set_Wykon (int n);

    double get_Proj (){return Proj;} //rozkmiń czy może lepiej zeby dawał pointer i jak to robić (niesitotne) -- istotne (może referencja?)
    double get_Skala (){return Skala;} // przeanalizuj czy to serio powoduje jakąś oszczędność w zużyciu pamięci
    double get_Wykon (){return Wykon;} //PANC::check

    double slope (double max, double nachyl, double co);
    double zawez(double co, double wokol, double wzakrplusminus);


private:
    //tymczasowo -- PANC:: okazuje się że nie i tak zostanie
    double Proj; //przerób na &proj kiedyś
    double Skala; // musi być double wtedy nie trzeba pamiętać, żeby przerabiać wynik z intów w double - prostszy kod
    double Wykon;

};

class pan_stalowy: public virtual Pancerz{
public:
    pan_stalowy(){}
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Masa ();
    double get_Trwalosc ();
    double get_Skutecznosc ();
};

class pan_aluminiowy: public virtual Pancerz{
public:
    pan_aluminiowy(){}
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Masa ();
    double get_Trwalosc ();
    double get_Skutecznosc ();
};

class pan_tytanowy: public virtual Pancerz{
public:
    pan_tytanowy(){}
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Masa ();
    double get_Trwalosc ();
    double get_Skutecznosc ();
};

class pan_DU: public virtual Pancerz{
public:
    pan_DU(){}
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Masa ();
    double get_Trwalosc ();
    double get_Skutecznosc ();
};

class pan_ceramiczny: public virtual Pancerz{
public:
    pan_ceramiczny(){}
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Masa ();
    double get_Trwalosc ();
    double get_Skutecznosc ();
};
#endif // PANCERZ_H
