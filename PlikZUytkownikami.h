#include <iostream>
#include <vector>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
using namespace std;

class PlikZUytkownikami
{
    string nazwaPlikuZUzytkownikami;
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    fstream plikTekstowy;
public:
    PlikZUytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);

};
