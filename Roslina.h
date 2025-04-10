#ifndef Roslina_h
#define Roslina_h

#include "Organizm.h"

class Swiat;

class Roslina : public Organizm {
public:
    Roslina(int sila, int inicjatywa, int x, int y, Swiat* swiat, int kolor, char symbol);
    virtual ~Roslina();

    virtual void akcja() override;
    virtual void kolizja(Organizm* atakowany) override;
    virtual void rysowanie() override;
    virtual void zjedz(Organizm* zwierze);
    virtual void wypisz() = 0;
    virtual std::string nazwa() = 0;
};

#endif