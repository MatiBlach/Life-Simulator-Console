#include "Organizm.h"
#include "Swiat.h"
#include "Czlowiek.h"

Organizm::Organizm(int sila, int inicjatywa, int x, int y, Swiat* swiat, int kolor, char symbol)
    : sila(sila), inicjatywa(inicjatywa), x(x), y(y), swiat(*swiat), kolor(kolor), symbol(symbol) {}

Organizm::~Organizm() {}

int Organizm::getSila() const {
    return sila;
}

int Organizm::getInicjatywa() const {
    return inicjatywa;
}

int Organizm::getWiek() const {
    return wiek;
}

int Organizm::getX() const {
    return x;
}

int Organizm::getY() const {
    return y;
}

void Organizm::setX(int x) {
    this->x = x;
}

void Organizm::setY(int y) {
    this->y = y;
}

void Organizm::setKolor(int kolor) {
    this->kolor = kolor;
}

void Organizm::zwiekszWiek() {
    this->wiek++;
}

Swiat& Organizm::getSwiat() const {
    return swiat;
}

int Organizm::getKolor() const {
    return kolor;
}

char Organizm::getSymbol() const {
    return symbol;
}
 
bool Organizm::getAkcja() const {
    return czyWykonanoAkcje;
}

void Organizm::setAkcja(bool value) {
    czyWykonanoAkcje = value;
}

void Organizm::zabij() {
    czyZywy = false;
}

bool Organizm::czyZyje() const {
    return this->czyZywy;
}

void Organizm::kolizja(Organizm* atakujacy)
{
    if (sila >= atakujacy->getSila()) {
        swiat.przeniesOrganizm(this, atakujacy->getX(), atakujacy->getY());
        atakujacy->zabij();

    }
    else {
        this->zabij();
    }
}

bool Organizm::czySilniejszy(Organizm* org) const {
    return this->getSila() > org->getSila();
}

bool Organizm::czyOdbilAtak(Organizm* atakujacy) const {
    return false;
}

void Organizm::setSila(int sila) {
    this->sila = sila;
}

void Organizm::zabijWokol() {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue; 
            }
            Organizm* org = swiat.getOrganizm(i, j);
            if (org != nullptr) {
                org->zabij();
            }
        }
    }
}

std::pair<int, int> Organizm::losujWspolrzedne(int x, int y) {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    int newX = x + dx;
    int newY = y + dy;
    return std::make_pair(newX, newY);
}
