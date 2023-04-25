#pragma once
#include "Pantalon.h"

class Jeans:public Pantalon{
private:
	bool ajustados;
public:
	Jeans();
	Jeans(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};