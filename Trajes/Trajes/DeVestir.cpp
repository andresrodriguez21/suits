#include "DeVestir.h"

DeVestir::DeVestir() :Pantalon() {
	casimir = true;
}

DeVestir::DeVestir(double p, string t, string c, string cod, bool x) : Pantalon() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	casimir = x;
}

double DeVestir::getPrecio() {
	return precio;
}

string DeVestir::getTalla() {
	return talla;
}

string DeVestir::getColor() {
	return color;
}

string DeVestir::getCodigo() {
	return codigo;
}

bool DeVestir::getX() {
	return casimir;
}

string DeVestir::toString() {
	stringstream s;
	if (casimir) {
		s << "Pantalon " << color << " de vestir (casimir). Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Pantalon " << color << " de vestir (no casimir). Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}