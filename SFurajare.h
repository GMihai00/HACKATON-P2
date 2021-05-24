#ifndef SISTEMFURAJARE_H_INCLUDED
#define SISTEMFURAJARE_H_INCLUDED


#include <bits/stdc++.h>

using namespace std;

class SFurajare
{
protected:
    string firma;
    int capacitate_stocare;
    int capacitate_curenta;
    string vechime; // zi/luna/an data cand a inceput sa functioneze;
    string garantie; // zi/luna/an - zi/luna/an

public:

    SFurajare(string = "", int = 0, int = 0, string = "", string = "");
    SFurajare(const SFurajare&);
    ~SFurajare();

    friend ostream & operator << (ostream &, const SFurajare &);
    friend istream & operator >> (istream &, SFurajare &);

    bool is_in_garantie(string );
    friend bool verificare_data(string);
};
#endif // SISTEMFURAJARE_H_INCLUDED
