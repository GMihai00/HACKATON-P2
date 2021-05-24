#include "Hambar.h"

Hambar::Hambar(int nr_intrari2, pair <double, double> dim_usi2, int apa_curenta2, int electricitate2, int  ventilare_aer2, string adresa2, vector <Boxa*> v_boxe2)
{
    this->nr_intrari = nr_intrari2;
    this->dim_usi = dim_usi2;
    this->apa_curenta = apa_curenta2;
    this->electricitate = electricitate2;
    this->ventilare_aer = ventilare_aer2;
    this->adresa = adresa2;
    for(int i = 0; i < v_boxe2.size(); i++)
    {
        Boxa* p = new Boxa(*v_boxe2[i]);
        this->v_boxe.push_back(p);
    }

}

Hambar::Hambar(const Hambar& x)
{
    this->nr_intrari = x.nr_intrari;
    this->dim_usi = x.dim_usi;
    this->apa_curenta = x.apa_curenta;
    this->electricitate = x.electricitate;
    this->ventilare_aer = x.ventilare_aer;
    this->adresa = x.adresa;
    for(int i = 0; i < x.v_boxe.size(); i++)
    {
        Boxa* p = new Boxa(*x.v_boxe[i]);
        this->v_boxe.push_back(p);
    }

}

Hambar::~Hambar()
{
    for(int i = 0; i < this->v_boxe.size(); i++)
        delete this->v_boxe[i];

}

istream & operator >> (istream &ist, Hambar &x)
{
    cout <<"Nr.  intrari: ";
    ist >> x.nr_intrari;
    cout <<"Dimensiune usi (l h): ";
    ist >> x.dim_usi.first >> x.dim_usi.second ;
    cout <<"Apa curenta(1-da, 0-nu): ";


    do
    {
        ist >> x.apa_curenta;
        if(x.apa_curenta > 1 || x.apa_curenta < 0)
            cout <<"Eroare!Va rog reintroduceti valoarea de adevar(1/0)\n";
    }while(x.apa_curenta > 1 || x.apa_curenta < 0);

    cout <<"Electricitate(1-da, 0-nu): ";
    do
    {
        ist >> x.electricitate;
        if(x.electricitate > 1 || x.electricitate < 0)
            cout <<"Eroare!Va rog reintroduceti valoarea de adevar(1/0)\n";
    }while(x.electricitate > 1 || x.electricitate < 0);

    cout <<"Ventilare aer(1-da, 0-nu): ";
    do
    {
        ist >> x.ventilare_aer;
        if(x.ventilare_aer > 1 || x.ventilare_aer < 0)
            cout <<"Eroare!Va rog reintroduceti valoarea de adevar(1/0)\n";
    }while(x.ventilare_aer > 1 || x.ventilare_aer < 0);
    cout <<"Adresa: ";
    ist.ignore();
    getline(ist, x.adresa);
    cout <<"Nr boxe: ";
    int nrboxe;
    ist >> nrboxe;
    for(int i = 0; i < nrboxe; i++)
    {
        cout <<"Boxa:\n";
        Boxa* p = new Boxa;
        ist >> *p;
        x.v_boxe.push_back(p);
    }
    return ist;
}

ostream & operator << (ostream &ost, const Hambar &x)
{
    ost << "Hala aflata la adresa: " << x.adresa << ", alcatuita din " << x.v_boxe.size() <<" boxe are urmatoarele facilitati:\n";
    int cnt = 0;
    if(x.apa_curenta)
    {
        cnt++;
        ost <<"Apa curenta; ";
    }
    if(x.electricitate)
    {
        cnt++;
        ost <<"Electricitate; ";
    }

    if(x.ventilare_aer)
    {
        cnt++;
        ost <<"Sisteme de ventilare; ";
    }

    if(cnt == 0)
        ost <<'-';

    ost <<'\n';

    for(int i = 0; i < x.v_boxe.size(); i++)
        ost << *x.v_boxe[i] <<'\n';
    return ost;
}

