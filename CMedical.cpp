#include "CMedical.h"

bool verificare_data9(string s)
{
    int v[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(s.size() < 7)
        return false;

    int zi = 0;
    if(!(s[0] >= '0' && s[0] <= '9'))
        return false;

    zi = s[0] - '0';
    if(!(s[1] >= '0' && s[1] <= '9'))
        return false;

    zi = zi * 10 + s[1] - '0';


    if(s[2] != '/')
        return false;

    int luna = 0;
     if(!(s[3] >= '0' && s[3] <= '9'))
        return false;

    luna = s[3] - '0';
    if(!(s[4] >= '0' && s[4] <= '9'))
        return false;

    luna = luna * 10 + s[4] - '0';

    if(s[5] != '/')
        return false;

    int an = 0;

    for(int i = 6; i < s.size(); i++)
    {
        if(!(s[i] >= '0' && s[i] <= '9'))
            return false;

        an = an * 10 + s[i] - '0';
    }

    if(an % 4 == 0)
        v[1]++;

    if(luna > 12)
        return false;
    if(v[luna - 1] < zi)
        return false;

    return true;


}
CMedical::CMedical(string IDM2, string IDT2, string data_nasteri2, set <string> boli_precedente2, set <string> boli_curente2, set <string> tratamente_efectuate2, set <string> tratamente_curente2, int sex2, int fertilitate2)
{
    this->IDM = IDM2;
    this->IDT = IDT2;
    this->data_nasteri = data_nasteri2;
    this->boli_precedente = boli_precedente2;
    this->boli_curente = boli_curente2;
    this->tratamente_efectuate = tratamente_efectuate2;
    this->tratamente_curente = tratamente_curente2;
    this->sex = sex2;
    this->fertilitate = fertilitate2;

}

CMedical::CMedical(const CMedical& x)
{
    cout <<"!"; // aici in jos prob
    this->IDM = x.IDM;
    this->IDT = x.IDT;
    this->data_nasteri = x.data_nasteri;
    this->boli_precedente = x.boli_precedente;
    this->boli_curente = x.boli_curente;
    this->tratamente_efectuate = x.tratamente_efectuate;
    this->tratamente_curente = x.tratamente_curente;
    this->sex = x.sex;
    this->fertilitate = x.fertilitate;

}

CMedical::~CMedical()
{

}

istream& operator >> (istream &ist, CMedical &x)
{
    string s;
    cout << "IDMama(in caz ca nu il stiti introduceti -):";
    ist.ignore();
    getline(ist, x.IDM);
    cout << "IDTata:(in caz ca nu il stiti introduceti -):";
    ist.ignore();
    getline(ist, x.IDT);
    cout <<"Data nasteri(zz/ll/aaaa):";
    bool ok;
    do
    {
        fflush(stdin);
        getline(ist, x.data_nasteri);
        ok = verificare_data9(x.data_nasteri);
        if(ok == false)
            cout <<"Data calendaristica nu exista!Va rugam introduceti o data valida\n\n";
    }while(ok == false);

    cout <<"Nr boli precedenet:";
    int nrboli;
    ist >> nrboli;
    while(x.boli_precedente.size() != nrboli)
    {
        cout <<"Boala:";
        ist.ignore();
        getline(ist, s);
        x.boli_precedente.insert(s);
    }

    cout <<"Nr boli curente:";
    ist >> nrboli;
    while(x.boli_curente.size() != nrboli)
    {
        cout <<"Boala:";
        ist.ignore();
        getline(ist, s);
        x.boli_curente.insert(s);
    }

    cout <<"Nr tratamente urmate:";
    ist >> nrboli;
    while(x.tratamente_efectuate.size() != nrboli)
    {
        cout <<"Tratamentul:";
        ist.ignore();
        getline(ist, s);
        x.tratamente_efectuate.insert(s);
    }
    cout <<"Nr tratamente in desfasurare:";
    ist >> nrboli;
    while(x.tratamente_curente.size() != nrboli)
    {
        cout <<"Tratamentul:";
        ist.ignore();
        getline(ist, s);
        x.tratamente_curente.insert(s);
    }
    cout <<"Sexul(1-M, 0-F):";

    do
    {
        ist >> x.sex;
        if(x.sex > 1 || x.sex < 0)
            cout <<"Eroare!Va rog introduceti o valoarea de adevar valida\n";
    }while(x.sex > 1 || x.sex < 0);

    cout <<"Fertilitate(1-Fertil, 0-Infertil):";
    do
    {
        ist >> x.fertilitate;
        if(x.fertilitate > 1 || x.fertilitate < 0)
            cout <<"Eroare!Va rog introduceti o valoarea de adevar valida\n";
    }while(x.fertilitate > 1 || x.fertilitate < 0);


    return ist;
}

ostream& operator << (ostream &ost, const CMedical &x)
{
    ost <<"Fisa medicala porc"<<'\n';
    ost << "Data nasteri:" << x.data_nasteri <<'\n';
    ost << "Sex: " << ((x.sex == 0) ? "Feminin" : "Masculin") <<'\n';
    ost << "Fertilitate: " << ((x.fertilitate == 0) ? "Infertil" : "Fertil") <<'\n';
    ost << "Boli anterioare: ";
    if(x.boli_precedente.size() == 0)
        ost <<'-';
    for(auto it: x.boli_precedente)
        ost << it <<";\n";
    ost <<'\n' << "Tratamente anterioare: ";
    if(x.tratamente_efectuate.size() == 0)
        ost <<'-';
    for(auto it: x.tratamente_efectuate)
        ost << it <<";\n";
    ost <<'\n' << "Boli curente: ";
    if(x.boli_curente.size() == 0)
        ost <<'-';
    for(auto it: x.boli_curente)
        ost << it <<";\n";
    ost <<'\n' << "Tratamente curente: ";
    if(x.tratamente_curente.size() == 0)
        ost <<'-';
    for(auto it : x.tratamente_curente)
        ost << it <<";\n";


    return ost;
}

void CMedical::remove_boala(string boala)
{
    if(this->boli_curente.find(boala) != this->boli_curente.end())
    {
        this->boli_curente.erase(boala);
        this->boli_precedente.insert(boala);
    }
    else
        throw "Eroare!Porcul respectiv nu are boala respectiva.";
}

void CMedical::add_boala(string boala)
{
    if(this->boli_curente.find(boala) == this->boli_curente.end())
        this->boli_curente.insert(boala);
    else
        throw "Eroare!Porcul are deja boala respectiva.";
}

void CMedical::remove_tratament(string tratament)
{
    if(this->tratamente_curente.find(tratament) != this->tratamente_curente.end())
    {
        this->tratamente_curente.erase(tratament);
        this->tratamente_efectuate.insert(tratament);
    }
    else
        throw "Eroare!Porcul respectiv nu a urmat tratamentul respectiv.";
}


void CMedical::add_tratament(string tratament)
{
    if(this->tratamente_curente.find(tratament) == this->tratamente_curente.end())
        this->tratamente_curente.insert(tratament);
    else
        throw "Eroare!Porcul urmeaza deja tratamentul respectiv.";
}

void CMedical::update_fertilitate(bool fert)
{
    this->fertilitate = fert;
}

bool CMedical::sanatosi()
{
    return (this->boli_curente.size() == 0);
}

bool CMedical::fertil()
{
    return this->fertilitate;
}


