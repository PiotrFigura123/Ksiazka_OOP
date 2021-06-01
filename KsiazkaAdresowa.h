#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenager.h"
using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenager adresatMenager;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZUzytkownikami2)
    :uzytkownikMenedzer(nazwaPlikuZUzytkownikami),adresatMenager(nazwaPlikuZUzytkownikami2)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();

    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    void rejestracjaAdresata();
    void wyswietlWszystkichAdresatow();
};
#endif // KSIAZKAADRESOWA_H
