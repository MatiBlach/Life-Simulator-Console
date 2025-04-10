#ifndef BarszczSosnowskiego_h
#define BarszczSosnowskiego_h

#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(int x, int y, Swiat* swiat);
	BarszczSosnowskiego(Swiat* swiat);
	~BarszczSosnowskiego();

	void akcja() override;

	void zjedz(Organizm* zwierze) override;

	void zabijWokol() override;

	Organizm* utworzDziecko(int x, int y) override;

	void wypisz();
	std::string nazwa() override;
};

#endif