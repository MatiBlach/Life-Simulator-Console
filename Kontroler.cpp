#include "Kontroler.h"
#include "Swiat.h"
#include "Czlowiek.h"

Kontroler::Kontroler(Swiat* s, Czlowiek* g) : swiat(s), gracz(g) {}

void Kontroler::obslugaKlawiatury() {
    char znak;
    bool wykonajTure = false;
    bool nowySwiat = false;
    while (swiat->getGraczZyje()) {
        znak = _getch(); 
        switch (znak) {
        case 'a':
        case 'A':
        case 75: // strza�ka w lewo
            if (swiat->czyNaPlanszy(gracz->getX() - 1, gracz->getY())) {
                gracz->akcja(gracz->getX() - 1, gracz->getY());
                wykonajTure = true;
            }
            
            break;
        case 'd':
        case 'D':
        case 77: // strza�ka w prawo
            if (swiat->czyNaPlanszy(gracz->getX() + 1, gracz->getY())) {
                gracz->akcja(gracz->getX() + 1, gracz->getY()); 
                wykonajTure = true;
            }
            
            break;
        case 'w':
        case 'W':
        case 72: // strza�ka w g�r�
            if (swiat->czyNaPlanszy(gracz->getX(), gracz->getY() - 1)) {
                gracz->akcja(gracz->getX(), gracz->getY() - 1); 
                wykonajTure = true;
            }

            break;
        case 's':
        case 'S':
        case 80: // strza�ka w d�
            if (swiat->czyNaPlanszy(gracz->getX(), gracz->getY() + 1)) {
                gracz->akcja(gracz->getX(), gracz->getY() + 1); 
                wykonajTure = true;
            }
  
            break;
        case 'f':
        case 'F': 
            gracz->aktywujUmiejetnosc();
            break;
        case 'O':
        case 'o':
            swiat->zapisz();
            break;
        case 'L':
        case 'l':
            swiat = swiat->wczytaj();
            gracz = swiat->getGracz();
            nowySwiat = true;
            break;
        default:
            continue;
        }
        if (wykonajTure) {
            swiat->wykonajTure(); 
            swiat->rysujSwiat(); 
            wykonajTure = false;
        }
        else if (nowySwiat) {
            swiat->rysujSwiat();
            nowySwiat = false;
        }
    }
}


