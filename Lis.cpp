#include "Lis.h"
#include "Swiat.h"


Lis::Lis(int x, int y, Swiat* swiat) : Zwierze(3, 7, x, y, swiat, Kolory::CZERWONY_JASNY, Znaki::LIS) {
    swiat->dodajOrganizm(this, x, y);
}

Lis::Lis(Swiat* swiat) : Zwierze(3, 7, x, y, swiat, Kolory::CZERWONY_JASNY, Znaki::LIS) {
    swiat->dodajOrganizm(this);
}

Lis::~Lis() {}

void Lis::akcja() {
    if (czyZyje() && !getAkcja()) {
        int newX, newY, i = 0;
        do {
            std::pair<int, int> newXY = losujWspolrzedne(x, y);
            newX = newXY.first;
            newY = newXY.second;
            i++;
        } while (!swiat.czyNaPlanszy(newX, newY) && i < 16 || newX == getX() && newY == getY() && i < 16);

        if (swiat.czyNaPlanszy(newX, newY)) {

            if (swiat.czyPuste(newX, newY)) {
                // Przemieszczenie na puste pole
                swiat.przeniesOrganizm(this, newX, newY);
            }
            else {
                if (this != swiat.getOrganizm(newX, newY) && swiat.getOrganizm(newX, newY) != nullptr
                    && !swiat.getOrganizm(newX, newY)->czySilniejszy(this))
                    kolizja(swiat.getOrganizm(newX, newY));
            }
        }
    }
    setAkcja(false);
}

Organizm* Lis::utworzDziecko(int x, int y) {
    return new Lis(x, y, &swiat);
}

void Lis::wypisz() {
    std::cout << "Lis";
}

std::string Lis::nazwa() {
    return "Lis";
}