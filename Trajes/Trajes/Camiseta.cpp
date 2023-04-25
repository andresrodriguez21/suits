#include "Camiseta.h"

Camiseta::Camiseta() :Camisa() {
	cuelloV = true;
}

Camiseta::Camiseta(double p, string t, string c, string cod, bool x) :Camisa() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	cuelloV = x;
}

double Camiseta::getPrecio() {
	return precio;
}

string Camiseta::getTalla() {
	return talla;
}

string Camiseta::getColor() {
	return color;
}

string Camiseta::getCodigo() {
	return codigo;
}

bool Camiseta::getX() {
	return cuelloV;
}

string Camiseta::toString() {
	stringstream s;
	if (cuelloV) {
		s << "Camiseta " << color << " de cuello V. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Camiseta " << color << " de cuello redondo. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}