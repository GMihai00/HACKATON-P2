#ifndef PMIC_H_INCLUDED
#define PMIC_H_INCLUDED

#include <bits/stdc++.h>
#include "Porc.h"

using namespace std;

class Pmic: public Porc
{

public:

    Pmic(int = 0, int = 0, string  = "",  CMedical* = NULL,  string = "");
    Pmic(const Pmic&);
    Pmic(const Porc&);
    ~Pmic();

    friend ostream & operator << (ostream &, const Pmic &);
    friend istream & operator >> (istream &, Pmic &);

    void Citire(istream& );
    void Afisare(ostream& );
    friend bool verificare_data2(string);


};
#endif // PMIC_H_INCLUDED
