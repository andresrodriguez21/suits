#include "TrajeEjecutivo.h"

TrajeEjecutivo::TrajeEjecutivo(string tip, double cant) :Traje() {
	tipo = tip;
	vecesVendido = cant;
	ptrCamisa = crearCamisa();
	ptrPantalon = crearPantalon();
	ptrZapato = crearZapato();
}

TrajeEjecutivo::TrajeEjecutivo(string tip, double cant, Camisa* camisa, Pantalon* pantalon, Zapato* zapato) :Traje() {
	tipo = tip;
	vecesVendido = cant;
	ptrCamisa = camisa;
	ptrPantalon = pantalon;
	ptrZapato = zapato;
}

Camisa* TrajeEjecutivo::crearCamisa() {
	return InterfazTraje::crearMangaLarga();
}

Pantalon* TrajeEjecutivo::crearPantalon() {
	return InterfazTraje::crearVestir();
}

Zapato* TrajeEjecutivo::crearZapato() {
	return InterfazTraje::crearEjecutivo();
}

Camisa* TrajeEjecutivo::getCamisa() {
	return ptrCamisa;
}

Pantalon* TrajeEjecutivo::getPantalon() {
	return ptrPantalon;
}

Zapato* TrajeEjecutivo::getZapato() {
	return ptrZapato;
}

string TrajeEjecutivo::getID() {
	codigo = ptrCamisa->getCodigo() + ptrPantalon->getCodigo() + ptrZapato->getCodigo();
	return codigo;
}

string TrajeEjecutivo::getTipo() {
	return tipo;
}

int TrajeEjecutivo::getVecesVendido() {
	return vecesVendido;
}

void TrajeEjecutivo::setVecesVendido() {
	vecesVendido++;
}

double TrajeEjecutivo::getPrecio() {
	precio = ptrCamisa->getPrecio() + ptrPantalon->getPrecio() + ptrZapato->getPrecio();
	return precio;
}

string TrajeEjecutivo::toString() {
	stringstream s;
	s << "---------------------Traje ejecutivo---------------------" << endl << endl;
	s << "Codigo del traje: " << getID() << "	| Lo han comprado " << vecesVendido << " veces." << endl;
	s << "Precio del traje: $" << getPrecio() << endl << endl;
	s << ptrCamisa->toString();
	s << ptrPantalon->toString();
	s << ptrZapato->toString();
	s << "---------------------------------------------------------" << endl << endl;
	return s.str();
}