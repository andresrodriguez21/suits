#pragma once
#include "Pantalon.h"

class Pantaloneta :public Pantalon {
private:
	bool estampada;
public:
	Pantaloneta();
	Pantaloneta(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};