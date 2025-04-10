#include "WilczeJagody.h"
#include "Swiat.h"

WilczeJagody::WilczeJagody(int x, int y, Swiat* swiat) : Roslina(99, 0, x, y, swiat, Kolory::CYJAN_JASNY, Znaki::WILCZE_JAGODY) {
	swiat->dodajOrganizm(this);
}

WilczeJagody::WilczeJagody(Swiat* swiat) : Roslina(99, 0, x, y, swiat, Kolory::CYJAN_JASNY, Znaki::WILCZE_JAGODY) {
	swiat->dodajOrganizm(this);
}

WilczeJagody::~WilczeJagody() {}

void WilczeJagody::zjedz(Organizm* zwierze) {
	zwierze->zabij();
	Roslina::zjedz(zwierze);
}

void WilczeJagody::wypisz() {
	std::cout << "Wilcze Jagody";
}

Organizm* WilczeJagody::utworzDziecko(int x, int y) {
	return new WilczeJagody(x, y, &swiat);
}

std::string WilczeJagody::nazwa() {
	return "WilczeJagody";
}

