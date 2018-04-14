#include "cl_tabpancerz.h"
#include "ui_cl_tabpancerz.h"

cl_TabPancerz::cl_TabPancerz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cl_TabPancerz)
{
    ui->setupUi(this);
    ui->lista_pancerz->setCurrentRow(0);
}

cl_TabPancerz::~cl_TabPancerz()
{
    delete ui;
}


void cl_TabPancerz::on_ProjPanc_valueChanged(int value)
{
    emit ProjPanc(value);
}

void cl_TabPancerz::on_SkPanc_valueChanged(int value)
{
    emit SkPanc(value);
}

void cl_TabPancerz::on_lista_pancerz_itemSelectionChanged()
{
    int n = ui->lista_pancerz->currentRow(); // EKSP:: czy może być unsigned?
    emit ListaPanc(n);
}

void cl_TabPancerz::on_WykPanc_valueChanged(int value)
{
    emit WykPanc(value);
}
