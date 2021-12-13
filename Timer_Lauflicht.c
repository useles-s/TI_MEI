/*****************************************
heinrich-hertz-berufskolleg der stadt bonn
Autor:				Rogerio Da Silva
Klasse:				IH119
Datum:				08.11.2021
Datei:				main.c
Einsatz:			Lauflicht mit Pause
Beschreibung: Stripclub lights.
*******************************************
Aenderungen:
- 08.11.2021 Adding basic stuff
- 10.11.2021 Improving stuff
- 08.12.2021 Replacing Delay with Timer0
******************************************/
// Text im Quelltext einbinden
#include "REG517A.h"

// Globale Variabeln
int counter = 0;
int doAction = 0;

// Prototypen 
void IRQ_Timer0();
// void Delay(int); //TODO: Replace
// void StopProcess();
// int ChangeSpeed(int);

// Hauptprogramm                        
void main() {
	// Var Initialization
	int Index = 0;
	int backup = 0;
	char mask = 0x01;
	int speed = 500;
	
	char Values[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}; 
	
	// Timer Initialization
	TR0  = 0;
	TF0  = 0;
	IT0  = 0;
	TMOD = 0x01;
	
	TL0  = 0xAF;
	TH0  = 0x3C;
	// IR System Initialization
	ET0 = 1;
	EAL = 0;
	
	// Adapt Ports
	P4 = 0x00; // Deactivate RGB LED
	P1 = 0x00; // Deactivate all LEDs onBoard
	
	while(1){
		for(Index = backup; Index < 0; Index++) { // Forward
			P1 = Values[Index];
			backup++;
			
			while(doAction == 0);
			
			doAction = 0;
		} 
		
		for(Index = backup; Index > 0; Index--) { // Backwards
			P1 = Values[Index];
			backup = Index;
			
			while(doAction == 0);
			
			doAction = 0;
		}
		
		/*P4 = 0x00;
		
		
		backup = 0;
		for(Index = backup; Index < 8; Index++) {
			P1 = Values[Index];
			backup++;
			
			speed = ChangeSpeed(speed);
			
			if(P6 != (P6 | mask)) {
				while(P6 != (P6 | mask));
				break;
			}
			
			Delay(speed); //Hier warten
		}
		
		for(Index = backup; Index > 0; Index--) {
			P1 = Values[Index];
			backup--;
			
			speed = ChangeSpeed(speed);
			
			if(P6 != (P6 | mask)) {
				while(P6 != (P6 | mask));
				break;
			}
			
			Delay(speed); //Hier warten
		}
	}*/
	}
}
	

/// Funktionen    
void IRQ_Timer0() interrupt 1 {
	TR0 = 0;
	EAL = 0;
	
	TL0  = 0xAF;
	TH0  = 0x3C;
	
	counter++;
	
	if(counter >= 10) {
		doAction = 1;
		counter = 0;
	}
	
	TR0 = 1;
	EAL = 1;
}

/*
void Delay(int ms) {
	int Index, Index2;
	
	for (Index = 0; Index <= ms; Index++) {
		StopProcess();
		for (Index2 = 0; Index2 < 250; Index2++);
	}
} 
*/


/*int ChangeSpeed(old) {
	int speed = old;
	
	if(P3 != (P3 | 0x04)) {
		while(P3 != (P3 | 0x04));
			speed = speed - 50;
			
		if(speed < 50) {
			speed = 500;
		}
		return speed;
	}
	return old;
}


void StopProcess() {
	int IsStop = 0;
	int Index,Index2,Index3;
	char backup = P1;
	char mask = 0x01;
	
	while(P5 != (P5 | mask)) {
		IsStop = 1;
	}
	while (IsStop == 1) {
		for (Index = 0; Index <= 3000; Index++);
		
		while(P5 != (P5 | mask)) {
			IsStop = 0;
		}
		
		while (P6 != (P6 | mask)) {
			P1 = 0xAA;
			Delay(500);
			
			P1 = 0x00;
			Delay(500);
			
		}
		P1 = backup;
	}
}*/
