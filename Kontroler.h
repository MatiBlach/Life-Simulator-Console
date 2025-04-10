#pragma once
#ifndef Kontroler_h
#define Kontroler_h

#include <conio.h>

class Czlowiek;
class Swiat;

class Kontroler {
private:
    Swiat* swiat;
    Czlowiek* gracz; 

public:
    Kontroler(Swiat* s, Czlowiek* g);

    void obslugaKlawiatury();
};

#endif
