#ifndef BOXA_H_INCLUDED
#define BOXA_H_INCLUDED

#include <bits/stdc++.h>
#include "Porc.h"
#include "SFurajare.h"
#include "Pmic.h"
#include "Pmatur.h"
#include "Scroafa.h"

using namespace std;

class Boxa
{
protected:
    int nr_boxa;
    pair <double,double> dim;
    int capacitate_purcei;
    vector <Porc*> v_porci;
    vector <SFurajare*> v_furaje;
    int nr_ventilatoare;


public:
    Boxa(pair <double, double> = {0, 0}, int = 0, vector <Porc*> = {}, vector <SFurajare*> = {}, int = 0);
    Boxa(const Boxa&);
    virtual ~Boxa();

    static int nr_total_boxe;

    friend ostream & operator << (ostream &, const Boxa &);
    friend istream & operator >> (istream &, Boxa &);

    void add_pig(Porc**); // iau adresa la pointer si o deferentiez

    //functie verificare nevoie sfurajere
    void add_sfurajer(SFurajare**);

    int get_capacitate();
    int get_ocupat();
    int get_greutate_totala();
    vector <string> det_rase();
    int get_nr_pmic();
    int get_nr_pmatur();
    int get_nr_scroafa();
    int get_nr_sanatos();
    int get_nr_fertil();
    int get_nr_furajere();
    int get_nr_vents();

    // cautari porci dupa varsta, rasa, ID, stare de sanatate, greutate
    // metoda afisare date
};

#endif // BOXA_H_INCLUDED
