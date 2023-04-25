#pragma once
#include "Camisa.h"

class Camiseta :public Camisa {
private:
	bool cuelloV;

public:
	Camiseta();
	Camiseta(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};
