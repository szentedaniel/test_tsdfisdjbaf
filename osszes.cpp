#include "osszes.h"

int Eszleles::Osszes::getDarabszam() const
{
    return darabszam;
}

Eszleles::Osszes::Osszes(int _szam) : darabszam(_szam)
{
    tomb = new Foldrenges [darabszam];
}

Eszleles::Osszes::Osszes() : darabszam(6)
{
    tomb = new Foldrenges [darabszam];
}

Eszleles::Osszes::~Osszes()
{
    delete [] tomb;
}

int Eszleles::Osszes::mennyi() const
{
    return darabszam;
}

int Eszleles::Osszes::mennyi(unsigned int h) const
{
    int darab = 0;
    for(int i = 0; i < darabszam; i++){
        if(tomb[i].getHonap() == h) darab++;
    }
    return darab;
}

void Eszleles::Osszes::beallit(int idx, string varos, unsigned int h, unsigned int n)
{
    if(idx >= darabszam){
        cout << "ERROR" << endl;
    }
    else tomb[idx].setVaros(varos), tomb[idx].setHonap(h), tomb[idx].setNap(n);
}

void Eszleles::Osszes::miVoltEddig() const
{
    for(int i = 0; i < darabszam; i++){
        if(&tomb[i] != nullptr){
            cout << tomb[i].getVaros() << ": " << tomb[i].getHonap() << "." << tomb[i].getNap() << endl;
        }
    }
}

bool Eszleles::Osszes::kevesebb(Eszleles::Osszes &a)
{
    if(a.getDarabszam() > darabszam) return true;
    else return false;
}
