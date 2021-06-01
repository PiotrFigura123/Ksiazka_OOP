#include "AdresatMenager.h"

int AdresatMenager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

int AdresatMenager::dodajAdresata(int IdZalogowanegoUzytkownika)
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(IdZalogowanegoUzytkownika);
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}


Adresat AdresatMenager::podajDaneNowegoAdresata(int IdZalogowanegoUzytkownika)
{
    Adresat adresat;

    adresat.ustawIdUzytkownika(IdZalogowanegoUzytkownika);
    adresat.ustawId(pobierzZPlikuIdOstatniegoAdresata());

    cout << "Podaj imie: ";
    string imie;
    cin>>imie;
    adresat.ustawImie(imie);
    //adresat.imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    cout << "Podaj nazwisko: ";
    string nazwisko;
    cin>>nazwisko;
    adresat.ustawNazwisko(nazwisko);
    //adresat.nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.nazwisko);

    cout << "Podaj numer telefonu: ";
    string numerTelefonu;
    cin>>numerTelefonu;
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    string email;
    cin>>email;
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    string adres;
    cin>>adres;

    adresat.ustawAdres(adres);



    system("pause");
    return adresat;
}


void AdresatMenager::wyswietlDaneAdresata(Adresat adresat, int IdZalogowanegoUzytkownika)
{
    cout << endl << "Id adresata:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "IDUzytkownika:           " << IdZalogowanegoUzytkownika<< endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void  AdresatMenager::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{

    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

int AdresatMenager::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat AdresatMenager::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
               adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
               adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
               adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
int AdresatMenager::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string AdresatMenager::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}



int AdresatMenager::pobierzZPlikuIdOstatniegoAdresata()
{


    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;


}

void AdresatMenager::wyswietlWszystkichAdresatow()
{
    adresaci = plikZAdresatami.wczytajWszytkichAdresatow();

    for (int i=1; i<adresaci.size(); i++)
    {
        cout<<adresaci[i].pobierzId()<<" ";
        cout<<adresaci[i].pobierzImie()<<" ";
        cout<<adresaci[i].pobierzNazwisko()<<" ";
        cout<<adresaci[i].pobierzNumerTelefonu()<<" ";
        cout<<adresaci[i].pobierzEmail()<<" ";
        cout<<adresaci[i].pobierzAdres()<<endl;
    }
}
