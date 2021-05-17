#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    string haslo;
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenedzer:: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin( string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        cout<<uzytkownicy[i].pobierzId()<<endl;
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<uzytkownicy[i].pobierzHaslo()<<endl;

    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenedzer::logowanieUzytkownika()
{

    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    cin>>login;
    cout<<"wielkosc wektora uzytkownicy = "<< uzytkownicy.size()<<endl;

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if(login == uzytkownicy[i].pobierzLogin())
        {
            cout << endl << "Istnieje uzytkownik o takim loginie. ID = " <<uzytkownicy[i].pobierzId()<< endl;
            cout<<"Haslo:"<<uzytkownicy[i].pobierzHaslo()<<endl;
        }

        for (int iloscProb = 3; iloscProb > 0; iloscProb--)
        {
            cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
            cin>>haslo;

            if ( haslo ==uzytkownicy[i].pobierzHaslo())
            {
                cout << endl << "Zalogowales sie." << endl << endl;
                system("pause");
                return  uzytkownicy[i].pobierzId();
            }
        }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
}

