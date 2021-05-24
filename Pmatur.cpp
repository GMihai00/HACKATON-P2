#include "Pmatur.h"
bool verificare_data3(string s)
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

Pmatur::Pmatur(int varsta2, int greutate2, string rasa2, CMedical* cm2,  string lte2) : Porc(varsta2, greutate2,rasa2, cm2, lte2)
{
    this->tip_alimentatie = 1;
    return;
}

Pmatur::Pmatur(const Pmatur& x) : Porc(x)
{
    return;
}

Pmatur::Pmatur(const Porc& x) : Porc(x)
{
    return;
}

Pmatur::~Pmatur()
{

}

istream & operator >> (istream &ist, Pmatur &x)
{
    cout <<"Varsta(ani):";
    ist >> x.varsta;
    cout <<"Greutate(kg):";
    ist >> x.greutate;
    cout <<"Rasa:";
    ist.ignore();
    getline(ist, x.rasa);
    cout <<"Data ultimei hraniri(zz/ll/aaaa):";
    bool ok;
    do
    {
        fflush(stdin);
        getline(ist, x.lte);
        ok = verificare_data3(x.lte);
        if(ok == false)
        cout <<"Data calendaristica nu exista!Va rugam introduceti o data valida\n";
    }while(ok == false);

    cout <<"Certificat medical:\n";
    ist >> *x.cm;
    return ist;
}

ostream & operator << (ostream &ost, const Pmatur &x)
{
    ost << "Porc matur cu varsta de " << x.varsta <<" ani ,greutatea de "<< x.greutate << " apartinand rasei " << x.rasa <<'\n';
    ost << *x.cm;

    return ost;
}

void Pmatur::Citire(istream& ist)
{
    ist >> *this;

}
void Pmatur::Afisare(ostream& ost)
{
    ost << *this;

}

