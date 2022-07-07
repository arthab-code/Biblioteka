#include <iostream>
#include <dirent.h>
#include <filesystem>
#include <fstream>
#include "Ksiazka.h"
#include "BazaKsiazek.h"
#include <vector>

using namespace std;


BazaKsiazek::BazaKsiazek()
{
    this->nazwaFolderu = "bazaKsiazek";
    this->nazwaPlikuBazy = "ksiazki.txt";
    this->nazwaPlikuKatalogu = "katalogID.txt";
    this->nazwaPlikuIlosci = "iloscKsiazek.txt";
}
string BazaKsiazek::ZwrocSciezke(char* nazwaPliku)
{
    string folder, plik;
    folder = nazwaFolderu;
    plik = nazwaPliku;

    return folder+"/"+plik;
}

int BazaKsiazek::NR_KATALOGOWY = 0;
int BazaKsiazek::LICZBA_KSIAZEK = 0;


void BazaKsiazek::DodajUsunLiczbeKsiazek(int wartosc)
{
 string sciezka = ZwrocSciezke(nazwaPlikuIlosci);

   fstream plik;

   try{
   LICZBA_KSIAZEK += wartosc;
   plik.open(sciezka, ios::out);
   plik << LICZBA_KSIAZEK << endl;

   plik.close();
   }
    catch (const char* msg)
   {
       cout << msg << endl;
       exit(EXIT_FAILURE);
   }

}

void BazaKsiazek::DodajNrKatalogowy()
{
  string sciezka = ZwrocSciezke(nazwaPlikuKatalogu);

   fstream plik;

   try{
   NR_KATALOGOWY++;
   plik.open(sciezka);
   plik << NR_KATALOGOWY;

   plik.close();
   }
    catch (const char* msg)
    {
       cout << msg << endl;
       exit(EXIT_FAILURE);
    }

}

void BazaKsiazek::Inicjalizuj()
{
    mkdir(nazwaFolderu);
    string sciezka = ZwrocSciezke(nazwaPlikuBazy);
    fstream plik_sprawdz(sciezka), plik;

    if (!plik_sprawdz.good())
    {
        try{
             plik_sprawdz.open(sciezka, ios::out);
            fstream plikIlosc, plikKatalog;
           sciezka = ZwrocSciezke(nazwaPlikuIlosci);
           plikIlosc.open(sciezka, ios::out);
           plikIlosc << 0;
           plikIlosc.close();

           sciezka = ZwrocSciezke(nazwaPlikuKatalogu);
           plikKatalog.open(sciezka, ios::out);
           plikKatalog << 0;
           plikKatalog.close();
           plik_sprawdz.close();


        } catch (const char* msg)
        {
            cout << msg << endl;
            exit(EXIT_FAILURE);
        }

    } else {

        try{
          fstream plikIlosc, plikKatalog;
           sciezka = ZwrocSciezke(nazwaPlikuIlosci);
           plikIlosc.open(sciezka);
           plikIlosc >> LICZBA_KSIAZEK;
           plikIlosc.close();

           sciezka = ZwrocSciezke(nazwaPlikuKatalogu);
           plikKatalog.open(sciezka);
           plikKatalog >> NR_KATALOGOWY;
           plikKatalog.close();

        plik.close();
        } catch (const char* msg)
        {
            cout << msg << endl;
            exit(EXIT_FAILURE);
        }
    }
   plik_sprawdz.close();
}

void BazaKsiazek::DodajDoBazy(Ksiazka ksiazka, bool czyLiczyc)
{
    if (czyLiczyc)
    {
    DodajNrKatalogowy();
    DodajUsunLiczbeKsiazek(1);
    }


   string sciezka = ZwrocSciezke(nazwaPlikuBazy);

   fstream plik;

   try{
   plik.open(sciezka,ios::out | ios::app);

   if (czyLiczyc)
   {
      string nrKatalogowy = "["+to_string(NR_KATALOGOWY)+"]";
      plik << nrKatalogowy << endl;
   } else {
      plik << "["+to_string(ksiazka.ZwrocNrKatalogowy())+"]" << endl;
   }

   plik << ksiazka.ZwrocDzial() << endl;
   plik << ksiazka.ZwrocISBN()<< endl;
   plik << ksiazka.ZwrocTytul() << endl;
   plik << "[AUT]" << endl;

   for (int i=0; i<ksiazka.ZwrocAutorow().size(); i++)
    plik << ksiazka.ZwrocAutorow()[i] << endl;

   plik << "[/AUT]" << endl;
   plik << ksiazka.ZwrocZarezerwowanie() << endl;
   plik << ksiazka.ZwrocPozyczenie() << endl;
   plik << ksiazka.ZwrocIdWypozyczajacego() << endl;

   plik.close();
   }
    catch (const char* msg)
    {
       cout << msg << endl;
       exit(EXIT_FAILURE);
    }

}

