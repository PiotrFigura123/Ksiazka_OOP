#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy2;
    plikTekstowy2.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy2.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        cout<<liniaZDanymiAdresata;

        if (PlikTekstowy::czyPlikJestPusty() == true)
        {
            plikTekstowy2 << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy2 << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy2.close();
        return true;
    }
    return false;
}

vector <Adresat>  PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{

    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy2;
    plikTekstowy2.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);
    if (plikTekstowy2.good() == true)
    {
        while (getline(plikTekstowy2, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {


                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
                daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
                idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
            }
        }
        plikTekstowy2.close();
    }
    return adresaci;

}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
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

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

/*bool PlikZAdresatami::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
};*/


int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

void PlikZAdresatami::ustawIdOstatniegoAdresata(int ustawNoweIdOstatniegoAdresata)
{
    idOstatniegoAdresata = ustawNoweIdOstatniegoAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajWszytkichAdresatow()
{
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy2;
    plikTekstowy2.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy2.good() == true)
    {
        while (getline(plikTekstowy2, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
            adresaci.push_back(adresat);
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy2.close();

    return adresaci;
}

void PlikZAdresatami::usunWybranegoAdresataZPliku(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    odczytywanyPlikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(TYMCZAS_NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while(getline(odczytywanyPlikTekstowy, wczytanaLinia))

        {
            if (daneJednegoAdresataOddzielonePionowymiKreskami == wczytanaLinia)
            {
                numerWczytanejLinii++;
            }
            else
            {
                tymczasowyPlikTekstowy<<wczytanaLinia<<endl;
                numerWczytanejLinii++;

            }
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunPlik(PlikTekstowy::pobierzNazwePliku());
    zmienNazwePliku(TYMCZAS_NAZWA_PLIKU_Z_ADRESATAMI, PlikTekstowy::pobierzNazwePliku());

}


void PlikZAdresatami::edytujWybranegoAdresataZPliku(string daneJednegoAdresataOddzielonePionowymiKreskami, string noweDaneJednegoAdresataOddzielonePionowymiKreskami)
{
    cout<<"jestem w pliku"<<endl;
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    odczytywanyPlikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(TYMCZAS_NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while(getline(odczytywanyPlikTekstowy, wczytanaLinia))

        {
            if (daneJednegoAdresataOddzielonePionowymiKreskami == wczytanaLinia)
            {
                 cout<<"znalazlem linie i podmieniam"<<endl;
                tymczasowyPlikTekstowy<<noweDaneJednegoAdresataOddzielonePionowymiKreskami<<endl;
                numerWczytanejLinii++;
            }
            else
            {
                tymczasowyPlikTekstowy<<wczytanaLinia<<endl;
                numerWczytanejLinii++;

            }
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunPlik(PlikTekstowy::pobierzNazwePliku());
    zmienNazwePliku(TYMCZAS_NAZWA_PLIKU_Z_ADRESATAMI, PlikTekstowy::pobierzNazwePliku());

}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}
