#pragma once
#ifndef Czlowiek_h
#define Czlowiek_h

class Zwierze;
class Swiat;

#include "Zwierze.h"
#include "Swiat.h"

class Czlowiek : public Zwierze {
private:
    int zaIleUmiejetnosc = 0;
    int czasTrwaniaUmiejetnosci = 5;
    bool czyUmiejetnoscAktywna = false;
public:
    Czlowiek(int x, int y, Swiat* swiat);
    ~Czlowiek();

    void akcja() override;
    void akcja(int x, int y);

    void kolizja(Organizm* atakowany) override;
    Zwierze* utworzDziecko(int x, int y) override;
    void rysowanie();
    void rozmnazanie(Organizm* partner) override;
    void aktualizujUmiejetnosc();

    void aktywujUmiejetnosc();
    bool getUmiejetnosc() const;
    void wypisz() override;
    std::string nazwa() override;
};

#endif