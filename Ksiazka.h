#ifndef KSIAZKA_H_INCLUDED
#define KSIAZKA_H_INCLUDED
#include <vector>
#include <iostream>

using namespace std;

class Ksiazka
{
   private:
       int nrKatalogowy;
       unsigned int nrISBN;
       string tytul;
       vector<string> autor;
       bool jestPozyczona;
       bool jestZarezerwowana;
       char dzial;
       unsigned int idWypozyczajacego;


    public:
        void UstalNrKatalogowy(int _nrKatalogowy);
        int ZwrocNrKatalogowy();

        void UstawISBN(unsigned int nr);
        unsigned int ZwrocISBN();

        void DodajAutora(string autor);
        vector<string> ZwrocAutorow();

        void DodajTytul(string wartosc);
        string ZwrocTytul();

        void CzyZarezerwowano(bool wartosc);
        bool ZwrocZarezerwowanie();

        void CzyPozyczono(bool wartosc);
        bool ZwrocPozyczenie();

        void UstawDzial(char wartosc);
        char ZwrocDzial();

        void UstawIdWypozyczajacego(unsigned int wartosc);
        unsigned int ZwrocIdWypozyczajacego();

        void WyczyscAutorow();

};


#endif // KSIAZKA_H_INCLUDED
