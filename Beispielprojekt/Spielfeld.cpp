#include "Spielfeld.h"
// Konstruktor f�r die Spielfeldklasse.
	// Initialisiert die Gr��e der Bl�cke, die Gr��e des Spielfelds und die Gr��e eines Spielerblocks.
	
Spielfeld::Spielfeld(int block_x, int block_y, int Spielfeld_x, int Spielfeld_y, int block_x_spieler, int block_y_spieler)
    : block_x(block_x), block_y(block_y), Spielfeld_x(Spielfeld_x), Spielfeld_y(Spielfeld_y), block_x_spieler(block_x_spieler), block_y_spieler(block_y_spieler),
    spielfeld_x_Anzahl(Spielfeld_x / block_x), spielfeld_y_Anzahl(Spielfeld_y / block_y)
{
    // Andere Konstruktorenlogik, falls erforderlich

}

// Getter-Funktion f�r die Gr��e eines Blocks in X-Richtung.
int Spielfeld::get_block_x() const { return this->block_x; }

// Getter-Funktion f�r die Gr��e eines Blocks in Y-Richtung.
int Spielfeld::get_block_y() const { return this->block_y; }

// Getter-Funktion f�r die Gesamtbreite des Spielfelds in Bl�cken.
int Spielfeld::get_Spielfeld_x() const { return this->Spielfeld_x; }

// Getter-Funktion f�r die Gesamth�he des Spielfelds in Bl�cken.
int Spielfeld::get_Spielfeld_y() const { return this->Spielfeld_y; }

// Getter-Funktion f�r die Anzahl der Bl�cke in X-Richtung auf dem Spielfeld.
int Spielfeld::get_Spielfeld_x_Anzahl() const { return this->spielfeld_x_Anzahl; }

// Getter-Funktion f�r die Anzahl der Bl�cke in Y-Richtung auf dem Spielfeld.
int Spielfeld::get_Spielfeld_y_Anzahl() const { return this->spielfeld_y_Anzahl; }

// Getter-Funktion f�r die Matrix, die das Spielfeld repr�sentiert.
vector<vector<Block>> Spielfeld::get_Matrix_Spielfeld() { return this->spielfeld_matrix; }


void Spielfeld::initialisieren() {
    // Initialisiert das Spielfeld durch Zuweisen von Typen zu den Bl�cken basierend auf den definierten Regeln.
    // Randbl�cke haben den Typ 0 (Umrandung), gerade Bl�cke haben den Typ 1 (fester Block in der Mitte),
    // zuf�llige Bl�cke haben den Typ 3 (zerst�rbare Kiste) oder Typ 2 (Leerfeld).
    // Die Initialisierung erfolgt in einer Schleife durch die gesamte Spielfeldmatrix.

    // Initialisiert Zufallszahlengenerator 
    srand(time(NULL));

    // �u�ere Schleife durchl�uft die Bl�cke in X-Richtung.
    for (size_t x = 0; x < this->spielfeld_x_Anzahl; x++) {
        // Innere Schleife durchl�uft die Bl�cke in Y-Richtung.
        vector<Block> v;
        for (size_t y = 0; y < this->spielfeld_y_Anzahl; y++) {

            // Neuen Block erstellen.
            Block b;

            // �berpr�fen, ob der Block an einem Rand liegt.
            if (y == 0 || y == this->spielfeld_y_Anzahl - 1 || x == 0 || x == this->spielfeld_x_Anzahl - 1) {
                b.Typ = 0; // Randblock (Typ 0)
            }
            // �berpr�fen, ob der Block an geraden Koordinaten liegt.
            else if (y % 2 == 0 && x % 2 == 0) {
                b.Typ = 1; // Fester Block in der Mitte (Typ 1)
            }
            // �berpr�fen, ob der Block nicht in einer festen Struktur liegt.
            else if (!((y < 7 && x < 7) || (y > (spielfeld_y_Anzahl - 7) && x > (spielfeld_x_Anzahl - 7)))) {
                // Zuf�llig entscheiden, ob der Block eine zerst�rbare Kiste (Typ 3) oder ein Leerfeld (Typ 2) ist.
                if (rand() % 3 == 0) {
                    b.Typ = 3; // Zerst�rbare Kiste (Typ 3)
                }
                else {
                    b.Typ = 2; // Leerfeld (Typ 2)
                }
            }
            else {
                b.Typ = 2; // Leerfeld (Typ 2)
            }

            // Den erstellten Block der aktuellen Zeile hinzuf�gen.
            v.push_back(b);
        }

        // Die aktuelle Zeile zur Spielfeldmatrix hinzuf�gen.
        this->spielfeld_matrix.push_back(v);
    }
}


bool Spielfeld::ueberpruefen(int act_Postion_X, int act_Postion_Y) {
    // �berpr�ft, ob die Position des Spielers auf dem Spielfeld g�ltig ist.
    // Gibt True zur�ck, wenn der Block vom Typ 2 (Leerfeld) ist, andernfalls False.

    // Berechnet die Blockposition des Spielers in X- und Y-Richtung.
    int Block_Anzahl_X = int(trunc(double((act_Postion_X) / this->block_x_spieler)));
    int Block_Anzahl_Y = int(trunc(double((act_Postion_Y) / this->block_y_spieler)));

    // Holt den Typ des Blocks an der berechneten Position.
    int Typ = this->spielfeld_matrix.at(Block_Anzahl_X).at(Block_Anzahl_Y).Typ;

    // �berpr�ft, ob der Block ein Leerfeld (Typ 2) ist.
    if (Typ == 2) {
        return true;  // G�ltige Position
    }
    else {
        return false; // Ung�ltige Position
    }
}


bool Spielfeld::Bloeck_sammelen(int act_Postion_X, int act_Postion_Y) {
    // Sammelt einen Block auf der angegebenen Position ein, falls der Block vom Typ 3 (zerst�rbare Kiste) ist.
    // �ndert den Blocktyp auf Typ 2 (Leerfeld) und gibt True zur�ck, ansonsten gibt es False zur�ck.

    // Berechnet die Blockposition des Spielers in X- und Y-Richtung.
    int Block_Anzahl_X = int(trunc(double((act_Postion_X) / this->block_x_spieler)));
    int Block_Anzahl_Y = int(trunc(double((act_Postion_Y) / this->block_y_spieler)));

    // Holt den Typ des Blocks an der berechneten Position.
    int Typ = this->spielfeld_matrix.at(Block_Anzahl_X).at(Block_Anzahl_Y).Typ;

    // �berpr�ft, ob der Block eine zerst�rbare Kiste (Typ 3) ist.
    if (Typ == 3) {
        // �ndert den Blocktyp auf Typ 2 (Leerfeld).
        this->spielfeld_matrix.at(Block_Anzahl_X).at(Block_Anzahl_Y).Typ = 2;
        return true;  // Erfolgreich eingesammelt
    }
    else {
        return false; // Keine zerst�rbare Kiste an der Position
    }
}

