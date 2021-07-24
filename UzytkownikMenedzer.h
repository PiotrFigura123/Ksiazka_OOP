#ifndef UZYTKOWNIKMEDZER_H
#define UZYTKOWNIKMEDZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "PlikZUytkownikami.h"
#include "Uzytkownik.h"
#include "AdresatMenager.h"
#include "PlikTekstowy.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    void zmianaHaslaZalogowanegoUzytkownika();
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami):plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika=0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku(nazwaPlikuZUzytkownikami);
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
};
#endif
