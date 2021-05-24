#include "SFurajare.h"

SFurajare::SFurajare(string firma2, int capacitate_stocare2, int capacitate_curenta2, string vechime2, string garantie2)
{
    this->firma = firma2;
    this->capacitate_stocare = capacitate_stocare2;
    this->capacitate_curenta = capacitate_curenta2;
    this->vechime = vechime2;
    this->garantie = garantie2;
}

SFurajare::SFurajare(const SFurajare& x)
{
    this->firma = x.firma;
    this->capacitate_stocare = x.capacitate_stocare;
    this->capacitate_curenta = x.capacitate_curenta;
    this->vechime = x.vechime;
    this->garantie = x.garantie;
}

SFurajare::~SFurajare()
{

}

bool verificare_data(string s)
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

istream & operator >> (istream &ist, SFurajare &x)
{
    cout <<"Firma: ";
    ist.ignore();
    getline(ist, x.firma);
    cout <<"Capacitate maxima: ";
    ist >> x.capacitate_stocare;
    cout <<"Locuri ocupate: ";
    do
    {
        ist >> x.capacitate_curenta;
        if(x.capacitate_curenta > x.capacitate_stocare)
            cout <<"Eroare!Capacitate depasita.Va rugam introduceti o valoare valida\n";

    }while(x.capacitate_curenta > x.capacitate_stocare);

    cout <<"Data inceperi activitati(zz/ll/aaaa):";
    bool ok;
    do
    {
        ok = true;
        fflush(stdin);
        getline(ist, x.vechime);
        ok = verificare_data(x.vechime);
        if(ok == false)
            cout <<"Data calendaristica nu exista!Va rugam introduceti o data valida\n";

    }while(ok == false);
    cout <<"Garantie pana la data de (zz/ll/aaaa):";
      do
    {
        bool ok = true;
        fflush(stdin);
        getline(ist, x.garantie);
        ok = verificare_data(x.garantie);
        if(ok == false)
            cout <<"Data calendaristica nu exista!Va rugam introduceti o data valida\n";

    }while(ok == false);

    return ist;
}

ostream & operator << (ostream &ost, const SFurajare &x)
{
    ost << "Sistemul furajer produs de firma " << x.firma << " ce si-a inceput activitatea la data de "<< x.vechime << " cu garantia pana la data de " << x.garantie;
    ost << " are in momentul de fata ocupat din capacitatea toatala " << x.capacitate_curenta <<'//' << x.capacitate_stocare;
    return ost;
}

bool SFurajare::is_in_garantie(string time_curent)
{

    int zi = (time_curent[0] - '0') * 10 + (time_curent[1] - '0') ;
    int luna = (time_curent[3] - '0') * 10 + (time_curent[4] - '0');
    int an = 0;
    for(int i = 6; i < time_curent.size(); i++)
        an = an * 10 + (time_curent[i] - '0');

    int ziex = (this->garantie[0] - '0') * 10 + (this->garantie[1] - '0') ;
    int lunaex = (this->garantie[3] - '0') * 10 + (this->garantie[4] - '0');
    int anex = 0;
    for(int i = 6; i < this->garantie.size(); i++)
        anex = anex * 10 + (this->garantie[i] - '0');


    if(an != anex)
        return an < anex;
    else
        if(luna != lunaex)
            return luna < lunaex;
        else
            return zi <= ziex;

    // verificam motamo daca e in garantie sau ba
}