ostream& Hambar::det_statistica(ostream& ost)
{
    int cap_ocupat = 0;
    int cap_max = 0;
    int greutatet = 0;
    int nr_pmic = 0;
    int nr_pmatur = 0;
    int nr_scroafa = 0;
    int nr_fertil = 0;
    int nr_sanatos = 0;
    multiset <string> mrase;
    set <string> rase;
    for(int i = 0; i < this->v_boxe.size(); i++)
    {
        cap_ocupat += this->v_boxe[i]->get_ocupat();
        cap_max += this->v_boxe[i]->get_capacitate();
        greutatet += this->v_boxe[i]->get_greutate_totala();
        nr_pmic += this->v_boxe[i]->get_nr_pmic();
        nr_pmatur += this->v_boxe[i]->get_nr_pmatur();
        nr_scroafa += this->v_boxe[i]->get_nr_scroafa();
        nr_sanatos += this->v_boxe[i]->get_nr_sanatos();
        nr_fertil += this->v_boxe[i]->get_nr_fertil();
        vector <string> v;
        v = this->v_boxe[i]->det_rase();
        for(int j = 0; j < v.size(); j++)
        {
            mrase.insert(v[j]);
            rase.insert(v[j]);
        }

    }



    ost <<"Capacitate ocupata: " <<cap_ocupat << "/" <<cap_max <<'\n';
    ost <<"Dintre acestia " << nr_pmic <<" sunt pui, "<< nr_pmatur <<" sunt adulti si " << nr_scroafa <<" sunt scroafe\n";
    ost <<"Acestia sunt feritli in numar de " << nr_fertil <<" si sanatosi in numar de "<< nr_sanatos <<'\n';
    ost <<"Porci apartin a "<< rase.size() <<" rase distincte, dintre care:\n";
    for(auto it: rase)
        ost << mrase.count(it) <<" porci apartinand rasei "<< it <<'\n';
    ost <<"Acestia insumeaza ca si greutate un total de "<< greutatet <<" kg"<<'\n';

    return ost;
}
int det_nr_cifre(int x)
{
    int cnt = 0;
    if(x == 0)
        cnt++;
    while(x)
    {
        x /= 10;
        cnt++;
    }

    return cnt;
}


ostream& Hambar::desenare(ostream& ost)
{
    int spatiere = 50;
    for(int i = 0; i < this->v_boxe.size(); i+=2)
    {

        int nrvents1 = this->v_boxe[i]->get_nr_vents();
        int nrfurajere1 = this->v_boxe[i]->get_nr_furajere();
        int cap_ocupat1 = this->v_boxe[i]->get_ocupat();
        int cap_max1 = this->v_boxe[i]->get_capacitate();


        if(i + 1 < this->v_boxe.size())
        {
            int nrvents2 = this->v_boxe[i + 1]->get_nr_vents();
            int nrfurajere2 = this->v_boxe[i + 1]->get_nr_furajere();
            int cap_ocupat2 = this->v_boxe[i + 1]->get_ocupat();
            int cap_max2 = this->v_boxe[i + 1]->get_capacitate();


            int nrcar = det_nr_cifre(cap_max1) + 1 + det_nr_cifre(cap_ocupat1);
            ost << cap_ocupat1 <<'/' << cap_max1;
            for(int j = 0; j < spatiere - nrcar; j++)
                ost <<' ';
            ost << "| ";
            ost << cap_ocupat2 <<'/'<< cap_max2;
            ost <<'\n';
            nrcar = 9 + det_nr_cifre(nrfurajere1);
            ost << "Furajare:" << nrfurajere1;
            for(int j = 0; j < spatiere - nrcar; j++)
                ost <<' ';
            ost <<"| ";
            ost << "Furajare:" << nrfurajere2;
            ost <<'\n';
            nrcar = 13 + det_nr_cifre(nrvents1);
            ost <<"Ventilatoare:" << nrvents1;
            for(int j = 0; j < spatiere - nrcar; j++)
                ost <<' ';
            ost <<"| ";
            ost <<"Ventilatoare:" << nrvents2;
            ost <<'\n';
            for(int j = 0; j < spatiere* 2 + 2; j++)
                ost <<'_';
            ost <<'\n';
        }
        else
        {
            int nrcar = det_nr_cifre(cap_max1) + 1 + det_nr_cifre(cap_ocupat1);
            ost << cap_ocupat1 <<'/' << cap_max1;
            for(int j = 0; j < spatiere - nrcar; j++)
                ost <<' ';
            ost << "| ";
            ost <<'\n';
            nrcar = 9 + det_nr_cifre(nrfurajere1);
            ost << "Furajare:" << nrfurajere1;
            for(int j = 0; j < spatiere - nrcar; j++)
                ost <<' ';
            ost <<"| ";
            ost <<'\n';
            nrcar = 13 + det_nr_cifre(nrvents1);
            ost <<"Ventilatoare:" << nrvents1;
            for(int j = 0; j < spatiere - nrcar; j++)
                ost <<' ';
            ost <<"| ";
            ost <<'\n';
            for(int j = 0; j < spatiere + 1; j++)
                ost <<'_';
            ost <<'\n';
        }
    }
}
