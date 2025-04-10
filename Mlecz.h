#ifndef Mlecz_h
#define Mlecz_h

#include "Roslina.h"

class Mlecz : public Roslina {
public:
	Mlecz(int x, int y, Swiat* swiat);
	Mlecz(Swiat* swiat);
	~Mlecz();

	Organizm* utworzDziecko(int x, int y) override;
	void akcja() override;
	void wypisz() override;
	std::string nazwa() override;
};

#endif