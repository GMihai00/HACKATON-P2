#ifndef SCROAFA_H_INCLUDED
#define SCROAFA_H_INCLUDED

#include <bits/stdc++.h>
#include "Porc.h"

using namespace std;

class Scroafa: public Porc
{
protected:
    set <string> pui;

public:
    Scroafa(int = 0, int = 0, string = "",  CMedical* = NULL, string = "", set <string> = {});
    Scroafa(const Scroafa&);
    Scroafa(const Porc&);
    ~Scroafa();

    void add_pui(string);

    friend ostream & operator << (ostream &, const Scroafa&);
    friend istream & operator >> (istream &, Scroafa&);

    void Citire(istream& );
    void Afisare(ostream& );
    friend bool verificare_data4(string);

};

#endif // SCROAFA_H_INCLUDED
