#include "Spieler.h"
// Konstruktor f�r die Spielerklasse
// Initialisiert die Position des Spielers (X, Y), die Anzahl der Bl�cke und die erforderliche Anzahl zum Gewinnen.
Spieler::Spieler(int StartPosition_X, int StartPosition_Y, int Anz_Bloecke_int, int Gewinn_Bloecke_int )
{
	act_Postion_X = StartPosition_X; // - StartPosition_X: Startposition des Spielers auf der X-Achse
	act_Postion_Y = StartPosition_Y; // - StartPosition_Y: Startposition des Spielers auf der Y-Achse
	Anz_Bloecke = Anz_Bloecke_int;   // - Anz_Bloecke_int: Anfangszahl der Bl�cke, die der Spieler hat
	Gewinn_Bloecke = Gewinn_Bloecke_int; // -Gewinn_Bloecke_int: Die Anzahl der Bl�cke, die der Spieler ben�tigt, um das Spiel zu gewinnen

};

// Getter-Funktion f�r die X-Position des Spielers.
// Gibt die aktuelle X-Position des Spielers zur�ck.
// R�ckgabewert: Eine ganze Zahl, die die X-Position repr�sentiert.
int Spieler::get_act_Postion_X() const {
	return this->act_Postion_X;
}

// Getter-Funktion f�r die Y-Position des Spielers.
// Gibt die aktuelle Y-Position des Spielers zur�ck.
// R�ckgabewert: Eine ganze Zahl, die die Y-Position repr�sentiert.
int Spieler::get_act_Postion_Y() const {
	return this->act_Postion_Y;
}

// Getter-Funktion f�r die Anzahl der Bl�cke des Spielers.
// Gibt die aktuelle Anzahl der Bl�cke des Spielers als Zeichenkette zur�ck.
// R�ckgabewert: Eine Zeichenkette, die die Anzahl der Bl�cke repr�sentiert.
string Spieler::get_Anz_Bloecke() const {
	return to_string(this->Anz_Bloecke);
}

// Setter - Funktion f�r die Erh�hung der X - Position des Spielers um 20 Einheiten.
void Spieler::set_Postion_X_plus() {
	this->act_Postion_X = this->act_Postion_X + 20;
}

// Setter-Funktion f�r die Verringerung der X-Position des Spielers um 20 Einheiten.
void Spieler::set_Postion_X_minus() {
	this->act_Postion_X = this->act_Postion_X - 20;
}

// Setter-Funktion f�r die Erh�hung der Y-Position des Spielers um 20 Einheiten.
void Spieler::set_Postion_Y_plus() {
	this->act_Postion_Y = this->act_Postion_Y + 20;
}

// Setter-Funktion f�r die Verringerung der Y-Position des Spielers um 20 Einheiten.
void Spieler::set_Postion_Y_minus() {
	this->act_Postion_Y = this->act_Postion_Y - 20;
}



// Erh�ht die Anzahl der Bl�cke des Spielers um 1.
void Spieler::Anz_Bloecke_plus() {
	this->Anz_Bloecke = this->Anz_Bloecke + 1;
}

// �berpr�ft, ob der Spieler gen�gend Bl�cke gesammelt hat, um das Spiel zu gewinnen.
// R�ckgabewert: True, wenn der Spieler gen�gend Bl�cke gesammelt hat; sonst False.
bool Spieler::Spieler_gewonnen() {
	if (this->Anz_Bloecke >= this->Gewinn_Bloecke) {
		return true;
	}
	else {
		return false;
	}
}


