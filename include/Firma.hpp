#ifndef FIRMA_HPP
#define FIRMA_HPP

#include "Kredyt.hpp"
#include "Pracownik.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

const int    CI                     = 50;
const int    CMag                   = 100;
const int    CMkt                   = 150;
const int    CR                     = 200;
const double MAX_WSPOLCZYNNIK_DLUGU = 3.0;

class Firma
{
private:
    vector< unique_ptr< Pracownik > > pracownicy;
    vector< Kredyt >                  kredyty;
    double                            stan_konta         = 100000;
    double                            wartosc_spolki     = 0;
    int                               miesiac            = 0;
    double                            calkowity_przychod = 0;

public:
    void   zatrudnij_inzyniera(string imie, string wydzial);
    void   zatrudnij_magazyniera(string imie, bool uprawnienia);
    void   zatrudnij_marketer(string imie, int obserwujacy);
    void   zatrudnij_robotnika(string imie, double roz_buta);
    double oblicz_przychod();
    void   oblicz_wartosc_spolki();
    void   wyplac_wynagrodzenia();
    void   nowy_miesiac();
    void   wyswietl_stan_firmy() const;
    void   wyswietl_pracownikow() const;
    bool   czy_bankructwo() const;
    bool   czy_wygrana() const;
    void   zaciagnij_kredyt(double kwota, int czas_splaty);
    void   splac_raty();
};

#endif
