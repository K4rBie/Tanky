/**
 * @file glowneokno.cpp
 * @brief To ciało zawiera wszystkie funkcje odpowiedzialne za komunikację pomiędzy GUI i obiektem klasy pojazd.
 * @author Karol Bieńkowski
 * @date 2018-03-05
 */

#include "glowneokno.h"
#include "ui_glowneokno.h"

/**/
/**
 * @brief Konstruktor klasy GlowneOkno.
 * @param parent Qtowe cuda, nie pytajcie.
 */
GlowneOkno::GlowneOkno(QWidget *parent): QMainWindow(parent), ui(new Ui::GlowneOkno)
{
    ui->setupUi(this);

    /* Dodaję taby dla pancerzy */
    tab1 = new cl_TabPancerz;
    ui->tab_Pancerz->addTab(tab1, "warstwa 1");


    /* Ustawiam domyślne elementy listy */
    ui->lista_podwozie->setCurrentRow(0);
    ui->lista_Silnik->setCurrentRow(0);

    pojazd = new Pojazd();


    connect(tab1,SIGNAL(ProjPanc(int)), this, SLOT(ProjPanc_valChanged(int)));
    connect(tab1,SIGNAL(SkPanc(int)), this, SLOT(SkPanc_valChanged(int)));
    connect(tab1,SIGNAL(WykPanc(int)), this, SLOT(WykPanc_valChanged(int)));
    connect(tab1,SIGNAL(ListaPanc(unsigned int)), this, SLOT(ListaPanc_Changed(unsigned int)));

    wpisz(); // byćmoże powinno trafić na koniec ale nie wiem czy to czegoś nie popsuje
}
/**
 * @brief Desktruktor klasy GlowneOkno.
 */
GlowneOkno::~GlowneOkno()
{
    //delete tab1; //nie wie co usuwa gdy ta wartość została wyczyszczona wcześniej/ lepiej czyść tu wszystkie taby
    int n = ui->tab_Pancerz->count(); //oddzielnie od ifa bo może się zmieniać podczas wywoływania :P
    for(int i=0;i<n;i++)
    {
        QWidget *tab = ui->tab_Pancerz->widget(i);
        delete tab;
    }

    delete pojazd;
    delete ui;
}

void GlowneOkno::wpisz(){ //możliwe że powinienem to oddelegować jako kolejną funkcję :P
    //ma wyglądać tak: daje niebieski jak wartość rośnie, czerwony jak maleje. Jednocześnie ma nie znikać gdy się nie zmienia co skok tylko rzadziej i powinna się resetować gdy poruszam innym slajderem niż ostatnio.
//    QString qstr = ui->VLKosztProd->text();
//    int x = qstr.toInt(); //nowa wartość
//    int n = round(pojazd->get_KosztProd()); //stara wartość
    ui->VLKosztProd->setText(doQstr(pojazd->get_KosztProd()));
//    if (x>n){
//        ui->VLKosztProd->setStyleSheet("QLabel { background-color : red; }");
//    }else{
//        ui->VLKosztProd->setStyleSheet("QLabel { background-color : blue; }");
//    }

    ui->val_KosztExplo->setText(doQstr(pojazd->get_KosztExpl()));
    ui->val_KosztProj->setText(doQstr(pojazd->get_KosztProj()));

    ui->VLMobilnosc->setText(doQstr(pojazd->get_Mob_Twa())); //liczenie Mobilności jako listy nie ma sensu bo tutaj i tak trzeba 3x...
    ui->VLMob2->setText(doQstr(pojazd->get_Mob_Sre())); // ...to wywołać
    ui->VLMob3->setText(doQstr(pojazd->get_Mob_Mie()));

    ui->val_CzasProd->setText(doQstr(pojazd->get_CzasProd()));
    ui->val_CzasProj->setText(doQstr(pojazd->get_CzasProj()));

    ui->val_Masa->setText(doQstr(pojazd->get_Masa()));
    ui->val_Rozmiar->setText(doQstr(pojazd->get_Rozmiar()));

    ui->val_ObrMie->setText(doQstr(pojazd->get_ObrMie()));
    ui->val_ObrTwa->setText(doQstr(pojazd->get_ObrTwa()));

    ui->val_Trwalosc->setText(doQstr(pojazd->get_Trwalosc()));
    ui->val_Wytrzym->setText(doQstr(pojazd->get_Wytrzymal()));
}

/*SLAJDERY*/

