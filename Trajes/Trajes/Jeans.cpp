#include "Jeans.h"

Jeans::Jeans() :Pantalon() {
	ajustados = true;
}

Jeans::Jeans(double p, string t, string c, string cod, bool x) : Pantalon() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	ajustados = x;
}

double Jeans::getPrecio() {
	return precio;
}

string Jeans::getTalla() {
	return talla;
}

string Jeans::getColor() {
	return color;
}

string Jeans::getCodigo() {
	return codigo;
}

bool Jeans::getX() {
	return ajustados;
}

string Jeans::toString() {
	stringstream s;
	if (ajustados) {
		s << "Jeans " << color << " ajustados. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Jeans " << color << " no ajustados. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}