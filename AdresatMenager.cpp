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

void AdresatMenager::usunAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{
     system("cls");
     cout <<"ID zalogowanego uytkowanika " <<ID_ZALOGOWANEGO_UZYTKOWNIKA<<endl;
     string idZalogownego;
     idZalogownego = MetodyPomocnicze::konwerjsaIntNaString(ID_ZALOGOWANEGO_UZYTKOWNIKA);
      system("pause");
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami ="";
    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            daneJednegoAdresataOddzielonePionowymiKreskami= MetodyPomocnicze::konwerjsaIntNaString(idUsuwanegoAdresata)+"|"+idZalogownego+"|"+itr->pobierzImie()+"|"+itr->pobierzNazwisko()+"|"+itr->pobierzNumerTelefonu()+"|"+itr->pobierzEmail()+"|"+itr->pobierzAdres()+"|";

            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            cin>>znak;
            if (znak == 't')
            {
                cout<<"daneJednegoAdresataOddzielonePionowymiKreskami "<<daneJednegoAdresataOddzielonePionowymiKreskami<<endl;
                plikZAdresatami.usunWybranegoAdresataZPliku(daneJednegoAdresataOddzielonePionowymiKreskami);
                //numerLiniiUsuwanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                //usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);

                cout<<"Jestem pprzed usunieciuadresata z wektora"<<endl;
                cout<<adresaci.size()<<endl;
                *adresaci.erase(itr);
                cout<<"Jestem po usunieciuadresata z wektora"<<endl;
                cout<<adresaci.size()<<endl;
                cout<<"Jestem po usunieciuadresata z wektora"<<endl;
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");

            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("p       ause");

            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }

}

int AdresatMenager::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    cin>>idWybranegoAdresata;
    return idWybranegoAdresata;
}

void AdresatMenager::edytujAdresata(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{
    system("cls");
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami ="";

    string noweDaneJednegoAdresataOddzielonePionowymiKreskami="";
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            daneJednegoAdresataOddzielonePionowymiKreskami= MetodyPomocnicze::konwerjsaIntNaString(idEdytowanegoAdresata)+"|"+MetodyPomocnicze::konwerjsaIntNaString(ID_ZALOGOWANEGO_UZYTKOWNIKA)+"|"
                +adresaci[i].pobierzImie()+"|"+adresaci[i].pobierzNazwisko()+"|"+adresaci[i].pobierzNumerTelefonu()+"|"+adresaci[i].pobierzEmail()+"|"+adresaci[i].pobierzAdres()+"|";

            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                {
                    cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                noweDaneJednegoAdresataOddzielonePionowymiKreskami= MetodyPomocnicze::konwerjsaIntNaString(idEdytowanegoAdresata)+"|"+MetodyPomocnicze::konwerjsaIntNaString(ID_ZALOGOWANEGO_UZYTKOWNIKA)+"|"
                +adresaci[i].pobierzImie()+"|"+adresaci[i].pobierzNazwisko()+"|"+adresaci[i].pobierzNumerTelefonu()+"|"+adresaci[i].pobierzEmail()+"|"+adresaci[i].pobierzAdres()+"|";

                plikZAdresatami.edytujWybranegoAdresataZPliku(daneJednegoAdresataOddzielonePionowymiKreskami, noweDaneJednegoAdresataOddzielonePionowymiKreskami);

                break;
                }

            case '2':
                {
                    cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                 noweDaneJednegoAdresataOddzielonePionowymiKreskami= MetodyPomocnicze::konwerjsaIntNaString(idEdytowanegoAdresata)+"|"+MetodyPomocnicze::konwerjsaIntNaString(ID_ZALOGOWANEGO_UZYTKOWNIKA)+"|"
                +adresaci[i].pobierzImie()+"|"+adresaci[i].pobierzNazwisko()+"|"+adresaci[i].pobierzNumerTelefonu()+"|"+adresaci[i].pobierzEmail()+"|"+adresaci[i].pobierzAdres()+"|";

                plikZAdresatami.edytujWybranegoAdresataZPliku(daneJednegoAdresataOddzielonePionowymiKreskami, noweDaneJednegoAdresataOddzielonePionowymiKreskami);


                break;
                }
            case '3':
                {
                   cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                noweDaneJednegoAdresataOddzielonePionowymiKreskami= MetodyPomocnicze::konwerjsaIntNaString(idEdytowanegoAdresata)+"|"+MetodyPomocnicze::konwerjsaIntNaString(ID_ZALOGOWANEGO_UZYTKOWNIKA)+"|"
                +adresaci[i].pobierzImie()+"|"+adresaci[i].pobierzNazwisko()+"|"+adresaci[i].pobierzNumerTelefonu()+"|"+adresaci[i].pobierzEmail()+"|"+adresaci[i].pobierzAdres()+"|";
                plikZAdresatami.edytujWybranegoAdresataZPliku(daneJednegoAdresataOddzielonePionowymiKreskami, noweDaneJednegoAdresataOddzielonePionowymiKreskami);

                break;
                }

            case '4':
                {
                    cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                 noweDaneJednegoAdresataOddzielonePionowymiKreskami= MetodyPomocnicze::konwerjsaIntNaString(idEdytowanegoAdresata)+"|"+MetodyPomocnicze::konwerjsaIntNaString(ID_ZALOGOWANEGO_UZYTKOWNIKA)+"|"
                +adresaci[i].pobierzImie()+"|"+adresaci[i].pobierzNazwisko()+"|"+adresaci[i].pobierzNumerTelefonu()+"|"+adresaci[i].pobierzEmail()+"|"+adresaci[i].pobierzAdres()+"|";

                plikZAdresatami.edytujWybranegoAdresataZPliku(daneJednegoAdresataOddzielonePionowymiKreskami, noweDaneJednegoAdresataOddzielonePionowymiKreskami);

                break;
                }

            case '5':
                {
                    cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                 noweDaneJednegoAdresataOddzielonePionowymiKreskami= MetodyPomocnicze::konwerjsaIntNaString(idEdytowanegoAdresata)+"|"+MetodyPomocnicze::konwerjsaIntNaString(ID_ZALOGOWANEGO_UZYTKOWNIKA)+"|"
                +adresaci[i].pobierzImie()+"|"+adresaci[i].pobierzNazwisko()+"|"+adresaci[i].pobierzNumerTelefonu()+"|"+adresaci[i].pobierzEmail()+"|"+adresaci[i].pobierzAdres()+"|";

                plikZAdresatami.edytujWybranegoAdresataZPliku(daneJednegoAdresataOddzielonePionowymiKreskami, noweDaneJednegoAdresataOddzielonePionowymiKreskami);

                break;
                }

            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenager::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    cin >>wybor;

    return wybor;
}
