#ifndef CMEDICAL_H_INCLUDED
#define CMEDICAL_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class CMedical
{
protected:
    string IDM;
    string IDT;
    string data_nasteri; //zi//luna//an
    set <string> boli_precedente;
    set <string> boli_curente;
    set <string> tratamente_efectuate;
    set <string> tratamente_curente;
    int sex; // 0 - F 1 - M
    int fertilitate; // 0-infertil 1 -fertil

public:

    CMedical(string = "", string = "", string = "", set <string> = {}, set <string> = {}, set <string> = {}, set <string> = {}, int = 0, int = 0);
    CMedical(const CMedical&);
    ~CMedical();

    void remove_boala(string);
    void add_boala(string);
    void remove_tratament(string);
    void add_tratament(string);
    void update_fertilitate(bool);

    friend ostream & operator << (ostream &, const CMedical &);
    friend istream & operator >> (istream &, CMedical &);

    bool sanatosi();
    bool fertil();
     friend bool verificare_data9(string);
};

#endif // CMEDICAL_H_INCLUDED
