#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa(int x, int y, Swiat* swiat) : Roslina(0, 0, x, y, swiat, Kolory::ZIELONY_JASNY, Znaki::TRAWA) {
	swiat->dodajOrganizm(this);
}

Trawa::Trawa(Swiat* swiat) : Roslina(0, 0, x, y, swiat, Kolory::ZIELONY_JASNY, Znaki::TRAWA) {
	swiat->dodajOrganizm(this);
}

Trawa::~Trawa() {}

Organizm* Trawa::utworzDziecko(int x, int y) {
	return new Trawa(x, y, &swiat);
}

void Trawa::wypisz() {
	std::cout << "Trawa";
}

std::string Trawa::nazwa() {
	return "Trawa";
}
