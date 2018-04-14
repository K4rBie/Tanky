#ifndef CL_TABPANCERZ_H
#define CL_TABPANCERZ_H

#include <QWidget>
#include <QTextStream>
#include "pojazd.h"
#include <vector>

namespace Ui {
class cl_TabPancerz;
}

class cl_TabPancerz : public QWidget
{
    Q_OBJECT

public:
    explicit cl_TabPancerz(QWidget *parent = 0);
    ~cl_TabPancerz();

private slots:
    void on_ProjPanc_valueChanged(int value); //już wiesz jak to działa, zrób to ładnie

    void on_lista_pancerz_itemSelectionChanged();

    void on_SkPanc_valueChanged(int value);

    void on_WykPanc_valueChanged(int value);

signals:
    void ProjPanc (int value);
    void SkPanc (int value);
    void WykPanc (int value);
    void ListaPanc (int value);

private:
    Ui::cl_TabPancerz *ui;
};

#endif // CL_TABPANCERZ_H
