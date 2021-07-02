#include "AdresatMenager.h"

void AdresatMenager::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

}


Adresat AdresatMenager::podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata()+1));

    cout<<"adresat ID = "<< adresat.pobierzId()<<endl;
    cout<<"uzytkownik ID = "<< adresat.pobierzIdUzytkownika()<<endl;
    cout << "Podaj imie: ";
    cin>>imie;

    cout << "Podaj nazwisko: ";
    cin>>nazwisko;

    cout << "Podaj numer telefonu: ";
    cin>>numerTelefonu;

    cout << "Podaj email: ";
    cin>>email;

    cout << "Podaj adres: ";
    cin>>adres;

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}


void AdresatMenager::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id adresata:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "IDUzytkownika:           " << ID_ZALOGOWANEGO_UZYTKOWNIKA<< endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenager::wyswietlWszystkichAdresatow()
{
    adresaci = plikZAdresatami.wczytajWszytkichAdresatow();

    for (int i=0; i<adresaci.size(); i++)
    {

        cout<<"Id: "<< adresaci[i].pobierzId()<<endl;
        cout<<"Imie: "<<adresaci[i].pobierzImie()<<endl;
        cout<<"Nazwisko: "<<adresaci[i].pobierzNazwisko()<<endl;
        cout<<"Tel: "<<adresaci[i].pobierzNumerTelefonu()<<endl;
        cout<<"Email: "<<adresaci[i].pobierzEmail()<<endl;
        cout<<"Adre: "<<adresaci[i].pobierzAdres()<<endl<<endl;
    }
}
