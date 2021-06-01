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
    adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    adresatMenager.dodajAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());

}
 void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
 {
          uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
 }
void KsiazkaAdresowa::wylogujUzytkownika()
 {
          uzytkownikMenedzer.wylogujUzytkownika();
 }
void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
 {
         adresatMenager.wyswietlWszystkichAdresatow();
 }
