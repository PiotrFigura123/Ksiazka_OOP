#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

}
void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if ( uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        cout<<"Uzytkownik jest zalogowany: "<<uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()<<endl;
        adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }

}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenager;
    adresatMenager= NULL;
}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenager->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenager->dodajAdresata();
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenager->usunAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenager->edytujAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}
