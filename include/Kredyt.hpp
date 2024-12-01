#ifndef KREDYT_HPP
#define KREDYT_HPP

#include <stdexcept>
using namespace std;

class Kredyt
{
private:
    double kwota;
    double odsetki;
    int    czas_splaty;
    double miesieczna_rata;

public:
    Kredyt(double kwota_kredytu, int czas);

    double get_miesieczna_rata() const;
    double get_kwota() const;
    int    get_czas_splaty() const;
};

#endif
