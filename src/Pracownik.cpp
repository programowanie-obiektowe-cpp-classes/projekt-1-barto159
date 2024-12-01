#include "Pracownik.hpp"

int Inzynier::liczba_inzynierow     = 0;
int Magazynier::liczba_magazynierow = 0;
int Marketer::liczba_marketerow     = 0;
int Robotnik::liczba_robotnikow     = 0;

Inzynier::Inzynier(string im, string wydz) : Pracownik(im, 10000), wydzial(wydz)
{
    liczba_inzynierow++;
}

void Inzynier::print_dane() const
{
    cout << "Inzynier: " << imie << ", Wydzial: " << wydzial << ", Wynagrodzenie: " << wynagrodzenie << endl;
}

int Inzynier::get_liczba_inzynierow()
{
    return liczba_inzynierow;
}

Inzynier::~Inzynier()
{
    liczba_inzynierow--;
}

Magazynier::Magazynier(string im, bool uprawnienia_na_wozki) : Pracownik(im, 6000), uprawnienia(uprawnienia_na_wozki)
{
    liczba_magazynierow++;
}

void Magazynier::print_dane() const
{
    cout << "Magazynier: " << imie << ", Uprawnienia na wozki: " << (uprawnienia ? "Tak" : "Nie")
         << ", Wynagrodzenie: " << wynagrodzenie << endl;
}

int Magazynier::get_liczba_magazynierow()
{
    return liczba_magazynierow;
}

Magazynier::~Magazynier()
{
    liczba_magazynierow--;
}

Marketer::Marketer(string im, int obser) : Pracownik(im, 8000), obserwujacy(obser)
{
    liczba_marketerow++;
}

void Marketer::print_dane() const
{
    cout << "Marketer: " << imie << ", Obserwujacy: " << obserwujacy << ", Wynagrodzenie: " << wynagrodzenie << endl;
}

int Marketer::get_liczba_marketerow()
{
    return liczba_marketerow;
}

Marketer::~Marketer()
{
    liczba_marketerow--;
}

Robotnik::Robotnik(string im, double but) : Pracownik(im, 5000), roz_buta(but)
{
    liczba_robotnikow++;
}

void Robotnik::print_dane() const
{
    cout << "Robotnik: " << imie << ", Rozmiar buta: " << roz_buta << ", Wynagrodzenie: " << wynagrodzenie << endl;
}

int Robotnik::get_liczba_robotnikow()
{
    return liczba_robotnikow;
}

Robotnik::~Robotnik()
{
    liczba_robotnikow--;
}
