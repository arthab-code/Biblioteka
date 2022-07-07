#ifndef EDYTORKSIAZKI_H_INCLUDED
#define EDYTORKSIAZKI_H_INCLUDED

#include <vector>
#include <iostream>
#include "Ksiazka.h"
using namespace std;

class EdytorKsiazki
{
    public:
    Ksiazka * WpiszDane();
    bool SprawdzDlugoscCiagu(string ciag, int min_, int max_);
    vector<string> DodajAutorow(int ilu);

    void EdytujTytul(int nrWBazie);
    void EdytujISBN(int nrWBazie);
    void EdytujAutorow(int nrWBazie);
    void EdytujRezerwacje(int nrWBazie);
    void EdytujWypozyczenie(int nrWBazie);
    vector<Ksiazka> ZwrocVectorKsiazek();
    void KlonujKsiazke(int nrWBazie);


};

#endif // EDYTORKSIAZKI_H_INCLUDED
