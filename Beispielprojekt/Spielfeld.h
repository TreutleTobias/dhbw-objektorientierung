#pragma once

#include <vector>
#include <iostream>
using namespace std;

// Struktur, die einen Block auf dem Spielfeld repräsentiert.
struct Block
{
    int Typ;    // 0 = Umrandung des Spielfelds, 1 = fester Block in der Mitte, 2 = Leerfeld, 3 = zerstörbare Kiste
    int farbe;  // Farbe des Blocks
};

// Spielfeld-Klasse repräsentiert das Spielfeld in einem Spiel.
class Spielfeld
{

private: // Standartmäßig

    const int block_x;              // Größe eines Blocks in X-Richtung
    const int block_y;              // Größe eines Blocks in Y-Richtung
    const int Spielfeld_x;          // Gesamtbreite des Spielfelds in Blöcken
    const int Spielfeld_y;          // Gesamthöhe des Spielfelds in Blöcken
    const int block_x_spieler;      // Größe eines Spielerblocks in X-Richtung
    const int block_y_spieler;      // Größe eines Spielerblocks in Y-Richtung
    const int spielfeld_x_Anzahl;   // Anzahl der Blöcke in X-Richtung
    const int spielfeld_y_Anzahl;   // Anzahl der Blöcke in Y-Richtung

    vector<vector<Block>> spielfeld_matrix;  // Matrix, die das Spielfeld repräsentiert

public:
    // Konstruktor für die Spielfeldklasse.
    // Initialisiert die Größe der Blöcke, die Größe des Spielfelds und die Größe eines Spielerblocks.
    Spielfeld(int block_x, int block_y, int Spielfeld_x, int Spielfeld_y, int block_x_spieler, int block_y_spieler);

    // Getter-Funktionen für verschiedene Eigenschaften des Spielfelds.
    int get_block_x() const;
    int get_block_y() const;
    int get_Spielfeld_x() const;
    int get_Spielfeld_y() const;
    int get_Spielfeld_x_Anzahl() const;
    int get_Spielfeld_y_Anzahl() const;

    // Initialisiert das Spielfeld mit Blöcken.
    void initialisieren();

    // Überprüft, ob die angegebene Position auf dem Spielfeld gültig ist.
    bool ueberpruefen(int act_Postion_X, int act_Postion_Y);

    // Sammelt einen Block auf der angegebenen Position ein und gibt an, ob die Operation erfolgreich war.
    bool Bloeck_sammelen(int act_Postion_X, int act_Postion_Y);

    // Gibt die Matrix repräsentierend das Spielfeld zurück.
    vector<vector<Block>> get_Matrix_Spielfeld();
};