void GlowneOkno::ProjPanc_valChanged(const int &value) //PANC::check
{
/* aktualnie jedyne rozsądne rozwiązanie brzmi: Pojazd ma wektor pointerów do warstw pancerza
 * każdy zlajder ma wartość początkową 10, więc można to hardkodować, albo wysyłać wartość po striggerowaniu utworzenia slajdera [1]
 * zmiana wartości slajdera wysyła sygnał do GłownegoOkna, który wysyła to dalej do Pojazdu i on zapisuje ją w odpowiednim elemencie wektora, a potem przelicza wszystko
 * to oznacza, że numer taba tez musi trafiać do Pojazdu
 * dodawanie nowego taba musi powiększać wektor i nadawać mu bazowe wartości (slidery 10, typ pancerz -- raczej w konstruktorze pancerza)
 * rozmiar wektora musi reagować na zmianę ilości tabów przez GłówneOkno.
 * usuwanie okna musi przeliczać nowe wartości i usuwać wektor
 *
 * [1] trzebaby najpierw zrobić nowy element slidera, potem w kostruktorze cl_tabpancerz przenieść wartość sliderów do pancerza i odświeżyć liczenie. Zaletą jest to że można sobie zmieniać wartości początkowe i wszystko będzie śmigać. Tylko czy to jest takie przydatne żeby zmieniać tyle kodu? raczej nie
 */

    pojazd->set_ProjPanc(value, ui->tab_Pancerz->currentIndex()); //PANC::check
    wpisz();
}

void GlowneOkno::SkPanc_valChanged(const int &value) //PANC::check
{
    pojazd->set_SkPanc(value, ui->tab_Pancerz->currentIndex());
    wpisz();
}

void GlowneOkno::WykPanc_valChanged(const int &value) //PANC::check
{
    pojazd->set_WykPanc(value, ui->tab_Pancerz->currentIndex());
    wpisz();
}



void GlowneOkno::on_ProjSlnk_valueChanged(int value){
    pojazd->set_ProjSlnk(value);
    wpisz();
}

void GlowneOkno::on_SkSlnk_valueChanged(int value){
    pojazd->set_SkSlnk(value);
    wpisz();
}

void GlowneOkno::on_WykSlnk_valueChanged(int value){
    pojazd->set_WykSlnk(value);
    wpisz();
}



void GlowneOkno::on_ProjNapd_valueChanged(int value){
    pojazd->set_ProjNapd(value);
    wpisz();
}

void GlowneOkno::on_SkNapd_valueChanged(int value){
    pojazd->set_SkNapd(value);
    wpisz();
}

void GlowneOkno::on_WykNapd_valueChanged(int value){
    pojazd->set_WykNapd(value);
    wpisz();
}


/*LISTY*/

/**
 * @brief Zmienia rodzaj napędu.
 *
 * Po kliknięciu na listę podwozi następuje zmiana rodzaju napędu na nowo wybrany i aktualizacja wszystkich cech pojazdu.
 */
void GlowneOkno::on_lista_podwozie_itemClicked()
{
    pojazd->set_Naped(ui->lista_podwozie->currentRow());
    wpisz();
}

/**
 * @brief Zmienia rodzaj silnika.
 *
 * Po kliknięciu na listę silników następuje zmiana rodzaju silnika na nowo wybrany i aktualizacja wszystkich cech pojazdu.
 */
void GlowneOkno::on_lista_Silnik_itemClicked()
{
    pojazd->set_Silnik(ui->lista_Silnik->currentRow() );
    wpisz();
}

/**
 * @brief Zmienia rodzaj pancerza.
 *
 * Po kliknięciu na listę pancerzy następuje zmiana rodzaju pancerza na nowo wybrany i aktualizacja wszystkich cech pojazdu.
 * @param n Numer odpowiadający rodzajowi pancerza
 */
void GlowneOkno::ListaPanc_Changed(const int &n) // EKSP: unsign //PANC::check
{
    unsigned int index = ui->tab_Pancerz->currentIndex();
    pojazd->set_typPancerza(index, n);
    wpisz();
}

/*PRIVATE*/

/**
 * @brief Zmienia typ liczbę w Qstr.
 * Zmienia typ int w Qstr. Aby wypisać wartość w GUI, zmienna musi mieć typ Qstr.
 * @param x Zmienna, której typ należy zmienić.
 * @return Zwraca zmienną typu Qstr.
 */

template<class TYPE>
QString GlowneOkno::doQstr(TYPE x)
{
    std::ostringstream strs;
    strs.str("");
    strs << round(x);
    std::string str = strs.str();
    QString qstr = QString::fromStdString(str);
    return qstr;
}



void GlowneOkno::on_actionZapisz_triggered()
{
    zapisz();
}

