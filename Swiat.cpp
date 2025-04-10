#include "Swiat.h"
#include "Czlowiek.h"
#include <fstream>
#include "Organizmy.h"

Swiat::Swiat(int szerokosc, int wysokosc) {
    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;
    plansza = new Organizm * *[szerokosc];
    for (int i = 0; i < szerokosc; i++) {
        plansza[i] = new Organizm * [wysokosc];
        for (int j = 0; j < wysokosc; j++) {
            plansza[i][j] = nullptr;
        }
    }
    gracz = new Czlowiek(0, 0, this);
    dodajOrganizm(gracz);
    setGraczZyje(true);
    kontroler = new Kontroler(this, gracz);
    interfejs = new Interfejs(szerokosc, wysokosc);
}

Swiat::Swiat(int szerokosc, int wysokosc, int x, int y) {
    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;
    plansza = new Organizm * *[szerokosc];
    for (int i = 0; i < szerokosc; i++) {
        plansza[i] = new Organizm * [wysokosc];
        for (int j = 0; j < wysokosc; j++) {
            plansza[i][j] = nullptr;
        }
    }
    gracz = new Czlowiek(x, y, this);
    dodajOrganizm(gracz);
    setGraczZyje(true);
    kontroler = new Kontroler(this, gracz);
    interfejs = new Interfejs(szerokosc, wysokosc);
}

Swiat::~Swiat() {
    for (int i = 0; i < szerokosc; i++) {
        for (int j = 0; j < wysokosc; j++) {
            delete plansza[i][j];
        }
        delete[] plansza[i];
    }
    delete[] plansza;
    delete kontroler;
    delete interfejs;
}

bool Swiat::porownaj(const Organizm* a, const Organizm* b) const {
    if (a->getInicjatywa() != b->getInicjatywa()) {
        return a->getInicjatywa() > b->getInicjatywa();
    }
    else {
        return a->getWiek() > b->getWiek();
    }
}

void Swiat::sortujOrganizmy(std::vector<Organizm*>& organizmy) {
    std::sort(organizmy.begin(), organizmy.end(), std::bind(&Swiat::porownaj, this, std::placeholders::_1, std::placeholders::_2));
}

void Swiat::usunMartweOrganizmy() {
    for (auto& o : organizmy) {
        if (!o->czyZyje()) {
            usunOrganizm(o);
        }
    }
}

void Swiat::wykonajTure() {

    if (getGraczZyje()) {
        sortujOrganizmy(organizmy); // posortuj organizmy

        std::vector<Organizm*> kopiaOrganizmy = organizmy;

        gracz->aktualizujUmiejetnosc();

        for (auto& o : kopiaOrganizmy) { // wykonaj akcjê dla ka¿dego organizmu
            if (&o != nullptr) {
                o->zwiekszWiek();
                o->akcja();
                aktualizujPlansze();
                if (getKomunikat() > 15 || getKomunikat() == 0) {
                    setKomunikat(0);
                    interfejs->wyczyscKomunikaty();
                }


            }

        
        }
        usunMartweOrganizmy();
        
    }

   

   

}

void Swiat::rysujSwiat() {
    interfejs->rysujInterfejs();

    for (auto org : organizmy) {
        interfejs->rysujOrganizm(org);
    }
    interfejs->rysujOrganizm(gracz);
    if (getGraczZyje() && gracz->getUmiejetnosc()) {
        interfejs->rysujUmiejetnosc(getGraczX(), getGraczY());
    }
        

 }

void Swiat::dodajOrganizm(Organizm* o) {
    int x, y;
    if (!czyPelny()) {

        if (o->getX() >= 0 && o->getY() >= 0) {
            x = o->getX();
            y = o->getY();
        }
        else {

            do {
                x = rand() % szerokosc;
                y = rand() % wysokosc;
            } while (czyPoleZajete(x, y));
            o->setX(x);
            o->setY(y);

        }
    
        if (plansza[x][y] == nullptr) {
            organizmy.push_back(o);
            plansza[x][y] = o;
        }
    }
}


void Swiat::dodajOrganizm(Organizm* o, int x, int y) {
    auto it = find(organizmy.begin(), organizmy.end(), o);
    if (!czyPelny() && plansza[x][y] == nullptr && it == organizmy.end()) {
        o->setX(x);
        o->setY(y);
        organizmy.push_back(o);
        plansza[x][y] = o;
    }
}

void Swiat::usunOrganizm(Organizm* org) {
 
    auto it = find(organizmy.begin(), organizmy.end(), org); 
    if (it != organizmy.end()) {
        plansza[org->getX()][org->getY()] = nullptr; 
        organizmy.erase(it); 
    }
    if (org == gracz) {
        setGraczZyje(false);
        interfejs->wypiszZgon(getKomunikat());
    }

    delete org; 
   
}

Organizm* Swiat::getOrganizm(int x, int y) const {
    if (x < 0 || x >= szerokosc || y < 0 || y >= wysokosc) {
        return nullptr;
    }
    return plansza[x][y];
}

void Swiat::setOrganizm(int x, int y, Organizm* organizm) {
    if (x < 0 || x >= szerokosc || y < 0 || y >= wysokosc) {
        return;
    }
    plansza[x][y] = organizm;
}
void Swiat::setGracz(int x, int y) {
    gracz->setX(x);
    gracz->setY(y);
}

int Swiat::getGraczX() const {
    return gracz->getX();
}

int Swiat::getGraczY() const {
    return gracz->getY();
}

bool Swiat::czyPoleZajete(int x, int y) const {
    for (Organizm* o : organizmy) {
        if (o->getX() == x && o->getY() == y) {
            return true;
        }
    }
    return false;
}

