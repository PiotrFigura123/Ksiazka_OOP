#include <iostream>
#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"
using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt", "Adresaci.txt");
    char wybierzOpcjeZMenuUzytkownika = '0';
    char wyboru = '0';
    while(true)
    {
        LOOP:
        wybierzOpcjeZMenuUzytkownika = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

        switch (wybierzOpcjeZMenuUzytkownika)
        {
        case '1':
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case '2':
        {
            ksiazkaAdresowa.logowanieUzytkownika();
            while(true)
            {
                wyboru = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
            switch (wyboru)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogujUzytkownika();
                goto LOOP;
                break;
            }
            }

            break;
        }
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
}


