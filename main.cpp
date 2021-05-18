#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //cout<<"Rejestracja"<<endl;
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    cout<<"Log"<<endl;
    ksiazkaAdresowa.logowanieUzytkownika();
    cout<<"Pass"<<endl;
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    return 0;
}
