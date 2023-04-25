#pragma once
#include "Camisa.h"

class MangaLarga :public Camisa {
private:
	bool lisa;
public:
	MangaLarga();
	MangaLarga(double, string, string, string, bool);
	double getPrecio();
	string getTalla();
	string getColor();
	string getCodigo();
	bool getX();
	string toString();
};