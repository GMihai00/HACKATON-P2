#ifndef HAMBAR_H_INCLUDED
#define HAMBAR_H_INCLUDED

#include <bits/stdc++.h>
#include "Boxa.h"

using namespace std;


class Hambar
{
protected:
    int nr_intrari;
    pair <double, double> dim_usi;
    int apa_curenta;
    int electricitate;
    int ventilare_aer;
    string adresa;
    vector <Boxa*> v_boxe;

public:

    Hambar(int = 0, pair <double, double> = {0.,0.}, int = 0, int = 0, int = 0, string = "", vector <Boxa*> = {});
    Hambar(const Hambar& );
    virtual ~Hambar();

    friend ostream & operator << (ostream &, const Hambar &); // metoda afisare statistica
    friend istream & operator >> (istream &, Hambar &);

    ostream& det_statistica(ostream& );

    ostream& desenare(ostream& );

    friend int det_nr_cifre(int x);
    friend void fil(int = 0, char = ' ');
};


#endif // HAMBAR_H_INCLUDED