void Swiat::aktualizujPlansze() {
    for (int x = 0; x < szerokosc; x++) {
        for (int y = 0; y < wysokosc; y++) {
            plansza[x][y] = nullptr;
        }
    }
    for (auto org : organizmy) {
        int x = org->getX();
        int y = org->getY();
        if(org->czyZyje())
        plansza[x][y] = org;
    }
}

bool Swiat::czyPelny() const {
    return organizmy.size() >= szerokosc * wysokosc;
}

bool Swiat::czyPuste(int x, int y) {
    if(plansza[x][y] != nullptr)
        return !plansza[x][y]->czyZyje();
    return true;
}

bool Swiat::czyNaPlanszy(int x, int y) const {
    return x >= 0 && x < szerokosc&& y >= 0 && y < wysokosc;
}

void Swiat::przeniesOrganizm(Organizm* org, int newX, int newY) {
    plansza[org->getX()][org->getY()] = nullptr;
    org->setX(newX);
    org->setY(newY);
    plansza[newX][newY] = org;
}

bool Swiat::getGraczZyje() const {
    return graczZyje;
}

void Swiat::setGraczZyje(bool value) {
    graczZyje = value;
}


int Swiat::ileOrganizmow() const {
   return (int)organizmy.size();
}

void Swiat::symuluj() {
    rysujSwiat();
   
    kontroler->obslugaKlawiatury();
}

Interfejs* Swiat::getInterfejs() const {
    return interfejs;
}

int Swiat::getKomunikat() const {
    return komunikat;
}

void Swiat::setKomunikat(int i) {
    komunikat = i;
}

void Swiat::zapisz() const {
    HANDLE plik = CreateFile(L"SAVE", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (plik == INVALID_HANDLE_VALUE) {
        return;
    }

    std::string tekst;
    tekst += std::to_string(szerokosc) + "\n";
    tekst += std::to_string(wysokosc) + "\n";
    tekst += std::to_string(getGraczX()) + "\n";
    tekst += std::to_string(getGraczY()) + "\n";
    tekst += std::to_string(organizmy.size() - 1) + "\n";
    for (const auto& o : organizmy) {
        if (o != gracz) {
            tekst += o->nazwa() + "\n";
            tekst += std::to_string(o->getX()) + "\n";
            tekst += std::to_string(o->getY()) + "\n";
        }
    }

    DWORD bytesWritten;
    WriteFile(plik, tekst.c_str(), tekst.size(), &bytesWritten, NULL);

    CloseHandle(plik);
}

Swiat* Swiat::wczytaj() {
    std::ifstream plik(L"Save", std::ios::binary);
  

    int szerokosc, wysokosc, graczX, graczY;
    std::string typ, org;
    int x, y;
    int iloscOrganizmow;

    
    std::getline(plik, typ);
    szerokosc = std::stoi(typ);
    std::getline(plik, typ);
    wysokosc = std::stoi(typ);
    std::getline(plik, typ);
    graczX = std::stoi(typ);
    std::getline(plik, typ);
    graczY = std::stoi(typ);

    

    zwolnijPamiec();
    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;
    plansza = new Organizm * *[szerokosc];
    for (int i = 0; i < szerokosc; i++) {
        plansza[i] = new Organizm * [wysokosc];
        for (int j = 0; j < wysokosc; j++) {
            plansza[i][j] = nullptr;
        }
    }
    gracz = new Czlowiek(graczX, graczY, this);
    dodajOrganizm(gracz);
    setGraczZyje(true);
    kontroler = new Kontroler(this, gracz);
    interfejs = new Interfejs(szerokosc, wysokosc);
    
    std::getline(plik, typ);
    iloscOrganizmow = std::stoi(typ);

   
    for (int i = 0; i < iloscOrganizmow; i++) {
        std::getline(plik, typ);
        org = typ;
        std::getline(plik, typ);
        x = std::stoi(typ);
        std::getline(plik, typ);
        y = std::stoi(typ);

        Organizm* nowyOrganizm = nullptr;
        if (org == "Wilk") {
            nowyOrganizm = new Wilk(x, y, this);
        }
        else if (org == "Owca") {
            nowyOrganizm = new Owca(x, y, this);
        }
        else if (org == "Zolw") {
            nowyOrganizm = new Zolw(x, y, this);
        }
        else if (org == "Lis") {
            nowyOrganizm = new Lis(x, y, this);
        }
        else if (org == "Antylopa") {
            nowyOrganizm = new Antylopa(x, y, this);
        }
        else if (org == "Trawa") {
            nowyOrganizm = new Trawa(x, y, this);
        }
        else if (org == "Mlecz") {
            nowyOrganizm = new Mlecz(x, y, this);
        }
        else if (org == "Guarana") {
            nowyOrganizm = new Guarana(x, y, this);
        }
        else if (org == "WilczeJagody") {
            nowyOrganizm = new WilczeJagody(x, y, this);
        }
        else if (org == "BarszczSosnowskiego") {
            nowyOrganizm = new BarszczSosnowskiego(x, y, this);
        }

        dodajOrganizm(nowyOrganizm);
    }

    plik.close();

    rysujSwiat();
    return this;
}

void Swiat::zwolnijPamiec() {
    for (int i = 0; i < szerokosc; i++) {
        for (int j = 0; j < wysokosc; j++) {
            delete plansza[i][j];
        }
        delete[] plansza[i];
    }
    delete[] plansza;
    delete kontroler;
    delete interfejs;
    organizmy.clear();
}

Czlowiek* Swiat::getGracz() const {
    return gracz;
}