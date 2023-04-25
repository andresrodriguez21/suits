#include "TrajeTrabajo.h"

TrajeTrabajo::TrajeTrabajo(string tip, double cant) :Traje() {
	tipo = tip;
	vecesVendido = cant;
	ptrCamisa = crearCamisa();
	ptrPantalon = crearPantalon();
	ptrZapato = crearZapato();
}

TrajeTrabajo::TrajeTrabajo(string tip, double cant, Camisa* camisa, Pantalon* pantalon, Zapato* zapato) :Traje() {
	tipo = tip;
	vecesVendido = cant;
	ptrCamisa = camisa;
	ptrPantalon = pantalon;
	ptrZapato = zapato;
}

Camisa* TrajeTrabajo::crearCamisa() {
	return InterfazTraje::crearConCuadros();
}

Pantalon* TrajeTrabajo::crearPantalon() {
	return InterfazTraje::crearJeans();
}

Zapato* TrajeTrabajo::crearZapato() {
	return InterfazTraje::crearBota();
}

Camisa* TrajeTrabajo::getCamisa() {
	return ptrCamisa;
}

Pantalon* TrajeTrabajo::getPantalon() {
	return ptrPantalon;
}

Zapato* TrajeTrabajo::getZapato() {
	return ptrZapato;
}

string TrajeTrabajo::getID() {
	codigo = ptrCamisa->getCodigo() + ptrPantalon->getCodigo() + ptrZapato->getCodigo();
	return codigo;
}

string TrajeTrabajo::getTipo() {
	return tipo;
}

int TrajeTrabajo::getVecesVendido() {
	return vecesVendido;
}

void TrajeTrabajo::setVecesVendido() {
	vecesVendido++;
}

double TrajeTrabajo::getPrecio() {
	precio = ptrCamisa->getPrecio() + ptrPantalon->getPrecio() + ptrZapato->getPrecio();
	return precio;
}

string TrajeTrabajo::toString() {
	stringstream s;
	s << "---------------------Traje de trabajo--------------------" << endl << endl;
	s << "Codigo del traje: " << getID() << "	| Lo han comprado " << vecesVendido << " veces." << endl;
	s << "Precio del traje: $" << getPrecio() << endl << endl;
	s << ptrCamisa->toString();
	s << ptrPantalon->toString();
	s << ptrZapato->toString();
	s << "---------------------------------------------------------" << endl << endl;
	return s.str();
}