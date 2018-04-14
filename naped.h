/**
 * @file naped.h
 * @brief Ta głowa zawiera klasę napędu i klasy konkretnych typów napędów, które po niej dziedziczą.
 * @author Karol Bieńkowski
 * @date 2018-03-05
 */

#ifndef NAPED_H
#define NAPED_H
#include "cmath"
#include <QTextStream>

/**
 * @brief klasa służąca jako podstawa pod polimorfizm rodzaju napędu.
 *
 */

class Naped
{
public:
    Naped();
    ~Naped(); // można przerobić polimorfię tak żeby wszystko było dynamiczne ale wtedy destruktor musi być virtualny

    virtual double get_KosztProd (){return 1;}
    virtual double get_KosztProj (){return 1;}
    virtual double get_KosztUtrz (){return 1;}
    virtual double get_Wytrzymal (){return 1;}
    virtual double get_CzasProd (){return 1;}
    virtual double get_CzasProj (){return 1;}
    virtual double get_Masa (){return 1;}
    virtual double get_Trwalosc (){return 1;}
    virtual double get_Udzwig (){return 1;}

    virtual double get_ModMobiTwa (){return 1;}
    virtual double get_ModMobiSre (){return 1;}
    virtual double get_ModMobiMie (){return 1;}

    void set_Proj (double n){*Proj = n;}
    void set_Skal (double n){*Skala = n;}
    void set_Wyk (double n){*Wykon = n;}

    double get_Proj (){return *Proj;}
    double get_Skala (){return *Skala;} //potrzebuję te funkcje bo private jest private nawet z public virtual
    double get_Wykon (){return *Wykon;}

    double slope (double max, double nachyl, double co);
    double zawez(double co, double wokol, double wzakrplusminus);

private:
    double *Proj;
    double *Skala;
    double *Wykon;
};


class nap_gasiennicowy: public virtual Naped{
public:
    nap_gasiennicowy(){}
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Masa ();
    double get_Trwalosc ();
    double get_Udzwig ();

    double get_ModMobiTwa (){return 6;}
    double get_ModMobiSre (){return 5;}
    double get_ModMobiMie (){return 3;}

private:
    //możesz wszystkie funkcje zrobić takimi samymi, będą tylko w klasie Naped, podklasy będą się do nich odnosić i wstawiać prywatną stałą z parametrami. A możesz zostawić jak jest i też jest spoko

};

class nap_polgasiennicowy: public virtual Naped{
public:
    nap_polgasiennicowy (){}
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Masa ();
    double get_Trwalosc ();
    double get_Udzwig ();

    double get_ModMobiTwa (){return 7;}
    double get_ModMobiSre (){return 5;}
    double get_ModMobiMie (){return 2;}

private:

};

class nap_kolowy: public virtual Naped{
public:
    nap_kolowy (){}
    double get_KosztProd ();
    double get_KosztProj ();
    double get_KosztUtrz ();
    double get_Wytrzymal ();
    double get_CzasProd ();
    double get_CzasProj ();
    double get_Masa ();
    double get_Trwalosc ();
    double get_Udzwig ();

    double get_ModMobiTwa (){return 10;}
    double get_ModMobiSre (){return 5;}
    double get_ModMobiMie (){return 1;}

private:

};

#endif // NAPED_H
