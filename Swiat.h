#pragma once
#ifndef Swiat_h
#define Swiat_h

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <windows.h>
#include "Interfejs.h"
#include "Kontroler.h"

class Organizm;
class Czlowiek;

class Swiat {
private:
    int szerokosc;
    int wysokosc;
    Czlowiek* gracz;
    std::vector<Organizm*> organizmy;
    Organizm*** plansza;
    Interfejs* interfejs;
    Kontroler* kontroler;
    bool graczZyje;
    int komunikat;

public:
    Swiat(int szerokosc, int wysokosc);

    Swiat(int szerokosc, int wysokosc, int x, int y);

    ~Swiat();

    Organizm* getOrganizm(int x, int y) const;

    void setOrganizm(int x, int y, Organizm* organizm);

    void setGracz(int x, int y);

    int getGraczX() const;

    int getGraczY() const;

    void symuluj();

    void wykonajTure();
    
    void rysujSwiat();
        
    void dodajOrganizm(Organizm* o);

    void dodajOrganizm(Organizm* o, int x, int y);

    void usunOrganizm(Organizm* o);

    void usunMartweOrganizmy();

    void przeniesOrganizm(Organizm* org, int newX, int newY);

    bool czyNaPlanszy(int x, int y) const;

    bool czyPuste(int x, int y);

    bool czyPelny() const;

    bool czyPoleZajete(int x, int y) const;

    bool getGraczZyje() const;

    Interfejs* getInterfejs() const;

    void setGraczZyje(bool value);

    bool porownaj(const Organizm* a, const Organizm* b) const;

    int ileOrganizmow() const;

    void sortujOrganizmy(std::vector<Organizm*>& organizmy); \

    void aktualizujPlansze();

    int getKomunikat() const;

    void setKomunikat(int i);

    void zapisz() const;

    Swiat* wczytaj();

    Czlowiek* getGracz() const;

    void zwolnijPamiec();


};

#endif