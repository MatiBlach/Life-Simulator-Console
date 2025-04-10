#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(int x, int y, Swiat* swiat) : Roslina(0, 0, x, y, swiat, Kolory::ZOLTY, Znaki::MLECZ) {
	swiat->dodajOrganizm(this);
}

Mlecz::Mlecz(Swiat* swiat) : Roslina(0, 0, x, y, swiat, Kolory::ZOLTY, Znaki::MLECZ) {
	swiat->dodajOrganizm(this);
}

Mlecz::~Mlecz() {}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		Roslina::akcja();
	}
}

Organizm* Mlecz::utworzDziecko(int x, int y) {
	return new Mlecz(x, y, &swiat);
}

void Mlecz::wypisz() {
	std::cout << "Mlecz";
}
std::string Mlecz::nazwa() {
	return "Mlecz";
}