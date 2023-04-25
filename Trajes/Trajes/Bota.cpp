#include "Bota.h"

Bota::Bota():Zapato(){
	alta = true;
}

Bota::Bota(double p, string t, string c, string cod, bool x) : Zapato() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	alta= x;
}

double Bota::getPrecio() {
	return precio;
}

string Bota::getTalla() {
	return talla;
}

string Bota::getColor() {
	return color;
}

string Bota::getCodigo() {
	return codigo;
}

bool Bota::getX() {
	return alta;
}

string Bota::toString() {
	stringstream s;
	if (alta) {
		s << "Botas " << color << " altas. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Botas " << color << " bajas. Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}