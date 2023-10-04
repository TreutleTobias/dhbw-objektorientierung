#pragma once


#include <vector>
#include <iostream>
using namespace std;
struct Block
{
	int Typ; // 0 =  Umrandung des Spielfelds , 1 = fester Block in der Mitte , 2= Leer Feld, 3= zerstörbare Kiste
	int farbe;
};

class Spielfeld //: public Gosu::GameWindow
{

private: //Standartmäßig

	const int block_x; // Größe in X
	const int block_y; // Größe in Y
	const int Spielfeld_x;
	const int Spielfeld_y;
	const int spielfeld_x_Anzahl;
	const int spielfeld_y_Anzahl;
	vector<vector<Block>> spielfeld_matrix;

public:
	Spielfeld(int block_x, int block_y, int Spielfeld_x, int Spielfeld_y);
	int get_block_x() const;
	int get_block_y() const;
	int get_Spielfeld_x() const;
	int get_Spielfeld_y() const;
	void initialisieren();
	vector<vector<Block>> get_Matrix_Spielfeld();


};