#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include "Zwierze.h"
#include "Czlowiek.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat* swiat) : Roslina(10, 0, x, y, swiat, Kolory::ZIELONY_JASNY, Znaki::BARSZCZ_SOSNOWSKIEGO) {
	swiat->dodajOrganizm(this);
}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat) : Roslina(10, 0, x, y, swiat, Kolory::ZIELONY_JASNY, Znaki::BARSZCZ_SOSNOWSKIEGO) {
	swiat->dodajOrganizm(this);
}

BarszczSosnowskiego::~BarszczSosnowskiego() {}

void BarszczSosnowskiego::zjedz(Organizm* zwierze) {
	zwierze->zabij();
	Roslina::zjedz(zwierze);
}

void BarszczSosnowskiego::akcja() {
	zabijWokol();
	Roslina::akcja();
}

void BarszczSosnowskiego::zabijWokol() {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue; 
            }
            Organizm* org = swiat.getOrganizm(i, j);
            if (dynamic_cast<Zwierze*>(org) != nullptr) {
    
                if (dynamic_cast<Czlowiek*>(org) != nullptr) {
                    Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(org);
                    if (!czlowiek->getUmiejetnosc()) 
                        czlowiek->zabij();
                    return;
               
                }

                org->zabij();
            }
        }
    }
}

Organizm* BarszczSosnowskiego::utworzDziecko(int x, int y) {
	return new BarszczSosnowskiego(x, y, &swiat);
}
void BarszczSosnowskiego::wypisz() {
    std::cout << "Barszcz Sosnowskiego";
}
std::string BarszczSosnowskiego::nazwa() {
    return "BarszczSosnowskiego";
}
