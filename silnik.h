/**
 * @file silnik.h
 * @brief Ta głowa zawiera klasę silnika i klasy konkretnych typów silników, które po niej dziedziczą.
 * @author Karol Bieńkowski
 * @date 2018-03-05
 */

#ifndef SILNIK_H
#define SILNIK_H

#include <QDebug>
#include <cmath>
#include <QTextStream>

/**
 * @brief klasa służąca jako podstawa pod polimorfizm rodzaju silnika.
 *
 */

class Silnik
{
public:
    Silnik();
    ~Silnik();

    virtual double get_Moc (){return 1;}
    virtual double get_KosztProd (){return 1;}
    virtual double get_Masa (){return 1;}
    virtual double get_KosztProj (){return 1;}
    virtual double get_KosztUtrz (){return 1;}
    virtual double get_Wytrzymal (){return 1;}
    virtual double get_CzasProd (){return 1;}
    virtual double get_CzasProj (){return 1;}
    virtual double get_Trwalosc (){return 1;}

    void set_Proj(double n){*Proj = n;}
    void set_Skal(double n){*Skala = n;}
    void set_Wyk(double n){*Wykon = n;}

    double get_Proj (){return *Proj;}
    double get_Skala (){return *Skala;}
    double get_Wykon (){return *Wykon;}

    double slope (double max, double nachyl, double co);
    double zawez (double co, double wokol, double wzakresie);


private:

    double *Proj;
    double *Skala;
    double *Wykon;
};


class sil_diesel: public virtual Silnik{
public:
    sil_diesel(){}

    double get_Moc ();
    double get_KosztProd ();
    double get_Masa ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Trwalosc ();

private:

};

class sil_turbina: public virtual Silnik{
public:
    sil_turbina(){}

    double get_Moc ();
    double get_KosztProd ();
    double get_Masa ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Trwalosc ();

private:

};

class sil_elektryczny: public virtual Silnik{
public:
    sil_elektryczny(){}

    double get_Moc ();
    double get_KosztProd ();
    double get_Masa ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Trwalosc ();

private:

};


#endif // SILNIK_H
