#include <iostream>
#include <ctime>
#include <windows.h>
#include "Swiat.h"
#include "Organizmy.h"

 
int main() {
    srand((int)(time(NULL)));
    Swiat swiat(20,20);
    new Wilk(&swiat);
    new Wilk(&swiat);
    new Antylopa(&swiat);
    new Antylopa(&swiat);
    new Mlecz(&swiat);
    new WilczeJagody(&swiat);
    new WilczeJagody(&swiat);
    new WilczeJagody(&swiat);
    new WilczeJagody(&swiat);
    new BarszczSosnowskiego(&swiat);
    new BarszczSosnowskiego(&swiat);
    new BarszczSosnowskiego(&swiat);
    new Trawa(&swiat);
    new Trawa(&swiat);
    new Trawa(&swiat);
    new Trawa(&swiat);
    new Guarana(&swiat);
    new Zolw(&swiat);
    new Zolw(&swiat);
    new Lis(&swiat);
    new Lis(&swiat);
    new Owca(&swiat);
    new Owca(&swiat);

    

    swiat.symuluj();
  
    return 0;
}



