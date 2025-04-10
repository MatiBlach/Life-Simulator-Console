#ifndef Wilk_h
#define Wilk_h

#include "Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(int x, int y, Swiat* swiat);
    Wilk(Swiat* swiat);
    ~Wilk();


    Organizm* utworzDziecko(int x, int y) override;

    void wypisz() override;
    std::string nazwa() override;
};

#endif