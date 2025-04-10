#ifndef Interfejs_h
#define Interfejs_h

#include <windows.h>
#include <iostream>
#include <string.h>
#include "Znaki.h"
#include "Kolory.h"

class Organizm;


class Interfejs {
private:
	std::string autor = "Mateusz Blach _193174";
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int KOLOR_INTERFEJSU = Kolory::SZARY_CIEMNY;
	COORD position;
	Znaki znaki;
	int szerokosc;
	int wysokosc;
	
	int startPosX = 3;
	int startPosY = 1;

public:
	Interfejs(int szerokosc, int wysokosc);
	void ustawKolor(int kolor);
	void rysujRamke(int szerokoscRamki, int wysokoscRamki, int startX, int startY);
	void rysujMape();
	void rysujInterfejs();
	void rysujAutor(int startX, int startY);
	void rysujOrganizm(Organizm* o);
	void rysujUmiejetnosc(int x, int y);
	HANDLE getHandle() const;
	COORD getPosition() const;
	void setPosition(int x, int y);
	int wypiszKomunikat(Organizm* a, Organizm* b, int i);
	int wypiszUmiejetnosc(Organizm* gracz, int i);
	void wypiszZgon(int i);
	int wyczyscKomunikaty();
	int getStartPosX() const;
	int getStartPosY() const;



};

#endif