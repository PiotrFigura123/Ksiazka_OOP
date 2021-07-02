#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);


public:

    PlikZAdresatami(string nazwaPlikuZAdreatami):NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdreatami){
    idOstatniegoAdresata =0;
    };

    bool dopiszAdresataDoPliku(Adresat adresat);
     vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata( int ustawNoweIdOstatniegoAdresata);
    vector <Adresat> wczytajWszytkichAdresatow();
};


#endif // PLIKZUZYTKOWNIKAMI_H
