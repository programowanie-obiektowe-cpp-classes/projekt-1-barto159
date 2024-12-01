#include "Firma.hpp"

int main()
{
    Firma firma;

    firma.zatrudnij_inzyniera("Jan", "IT");
    firma.zatrudnij_magazyniera("Anna", true);
    firma.zatrudnij_marketer("Kamil", 100);
    firma.zatrudnij_robotnika("Piotr", 42);
    cout << "Witamy w grze zarzadzania firma!" << endl;
    firma.wyswietl_stan_firmy();
    cout << "\nKomendy:\n"
         << "lp - Wylistuj pracownikow\n"
         << "zinz - Zatrudnij inzyniera\n"
         << "zmag - Zatrudnij magazyniera\n"
         << "zmkt - Zatrudnij marketera\n"
         << "zrob - Zatrudnij robotnika\n"
         << "kred - Wez kredyt\n"
         << "kt - Zakoncz ture\n";

    while (1)
    {

        while (1)
        {
            cout << "Twoja komenda: ";

            string cmd;
            cin >> cmd;
            if (cmd == "lp")
            {
                firma.wyswietl_pracownikow();
            }
            else if (cmd == "zinz")
            {
                string imie, wydzial;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj wydzial: ";
                cin >> wydzial;
                firma.zatrudnij_inzyniera(imie, wydzial);
            }
            else if (cmd == "zmag")
            {
                string imie;
                bool   uprawnienia;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Czy ma uprawnienia na wozki (1 - tak, 0 - nie): ";
                cin >> uprawnienia;
                firma.zatrudnij_magazyniera(imie, uprawnienia);
            }
            else if (cmd == "zmkt")
            {
                string imie;
                int    obserwujacy;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj liczbê obserwujacych: ";
                cin >> obserwujacy;
                firma.zatrudnij_marketer(imie, obserwujacy);
            }
            else if (cmd == "zrob")
            {
                string imie;
                double roz_buta;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj rozmiar buta: ";
                cin >> roz_buta;
                firma.zatrudnij_robotnika(imie, roz_buta);
            }
            else if (cmd == "kred")
            {
                double kwota;
                int    czas;
                cout << "Podaj kwote kredytu: ";
                cin >> kwota;
                cout << "Podaj czas splaty: ";
                cin >> czas;
                firma.zaciagnij_kredyt(kwota, czas);
            }
            else if (cmd == "kt")
            {
                break;
            }

            else
            {
                cout << "Nieznana komenda!" << endl;
            }
        }

        firma.nowy_miesiac();
        firma.wyswietl_stan_firmy();
        if (firma.czy_bankructwo())
        {
            cout << "Firma zbankrutowala!" << endl;
            break;
        }
        if (firma.czy_wygrana())
        {
            cout << "Wygrales!" << endl;
            break;
        }
    }
}