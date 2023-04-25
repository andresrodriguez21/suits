#include "TrajeDeportivo.h"

TrajeDeportivo::TrajeDeportivo(string tip, double cant) :Traje() {
	tipo = tip;
	vecesVendido = cant;
	ptrCamisa = crearCamisa();
	ptrPantalon = crearPantalon();
	ptrZapato = crearZapato();
}

TrajeDeportivo::TrajeDeportivo(string tip, double cant, Camisa* camisa, Pantalon* pantalon, Zapato* zapato):Traje() {
	tipo = tip;
	vecesVendido = cant;
	ptrCamisa = camisa;
	ptrPantalon = pantalon;
	ptrZapato = zapato;
}

Camisa* TrajeDeportivo::crearCamisa() {
	return InterfazTraje::crearCamiseta();
}

Pantalon* TrajeDeportivo::crearPantalon() {
	return InterfazTraje::crearPantaloneta();
}

Zapato* TrajeDeportivo::crearZapato() {
	return InterfazTraje::crearTenni();
}

Camisa* TrajeDeportivo::getCamisa() {
	return ptrCamisa;
}

Pantalon* TrajeDeportivo::getPantalon() {
	return ptrPantalon;
}

Zapato* TrajeDeportivo::getZapato() {
	return ptrZapato;
}

string TrajeDeportivo::getID() {
	codigo = ptrCamisa->getCodigo() + ptrPantalon->getCodigo() + ptrZapato->getCodigo();
	return codigo;
}

string TrajeDeportivo::getTipo() {
	return tipo;
}

int TrajeDeportivo::getVecesVendido() {
	return vecesVendido;
}

void TrajeDeportivo::setVecesVendido() {
	vecesVendido++;
}

double TrajeDeportivo::getPrecio() {
	precio = ptrCamisa->getPrecio() + ptrPantalon->getPrecio() + ptrZapato->getPrecio();
	return precio;
}

string TrajeDeportivo::toString() {
	stringstream s;
	s << "---------------------Traje deportivo---------------------" << endl << endl;
	s << "Codigo del traje: " << getID() << "	| Lo han comprado " << vecesVendido << " veces." << endl;
	s << "Precio del traje: $" << getPrecio() << endl << endl;
	s << ptrCamisa->toString();
	s << ptrPantalon->toString(); 
	s << ptrZapato->toString();
	s << "---------------------------------------------------------" << endl << endl;
	return s.str();
}