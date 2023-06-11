#include <iostream>
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
    vector<documents> wpisy; // Kontener przechowujący wpisy
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

    this -> wpisy.push_back(wpis);

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

}

void documents::wyswietl_wszystkie_pliki() {

}

double documents::oblicz_srednia_wynikow_wybranego_studenta() {
    return 0;
}

void documents::wyswietl_srednia_wynikow_wybranego_studenta() {

}

double documents::oblicz_i_wyswietl_srednia_wszystkich_studentow() {
    return 0;
}

void documents::wyswietl_najepszy_i_najgorszy_wynik() {

}


int main() {
    int choice;

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

    documents documents1;

    switch (choice) {
        case 1:
            documents1.dodaj_wpis();
            break;
        case 2:
            documents1.usun_wpis();
            break;
        default:
            cout << "Nieznana wartość";
            break;
    }

    return 0;
}