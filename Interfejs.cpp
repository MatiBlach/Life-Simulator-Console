#include "Interfejs.h"
#include "Czlowiek.h"
#include "Swiat.h"
#include <algorithm>


Interfejs::Interfejs(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc) {
    position.X = 0;
    position.Y = 0;
}

void Interfejs::ustawKolor(int kolor) {
    SetConsoleTextAttribute(hOut, kolor);
}

void Interfejs::setPosition(int x, int y) {
    position.X = x;
    position.Y = y;
}

void Interfejs::rysujRamke(int szerokoscRamki, int wysokoscRamki, int startX, int startY) {
    // Rysuj górn¹ ramkê
    setPosition(startX, startY);
    SetConsoleCursorPosition(getHandle(), getPosition());
    std::cout << znaki.RAMKA_ROG_LG; // lewy górny róg
    for (int i = 0; i < szerokoscRamki * 2 + 1; i++) {
        std::cout << znaki.RAMKA_POZIOM; // pozioma belka
    }
    std::cout << znaki.RAMKA_ROG_PG << std::endl; // prawy górny róg

    // Rysuj doln¹ ramkê
    setPosition(position.X, position.Y + wysokoscRamki + 1);
    SetConsoleCursorPosition(hOut, position);
    std::cout << znaki.RAMKA_ROG_LD; // lewy dolny róg
    for (int i = 0; i < szerokoscRamki * 2 + 1; i++) {
        std::cout << znaki.RAMKA_POZIOM; // pozioma belka
    }
    std::cout << znaki.RAMKA_ROG_PD << std::endl; // prawy dolny róg

    for (int i = 0; i < wysokoscRamki; i++) {
        setPosition(startX, startY + 1 + i);
        SetConsoleCursorPosition(hOut, position);

        std::cout << znaki.RAMKA_PION << ' '; // lewa belka
        for (int j = 0; j < szerokoscRamki; j++) {
            std::cout << ' ' << ' ';
        }
        std::cout << znaki.RAMKA_PION << std::endl; // prawa belka
    }
}

void Interfejs::rysujMape() {
    for (int i = 0; i < wysokosc; i++) {
     
        setPosition(startPosX + 1, startPosY + 1 + i);
        SetConsoleCursorPosition(hOut, position);

        std::cout << ' ';
        for (int j = 0; j < szerokosc; j++) {
            std::cout << znaki.PLANSZA_POLE << ' '; 
        }
        std::cout << std::endl;
    }
}

void Interfejs::rysujAutor(int startX, int startY) {
    int dlugosc = (int)autor.length();

   
    int szerokoscRamki = dlugosc / 2 + 2;
    int wysokoscRamki = 1;

   
    rysujRamke(szerokoscRamki, wysokoscRamki, startX, startY);

   
    setPosition(startX + 3, startY + 1);
    SetConsoleCursorPosition(hOut, position);
    
    std::cout << autor << std::endl;
}

void Interfejs::rysujOrganizm(Organizm* o) {
    int x = startPosX + 2;
    int y = startPosY + 1; 

    int virtual_x = o->getX(); 
    int virtual_y = o->getY(); 

    int field_width = 2;
    int field_height = 1; 
    x += virtual_x * field_width;
    y += virtual_y * field_height; 

    setPosition(x, y);
    SetConsoleCursorPosition(hOut, position);
    ustawKolor(o->getKolor());
    std::cout << o->getSymbol();
    ustawKolor(KOLOR_INTERFEJSU);
}

int Interfejs::wypiszKomunikat(Organizm* a, Organizm* b, int i) {
    if (i < 15) {
        setPosition(getStartPosX() + szerokosc * 2 + 10, getStartPosY() + 4 + i);
        SetConsoleCursorPosition(hOut, position);
        ustawKolor(a->getKolor());
        a->wypisz();
        ustawKolor(KOLOR_INTERFEJSU);
        if (dynamic_cast<Zwierze*>(b) != nullptr)
            if (typeid(*a) != typeid(*b))
                std::cout << " pokonal ";
            else
                std::cout << " urodzil ";
        else
            std::cout << " zjadl ";
        ustawKolor(b->getKolor());
        b->wypisz();
        std::cout << "." << "   ";
        ustawKolor(KOLOR_INTERFEJSU);

        i++;
        return i;
    }
    else
        return 0;
}

