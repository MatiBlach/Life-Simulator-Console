#include "Owca.h"
#include "Swiat.h"


Owca::Owca(int x, int y, Swiat* swiat) : Zwierze(4, 4, x, y, swiat, Kolory::BIALY, Znaki::OWCA) {
    swiat->dodajOrganizm(this, x, y);
}

Owca::Owca(Swiat* swiat) : Zwierze(4, 4, x, y, swiat, Kolory::BIALY, Znaki::OWCA) {
    swiat->dodajOrganizm(this);
}

Owca::~Owca() {}

Organizm* Owca::utworzDziecko(int x, int y) {
    return new Owca(x, y, &swiat);
}

void Owca::wypisz() {
    std::cout << "Owca";
}
std::string Owca::nazwa() {
    return "Owca";
}
