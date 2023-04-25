#include "Ejecutivo.h"

Ejecutivo::Ejecutivo() :Zapato() {
	fino = true;
}

Ejecutivo::Ejecutivo(double p, string t, string c, string cod, bool x) : Zapato() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	fino= x;
}

double Ejecutivo::getPrecio() {
	return precio;
}

string Ejecutivo::getTalla() {
	return talla;
}

string Ejecutivo::getColor() {
	return color;
}

string Ejecutivo::getCodigo() {
	return codigo;
}

bool Ejecutivo::getX() {
	return fino;
}

string Ejecutivo::toString() {
	stringstream s;
	if (fino) {
		s << "Zapatos " << color << " ejecutivos (finos). Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Zapatos " << color << " ejecutivos (no finos). Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}