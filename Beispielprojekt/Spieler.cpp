#include "Spieler.h"
// Konstruktor für die Spielerklasse
// Initialisiert die Position des Spielers (X, Y), die Anzahl der Blöcke und die erforderliche Anzahl zum Gewinnen.
Spieler::Spieler(int StartPosition_X, int StartPosition_Y, int Anz_Bloecke_int, int Gewinn_Bloecke_int )
{
	act_Postion_X = StartPosition_X; // - StartPosition_X: Startposition des Spielers auf der X-Achse
	act_Postion_Y = StartPosition_Y; // - StartPosition_Y: Startposition des Spielers auf der Y-Achse
	Anz_Bloecke = Anz_Bloecke_int;   // - Anz_Bloecke_int: Anfangszahl der Blöcke, die der Spieler hat
	Gewinn_Bloecke = Gewinn_Bloecke_int; // -Gewinn_Bloecke_int: Die Anzahl der Blöcke, die der Spieler benötigt, um das Spiel zu gewinnen

};

// Getter-Funktion für die X-Position des Spielers.
// Gibt die aktuelle X-Position des Spielers zurück.
// Rückgabewert: Eine ganze Zahl, die die X-Position repräsentiert.
int Spieler::get_act_Postion_X() const {
	return this->act_Postion_X;
}

// Getter-Funktion für die Y-Position des Spielers.
// Gibt die aktuelle Y-Position des Spielers zurück.
// Rückgabewert: Eine ganze Zahl, die die Y-Position repräsentiert.
int Spieler::get_act_Postion_Y() const {
	return this->act_Postion_Y;
}

// Getter-Funktion für die Anzahl der Blöcke des Spielers.
// Gibt die aktuelle Anzahl der Blöcke des Spielers als Zeichenkette zurück.
// Rückgabewert: Eine Zeichenkette, die die Anzahl der Blöcke repräsentiert.
string Spieler::get_Anz_Bloecke() const {
	return to_string(this->Anz_Bloecke);
}

// Setter - Funktion für die Erhöhung der X - Position des Spielers um 20 Einheiten.
void Spieler::set_Postion_X_plus() {
	this->act_Postion_X = this->act_Postion_X + 20;
}

// Setter-Funktion für die Verringerung der X-Position des Spielers um 20 Einheiten.
void Spieler::set_Postion_X_minus() {
	this->act_Postion_X = this->act_Postion_X - 20;
}

// Setter-Funktion für die Erhöhung der Y-Position des Spielers um 20 Einheiten.
void Spieler::set_Postion_Y_plus() {
	this->act_Postion_Y = this->act_Postion_Y + 20;
}

// Setter-Funktion für die Verringerung der Y-Position des Spielers um 20 Einheiten.
void Spieler::set_Postion_Y_minus() {
	this->act_Postion_Y = this->act_Postion_Y - 20;
}



// Erhöht die Anzahl der Blöcke des Spielers um 1.
void Spieler::Anz_Bloecke_plus() {
	this->Anz_Bloecke = this->Anz_Bloecke + 1;
}

// Überprüft, ob der Spieler genügend Blöcke gesammelt hat, um das Spiel zu gewinnen.
// Rückgabewert: True, wenn der Spieler genügend Blöcke gesammelt hat; sonst False.
bool Spieler::Spieler_gewonnen() {
	if (this->Anz_Bloecke >= this->Gewinn_Bloecke) {
		return true;
	}
	else {
		return false;
	}
}


