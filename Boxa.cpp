#include "Boxa.h"

int Boxa::nr_total_boxe = 0;

Boxa::Boxa( pair <double, double> dim2, int  capacitate_purcei2, vector <Porc*>  v_porci2, vector <SFurajare*>  v_furaje2, int nr_ventilatoare2)
{
    if(capacitate_purcei2 > (int) v_porci2.size())
        throw "Eroare!Capacitatea boxei a fost depasita.";

    nr_total_boxe++;
    this->nr_boxa = nr_total_boxe;
    this->dim = dim2;
    this->capacitate_purcei = capacitate_purcei2;
    for(int i = 0; i < (int) v_porci2.size(); i++)
    {
        Porc* p;
        if(dynamic_cast <Pmic*> (v_porci2[i]))
           p = new Pmic(*v_porci2[i]);
        else
        if(dynamic_cast <Pmatur*> (v_porci2[i]))
            p = new Pmatur(*v_porci2[i]);
        else
        if(dynamic_cast <Scroafa*> (v_porci2[i]))
            p = new Scroafa(*v_porci2[i]);
        this->v_porci.push_back(p);
    }
    for(int i = 0; i < (int) v_furaje2.size(); i++)
    {
        SFurajare* p = new SFurajare(*v_furaje2[i]);
        this->v_furaje.push_back(p);
    }
    this->nr_ventilatoare = nr_ventilatoare2;
}

Boxa::Boxa(const Boxa& x)
{
    nr_total_boxe++;
    this->nr_boxa = nr_total_boxe;
    this->dim = x.dim;
    this->capacitate_purcei = x.capacitate_purcei;
    for(int i = 0; i < (int) x.v_porci.size(); i++)
    {
        Porc* p;
       if(dynamic_cast<Pmic*>(x.v_porci[i]))
            p = new Pmic(*x.v_porci[i]);
        else
        if(dynamic_cast<Pmatur*>(x.v_porci[i]))
           p = new Pmatur(*x.v_porci[i]);
        else
        if(dynamic_cast<Scroafa*>(x.v_porci[i]))
            p = new Scroafa(*x.v_porci[i]);
        this->v_porci.push_back(p);
    }
    for(int i = 0; i < (int) x.v_furaje.size(); i++)
    {
        SFurajare* p = new SFurajare(*x.v_furaje[i]);
        this->v_furaje.push_back(p);
    }
    this->nr_ventilatoare = x.nr_ventilatoare;
}

Boxa::~Boxa()
{
    nr_total_boxe--;
    for(int i = 0; i < (int) this->v_porci.size(); i++)
        delete this->v_porci[i];

    for(int i = 0; i < (int) this->v_furaje.size(); i++)
        delete this->v_furaje[i];


}


void Boxa::add_pig(Porc** x)
{
    Porc* p;
    if(dynamic_cast<Pmic*>(*x))
        p = new Pmic(**x);
    else
    if(dynamic_cast<Pmatur*>(*x))
        p = new Pmatur(**x);
    else
    if(dynamic_cast<Scroafa*>(*x))
        p = new Scroafa(**x);
    this->v_porci.push_back(p);
}

void Boxa::add_sfurajer(SFurajare** x)
{
    SFurajare* p;
    p = new SFurajare(**x);
    this->v_furaje.push_back(p);

}

