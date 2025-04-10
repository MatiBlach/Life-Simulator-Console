#ifndef Guarana_h
#define Guarana_h

#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(int x, int y, Swiat* swiat);
	Guarana(Swiat* swiat);
	~Guarana();

	void zjedz(Organizm* zwierze) override;

	Organizm* utworzDziecko(int x, int y) override;
	void wypisz() override;
	std::string nazwa() override;
};

#endif