void Interfejs::wypiszZgon(int i) {
    if (i < 15) {
        setPosition(getStartPosX() + szerokosc * 2 + 10, getStartPosY() + 4 + i);
        SetConsoleCursorPosition(hOut, position);
        std::cout << "Gracz nie zyje.";
    }
}

int Interfejs::wypiszUmiejetnosc(Organizm* gracz, int i) {
    if (i < 15) {
        setPosition(getStartPosX() + szerokosc * 2 + 10, getStartPosY() + 4 + i);
        SetConsoleCursorPosition(hOut, position);
        ustawKolor(gracz->getKolor());
        gracz->wypisz();
        ustawKolor(KOLOR_INTERFEJSU);
        std::cout << " uzyl ";
        ustawKolor(Kolory::CZERWONY);
        std::cout << "CALOPALENIA!" << "   ";
        i++;
        return i;
    }
    else
        return 0;
}

int Interfejs::wyczyscKomunikaty() {
    for (int i = 0; i < 15; i++) {
        setPosition(getStartPosX() + szerokosc * 2 + 10, getStartPosY() + 4 + i);
        SetConsoleCursorPosition(hOut, position);
        std::cout << "                                                   ";
    }
    return 0;
}

void Interfejs::rysujUmiejetnosc(int x, int y) {
    
    
    COORD currPos = getPosition();

   
    ustawKolor(Kolory::CZERWONY_JASNY);

    setPosition(startPosX + (x + 1) * 2, startPosY + (y + 1));
    SetConsoleCursorPosition(hOut, position);
    std::cout << znaki.GRACZ;
    if (x > 0 && y > 0) {
        setPosition(startPosX + (x + 1) * 2 - 2, startPosY + (y + 1) - 1);
        SetConsoleCursorPosition(hOut, position);
        std::cout << znaki.PLANSZA_POLE;
    }
    if (x > 0) {
        setPosition(startPosX + (x + 1) * 2 - 2, startPosY + (y + 1));
        SetConsoleCursorPosition(hOut, position);
        std::cout << znaki.PLANSZA_POLE;
    }
    if (x > 0 && y < wysokosc - 1) {
        setPosition(startPosX + (x + 1) * 2 - 2, startPosY + (y + 1) + 1);
        SetConsoleCursorPosition(hOut, position);
        std::cout << znaki.PLANSZA_POLE;
    }
    if (y < wysokosc - 1) {
        setPosition(startPosX + (x + 1) * 2, startPosY + (y + 1) + 1);
        SetConsoleCursorPosition(hOut, position);
        std::cout << znaki.PLANSZA_POLE;
    }
    if (y < wysokosc - 1 && x < szerokosc - 1) {
        setPosition(startPosX + (x + 1) * 2 + 2, startPosY + (y + 1) + 1);
        SetConsoleCursorPosition(hOut, position);
        std::cout << znaki.PLANSZA_POLE;
    }
    if (x < szerokosc - 1) {
        setPosition(startPosX + (x + 1) * 2 + 2, startPosY + (y + 1));
        SetConsoleCursorPosition(hOut, position);
        std::cout << znaki.PLANSZA_POLE;
    }
    if (x < szerokosc - 1 && y > 0) {
        setPosition(startPosX + (x + 1) * 2 + 2, startPosY + (y + 1) - 1);
        SetConsoleCursorPosition(hOut, position);
        std::cout << znaki.PLANSZA_POLE;
    }
    if (y > 0) {
        setPosition(startPosX + (x + 1) * 2, startPosY + (y + 1) - 1);
        SetConsoleCursorPosition(hOut, position);
        std::cout << znaki.PLANSZA_POLE;
    }


    
    ustawKolor(KOLOR_INTERFEJSU);
    setPosition(currPos.X, currPos.Y);
    SetConsoleCursorPosition(hOut, position);
}

void Interfejs::rysujInterfejs() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursorInfo);

    ustawKolor(KOLOR_INTERFEJSU);
    rysujRamke(szerokosc, wysokosc, getStartPosX(), getStartPosY());
    rysujMape();

    
    rysujAutor(getStartPosX() + szerokosc * 2 + 10, getStartPosY());
    
}

HANDLE Interfejs::getHandle() const {
    return hOut;
}

COORD Interfejs::getPosition() const {
    return position;
}

int Interfejs::getStartPosX() const {
    return startPosX;
}

int Interfejs::getStartPosY() const {
    return startPosY;
}

