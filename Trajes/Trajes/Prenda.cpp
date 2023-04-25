#include "Prenda.h"

Prenda::Prenda(string cod, double pre) {
	codigo = cod;
	precio = pre;
}

string Prenda::getID(){
	return codigo;
}

double Prenda::getPrecio() {
	return precio;
}

string Prenda::toString() {
	stringstream s;
	s << "Codigo: " << codigo << " | " << "Precio: $" << precio << endl << endl;
	return s.str();
}
