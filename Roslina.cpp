#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(int sila, int inicjatywa, int x, int y, Swiat* swiat, int kolor, char symbol)
    : Organizm(sila, inicjatywa, x, y, swiat, kolor, symbol) {}

Roslina::~Roslina() {}

void Roslina::akcja() {
    int szansa_rozmnozenia = 5;
    int losowa_liczba = rand() % 100;
    if (losowa_liczba < szansa_rozmnozenia) { // rozmna¿anie siê roœliny
        int x, y, i = 0;
        bool znaleziono_wolne_pole = false;
        while (!znaleziono_wolne_pole && i < 8) {
            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;
            x = getX() + dx;
            y = getY() + dy;
            i++;
            if (swiat.czyNaPlanszy(x, y) && swiat.czyPuste(x, y)) {
                znaleziono_wolne_pole = true;
            }
        }
        if (znaleziono_wolne_pole) { // znaleziono wolne s¹siednie pole
            utworzDziecko(x, y);
        }
    }
    swiat.aktualizujPlansze();
}

void Roslina::kolizja(Organizm* atakowany) {
}

void Roslina::rysowanie() {
   
}

void Roslina::zjedz(Organizm* zwierze) {
    swiat.przeniesOrganizm(zwierze,this->getX(), this->getY());
    this->zabij();
    swiat.setKomunikat(swiat.getInterfejs()->wypiszKomunikat(zwierze, this, swiat.getKomunikat()));
}
