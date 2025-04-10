#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(int x, int y, Swiat* swiat) : Roslina(0, 0, x, y, swiat, Kolory::CZERWONY_JASNY, Znaki::GUARANA) {
	swiat->dodajOrganizm(this);
}

Guarana::Guarana(Swiat* swiat) : Roslina(0, 0, x, y, swiat, Kolory::CZERWONY_JASNY, Znaki::GUARANA) {
	swiat->dodajOrganizm(this);
}

Guarana::~Guarana() {}

void Guarana::zjedz(Organizm* zwierze) {
	zwierze->setSila(zwierze->getSila() + 3);
	Roslina::zjedz(zwierze);
}

Organizm* Guarana::utworzDziecko(int x, int y) {
	return new Guarana(x, y, &swiat);
}

void Guarana::wypisz() {
	std::cout << "Guarana";
}

std::string Guarana::nazwa() {
	return "Guarana";
}