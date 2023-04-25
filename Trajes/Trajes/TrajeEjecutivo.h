#pragma once
#include "Traje.h"

class TrajeEjecutivo:public Traje{

public:
	TrajeEjecutivo(string, double);
	TrajeEjecutivo(string, double, Camisa*, Pantalon*, Zapato*);

	Camisa* crearCamisa();
	Pantalon* crearPantalon();
	Zapato* crearZapato();

	Camisa* getCamisa();
	Pantalon* getPantalon();
	Zapato* getZapato();

	double getPrecio();
	string getID();
	string getTipo();
	int getVecesVendido();
	void setVecesVendido();
	string toString();
};