void BazaKsiazek::ZapiszZaktualizowanaKsiazke(vector<Ksiazka>& ksiazki)
{

     fstream plik;
     string sciezka = ZwrocSciezke(nazwaPlikuBazy);

     try
     {
      plik.open(sciezka, ios::out);

      plik.close();

      for (int i=0; i<ksiazki.size();i++)
      {
          DodajDoBazy(ksiazki[i],false);
      }

     }catch(const char* msg)
     {
         cout << msg << endl;
     }

}

void BazaKsiazek::UsunKsiazke(int nrWBazie)
{
     string sciezka = ZwrocSciezke(nazwaPlikuBazy);

   fstream plik;
   vector<string> temp;

   try{
   plik.open(sciezka);

   string nr = "["+to_string(nrWBazie)+"]";
   string linia;

   bool sprawdz = false;

   while(getline(plik,linia))
   {
       if (linia == nr)
       {
           while (linia != "[AUT]")
              getline(plik,linia);

           while (linia != "[/AUT]")
             getline(plik,linia);

           getline(plik,linia);
           getline(plik,linia);
           getline(plik,linia);
           getline(plik,linia);

           sprawdz = true;

       }

       temp.push_back(linia);

   }

   if (!sprawdz)
   {
       cout << "Brak takiej ksiazki" << endl;
       plik.close();
       return;
   }

   plik.close();
   DodajUsunLiczbeKsiazek(-1);
   plik.open(sciezka, ios::out);

   for (int i=0; i<temp.size(); i++)
   {
       plik << temp[i] << endl;
   }

   plik.close();

   }
    catch (const char* msg)
    {
       cout << msg << endl;
       exit(EXIT_FAILURE);
    }

}

Ksiazka BazaKsiazek::ZwrocKsiazke(int nrWBazie)
{
   string sciezka = ZwrocSciezke(nazwaPlikuBazy);
   string linia;
   fstream plik;

   Ksiazka ksiazka;

   try{
   plik.open(sciezka,ios::in);

   while(getline(plik,linia))
   {
       if (linia == "["+to_string(nrWBazie)+"]")
       {
         ksiazka.UstalNrKatalogowy(nrWBazie);
         getline(plik,linia);
         char tchar = linia[0];
         ksiazka.UstawDzial(tchar);
         getline(plik,linia);
         ksiazka.UstawISBN(atoi(linia.c_str()));
         getline(plik,linia);
         ksiazka.DodajTytul(linia);
         getline(plik,linia);
         getline(plik,linia);
         while (linia != "[/AUT]")
         {
             ksiazka.DodajAutora(linia);
             getline(plik,linia);

         }
         getline(plik,linia);
         ksiazka.CzyZarezerwowano((bool)atoi(linia.c_str()));
         getline(plik,linia);
         ksiazka.CzyPozyczono((bool)atoi(linia.c_str()));
         getline(plik,linia);
         ksiazka.UstawIdWypozyczajacego(atoi(linia.c_str()));
         plik.close();
         return ksiazka;
       }
   }
   plik.close();

   }
    catch (const char* msg)
    {
       cout << msg << endl;
       exit(EXIT_FAILURE);
    }

}

bool BazaKsiazek::SprawdzNrKatalogowy(int nrWBazie)
{
   string sciezka = ZwrocSciezke(nazwaPlikuBazy);
   string linia;
   fstream plik;

   try{
   plik.open(sciezka,ios::in);

   while(getline(plik,linia))
   {
       if (linia == "["+to_string(nrWBazie)+"]")
       {
           return true;
       }
   }
   plik.close();

   }
    catch (const char* msg)
    {
       cout << msg << endl;
       exit(EXIT_FAILURE);
    }

    return false;
}

