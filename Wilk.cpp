#include "Wilk.h"
#include "Swiat.h"


Wilk::Wilk(int x, int y, Swiat* swiat) : Zwierze(9, 5, x, y, swiat, Kolory::NIEBIESKI_JASNY, Znaki::WILK) {
    swiat->dodajOrganizm(this,x,y);
}

Wilk::Wilk(Swiat* swiat) : Zwierze(9, 5, x, y, swiat, Kolory::NIEBIESKI_JASNY, Znaki::WILK) {
    swiat->dodajOrganizm(this);
}

Wilk::~Wilk() {}

Organizm* Wilk::utworzDziecko(int x, int y) {
    return new Wilk(x, y, &swiat);
}

void Wilk::wypisz() {
    std::cout << "Wilk";
}

std::string Wilk::nazwa() {
    return "Wilk";
}