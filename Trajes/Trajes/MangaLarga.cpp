#include "MangaLarga.h"

MangaLarga::MangaLarga() :Camisa() {
	lisa = true;
}

MangaLarga::MangaLarga(double p, string t, string c, string cod, bool x) :Camisa() {
	precio = p;
	talla = t;
	color = c;
	codigo = cod;
	lisa = x;
}

double MangaLarga::getPrecio() {
	return precio;
}

string MangaLarga::getTalla() {
	return talla;
}

string MangaLarga::getColor() {
	return color;
}

string MangaLarga::getCodigo() {
	return codigo;
}

bool MangaLarga::getX() {
	return lisa;
}

string MangaLarga::toString() {
	stringstream s;
	if (lisa) {
		s << "Camisa " << color << " de manga larga (lisa). Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	else {
		s << "Camisa " << color << " de manga larga (no lisa). Talla " << talla << " (" << codigo << "): " << "$" << precio << endl << endl;
	}
	return s.str();
}