#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "PlikZUytkownikami.h"
#include "Uzytkownik.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();

    bool czyIstniejeLogin(string login);
    PlikZUytkownikami plikZUzytkownikami;
    void zapiszWszystkichUzytkownikowDoPliku();

public:
    void zmianaHaslaZalogowanegoUzytkownika();
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami):plikZUzytkownikami(nazwaPlikuZUzytkownikami){};

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    int logowanieUzytkownika();
};
