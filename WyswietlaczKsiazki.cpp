#include <iostream>
#include "Ksiazka.h"
#include "WyswietlaczKsiazki.h"

WyswietlaczKsiazki::Wyswietl(Ksiazka & ksiazka)
{
    cout << "Nr katalogowy: \t\t" << ksiazka.ZwrocNrKatalogowy() << endl;
    cout << "Dzial: \t\t\t"  << ksiazka.ZwrocDzial() << endl;
    cout << "ISBN: \t\t\t" << ksiazka.ZwrocISBN() << endl;
    cout << "Tytul: \t\t\t" << ksiazka.ZwrocTytul() << endl;
    cout << "Autorzy: \t\t";
    for (int i=0; i<ksiazka.ZwrocAutorow().size(); i++)
    {
        cout << ksiazka.ZwrocAutorow()[i] << " | ";
    }
    cout << endl;
    cout << "Rezerwacja: \t\t";

    if (ksiazka.ZwrocZarezerwowanie())
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;

    cout << "Wypozyczono: \t\t";

    if (ksiazka.ZwrocPozyczenie())
    {
        cout << "TAK" << endl;
        cout << "ID wypozyczajacego: \t" << ksiazka.ZwrocIdWypozyczajacego() << endl;
    }
    else
        cout << "NIE" << endl;
}
