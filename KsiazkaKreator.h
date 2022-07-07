#ifndef KSIAZKAKREATOR_H_INCLUDED
#define KSIAZKAKREATOR_H_INCLUDED

#include <vector>
#include <iostream>
#include "Ksiazka.h"

using namespace std;

class KsiazkaKreator
{
   private:
   Ksiazka * _ksiazka;

   public:
   KsiazkaKreator();
   ~KsiazkaKreator();
  // KsiazkaKreator * UstawNrKatalogowy();
   KsiazkaKreator * UstawISBN(unsigned int nr);
   KsiazkaKreator * UstawDzial(char dzial);
   KsiazkaKreator * UstawTytul(string tytul);
   KsiazkaKreator * UstawAutorow(vector<string> autorzy);
   KsiazkaKreator * UstawPozyczenie(bool wartosc);
   KsiazkaKreator * UstawRezerwacje(bool wartosc);
   KsiazkaKreator * UstawIdWypozyczajacego(unsigned int wartosc);
   Ksiazka * Buduj();

};
#endif // KSIAZKAKREATOR_H_INCLUDED
