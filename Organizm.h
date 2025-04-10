#pragma once
#ifndef Organizm_h
#define Organizm_h

#include <algorithm>
#include <vector>
#include <string>
#include <typeinfo>
#include "Kolory.h"
#include "Znaki.h"

class Swiat;

class Organizm {
protected:
    int sila;
    int inicjatywa;
    int wiek = 0;
    int x;
    int y;
    Swiat& swiat;
    int kolor = Kolory::BIALY;
    char symbol = ' ';
    bool czyWykonanoAkcje = false;
    bool czyZywy = true;
public:
    Organizm(int sila, int inicjatywa, int x, int y, Swiat* swiat, int kolor, char symbol);
    virtual ~Organizm();

    virtual void akcja() = 0;
    virtual void kolizja(Organizm* atakowany) = 0;
    virtual void rysowanie() = 0;
    virtual Organizm* utworzDziecko(int x, int y) = 0;

    int getWiek() const;
    int getSila() const;
    int getInicjatywa() const;
    int getX() const;
    int getY() const;
    int getKolor() const;
    char getSymbol() const;
    void setX(int x);
    void setY(int y);
    void setKolor(int kolor);
    void setSila(int sila);
    void zwiekszWiek();
    bool getAkcja() const;
    void setAkcja(bool value);
    void zabij();
    bool czyZyje() const;
    bool czySilniejszy(Organizm* org) const;
    virtual bool czyOdbilAtak(Organizm* atakujacy) const;
    virtual void zabijWokol();
    virtual std::pair<int, int> losujWspolrzedne(int x, int y);
    virtual void wypisz() = 0;
    virtual std::string nazwa() = 0;

    Swiat& getSwiat() const;


};

#endif