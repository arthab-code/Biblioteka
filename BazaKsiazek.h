#ifndef BAZAKSIAZEK_H_INCLUDED
#define BAZAKSIAZEK_H_INCLUDED

#include "Ksiazka.h"
#include <vector>
#include <iostream>

class BazaKsiazek
{
    private:
    char* nazwaFolderu;
    char* nazwaPlikuBazy;
    char* nazwaPlikuKatalogu;
    char* nazwaPlikuIlosci;

    public:
    static int NR_KATALOGOWY;
    static int LICZBA_KSIAZEK;
    BazaKsiazek();
    void Inicjalizuj();
    void DodajDoBazy(Ksiazka ksiazka, bool czyLiczyc);
    void ZapiszZaktualizowanaKsiazke(vector<Ksiazka>& ksiazki);
    Ksiazka ZwrocKsiazke(int nrWBazie);
    void UsunKsiazke(int nrWBazie);
    int ZwrocLiczbeKsiazek();
    void DodajNrKatalogowy();
    void DodajUsunLiczbeKsiazek(int wartosc);
    bool SprawdzNrKatalogowy(int nrWBazie);
    string ZwrocSciezke(char* nazwaPliku);

};

#endif // BAZAKSIAZEK_H_INCLUDED
