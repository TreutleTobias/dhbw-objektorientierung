#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Spieler.h"
#include "Spielfeld.h"
#include <vector>
#include <iostream>

// Verwendung des Standardnamenraums für 'std'
using namespace std;

// Definition von Konstanten für die Größe der Blöcke und des Spielfelds
const int block_x = 20; // Größe in X
const int block_y = 20; // Größe in Y
const int block_x_spieler = 20; // Größe in X für Spieler
const int block_y_spieler = 20; // Größe in Y für Spieler
const int Spielfeld_x = 780; // Größe des Spielfelds in X-Richtung
const int Spielfeld_y = 580; // Größe des Spielfelds in Y-Richtung

// Initialisierung von zwei Spielerobjekten ('spieler_1' und 'spieler_2')
Spieler spieler_1(block_x_spieler, block_y_spieler, 0, 30);
Spieler spieler_2(Spielfeld_x - (2 * block_x_spieler), Spielfeld_y - (2 * block_y_spieler), 0, 30);

// Initialisierung eines Spielfeldobjekts ('spielfeld')
Spielfeld spielfeld(block_x, block_y, Spielfeld_x, Spielfeld_y, block_x_spieler, block_y_spieler);




class GameWindow : public Gosu::Window
{
	
public:
	// Konstruktor der GameWindow-Klasse
	GameWindow()
		: Window(Spielfeld_x, Spielfeld_y + 40) // Fenstergröße festlegen
	{
		set_caption("Gosu Tutorial mit Git"); // Fenstertitel festlegen

		spielfeld.initialisieren(); // Spielfeld initialisieren
	}
	// Wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt

	void draw() override
	{	//Überprüft, ob Spieler gewonnen haben

		// Überprüfen, ob Spieler 1 gewonnen hat
		if (spieler_1.Spieler_gewonnen()) {
			// Text anzeigen, wenn Spieler 1 gewonnen hat
			Gosu::Font(40).draw_text("Spieler 1 gewonnen", (width() - Gosu::Font(40).text_width("Spieler 1 gewonnen")) / 2, height() / 2, 1, 1);
		}
		// Überprüfen, ob Spieler 2 gewonnen hat
		else if (spieler_2.Spieler_gewonnen()) {
			// Text anzeigen, wenn Spieler 2 gewonnen hat
			Gosu::Font(40).draw_text("Spieler 2 gewonnen", (width() - Gosu::Font(40).text_width("Spieler 2 gewonnen")) / 2, height() / 2, 1, 1);
		}
		else {
			// Zeichnen des Spielfelds
			for (size_t x = 0; x < spielfeld.get_Spielfeld_x_Anzahl(); x++) {
				for (size_t y = 0; y < spielfeld.get_Spielfeld_y_Anzahl(); y++) {
					// Switch-Anweisung zum Zeichnen der verschiedenen Blöcke im Spielfeld
					switch (spielfeld.get_Matrix_Spielfeld().at(x).at(y).Typ) {
					case 0: // Randblock
						graphics().draw_rect(double(x * block_x), double(y * block_y), double(block_x), double(block_y), Gosu::Color::BLUE, 0);
						break;
					case 1: // Fester Block in der Mitte
						graphics().draw_rect(double(x * block_x), double(y * block_y), double(block_x), double(block_y), Gosu::Color::RED, 0);
						break;
					case 2: // Leerfeld
						break;
					case 3: // Zerstörbare Kiste
						graphics().draw_rect(double(x * block_x), double(y * block_y), double(block_x), double(block_y), Gosu::Color::GRAY, 0);
						break;
					default:
						break;
					}
				}
			}

			// Zeichnen der beiden Spieler
			graphics().draw_rect(double(spieler_1.get_act_Postion_X()), double(spieler_1.get_act_Postion_Y()), double(block_x_spieler), double(block_y_spieler), Gosu::Color::GREEN, 0);
			graphics().draw_rect(double(spieler_2.get_act_Postion_X()), double(spieler_2.get_act_Postion_Y()), double(block_x_spieler), double(block_y_spieler), Gosu::Color::YELLOW, 0);

			// Anzeigen der Anzahl der gesammelten Blöcke für jeden Spieler
			Gosu::Font(20).draw_text("Spieler 1: " + spieler_1.get_Anz_Bloecke() + "   Spieler 2: " + spieler_2.get_Anz_Bloecke(), 10, Spielfeld_y, 1, 1);
		}
	}
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
				
