#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;
class Adresat
{
    int idAdresat;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string emial;
    string adres
public:

    void ustawId(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};

#endif
