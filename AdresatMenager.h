#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H
#include <iostream>
#include <vector>

#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenedzer.h"
#include "Adresat.h"

using namespace std;

class AdresatMenager
{

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idOstatniegoAdresata;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
public:

    AdresatMenager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika )
        :plikZAdresatami(nazwaPlikuZAdresatami),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void usunAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    void edytujAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    void wyszukajAdresatowPoImieniu(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    void wyszukajAdresatowPoNazwisku(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
};
#endif
