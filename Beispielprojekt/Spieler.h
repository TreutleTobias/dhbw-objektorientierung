#pragma once
#include <string>
using namespace std;

// Spieler-Klasse repräsentiert einen Spieler in einem Spiel.
class Spieler
{

private: // Standartmäßig

    int act_Postion_X;     // Aktuelle X-Position des Spielers
    int act_Postion_Y;     // Aktuelle Y-Position des Spielers
    int Anz_Bloecke;       // Anzahl der vom Spieler gesammelten Blöcke
    int Gewinn_Bloecke;    // Anzahl der Blöcke, die der Spieler benötigt, um das Spiel zu gewinnen

public:
    // Konstruktor für die Spielerklasse.
    // Initialisiert die Startposition des Spielers, die Anzahl der Blöcke und die Gewinnbedingung.
    Spieler(int StartPosition_X, int StartPosition_Y, int Anz_Bloecke, int Gewinn_Bloecke_int);

    // Getter-Funktionen für die X- und Y-Position sowie die Anzahl der Blöcke des Spielers.
    int get_act_Postion_X() const;
    int get_act_Postion_Y() const;
    string get_Anz_Bloecke() const;

    // Setter-Funktionen für die Veränderung der X- und Y-Position des Spielers.
    void set_Postion_X_plus();
    void set_Postion_X_minus();
    void set_Postion_Y_plus();
    void set_Postion_Y_minus();

    // Funktionen zum Verwalten der Anzahl der gesammelten Blöcke und Überprüfen, ob der Spieler gewonnen hat.
    void Anz_Bloecke_plus();
    bool Spieler_gewonnen();
};

