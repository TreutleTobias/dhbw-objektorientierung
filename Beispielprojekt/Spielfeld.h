#pragma once

#include <vector>
#include <iostream>
using namespace std;

// Struktur, die einen Block auf dem Spielfeld repr�sentiert.
struct Block
{
    int Typ;    // 0 = Umrandung des Spielfelds, 1 = fester Block in der Mitte, 2 = Leerfeld, 3 = zerst�rbare Kiste
    int farbe;  // Farbe des Blocks
};

// Spielfeld-Klasse repr�sentiert das Spielfeld in einem Spiel.
class Spielfeld
{

private: // Standartm��ig

    const int block_x;              // Gr��e eines Blocks in X-Richtung
    const int block_y;              // Gr��e eines Blocks in Y-Richtung
    const int Spielfeld_x;          // Gesamtbreite des Spielfelds in Bl�cken
    const int Spielfeld_y;          // Gesamth�he des Spielfelds in Bl�cken
    const int block_x_spieler;      // Gr��e eines Spielerblocks in X-Richtung
    const int block_y_spieler;      // Gr��e eines Spielerblocks in Y-Richtung
    const int spielfeld_x_Anzahl;   // Anzahl der Bl�cke in X-Richtung
    const int spielfeld_y_Anzahl;   // Anzahl der Bl�cke in Y-Richtung

    vector<vector<Block>> spielfeld_matrix;  // Matrix, die das Spielfeld repr�sentiert

public:
    // Konstruktor f�r die Spielfeldklasse.
    // Initialisiert die Gr��e der Bl�cke, die Gr��e des Spielfelds und die Gr��e eines Spielerblocks.
    Spielfeld(int block_x, int block_y, int Spielfeld_x, int Spielfeld_y, int block_x_spieler, int block_y_spieler);

    // Getter-Funktionen f�r verschiedene Eigenschaften des Spielfelds.
    int get_block_x() const;
    int get_block_y() const;
    int get_Spielfeld_x() const;
    int get_Spielfeld_y() const;
    int get_Spielfeld_x_Anzahl() const;
    int get_Spielfeld_y_Anzahl() const;

    // Initialisiert das Spielfeld mit Bl�cken.
    void initialisieren();

    // �berpr�ft, ob die angegebene Position auf dem Spielfeld g�ltig ist.
    bool ueberpruefen(int act_Postion_X, int act_Postion_Y);

    // Sammelt einen Block auf der angegebenen Position ein und gibt an, ob die Operation erfolgreich war.
    bool Bloeck_sammelen(int act_Postion_X, int act_Postion_Y);

    // Gibt die Matrix repr�sentierend das Spielfeld zur�ck.
    vector<vector<Block>> get_Matrix_Spielfeld();
};
