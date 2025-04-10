#ifndef Owca_h
#define Owca_h

#include "Zwierze.h"

class Owca : public Zwierze {
public:
    Owca(int x, int y, Swiat* swiat);
    Owca(Swiat* swiat);
    ~Owca();


    Organizm* utworzDziecko(int x, int y) override;
    void wypisz() override;
    std::string nazwa() override;
};

#endif