#include "Pantaloneta.h"

Pantaloneta::Pantaloneta() :Pantalon() {
	estampada = true;
}

Pantaloneta::Pantaloneta(double p, string t, string c, string cod, bool x) : Pantalon() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	estampada = x;
}

double Pantaloneta::getPrecio() {
	return precio;
}

string Pantaloneta::getTalla() {
	return talla;
}

string Pantaloneta::getColor() {
	return color;
}

string Pantaloneta::getCodigo() {
	return codigo;
}

bool Pantaloneta::getX() {
	return estampada;
}

string Pantaloneta::toString() {
	stringstream s;
	if (estampada) {
		s << "Pantaloneta " << color << " estampada. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Pantaloneta " << color << " no estampada. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}