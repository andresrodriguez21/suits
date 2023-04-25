#pragma once
#include "Pantalon.h"

class DeVestir :public Pantalon {
private:
	bool casimir;
public:
	DeVestir();
	DeVestir(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};