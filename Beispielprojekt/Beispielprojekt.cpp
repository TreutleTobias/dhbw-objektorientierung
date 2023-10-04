#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include "Spieler.h"
#include "Spielfeld.h"
#include <vector>
#include <iostream>
using namespace std;
const int block_x = 20; // Größe in X
const int block_y = 20; // Größe in Y
const int Spielfeld_x = 780;
const int Spielfeld_y = 580;
const int spielfeld_x_Anzahl = Spielfeld_x / block_x; // Spiel besteht aus 5 Blöcken
const int spielfeld_y_Anzahl = Spielfeld_y / block_y;



/*struct Block
{
	int Typ; // 0 =  Umrandung des Spielfelds , 1 = fester Block in der Mitte , 2= Leer Feld, 3= zerstörbare Kiste
	int farbe;
};
*/


Spieler spieler_1(block_x, block_y);

Spielfeld spielfeld(block_x, block_y, Spielfeld_x, Spielfeld_y);



class GameWindow : public Gosu::Window
{
	//Block Spielfeld[spielfeld_x_Anzahl][spielfeld_y_Anzahl];




public:

	GameWindow()
		: Window(Spielfeld_x, Spielfeld_y)
	{
		set_caption("Gosu Tutorial mit Git");

		spielfeld.initialisieren();

		/*for (size_t x = 0; x < spielfeld_x_Anzahl; x++) {

			for (size_t y = 0; y < spielfeld_y_Anzahl; y++) {

				if (y == 0 || y == spielfeld_y_Anzahl - 1 || x == 0 || x == spielfeld_x_Anzahl - 1) {

					Spielfeld[x][y].Typ = 0;

				}
				else if (y % 2 == 0 && x % 2 == 0) {

					Spielfeld[x][y].Typ = 1;
				}
				else {
					Spielfeld[x][y].Typ = 2;
				}
			}
		}*/



	}
	// Wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		for (size_t x = 0; x < spielfeld_x_Anzahl; x++) {

			for (size_t y = 0; y < spielfeld_y_Anzahl; y++) {
				switch (spielfeld.get_Matrix_Spielfeld().at(x).at(y).Typ)
				{
				case 0: graphics().draw_rect(double(x * block_x), double(y * block_y), double(block_x), double(block_y), Gosu::Color::BLUE, 0);
					break;
				case 1: graphics().draw_rect(double(x * block_x), double(y * block_y), double(block_x), double(block_y), Gosu::Color::RED, 0);
					break;
				case 2: break;
				default:
					break;
				}


			}

		}

		graphics().draw_rect(double(spieler_1.get_act_Postion_X()), double(spieler_1.get_act_Postion_Y()), double(block_x), double(block_y), Gosu::Color::WHITE, 0);


	}
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		//spieler_1.act_Postion_X = input().mouse_x(); Bewegung über die Maus
		//spieler_1.act_Postion_Y =input().mouse_y();

		if (input().down(Gosu::KB_RIGHT)) {

			spieler_1.set_Postion_X_plus();

		}
		else if (input().down(Gosu::KB_LEFT)) {

			spieler_1.set_Postion_X_minus();

		}
		else if (input().down(Gosu::KB_DOWN)) {

			spieler_1.set_Postion_Y_plus();

		}
		else if (input().down(Gosu::KB_UP)) {

			spieler_1.set_Postion_Y_minus();

		}

	}

};



// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
};




