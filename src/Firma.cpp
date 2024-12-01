#include "Firma.hpp"

void Firma::zatrudnij_inzyniera(string imie, string wydzial)
{
    pracownicy.push_back(make_unique< Inzynier >(imie, wydzial));
}

void Firma::zatrudnij_magazyniera(string imie, bool uprawnienia)
{
    pracownicy.push_back(make_unique< Magazynier >(imie, uprawnienia));
}

void Firma::zatrudnij_marketer(string imie, int obserwujacy)
{
    pracownicy.push_back(make_unique< Marketer >(imie, obserwujacy));
}

void Firma::zatrudnij_robotnika(string imie, double roz_buta)
{
    pracownicy.push_back(make_unique< Robotnik >(imie, roz_buta));
}

double Firma::oblicz_przychod()
{
    int pojemnosc_magazynu = Magazynier::get_liczba_magazynierow() * CMag;
    int popyt              = Marketer::get_liczba_marketerow() * CMkt;
    int produkcja          = Robotnik::get_liczba_robotnikow() * CR;
    int sprzedane_produkty = min({pojemnosc_magazynu, produkcja, popyt});
    int cena_produktu      = Inzynier::get_liczba_inzynierow() * CI;

    double przychod = sprzedane_produkty * cena_produktu;
    calkowity_przychod += przychod;
    return przychod;
}

void Firma::oblicz_wartosc_spolki()
{
    if (miesiac > 0)
    {
        wartosc_spolki = calkowity_przychod / miesiac;
    }
}

void Firma::wyplac_wynagrodzenia()
{
    double suma_wynagrodzen = 0;
    for (const auto& pracownik : pracownicy)
    {
        suma_wynagrodzen += pracownik->get_wynagrodzenie();
    }
    stan_konta -= suma_wynagrodzen;
}

void Firma::nowy_miesiac()
{
    miesiac++;
    double przychod = oblicz_przychod();
    stan_konta += przychod;
    wyplac_wynagrodzenia();
    oblicz_wartosc_spolki();
    splac_raty();
}

void Firma::wyswietl_stan_firmy() const
{
    cout << "Stan konta: " << stan_konta << ", Wartosc spolki: " << wartosc_spolki << ", Miesiac: " << miesiac << endl;
}

void Firma::wyswietl_pracownikow() const
{
    for (const auto& pracownik : pracownicy)
    {
        pracownik->print_dane();
    }
}

bool Firma::czy_bankructwo() const
{
    return stan_konta < 0;
}

bool Firma::czy_wygrana() const
{
    return stan_konta >= 1000000;
}

void Firma::zaciagnij_kredyt(double kwota, int czas_splaty)
{
    if (wartosc_spolki * MAX_WSPOLCZYNNIK_DLUGU < stan_konta + kwota)
    {
        cout << "Nie mozna zaciagnac kredytu. Zadluzenie przekracza dopuszczalny limit!" << endl;
        return;
    }

    try
    {
        Kredyt nowy_kredyt(kwota, czas_splaty);
        kredyty.push_back(nowy_kredyt);
        stan_konta += kwota;
        cout << "Kredyt zaciagniety: " << kwota << " PLN na " << czas_splaty << " miesiecy." << endl;
    }
    catch (const exception& e)
    {
        cout << "Blad: " << e.what() << endl;
    }
}

void Firma::splac_raty()
{
    for (auto it = kredyty.begin(); it != kredyty.end();)
    {
        stan_konta -= it->get_miesieczna_rata();
        it->get_czas_splaty();
        if (it->get_czas_splaty() <= 0)
        {
            it = kredyty.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
