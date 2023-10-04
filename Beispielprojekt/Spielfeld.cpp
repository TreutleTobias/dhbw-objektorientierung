#include "Spielfeld.h"

Spielfeld::Spielfeld(int block_x, int block_y, int Spielfeld_x, int Spielfeld_y)
    : block_x(block_x), block_y(block_y), Spielfeld_x(Spielfeld_x), Spielfeld_y(Spielfeld_y),
    spielfeld_x_Anzahl(Spielfeld_x / block_x), spielfeld_y_Anzahl(Spielfeld_y / block_y)
{
    // Andere Konstruktorenlogik, falls erforderlich

}

int Spielfeld::get_block_x() const { return this->block_x; }
int Spielfeld::get_block_y() const { return this->block_y; }
int Spielfeld::get_Spielfeld_x() const { return this->Spielfeld_x; }
int Spielfeld::get_Spielfeld_y() const { return this->Spielfeld_y; }
vector<vector<Block>> Spielfeld::get_Matrix_Spielfeld() { return this->spielfeld_matrix; };

void Spielfeld::initialisieren() {

	
	for (size_t x = 0; x < this ->spielfeld_x_Anzahl; x++) {
		vector<Block> v;
		for (size_t y = 0; y < this->spielfeld_y_Anzahl; y++) {

			
			Block b;
			if (y == 0 || y == this-> spielfeld_y_Anzahl - 1 || x == 0 || x == this-> spielfeld_x_Anzahl - 1) {

				b.Typ = 0;

			}
			else if (y % 2 == 0 && x % 2 == 0) {

				b.Typ = 1;
			}
			else {
				b.Typ = 2;
			}
			v.push_back(b);
		}

		this->spielfeld_matrix.push_back(v);

	}

};