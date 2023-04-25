#include "Tenni.h"

Tenni::Tenni() :Zapato() {
	adidas = true;
}

Tenni::Tenni(double p, string t, string c, string cod, bool x) : Zapato() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	adidas = x;
}

double Tenni::getPrecio() {
	return precio;
}

string Tenni::getTalla() {
	return talla;
}

string Tenni::getColor() {
	return color;
}

string Tenni::getCodigo() {
	return codigo;
}

bool Tenni::getX() {
	return adidas;
}

string Tenni::toString() {
	stringstream s;
	if (adidas) {
		s << "Tennis " << color << " Adidas. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Tennis " << color << " genericas. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}