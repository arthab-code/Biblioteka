#include <iostream>
#include "Biblioteka.h"
#include "EdytorKsiazki.h"
#include "Ksiazka.h"
#include "WyswietlaczKsiazki.h"
#include "BazaKsiazek.h"
#include <vector>

using namespace std;

void Biblioteka::Menu()
{
    char wybor;
    do{
    WyczyscEkran();
    cout << "[1] Lista ksiazek" << endl;
    cout << "[2] Dodaj ksiazke" << endl;
    cout << "[3] Edytuj ksiazke" << endl;
    cout << "[4] Usun ksiazke" << endl;
    cout << "[5] Klonuj ksiazke" << endl;
    cout << "[q] WYJSCIE" << endl;
    cin >> wybor;

    if (wybor == '1')
        WyswietlKsiazki();

    if (wybor == '2')
        DodajKsiazke();

    if (wybor == '3')
        PanelEdycji();

    if (wybor == '4')
        PanelUsuwania();

    if (wybor == '5')
        PanelKlonowania();

system("pause");
    }while(wybor != 'q');
}

void Biblioteka::PanelKlonowania()
{
    WyswietlKsiazki();
    BazaKsiazek bk;
    int index;
    cout << "Wprowadz nr katalogowy pozycji do klonowania" << endl;
    cin >> index;

    if(!bk.SprawdzNrKatalogowy(index))
    {
        cout << "Nieprawidlowa pozycja" << endl;
        return;
    }

    EdytorKsiazki ek;
    ek.KlonujKsiazke(index);
}

void Biblioteka::DodajKsiazke()
{
  Ksiazka * ksiazka = new Ksiazka;

  EdytorKsiazki ek;

  ksiazka = ek.WpiszDane();
  BazaKsiazek bk;
  bk.DodajDoBazy(*ksiazka, true);

  delete ksiazka;
}

void Biblioteka::PanelEdycji()
{
    WyswietlKsiazki();
    BazaKsiazek bk;
    int index;
    cout << "Wprowadz nr katalogowy pozycji do edycji" << endl;
    cin >> index;

    if(!bk.SprawdzNrKatalogowy(index))
    {
        cout << "Nieprawidlowa pozycja" << endl;
        return;
    }

char wybor;
    do{
    WyczyscEkran();
    cout << "[1] Edytuj tytul" << endl;
    cout << "[2] EDYTUJ ISBN" << endl;
    cout << "[3] Edytuj Autorow" << endl;
    cout << "[4] Dodaj / Usun rezerwacje" << endl;
    cout << "[5] Wypozycz / Zwroc ksiazke" << endl;
    cout << "[q] WYJSCIE" << endl;
    cin >> wybor;

    EdytorKsiazki ek;

    if (wybor == '1')
        ek.EdytujTytul(index);

    if (wybor == '2')
        ek.EdytujISBN(index);

    if (wybor == '3')
        ek.EdytujAutorow(index);

    if (wybor == '4')
        ek.EdytujRezerwacje(index);

    if (wybor == '5')
        ek.EdytujWypozyczenie(index);


    }while(wybor != 'q');
}

void Biblioteka::PanelUsuwania()
{
    WyswietlKsiazki();
    BazaKsiazek bk;

    int index;

    cout << "Wpisz numer katalogowy ksiazki do usuniecia:" << endl;
    cin >> index;

    bk.UsunKsiazke(index);
}

void Biblioteka::WyswietlKsiazki()
{
  WyswietlaczKsiazki wK;
  WyczyscEkran();

  BazaKsiazek bk;
  cout << "Lista ksiazek : " << endl << endl;

  for (int i=0;i<BazaKsiazek::NR_KATALOGOWY;i++)
  {
      if (bk.SprawdzNrKatalogowy(i+1))
      {
        Ksiazka ksiazka;
        ksiazka = bk.ZwrocKsiazke(i+1);
        wK.Wyswietl(ksiazka);
        cout << endl;
        cout << "________________________________"<<endl;
      }
  }
}



void Biblioteka::WyczyscEkran()
{
    system("cls");
}
