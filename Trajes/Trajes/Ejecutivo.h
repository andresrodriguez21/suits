#pragma once
#include "Zapato.h"

class Ejecutivo :public Zapato {
private:
	bool fino;

public:
	Ejecutivo();
	Ejecutivo(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};
