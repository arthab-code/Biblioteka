#include <iostream>
#include "EdytorKsiazki.h"
#include "KsiazkaKreator.h"
#include "BazaKsiazek.h"
#include "WyswietlaczKsiazki.h"
#include <vector>

using namespace std;

Ksiazka * EdytorKsiazki::WpiszDane()
{
  string tytul;
  vector<string> autorzy;
  char dzial;
  unsigned int nrISBN;
  int liczbaAutorow;

  cout << "Uzupelnij dzial" << endl;
  cin >> dzial;
  cout << "Uzupelnij tytul" << endl;
  cin >> tytul;
  if (!SprawdzDlugoscCiagu(tytul,2,50))
  {
      cout << "Nieprawidlowa liczba znakow w tytule" << endl;
      return NULL;
  }
  cout << "Uzupelnij nr ISBN" << endl;
  cin >> nrISBN;
  cout << "Podaj liczbe autorow ksiazek" << endl;
  cin >> liczbaAutorow;
  vector<string> listaAutorow = DodajAutorow(liczbaAutorow);

  Ksiazka * ksiazka = new Ksiazka;
  KsiazkaKreator * kk = new KsiazkaKreator;

  ksiazka = kk->UstawDzial(dzial)->UstawTytul(tytul)->UstawAutorow(listaAutorow)->UstawISBN(nrISBN)->UstawRezerwacje(false)->UstawPozyczenie(false)->UstawIdWypozyczajacego(0)->Buduj();

  return ksiazka;

}

bool EdytorKsiazki::SprawdzDlugoscCiagu(string ciag, int _min, int _max)
{
    bool wynik = true;

    if (ciag.size() > _max || ciag.size() < _min)
        wynik = false;

    return wynik;
}

vector<string> EdytorKsiazki::DodajAutorow(int ilu)
{
    cout << endl;

    vector<string> tmp;

    for (int i=0; i<ilu; i++)
    {
      string autor;
      cout << "Autor nr [" << i+1 << "] :" << endl;
      cin >> autor;
      tmp.push_back(autor);

    }
    cout << endl;
    return tmp;
}

vector<Ksiazka> EdytorKsiazki::ZwrocVectorKsiazek()
{
      BazaKsiazek bk;
      vector<Ksiazka> ksiazki;


      for (int i=0; i<BazaKsiazek::NR_KATALOGOWY; i++)
      {
          if (bk.SprawdzNrKatalogowy(i+1))
          {
              Ksiazka ksiazka;
              ksiazka = bk.ZwrocKsiazke(i+1);
              ksiazki.push_back(ksiazka);
          }

      }

      return ksiazki;
}

void EdytorKsiazki::EdytujTytul(int nrWBazie)
{
      BazaKsiazek bk;
      vector<Ksiazka> ksiazki = ZwrocVectorKsiazek();

      int index_temp;
      for (int i=0; i<ksiazki.size(); i++)
      {
              if (ksiazki[i].ZwrocNrKatalogowy() == nrWBazie)
              {
                  index_temp = i;
                  break;
              }
      }

      cout << "Podaj nowy tytul : " << endl;
      string tytul;
      cin >> tytul;

      ksiazki[index_temp].DodajTytul(tytul);

      bk.ZapiszZaktualizowanaKsiazke(ksiazki);
}

void EdytorKsiazki::EdytujISBN(int nrWBazie)
{
      BazaKsiazek bk;
      vector<Ksiazka> ksiazki = ZwrocVectorKsiazek();

      int index_temp;
      for (int i=0; i<ksiazki.size(); i++)
      {
              if (ksiazki[i].ZwrocNrKatalogowy() == nrWBazie)
              {
                  index_temp = i;
                  break;
              }
      }

      cout << "Podaj nowy ISBN : " << endl;
      unsigned int ISBN;
      cin >> ISBN;

      ksiazki[index_temp].UstawISBN(ISBN);

      bk.ZapiszZaktualizowanaKsiazke(ksiazki);
}

