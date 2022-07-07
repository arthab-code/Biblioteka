#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED

#include <iostream>
#include "Ksiazka.h"

using namespace std;

class Biblioteka
{
    private:
    vector<Ksiazka> _bazaKsiazek;

    public:
    void Menu();
    void PanelEdycji();
    void PanelUsuwania();
    void WyczyscEkran();
    void DodajKsiazke();
    void WyswietlKsiazki();

    void PanelKlonowania();


};

#endif // BIBLIOTEKA_H_INCLUDED
