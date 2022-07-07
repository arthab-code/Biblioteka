#include <iostream>
#include "KsiazkaKreator.h"
#include "BazaKsiazek.h"
using namespace std;

KsiazkaKreator::KsiazkaKreator()
{
    _ksiazka = new Ksiazka;
}

KsiazkaKreator::~KsiazkaKreator()
{
    delete _ksiazka;
}

/*KsiazkaKreator * KsiazkaKreator::UstawNrKatalogowy()
{
     int nr = BazaKsiazek::NR_KATALOGOWY++;
    _ksiazka->UstalNrKatalogowy(nr);

    return this;
}*/

KsiazkaKreator * KsiazkaKreator::UstawISBN(unsigned int nr)
{
    _ksiazka->UstawISBN(nr);

    return this;
}

KsiazkaKreator * KsiazkaKreator::UstawDzial(char dzial)
{
    _ksiazka->UstawDzial(dzial);

    return this;
}

KsiazkaKreator * KsiazkaKreator::UstawTytul(string tytul)
{
    _ksiazka->DodajTytul(tytul);

    return this;
}

KsiazkaKreator * KsiazkaKreator::UstawAutorow(vector<string> autorzy)
{
    for(int i=0; i<autorzy.size(); i++)
      _ksiazka->DodajAutora(autorzy[i]);

    return this;
}

KsiazkaKreator * KsiazkaKreator::UstawPozyczenie(bool wartosc)
{
    _ksiazka->CzyPozyczono(wartosc);

    return this;
}

KsiazkaKreator * KsiazkaKreator::UstawRezerwacje(bool wartosc)
{
    _ksiazka->CzyZarezerwowano(wartosc);

    return this;
}

KsiazkaKreator * KsiazkaKreator::UstawIdWypozyczajacego(unsigned int wartosc)
{
    _ksiazka->UstawIdWypozyczajacego(wartosc);

    return this;
}

Ksiazka * KsiazkaKreator::Buduj()
{
    return _ksiazka;
}
