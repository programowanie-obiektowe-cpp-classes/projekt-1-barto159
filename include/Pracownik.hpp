#ifndef PRACOWNIK_HPP
#define PRACOWNIK_HPP

#include <iostream>
#include <string>
using namespace std;

class Pracownik
{
protected:
    string imie;
    double wynagrodzenie;

public:
    Pracownik(string im, double w) : imie(im), wynagrodzenie(w) {}
    virtual void print_dane() const = 0;
    virtual ~Pracownik()            = default;

    double get_wynagrodzenie() const { return wynagrodzenie; }
    string get_imie() const { return imie; }
};

class Inzynier : public Pracownik
{
private:
    string     wydzial;
    static int liczba_inzynierow;

public:
    Inzynier(string im, string wydz);
    void       print_dane() const override;
    static int get_liczba_inzynierow();
    ~Inzynier();
};

class Magazynier : public Pracownik
{
private:
    bool       uprawnienia;
    static int liczba_magazynierow;

public:
    Magazynier(string im, bool uprawnienia_na_wozki);
    void       print_dane() const override;
    static int get_liczba_magazynierow();
    ~Magazynier();
};

class Marketer : public Pracownik
{
private:
    int        obserwujacy;
    static int liczba_marketerow;

public:
    Marketer(string im, int obser);
    void       print_dane() const override;
    static int get_liczba_marketerow();
    ~Marketer();
};

class Robotnik : public Pracownik
{
private:
    double     roz_buta;
    static int liczba_robotnikow;

public:
    Robotnik(string im, double but);
    void       print_dane() const override;
    static int get_liczba_robotnikow();
    ~Robotnik();
};

#endif
