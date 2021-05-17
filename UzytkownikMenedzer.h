#include <iostream>
#include <vector>
#include <fstream>
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
public:

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
};
