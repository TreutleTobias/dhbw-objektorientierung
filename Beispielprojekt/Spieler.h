#pragma once
#include <string>
using namespace std;

// Spieler-Klasse repr�sentiert einen Spieler in einem Spiel.
class Spieler
{

private: // Standartm��ig

    int act_Postion_X;     // Aktuelle X-Position des Spielers
    int act_Postion_Y;     // Aktuelle Y-Position des Spielers
    int Anz_Bloecke;       // Anzahl der vom Spieler gesammelten Bl�cke
    int Gewinn_Bloecke;    // Anzahl der Bl�cke, die der Spieler ben�tigt, um das Spiel zu gewinnen

public:
    // Konstruktor f�r die Spielerklasse.
    // Initialisiert die Startposition des Spielers, die Anzahl der Bl�cke und die Gewinnbedingung.
    Spieler(int StartPosition_X, int StartPosition_Y, int Anz_Bloecke, int Gewinn_Bloecke_int);

    // Getter-Funktionen f�r die X- und Y-Position sowie die Anzahl der Bl�cke des Spielers.
    int get_act_Postion_X() const;
    int get_act_Postion_Y() const;
    string get_Anz_Bloecke() const;

    // Setter-Funktionen f�r die Ver�nderung der X- und Y-Position des Spielers.
    void set_Postion_X_plus();
    void set_Postion_X_minus();
    void set_Postion_Y_plus();
    void set_Postion_Y_minus();

    // Funktionen zum Verwalten der Anzahl der gesammelten Bl�cke und �berpr�fen, ob der Spieler gewonnen hat.
    void Anz_Bloecke_plus();
    bool Spieler_gewonnen();
};

