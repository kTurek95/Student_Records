#include <iostream>
#include <vector>
using namespace std;

class documents {
public:
    int id;
    string imie;
    char plec;
    int wynik;

    void dodaj_wpis();
    void usun_wpis();
    void aktualizuj_wpis();
    void wyswietl_wszystkie_pliki();
    double oblicz_srednia_wynikow_wybranego_studenta();
    void wyswietl_srednia_wynikow_wybranego_studenta();
    double oblicz_i_wyswietl_srednia_wszystkich_studentow();
    void wyswietl_najepszy_i_najgorszy_wynik();

private:
    vector<documents> wpisy;
};


void documents::dodaj_wpis() {
    documents wpis;
    cout << "Podaj id ucznia: " << endl;
    cin >> wpis.id;
    cout << "Imię: " << endl;
    cin >> wpis.imie;
    cout << "Płeć (k/m): " << endl;
    cin >> wpis.plec;
    cout << "Wyniki z kolokwium: " << endl;
    cin >> wpis.wynik;

    this->wpisy.push_back(wpis);
}

void documents::usun_wpis() {
    int wpisId;

    cout << "Podaj id wpisu do usunięcia: ";
    cin >> wpisId;

    for (auto it = wpisy.begin(); it != wpisy.end(); ++it) {
        if (it->id == wpisId) {
            wpisy.erase(it);
            cout << "Wpis o ID " << wpisId << " został usunięty." << endl;
            return;
        }
    }
    cout << "Nie znaleziono wpisu o ID " << wpisId << "." << endl;
}


void documents::aktualizuj_wpis() {
    int wpisId;

    cout << "Podaj id wpisu do aktualizacji: ";
    cin >> wpisId;

    for (auto it = wpisy.begin(); it != wpisy.end(); ++it) {
        if (it->id == wpisId) {
            cout << "Aktualizacja wpisu o ID " << wpisId << ":" << endl;

            cout << "Nowe imię: ";
            cin >> it->imie;

            cout << "Nowa płeć (k/m): ";
            cin >> it->plec;

            cout << "Nowy wynik: ";
            cin >> it->wynik;

            cout << "Wpis o ID " << wpisId << " został zaktualizowany." << endl;
            return;
        }
    }
    cout << "Nie znaleziono wpisu o ID " << wpisId << "." << endl;
}


void documents::wyswietl_wszystkie_pliki() {
    if (wpisy.empty()) {
        cout << "Brak wpisow do wyswietlenia." << endl;
        return;
    }

    cout << "Wszystkie wpisy:" << endl;
    for (const auto& wpis : wpisy) {
        cout << "ID: " << wpis.id << endl;
        cout << "Imię: " << wpis.imie << endl;
        cout << "Płeć: " << wpis.plec << endl;
        cout << "Wynik: " << wpis.wynik << endl;
        cout << "---------------------" << endl;
    }
}


double documents::oblicz_srednia_wynikow_wybranego_studenta() {
    int wpisId;
    int sumaWynikow = 0;
    int liczbaWynikow = 0;

    cout << "Podaj ID studenta: ";
    cin >> wpisId;

    for (const auto& wpis : wpisy) {
        if (wpis.id == wpisId) {
            sumaWynikow += wpis.wynik;
            liczbaWynikow++;
        }
    }

    if (liczbaWynikow == 0) {
        cout << "Nie znaleziono studenta o podanym ID." << endl;
        return 0;
    }

    double srednia = static_cast<double>(sumaWynikow) / liczbaWynikow;
    return srednia;
}


void documents::wyswietl_srednia_wynikow_wybranego_studenta() {
    double srednia = oblicz_srednia_wynikow_wybranego_studenta();
    cout << "Średnia wyników wybranego studenta: " << srednia << endl;
}


double documents::oblicz_i_wyswietl_srednia_wszystkich_studentow() {
    if (wpisy.empty()) {
        cout << "Brak wpisów do obliczenia średniej." << endl;
        return 0;
    }

    int sumaWynikow = 0;
    int liczbaWynikow = 0;

    for (const auto& wpis : wpisy) {
        sumaWynikow += wpis.wynik;
        liczbaWynikow++;
    }

    double srednia = static_cast<double>(sumaWynikow) / liczbaWynikow;
    cout << "Średnia wyników wszystkich studentów: " << srednia << endl;
    return srednia;
}

void documents::wyswietl_najepszy_i_najgorszy_wynik() {
    if (wpisy.empty()) {
        cout << "Brak wpisów do wyświetlenia." << endl;
        return;
    }

    int najgorszyWynik = wpisy[0].wynik;
    int najlepszyWynik = wpisy[0].wynik;
    string imieNajgorszego = wpisy[0].imie;
    string imieNajlepszego = wpisy[0].imie;

    for (const auto& wpis : wpisy) {
        if (wpis.wynik < najgorszyWynik) {
            najgorszyWynik = wpis.wynik;
            imieNajgorszego = wpis.imie;
        }

        if (wpis.wynik > najlepszyWynik) {
            najlepszyWynik = wpis.wynik;
            imieNajlepszego = wpis.imie;
        }
    }

    cout << "Najlepszy wynik:" << endl;
    cout << "Imię: " << imieNajlepszego << endl;
    cout << "Wynik: " << najlepszyWynik << endl;

    cout << "Najgorszy wynik:" << endl;
    cout << "Imię: " << imieNajgorszego << endl;
    cout << "Wynik: " << najgorszyWynik << endl;
}



int main() {
    int choice;

    documents documents1;

    while (true) {

        cout << "MENU" << endl;
        cout << "1. Dodaj wpis" << endl;
        cout << "2. Usuń wpis" << endl;
        cout << "3. Aktualizuj wpis" << endl;
        cout << "4. Wyświetl wszystkie wpisy" << endl;
        cout << "5. Oblicz średnią wyników wybranego studenta" << endl;
        cout << "6. Wyświetl średnią wyników wybranego studenta" << endl;
        cout << "7. Oblicz i wyświetl średnią wszystkich studentów" << endl;
        cout << "8. Wyświetl najlepszy i najgorszy wynik (wraz z danymi studentów, którzy je osiągneli)." << endl;
        cout << "Wpisz swój wybór: ";
        cin >> choice;

        switch (choice) {
            case 1:
                documents1.dodaj_wpis();
                break;
            case 2:
                documents1.usun_wpis();
                break;
            case 3:
                documents1.aktualizuj_wpis();
                break;
            case 4:
                documents1.wyswietl_wszystkie_pliki();
                break;
            case 5:
                documents1.oblicz_srednia_wynikow_wybranego_studenta();
                break;
            case 6:
                documents1.wyswietl_srednia_wynikow_wybranego_studenta();
                break;
            case 7:
                documents1.oblicz_i_wyswietl_srednia_wszystkich_studentow();
                break;
            case 8:
                documents1.wyswietl_najepszy_i_najgorszy_wynik();
                break;
            default:
                cout << "Nieznana wartość" << endl;
                break;
        }

        if (choice == 9) {
            break;
        }


    }

    return 0;
}
