/*****************************************
heinrich-hertz-berufskolleg der stadt bonn
Autor:			Rogerio Da Silva
Klasse:			IH119
Datum:			06.10.2021
Datei:			main.c
Einsatz:		Lauflicht
Beschreibung:   Stripclub lights.
*******************************************
Aenderungen:
- 06.10.2021 Adding basic stuff
******************************************/
/** Text im Quelltext einbinden          */
#include "REG517A.h"

/** Prototypen                           */
void Delay(int);
void Animation1();
void Animation2();
void SetMask(char);

/** Hauptprogramm                        */
void main() {
    while(1) {
        Delay(1);
        Animation1();
        Delay(1);
        Animation2();
    }
}

/** Funktionen                           */
void Delay(int seconds) {
    int Index;
    int Index2;

    for (Index = 0; Index < (10 * seconds); Index++) {
        for (Index2 = 0; Index2 < 100000; Index2++) {
        }
    }
}

void Animation1() {
    P1 = 0x00;

    SetMask(0x01, 0);

    Delay(1);
    SetMask(0x00, 1);
    SetMask(0x02, 1);

    Delay(1);
    SetMask(0x00, 1);
    SetMask(0x04, 1);

    Delay(1);
    SetMask(0x00, 1);
    SetMask(0x08, 1);

    Delay(1);
    SetMask(0x00, 1);
    SetMask(0x20, 1);

    Delay(1);
    SetMask(0x00, 1);
    SetMask(0x40, 1);

    Delay(1);
    SetMask(0x00, 1);
    SetMask(0x90, 1);

}

void Animation2() {
    P1 = 0x00;

    Delay(1);
    P1 = 0x0AA;

    Delay(1);
    P1 = 0x55;
}

void SetMask(char SetTo, int override) {
    if(override == 1) {
        P1 = P1 & SetTo;
    } else if (override == 0) {
        P1 = P1 | SetTo;
    }
}

