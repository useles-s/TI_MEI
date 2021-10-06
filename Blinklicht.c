/*****************************************
heinrich-hertz-berufskolleg der stadt bonn
Autor:			Rogerio Da Silva
Klasse:			IH119
Datum:			27.09.2021
Datei:			main.c
Einsatz:		Blinklicht
Beschreibung:   Blinking LED Bulb.
*******************************************
Aenderungen:
- 27.09.2021 Adding the code
- 06.10.2021 Make it functional
******************************************/
/** Text im Quelltext einbinden          */
#include "REG517A.h"

/** Prototypen                           */
void Blink();
void Delay(int);

/** Hauptprogramm                        */
void main() {
    while(1) {
        Blink();
    }
}

/** Funktionen                           */
void Blink() {
    char Mask = 0x01;

    P1 = 0x00;

    P1 = P1 | Mask;
    Delay(1);

    Mask = 0x0FE;
    P1 = P1 & Mask;
    Delay(1);

}
void Delay(int seconds) {
    int Index;
    int Index2;

    for (Index = 0; Index < (10 * seconds); Index++) {
        for (Index2 = 0; Index2 < 100000; Index2++) {
        }
    }
}

