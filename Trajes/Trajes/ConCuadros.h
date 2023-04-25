#pragma once
#include "Camisa.h"
class ConCuadros : public Camisa {
private:
	bool grandes;
public:
	ConCuadros();
	ConCuadros(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};