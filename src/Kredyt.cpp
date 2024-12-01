#include "Kredyt.hpp"

const int MAX_CZAS_SPLATY = 12;

Kredyt::Kredyt(double kwota_kredytu, int czas) : kwota(kwota_kredytu), czas_splaty(czas)
{
    if (czas_splaty > MAX_CZAS_SPLATY)
    {
        throw invalid_argument("Czas splaty przekracza maksymalny limit!");
    }
    odsetki         = 0.01 * czas_splaty * kwota;
    miesieczna_rata = (kwota + odsetki) / czas_splaty;
}

double Kredyt::get_miesieczna_rata() const
{
    return miesieczna_rata;
}

double Kredyt::get_kwota() const
{
    return kwota;
}

int Kredyt::get_czas_splaty() const
{
    return czas_splaty;
}
