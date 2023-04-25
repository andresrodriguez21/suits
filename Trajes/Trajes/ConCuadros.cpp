#include "ConCuadros.h"

ConCuadros::ConCuadros() :Camisa() {
	grandes = true;
}

ConCuadros::ConCuadros(double p, string t, string c, string cod, bool x) :Camisa() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	grandes = x;
}

double ConCuadros::getPrecio() {
	return precio;
}

string ConCuadros::getTalla() {
	return talla;
}

string ConCuadros::getColor() {
	return color;
}

string ConCuadros::getCodigo() {
	return codigo;
}

bool ConCuadros::getX() {
	return grandes;
}

string ConCuadros::toString() {
	stringstream s;
	if (grandes) {
		s << "Camisa " << color << " de cuadros grandes. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Camisa " << color << " de cuadros pequenos. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}