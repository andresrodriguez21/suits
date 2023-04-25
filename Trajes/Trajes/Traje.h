#pragma once
#include<iostream>
#include <sstream>
#include "InterfazTraje.h"
#include "Camisa.h"
#include "Pantalon.h"
#include "Zapato.h"

using namespace std;

class Traje{
protected:
	double vecesVendido;
	double precio;
	string codigo;
	string tipo;
	//
	Camisa* ptrCamisa;
	Pantalon* ptrPantalon;
	Zapato* ptrZapato;

public:
	virtual Camisa* crearCamisa() = 0;
	virtual Pantalon* crearPantalon() = 0;
	virtual Zapato* crearZapato() = 0;

	virtual Camisa* getCamisa() = 0;
	virtual Pantalon* getPantalon() = 0;
	virtual Zapato* getZapato() = 0;

	virtual double getPrecio() = 0;
	virtual string getID() = 0;
	virtual string getTipo() = 0;
	virtual int getVecesVendido() = 0;
	virtual void setVecesVendido() = 0;
	virtual string toString() = 0;
};