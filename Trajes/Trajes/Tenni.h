#pragma once
#include "Zapato.h"

class Tenni :public Zapato {
private:
	bool adidas;

public:
	Tenni();
	Tenni(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};