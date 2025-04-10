#ifndef Antylopa_h
#define Antylopa_h

#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
    Antylopa(int x, int y, Swiat* swiat);
    Antylopa(Swiat* swiat);
    ~Antylopa();

    void akcja() override;
    void kolizja(Organizm* atakowany) override;

    Organizm* utworzDziecko(int x, int y) override;
    void wypisz();
    std::string nazwa() override;
};

#endif