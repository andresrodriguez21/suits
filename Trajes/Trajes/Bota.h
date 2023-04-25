#pragma once
#include "Zapato.h"

class Bota :public Zapato {

private:
	bool alta;

public:
	Bota();
	Bota(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};
