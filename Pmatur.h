#ifndef PMATUR_H_INCLUDED
#define PMATUR_H_INCLUDED

#include <bits/stdc++.h>
#include "Porc.h"

using namespace std;

class Pmatur: public Porc
{
public:
    Pmatur(int = 0, int = 0, string  = "", CMedical* = NULL,  string = "");
    Pmatur(const Pmatur&);
    Pmatur(const Porc&);
    ~Pmatur();

    friend ostream & operator << (ostream &, const Pmatur &);
    friend istream & operator >> (istream &, Pmatur &);

    void Citire(istream& );
    void Afisare(ostream& );
    friend bool verificare_data3(string);
};


#endif // PMATUR_H_INCLUDED
