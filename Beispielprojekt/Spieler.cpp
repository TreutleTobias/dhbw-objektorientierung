#include "Spieler.h"

Spieler::Spieler(int StartPosition_X, int StartPosition_Y)
{
	act_Postion_X = StartPosition_X;
	act_Postion_Y = StartPosition_Y;
};

int Spieler::get_act_Postion_X() const {

	return this->act_Postion_X;
};

int Spieler::get_act_Postion_Y() const {

	return this->act_Postion_Y;
};

void Spieler::set_Postion_X_plus() {

	this->act_Postion_X++;

};
void Spieler::set_Postion_X_minus() {

	this->act_Postion_X--;

};
void Spieler::set_Postion_Y_plus() {

	this->act_Postion_Y++;

};
void Spieler::set_Postion_Y_minus() {

	this->act_Postion_Y--;

};
