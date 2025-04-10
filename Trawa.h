#ifndef Trawa_h
#define Trawa_h

#include "Roslina.h"

class Trawa : public Roslina {
public:
	Trawa(int x, int y, Swiat* swiat);
	Trawa(Swiat* swiat);
	~Trawa();

	Organizm* utworzDziecko(int x, int y) override;
	void wypisz() override;
	std::string nazwa() override;
};

#endif