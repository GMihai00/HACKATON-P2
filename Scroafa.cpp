#include "Scroafa.h"

bool verificare_data4(string s)
{
    int v[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(s.size() < 7)
        return false;

    int zi = 0;
    if(!(s[0] >= '0' && s[0] <= '9'))
        return false;

    zi = s[0] - '0';
    if(!(s[1] >='0' && s[1] <= '9'))
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
Scroafa::Scroafa(int varsta2, int greutate2, string rasa2, CMedical* cm2,  string lte2, set <string> pui2) : Porc(varsta2, greutate2,  rasa2, cm2,  lte2)
{
    this->tip_alimentatie = 2;
    this->pui = pui2;
}

Scroafa::Scroafa(const Scroafa& x) : Porc(x)
{
    this->pui = x.pui;
}

Scroafa::Scroafa(const Porc& x) : Porc(x)
{
    return;
}
Scroafa::~Scroafa()
{

}

istream & operator >> (istream &ist, Scroafa &x)
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
        ok = verificare_data4(x.lte);
        if(ok == false)
        cout <<"Data calendaristica nu exista!Va rugam introduceti o data valida\n";
    }while(ok == false);

    cout <<"Certificat medical:\n";
    ist >> *x.cm;
    return ist;
    cout <<"Nr pui:";
    int nrpui;
    ist >> nrpui;
    string s;
    while(x.pui.size() != nrpui)
    {
        cout <<"ID Pui:";
        ist.ignore();
        getline(ist, s);
        x.pui.insert(s);
    }

    return ist;
}

ostream & operator << (ostream &ost, const Scroafa &x)
{
    ost << "Scroafa cu varsta de " << x.varsta <<" ani ,greutatea de "<< x.greutate << " apartinand rasei " << x.rasa << "cu un nr de " << x.pui.size() <<" copii " <<'\n';
    ost << *x.cm;
    return ost;
}
void Scroafa::Citire(istream& ist)
{
    ist >> *this;
}
void Scroafa::Afisare(ostream& ost)
{
    ost << *this;
}

void Scroafa::add_pui(string idpui)
{
    if(this->pui.find(idpui) == this->pui.end())
        this->pui.insert(idpui);
    else
        throw "Eroare!Copil deja inregistrat in baza de date.";
}
