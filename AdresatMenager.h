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


    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdWybranegoAdresata();

public:

    AdresatMenager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika )
        :plikZAdresatami(nazwaPlikuZAdresatami),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void usunAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA);

};
#endif
