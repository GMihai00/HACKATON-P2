#include "Porc.h"

int Porc::nr_porci = 0;

int lgput(int x,int p)
{
    int rez = 1;
    while(p > 0)
    {
        if(p & 1)
        {
            rez = (1ll * rez * x) % mod;
        }
        x = (1ll * x * x) % mod;
        p >>=1;
    }
    return rez;
}

int get_nr_divp(int x)
{
    int nrdiv = 1;
    if(x == 0)
        return 0;

    if(x % 2 == 0)
    {
        nrdiv++;
        while(x % 2 == 0)
            x /= 2;
    }

    for(int i = 3; i * i <= x; i+=2)
    {
        if(x % i == 0)
        {
            nrdiv++;
            while(x % i == 0)
                x /= i;
        }
    }

    if(x != 1)
        nrdiv++;

    return nrdiv;
}

void Porc::generate_ID()
{
    int x = nr_porci;
    int f = get_nr_divp(x);
    x = lgput(x, mod - 2);
    f = lgput(f, mod - 2);



    while(f)
    {
        int c = f % 61;
        this->ID.push_back(c + 33);
        f /= 61;
    }

    while(x)
    {
        int c = x % 61;
        this->ID.push_back(c + 33);
        x /= 61;
    }

    while(ID_set.find(this->ID) != ID_set.end())
    {
        this->ID.insert(0,1,'~');
    }

    ID_set.insert(this->ID);

}


Porc::Porc(int varsta2, int greutate2,  string rasa2, CMedical* cm2,string lte2)
{
    nr_porci++;
    generate_ID();

    this->varsta = varsta2;
    this->greutate = greutate2;
    this->rasa = rasa2;
    this->cm = new CMedical;
    if(cm2 != NULL)
        *(this->cm) = *cm2;
    this->lte = lte2;

}

Porc::Porc(const Porc& x)
{
    nr_porci++;
    generate_ID();
    this->varsta = x.varsta;
    this->greutate = x.greutate;
    this->tip_alimentatie = x.tip_alimentatie;
    this->rasa = x.rasa;
    this->cm = new CMedical;
    if(x.cm != NULL)
        *(this->cm) = *x.cm;
    this->nevoie_calorica = x.nevoie_calorica;
    this->nevoie_apa = x.nevoie_apa;
    this->lte = x.lte;

}

Porc::~Porc()
{
    nr_porci--;

    delete this->cm;
}

string Porc::get_rasa()
{
    return this->rasa;
}

bool Porc::operator!=(const Porc& x)
{
    return this->ID!=x.ID;
}



void Porc::det_nevoie_calorica()
{
    this->nevoie_calorica = (3000 * this->greutate / 100) + 1500 * varsta / 20;
}

void Porc::det_nevoie_apa()
{
    this->nevoie_apa = 50 * greutate / 1000 ;
}

void Porc::update_lte(string s)
{
    this->lte = s;
}

int Porc::get_greutate()
{
    return this->greutate;
}

bool Porc::sanatosp()
{
    return this->cm->sanatosi();
}

bool Porc::fertilp()
{
    return this->cm->fertil();
}

bool verificare_data1(string s)
{
    int v[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(s.size() < 7)
        return false;

    int zi = 0;
    if(!(s[0] >= '0' && s[0] <= '9'))
        return false;

    zi = s[0] - '0';
    if(!(s[1] >= '0' && s[1] <= '9'))
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
