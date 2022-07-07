#include <iostream>
#include "Ksiazka.h"

using namespace std;

void Ksiazka::UstalNrKatalogowy(int _nrKatalogowy) {this->nrKatalogowy = _nrKatalogowy;}
int Ksiazka::ZwrocNrKatalogowy() { return nrKatalogowy; }

void Ksiazka::UstawISBN(unsigned int nr) { this->nrISBN = nr; }
unsigned int Ksiazka::ZwrocISBN() { return nrISBN; }

void Ksiazka::DodajAutora(string autor) { this->autor.push_back(autor); }
vector<string> Ksiazka::ZwrocAutorow() { return autor; }

void Ksiazka::DodajTytul(string wartosc) { this->tytul = wartosc;}
string Ksiazka::ZwrocTytul() { return tytul; }

void Ksiazka::CzyZarezerwowano(bool wartosc)  { this->jestZarezerwowana = wartosc; }
bool Ksiazka::ZwrocZarezerwowanie() { return jestZarezerwowana; }

void Ksiazka::CzyPozyczono(bool wartosc) { this->jestPozyczona = wartosc; }
bool Ksiazka::ZwrocPozyczenie() { return jestPozyczona; }

void Ksiazka::UstawDzial(char wartosc) { this->dzial = wartosc; }
char Ksiazka::ZwrocDzial() { return dzial; }

void Ksiazka::UstawIdWypozyczajacego(unsigned int wartosc) { this->idWypozyczajacego = wartosc; }
unsigned int Ksiazka::ZwrocIdWypozyczajacego() { return idWypozyczajacego; }

void Ksiazka::WyczyscAutorow() { autor.clear(); }