		// Wenn die rechte Pfeiltaste gedrückt ist
		if (input().down(Gosu::KB_RIGHT)) {
			// Bewege Spieler 1 nach rechts
			spieler_1.set_Postion_X_plus();

			// Überprüfe, ob ein Block gesammelt wurde
			if (spielfeld.Bloeck_sammelen(spieler_1.get_act_Postion_X(), spieler_1.get_act_Postion_Y()) == true) {
				spieler_1.Anz_Bloecke_plus(); // Erhöhe die Anzahl der gesammelten Blöcke
			}

			// Überprüfe, ob die neue Position im Spielfeld gültig ist
			if (spielfeld.ueberpruefen(spieler_1.get_act_Postion_X(), spieler_1.get_act_Postion_Y()) == false) {
				// Setze die Position zurück, falls ungültig
				spieler_1.set_Postion_X_minus();
			}
		}
		// Wenn die linke Pfeiltaste gedrückt ist
		else if (input().down(Gosu::KB_LEFT)) {
			// Bewege Spieler 1 nach links
			spieler_1.set_Postion_X_minus();

			// Überprüfe, ob ein Block gesammelt wurde
			if (spielfeld.Bloeck_sammelen(spieler_1.get_act_Postion_X(), spieler_1.get_act_Postion_Y()) == true) {
				spieler_1.Anz_Bloecke_plus(); // Erhöhe die Anzahl der gesammelten Blöcke
			}

			// Überprüfe, ob die neue Position im Spielfeld gültig ist
			if (spielfeld.ueberpruefen(spieler_1.get_act_Postion_X(), spieler_1.get_act_Postion_Y()) == false) {
				// Setze die Position zurück, falls ungültig
				spieler_1.set_Postion_X_plus();
			}
		}
		// Wenn die untere Pfeiltaste gedrückt ist
		else if (input().down(Gosu::KB_DOWN)) {
			// Bewege Spieler 1 nach unten
			spieler_1.set_Postion_Y_plus();

			// Überprüfe, ob ein Block gesammelt wurde
			if (spielfeld.Bloeck_sammelen(spieler_1.get_act_Postion_X(), spieler_1.get_act_Postion_Y()) == true) {
				spieler_1.Anz_Bloecke_plus(); // Erhöhe die Anzahl der gesammelten Blöcke
			}

			// Überprüfe, ob die neue Position im Spielfeld gültig ist
			if (spielfeld.ueberpruefen(spieler_1.get_act_Postion_X(), spieler_1.get_act_Postion_Y()) == false) {
				// Setze die Position zurück, falls ungültig
				spieler_1.set_Postion_Y_minus();
			}
		}
		// Wenn die obere Pfeiltaste gedrückt ist
		else if (input().down(Gosu::KB_UP)) {
			// Bewege Spieler 1 nach oben
			spieler_1.set_Postion_Y_minus();

			// Überprüfe, ob ein Block gesammelt wurde
			if (spielfeld.Bloeck_sammelen(spieler_1.get_act_Postion_X(), spieler_1.get_act_Postion_Y()) == true) {
				spieler_1.Anz_Bloecke_plus(); // Erhöhe die Anzahl der gesammelten Blöcke
			}

			// Überprüfe, ob die neue Position im Spielfeld gültig ist
			if (spielfeld.ueberpruefen(spieler_1.get_act_Postion_X(), spieler_1.get_act_Postion_Y()) == false) {
				// Setze die Position zurück, falls ungültig
				spieler_1.set_Postion_Y_plus();
			}
		}

		// Steuerung für Spieler 2
		if (input().down(Gosu::KB_D)) {
			// Bewege Spieler 2 nach rechts
			spieler_2.set_Postion_X_plus();

			// Überprüfe, ob ein Block gesammelt wurde
			if (spielfeld.Bloeck_sammelen(spieler_2.get_act_Postion_X(), spieler_2.get_act_Postion_Y()) == true) {
				spieler_2.Anz_Bloecke_plus(); // Erhöhe die Anzahl der gesammelten Blöcke
			}

			// Überprüfe, ob die neue Position im Spielfeld gültig ist
			if (spielfeld.ueberpruefen(spieler_2.get_act_Postion_X(), spieler_2.get_act_Postion_Y()) == false) {
				// Setze die Position zurück, falls ungültig
				spieler_2.set_Postion_X_minus();
			}
		}
		// Wenn Taste A gedrückt wird, bewege Spieler 2 nach links
		else if (input().down(Gosu::KB_A)) {
			spieler_2.set_Postion_X_minus(); // Verringere die X-Position von Spieler 2
			if (spielfeld.Bloeck_sammelen(spieler_2.get_act_Postion_X(), spieler_2.get_act_Postion_Y()) == true) {
				spieler_2.Anz_Bloecke_plus(); // Erhöhe die Anzahl der gesammelten Blöcke
			}
			if (spielfeld.ueberpruefen(spieler_2.get_act_Postion_X(), spieler_2.get_act_Postion_Y()) == false) {
				spieler_2.set_Postion_X_plus(); // Setze die Position zurück, falls ungültig
			}
		}

		// Wenn Taste S gedrückt wird, bewege Spieler 2 nach unten
		else if (input().down(Gosu::KB_S)) {
			spieler_2.set_Postion_Y_plus(); // Erhöhe die Y-Position von Spieler 2
			if (spielfeld.Bloeck_sammelen(spieler_2.get_act_Postion_X(), spieler_2.get_act_Postion_Y()) == true) {
				spieler_2.Anz_Bloecke_plus(); // Erhöhe die Anzahl der gesammelten Blöcke
			}
			if (spielfeld.ueberpruefen(spieler_2.get_act_Postion_X(), spieler_2.get_act_Postion_Y()) == false) {
				spieler_2.set_Postion_Y_minus(); // Setze die Position zurück, falls ungültig
			}
		}


		// Wenn Taste W gedrückt wird, bewege Spieler 2 nach oben
		else if (input().down(Gosu::KB_W)) {
			spieler_2.set_Postion_Y_minus(); // Verringere die Y-Position von Spieler 2

			// Überprüfe, ob ein Block gesammelt wurde
			if (spielfeld.Bloeck_sammelen(spieler_2.get_act_Postion_X(), spieler_2.get_act_Postion_Y()) == true) {
				spieler_2.Anz_Bloecke_plus(); // Erhöhe die Anzahl der gesammelten Blöcke
			}

			// Überprüfe, ob die neue Position im Spielfeld gültig ist
			if (spielfeld.ueberpruefen(spieler_2.get_act_Postion_X(), spieler_2.get_act_Postion_Y()) == false) {
				// Setze die Position zurück, falls ungültig
				spieler_2.set_Postion_Y_plus();
			}
		}


	}

};



// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
};




