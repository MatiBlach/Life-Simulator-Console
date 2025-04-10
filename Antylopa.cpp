#include "Antylopa.h"
#include "Swiat.h"
#include "Roslina.h"


Antylopa::Antylopa(int x, int y, Swiat* swiat) : Zwierze(4, 4, x, y, swiat, Kolory::BRAZOWY, Znaki::ANTYLOPA) {
    swiat->dodajOrganizm(this, x, y);
}

Antylopa::Antylopa(Swiat* swiat) : Zwierze(4, 4, x, y, swiat, Kolory::BRAZOWY, Znaki::ANTYLOPA) {
    swiat->dodajOrganizm(this);
}

Antylopa::~Antylopa() {}

void Antylopa::akcja() {
    for (int i = 0; i < 2; i++) {
        Zwierze::akcja();
        swiat.aktualizujPlansze();
    }
}

void Antylopa::kolizja(Organizm* atakowany) {
    if (dynamic_cast<Roslina*>(atakowany) != nullptr) {
        Roslina* roslina = dynamic_cast<Roslina*>(atakowany);
        roslina->zjedz(this);
    }
    else {
        if (typeid(*this) == typeid(*atakowany) && this != atakowany) {
            rozmnazanie(atakowany);
        }
        else {
            if (rand() % 2 == 0) {
                Zwierze::walka(atakowany);
            }
            else {
                int newX, newY;
                std::pair<int, int> newXY = losujWspolrzedne(x, y);
                newX = newXY.first;
                newY = newXY.second;

                if (swiat.czyNaPlanszy(newX, newY) && swiat.czyPuste(newX, newY))
                    swiat.przeniesOrganizm(this, newX, newY);
            }
        }
    }
}

Organizm* Antylopa::utworzDziecko(int x, int y) {
    return new Antylopa(x, y, &swiat);
}

void Antylopa::wypisz() {
    std::cout << "Antylopa";
}
std::string Antylopa::nazwa() {
    return "Antylopa";
}