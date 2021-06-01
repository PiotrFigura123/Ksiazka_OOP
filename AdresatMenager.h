#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
//#include "PlikZUytkownikami.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenedzer.h"
#include "Adresat.h"

using namespace std;

//class UzytkownikMenedzer
class AdresatMenager
{
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    void wyswietlDaneAdresata(Adresat adresat,  int IdZalogowanegoUzytkownika);
    Adresat podajDaneNowegoAdresata(int IdZalogowanegoUzytkownika);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    PlikZAdresatami plikZAdresatami;

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void zapiszWszystichAdresatowDoPliku();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int pobierzZPlikuIdOstatniegoAdresata();
public:

    AdresatMenager(string nazwaPlikuZUzytkownikami2):plikZAdresatami(nazwaPlikuZUzytkownikami2){};
    int dodajAdresata(int IdZalogowanegoUzytkownika);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void rejestracjaAdresata(int idZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();
};
#endif
