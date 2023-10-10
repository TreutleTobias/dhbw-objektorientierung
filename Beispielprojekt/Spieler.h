#pragma once
class Spieler //: public Gosu::GameWindow
{

private: //Standartm‰ﬂig

	int act_Postion_X;
	int act_Postion_Y;

public:
	Spieler(int StartPosition_X, int StartPosition_Y);
	int get_act_Postion_X() const;
	int get_act_Postion_Y() const;
	void set_Postion_X_plus();
	void set_Postion_X_minus();
	void set_Postion_Y_plus();
	void set_Postion_Y_minus();
	

};

