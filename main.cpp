#include "glowneokno.h"
#include <QApplication>
//#include "cl_tabpancerz.h"
//#include "glowneokno.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GlowneOkno w;
    w.show();

    return a.exec();
}


/* TO DO LIST
 *
 * wszystkie slajdery powinny przenosić inty dopóki nie dotrą do właściwego elementu pojazdu, który zapisuje je jako double i tak na nich działa
 *
 * istnieje zagrożenie że unsignedy zostaną źle zrozumiane jeśli trafią (?) -- nie jeśli nie przypiszesz im gdzieś ujemnej wartości
 * przenieś slope i zawęź do oddzielnej klasy matma
 *
 *
 * QTextStream out(stdout);
 * out << "wejsciowy wektor listy:\n";
 */