void GlowneOkno::zapisz()
{
    QString Qnazwa= QFileDialog::getSaveFileName(this,tr("wybierz plik") ,"save.txt", tr("Plik tekstowy (*.txt)"));
    ofstream plik;
    std::string nazwa = Qnazwa.toUtf8().constData();
    plik.open(nazwa.c_str());
    if(plik.is_open() == true)
    {
        plik << ui->ProjSlnk->value() << '\n';
        plik << ui->SkSlnk->value() << '\n';
        plik << ui->WykSlnk->value() << '\n';

        plik << ui->ProjNapd->value() << '\n';
        plik << ui->SkNapd->value() << '\n';
        plik << ui->WykNapd->value() << '\n';

        if(ui->lista_podwozie->currentRow() == 0){
            plik << 0 << '\n';
        }else if(ui->lista_podwozie->currentRow() == 1){
            plik << 1 << '\n';
        }else if(ui->lista_podwozie->currentRow() == 2){
            plik << 2 << '\n';
        }

        if(ui->lista_Silnik->currentRow() == 0){
            plik << 0 << '\n';
        }else if(ui->lista_Silnik->currentRow() == 1){
            plik << 1 << '\n';
        }else if(ui->lista_Silnik->currentRow() == 2){
            plik << 2 << '\n';
        }
    }
    plik.close();
}

void GlowneOkno::on_actionWczytaj_triggered()
{
   wczytaj();
}

void GlowneOkno::wczytaj()
{
    QString Qnazwa= QFileDialog::getOpenFileName(this,tr("wybierz plik") ,"", tr("Plik tekstowy (*.txt)"));
    ifstream plik;
    std::string nazwa = Qnazwa.toUtf8().constData();
    plik.open(nazwa.c_str());
    if(plik.is_open() == true)
    {
        int n;
        plik >> n;
        ui->ProjSlnk->setValue(n);
        pojazd->set_ProjSlnk(n);
        plik >> n;
        ui->SkSlnk->setValue(n);
        pojazd->set_SkSlnk(n);
        plik >> n;
        ui->WykSlnk->setValue(n);
        pojazd->set_WykSlnk(n);
        plik >> n;
        ui->ProjNapd->setValue(n);
        pojazd->set_ProjNapd(n);
        plik >> n;
        ui->SkNapd->setValue(n);
        pojazd->set_SkNapd(n);
        plik >> n;
        ui->WykNapd->setValue(n);
        pojazd->set_WykNapd(n);

        plik >> n;
        if(n == 0)
        {
            ui->lista_podwozie->setCurrentRow(0);
            pojazd->set_Naped(0);
        }else if(n == 1)
        {
            ui->lista_podwozie->setCurrentRow(1);
            pojazd->set_Naped(1);
        }else if(n == 2)
        {
            ui->lista_podwozie->setCurrentRow(2);
            pojazd->set_Naped(2);
        }

        plik >> n;
        if(n == 0)
        {
            ui->lista_Silnik->setCurrentRow(0);
            pojazd->set_Naped(0);
        }
        else if(n == 1)
        {
            ui->lista_Silnik->setCurrentRow(1);
            pojazd->set_Naped(1);
        }
        else if(n == 2)
        {
            ui->lista_Silnik->setCurrentRow(2);
            pojazd->set_Naped(2);
        }
    }

    plik.close();
    wpisz();
}

void GlowneOkno::on_dodaj_warstwe_clicked()
{
    cl_TabPancerz *tab = new cl_TabPancerz;
    int n = ui->tab_Pancerz->count() + 1;
    QString x = doQstr(n);
    QString label = "warstwa " + x;

    ui->tab_Pancerz->addTab(tab, label);
    ui->tab_Pancerz->setCurrentIndex(ui->tab_Pancerz->count()-1);

    pojazd->add_vPancerze(); //PANC::check

    connect(tab,SIGNAL(ProjPanc(int)), this, SLOT(ProjPanc_valChanged(int)));
    connect(tab,SIGNAL(SkPanc(int)), this, SLOT(SkPanc_valChanged(int)));
    connect(tab,SIGNAL(WykPanc(int)), this, SLOT(WykPanc_valChanged(int)));
    connect(tab,SIGNAL(ListaPanc(int)), this, SLOT(ListaPanc_Changed(int)));

    wpisz();
}

void GlowneOkno::on_usun_warstwe_clicked()
{
//    pojazd->set_ProjPanc(ui->tab_Pancerz->currentIndex());
//    pojazd->set_WykPanc(ui->tab_Pancerz->currentIndex());
//    pojazd->set_SkPanc(ui->tab_Pancerz->currentIndex());
    if(ui->tab_Pancerz->count()!=0)
    {
        pojazd->del_vPancerze(ui->tab_Pancerz->currentIndex());

        QWidget *tab = ui->tab_Pancerz->currentWidget();

        ui->tab_Pancerz->removeTab(ui->tab_Pancerz->currentIndex());
        delete tab;

        int n = ui->tab_Pancerz->count();
        QString x;
        QString label;
        for(int i=0; i<n; i++)
        {
            x = doQstr(i+1);
            label = "warstwa " + x;
            ui->tab_Pancerz->setTabText(i,label);
        }
        wpisz();
    }
}