istream & operator >> (istream &ist, Boxa &x)
{
    cout <<"Dimensiune boxa(l h):";
    ist >> x.dim.first >> x.dim.second;
    cout <<"Nr ventilatoare:";
    ist >> x.nr_ventilatoare;
    cout <<"Capacitate maxima porci:";
    ist >> x.capacitate_purcei;

    int nrporci;
    do
    {
        cout <<"Nr locuri ocupate:";
        ist >> nrporci;
        if(nrporci > x.capacitate_purcei)
        {
            cout <<"Boxa nu are capacitatea necesara pt a gazdui asa de multi porci, va rugam reintroduceti numarul de porci:\n";
        }
    }
    while(nrporci > x.capacitate_purcei);

    for(int i = 0; i < nrporci; i++)
    {
        cout <<"Porc:\n";
        cout <<"Tip porc(Pui, Adult, Scroafa):";
        string s;
        do
        {
            ist.ignore();
            ist >> s;
            if(s != "Pui" && s != "Adult" && s != "Scroafa")
                cout <<"Ati introdus gresit datele de intrare, va rog alegeti din nou tipul de porc(Pui, Adult, Scroafa)\n";

        }while(s != "Pui" && s != "Adult" && s != "Scroafa");

        Porc *p;
        if(s == "Pui")
            p = new Pmic;
        else
        if(s == "Adult")
            p = new Pmatur;
        else
        if(s == "Scroafa")
            p = new Scroafa;

        p->Citire(ist);
        x.v_porci.push_back(p);
    }
    cout <<"Nr sisteme furajare:";
    int nrsfuraje;
    ist >> nrsfuraje;
    for(int i = 0; i < nrsfuraje; i++)
    {
        cout <<"Sistem furajare:\n";
        SFurajare* s = new SFurajare;
        ist >> *s;
        x.v_furaje.push_back(s);
    }
    return ist;
}

ostream & operator << (ostream &ost, const Boxa &x)
{
    ost << "Boxa cu numarul " << x.nr_boxa <<" cu capacitatea maxima de "<< x.capacitate_purcei <<" dintre care "<< x.v_porci.size() << " locuri sunt ocupate.";
    ost <<" \nAceasta are in momentul curent "<< x.nr_ventilatoare << " sisteme de ventilare incorporate si " << x.v_furaje.size() << " aparate de adapare:\n";
    ost <<"Lista aparate furajare:\n";
    for(int i = 0; i < (int) x.v_furaje.size(); i++)
        ost <<'-'<< *x.v_furaje[i] <<'\n';
    ost <<"Lista cu porci:\n";
    for(int i = 0; i < x.v_porci.size(); i++)
    {
        ost <<'-';
        x.v_porci[i]->Afisare(ost);
        ost <<'\n';
    }

    return ost;
}

int Boxa::get_capacitate()
{
    return this->capacitate_purcei;
}

int Boxa::get_ocupat()
{
    return this->v_porci.size();
}


int Boxa::get_greutate_totala()
{
    int sum = 0;
    for(int i = 0; i < this->v_porci.size(); i++)
        sum += this->v_porci[i]->get_greutate();

    return sum;
}

vector <string> Boxa::det_rase()
{
    vector <string> ms;
    for(int i = 0; i < this->v_porci.size(); i++)
        ms.push_back(this->v_porci[i]->get_rasa());

    return ms;
}

int Boxa::get_nr_pmic()
{
    int sum = 0;
     for(int i = 0; i < this->v_porci.size(); i++)
       if(dynamic_cast<Pmic*>(this->v_porci[i]))
        sum++;

    return sum;
}

int Boxa::get_nr_pmatur()
{
    int sum = 0;
     for(int i = 0; i < this->v_porci.size(); i++)
       if(dynamic_cast<Pmatur*>(this->v_porci[i]))
        sum++;

    return sum;
}


int Boxa::get_nr_scroafa()
{
    int sum = 0;
     for(int i = 0; i < this->v_porci.size(); i++)
       if(dynamic_cast<Scroafa*>(this->v_porci[i]))
        sum++;

    return sum;
}

int Boxa::get_nr_sanatos()
{
    int sum = 0;
    for(int i = 0; i < this->v_porci.size(); i++)
        sum += this->v_porci[i]->sanatosp();

    return sum;
}


int Boxa::get_nr_fertil()
{
    int sum = 0;
    for(int i = 0; i < this->v_porci.size(); i++)
        sum += this->v_porci[i]->fertilp();

    return sum;
}

int Boxa::get_nr_furajere()
{
    return this->v_furaje.size();
}

int Boxa::get_nr_vents()
{
    return this->nr_ventilatoare;
}