void EdytorKsiazki::EdytujRezerwacje(int nrWBazie)
{
      BazaKsiazek bk;
      vector<Ksiazka> ksiazki = ZwrocVectorKsiazek();

      int index_temp;
      for (int i=0; i<ksiazki.size(); i++)
      {
              if (ksiazki[i].ZwrocNrKatalogowy() == nrWBazie)
              {
                  index_temp = i;
                  break;
              }
      }
      bool czyZarezerwowano = false;
      char wybor;
      cout << "Chcesz zarezerwowac ksiazke ? [T/N] " << endl;
      cin >> wybor;
      if (wybor == 't' || wybor == 'T')
        czyZarezerwowano = true;


      ksiazki[index_temp].CzyZarezerwowano(czyZarezerwowano);

      bk.ZapiszZaktualizowanaKsiazke(ksiazki);
}

void EdytorKsiazki::EdytujWypozyczenie(int nrWBazie)
{
      BazaKsiazek bk;
      vector<Ksiazka> ksiazki = ZwrocVectorKsiazek();

      int index_temp;
      for (int i=0; i<ksiazki.size(); i++)
      {
              if (ksiazki[i].ZwrocNrKatalogowy() == nrWBazie)
              {
                  index_temp = i;
                  break;
              }
      }
      bool czyWypozyczono = false;
      char wybor;
      cout << "Chcesz wypozyczyc ksiazke ? [T/N] " << endl;
      cin >> wybor;
      if (wybor == 't' || wybor == 'T')
        czyWypozyczono = true;

      if (czyWypozyczono)
      {
         unsigned int idWypozyczajacego;
         cout << "Wpisz ID wypozyczajacego" << endl;
         cin >> idWypozyczajacego;
         ksiazki[index_temp].UstawIdWypozyczajacego(idWypozyczajacego);
      }

      ksiazki[index_temp].CzyPozyczono(czyWypozyczono);

      bk.ZapiszZaktualizowanaKsiazke(ksiazki);
}

void EdytorKsiazki::EdytujAutorow(int nrWBazie)
{
      BazaKsiazek bk;
      vector<Ksiazka> ksiazki = ZwrocVectorKsiazek();

      int index_temp;
      for (int i=0; i<ksiazki.size(); i++)
      {
              if (ksiazki[i].ZwrocNrKatalogowy() == nrWBazie)
              {
                  index_temp = i;
                  break;
              }
      }

      cout << "Uwaga lista autorow zostanie skasowana i utworzona na nowo!" << endl;
      int ile;
      cout << "Wpisz ilu autorow posiada ksiazka : " << endl;
      cin >> ile;

      ksiazki[index_temp].WyczyscAutorow();

      for (int i=0; i<ile; i++)
      {
          string autor;
          cout << "Autor ["+to_string(i+1)+"]" << endl;
          cin >> autor;
          ksiazki[index_temp].DodajAutora(autor);
      }

      bk.ZapiszZaktualizowanaKsiazke(ksiazki);


}

void EdytorKsiazki::KlonujKsiazke(int nrWBazie)
{
      BazaKsiazek bk;
      vector<Ksiazka> ksiazki = ZwrocVectorKsiazek();

      int index_temp;
      for (int i=0; i<ksiazki.size(); i++)
      {
              if (ksiazki[i].ZwrocNrKatalogowy() == nrWBazie)
              {
                  index_temp = i;
                  break;
              }
      }

      bk.DodajNrKatalogowy();
      bk.DodajUsunLiczbeKsiazek(1);

      Ksiazka ksiazkaKlon;
      ksiazkaKlon.UstalNrKatalogowy(BazaKsiazek::NR_KATALOGOWY);
      ksiazkaKlon.UstawISBN(ksiazki[index_temp].ZwrocISBN());
      ksiazkaKlon.UstawDzial(ksiazki[index_temp].ZwrocDzial());
      for (int i=0;i<ksiazki[index_temp].ZwrocAutorow().size(); i++)
      {
          ksiazkaKlon.DodajAutora(ksiazki[index_temp].ZwrocAutorow()[i]);
      }
      ksiazkaKlon.DodajTytul(ksiazki[index_temp].ZwrocTytul());
      ksiazkaKlon.CzyPozyczono(ksiazki[index_temp].ZwrocPozyczenie());
      ksiazkaKlon.UstawIdWypozyczajacego(ksiazki[index_temp].ZwrocIdWypozyczajacego());
      ksiazkaKlon.CzyZarezerwowano(ksiazki[index_temp].ZwrocZarezerwowanie());

      bk.DodajDoBazy(ksiazkaKlon, false);

      cout << "sklonowano ksiazke i nadano jej nr katalogowy : " << BazaKsiazek::NR_KATALOGOWY << endl;

}
