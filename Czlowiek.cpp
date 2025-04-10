#include "Czlowiek.h"
#include "Roslina.h"
#include "interfejs.h"

Czlowiek::Czlowiek(int x, int y, Swiat* swiat) :
    Zwierze(5, 4, x, y, swiat, Kolory::CYJAN, Znaki::GRACZ) {
    
}

Czlowiek::~Czlowiek() {
    
}

void Czlowiek::akcja() {
}

void Czlowiek::akcja(int x, int y) {
    if (swiat.czyNaPlanszy(x, y)) {
        if (swiat.czyPuste(x, y)) {
            swiat.przeniesOrganizm(this, x, y);
        }
        else {
            if(swiat.getOrganizm(x, y) != nullptr)
                kolizja(swiat.getOrganizm(x,y));
        }
    }
}

void Czlowiek::kolizja(Organizm* atakowany) {
    if (dynamic_cast<Roslina*>(atakowany) != nullptr) {
        Roslina* roslina = dynamic_cast<Roslina*>(atakowany);
        roslina->zjedz(this);
    }
    else if(atakowany != nullptr) {
        if (sila >= atakowany->getSila()) {
            swiat.przeniesOrganizm(this, atakowany->getX(), atakowany->getY());
            atakowany->zabij();

        }
        else {
            if (!this->getUmiejetnosc()) {
                this->zabij();
            }
            else {
                swiat.przeniesOrganizm(this, atakowany->getX(), atakowany->getY());
                atakowany->zabij();
            }
        }
    }
}

void Czlowiek::aktywujUmiejetnosc() {
  
    if (czyUmiejetnoscAktywna) {
        int x = getX();
        int y = getY();
        zabijWokol();
    }
    if (zaIleUmiejetnosc == 0) {
        czyUmiejetnoscAktywna = true;

    }

}

void Czlowiek::aktualizujUmiejetnosc() {

    if (czyUmiejetnoscAktywna && zaIleUmiejetnosc == 0 && czasTrwaniaUmiejetnosci > 0) {
        aktywujUmiejetnosc();
        swiat.setKomunikat(swiat.getInterfejs()->wypiszUmiejetnosc(this,swiat.getKomunikat())
        );
    }

    if (czyUmiejetnoscAktywna) {
        czasTrwaniaUmiejetnosci--;
        if (czasTrwaniaUmiejetnosci < 0) {
            czyUmiejetnoscAktywna = false; 
            zaIleUmiejetnosc = 4;
            czasTrwaniaUmiejetnosci = 5;
        }
    }
    else {
        if(zaIleUmiejetnosc > 0)
        zaIleUmiejetnosc--;
    }
}

bool Czlowiek::getUmiejetnosc() const {
    return czyUmiejetnoscAktywna;
}


Zwierze* Czlowiek::utworzDziecko(int x, int y)
{ 
    return NULL;
}

void Czlowiek::rozmnazanie(Organizm* partner) {}

void Czlowiek::rysowanie() {}

void Czlowiek::wypisz() {
    std::cout << "Gracz";
}

std::string Czlowiek::nazwa() {
    return "Czlowiek";
}