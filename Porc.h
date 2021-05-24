#ifndef PORC_H_INCLUDED
#define PORC_H_INCLUDED

#include <bits/stdc++.h>
#include "CMedical.h"

using namespace std;

const int mod = 3411949;


class Porc
{
protected:
    string ID;
    int varsta; // fa categori pt fiecare, uitate la cm pt scroafa / porc
    int greutate;
    int tip_alimentatie; // fa aici un map 0 pui, 1 porc , 2 scroafa
    string rasa; // fa un map si aici
    CMedical* cm; //pune aici si parinti
    int nevoie_calorica; //gaseste formula
    int nevoie_apa; // gaseste formula
    string lte; //format ora:minute zi/luna/an last time eat
    set <string> ID_set;

public:

    static int nr_porci;
    // functie de generare hashing ID  nr_factor_primi * invers_modular
    void generate_ID();
    Porc(int = 0, int = 0, string  = "",  CMedical* = NULL,  string = "");
    Porc(const Porc&);
    virtual ~Porc();
    string get_rasa();
    int get_greutate();
    void det_nevoie_calorica(); // gaseste formule pt astea 2
    void det_nevoie_apa();
    void update_lte(string );
    //clasa abstracta
    bool operator !=(const Porc&);
    virtual void Citire(istream& ) = 0;
    virtual void Afisare(ostream& ) = 0;
    bool sanatosp();
    bool fertilp();
    friend bool verificare_data1(string);
};

int lgput(int ,int );
int get_nr_divp(int );

#endif // PORC_H_INCLUDED
