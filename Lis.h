#ifndef Lis_h
#define Lis_h

#include "Zwierze.h"

class Lis : public Zwierze {
public:
    Lis(int x, int y, Swiat* swiat);
    Lis(Swiat* swiat);
    ~Lis();

    void akcja() override;

    Organizm* utworzDziecko(int x, int y) override;
    void wypisz() override;
    std::string nazwa() override;
};

#endif