#include <bits/stdc++.h>
#include "Hambar.h"
#include "Boxa.h"
#include "Porc.h"
#include "SFurajare.h"
#include "Pmic.h"
#include "Pmatur.h"
#include "Scroafa.h"
#include "CMedical.h";

using namespace std;

ofstream out("data.out");

void addhala(vector <Hambar*> &v)
{
    Hambar* a = new Hambar;
    cin >> *a;
    v.push_back(a);
}

void printdatehala(vector <Hambar*> v, int poz)
{
    cout << *v[poz] <<'\n';
}


void savedata(vector <Hambar*> v)
{
    for(int i = 0; i < v.size(); i++)
        out <<"Hala "<< i + 1 << ":\n" << *v[i] <<'\n';
}

void statistica(vector <Hambar*> v, int poz)
{
    v[poz]->det_statistica(cout);
    cout <<'\n';
}

void desenare(vector <Hambar*> v, int poz)
{
    v[poz]->desenare(cout);
    cout <<'\n';
}

int main()
{


    cout <<"Pentru adaugare unei noi hale apasati tasta 1\n";
    cout <<"Pentru afisarea datelor dintr-o hala anume apasati tasta 2\n";
    cout <<"Pentru reprezentarea unei hale apasati tasta 3\n";
    cout <<"Pentru afisarea unei statistici a unei hale anume apasati tasta 4\n";
    cout <<"Pentru a iesi apasati tasta 5\n";

    vector <Hambar*> v;
    //addhala, printdatehala, desenarehala, prinstatistica, exit
    int x;
    do
    {
        cout <<"Introduceti numarul operatiei:";
        cin >> x;

        switch(x)
        {
            case 1:
            {
                addhala(v);
                break;
            }
            case 2:
            {
                if(v.size() == 0)
                {
                    cout <<"Eroare!Nu exista nicio hala\n";
                    break;
                }
                else
                {

                    int poz;
                    do
                    {
                        cout <<"Introduceti numarul de ordine al halei:";
                        cin >> poz;
                        if(poz > v.size())
                            cout <<"Nu exista hala cu nr " << poz <<"\nVa rugam introduceti un numar de ordine valid\n";


                    }while(poz > v.size());


                    printdatehala(v, poz - 1);
                    break;
                }
            }
            case 3:
            {
                  int poz;
                do
                {
                    cout <<"Introduceti numarul de ordine al halei:";
                    cin >> poz;
                    if(poz > v.size())
                        cout <<"Nu exista hala cu nr " << poz <<"\nVa rugam introduceti un numar de ordine valid\n";


                }while(poz > v.size());

                desenare(v, poz - 1);
                break;
            }
            case 4:
            {
                int poz;
                do
                {
                    cout <<"Introduceti numarul de ordine al halei:";
                    cin >> poz;
                    if(poz > v.size())
                        cout <<"Nu exista hala cu nr " << poz <<"\nVa rugam introduceti un numar de ordine valid\n";


                }while(poz > v.size());

                statistica(v, poz - 1);
                break;
            }
            case 5:
            {
                cout <<"Doriti sa salvati o copie cu datele introduse?(1 - da, 0 - nu)\n";
                int f;

                do
                {

                    cin >> f;
                    if(f > 1 || f < 0)
                        cout <<"Eroare!Va rog introduceti o valoarea de adevar valida\n";
                }while(f > 1 || f < 0);

                if(f == 1)
                    savedata(v);


                break;
            }
            default:
            {
                cout <<"Ati introdus un numar de comanda inexistent!Va rugam introduceti unul valid\n";
            }
            fflush(stdin);
        }

    }while(x != 5);



    return 0;
}
