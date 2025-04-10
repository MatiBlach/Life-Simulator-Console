#ifndef WilczeJagody_h
#define WilczeJagody_h

#include "Roslina.h"

class WilczeJagody : public Roslina {
public:
	WilczeJagody(int x, int y, Swiat* swiat);
	WilczeJagody(Swiat* swiat);
	~WilczeJagody();

	void zjedz(Organizm* zwierze) override;

	Organizm* utworzDziecko(int x, int y) override;
	void wypisz() override;
	std::string nazwa() override;
};

#endif