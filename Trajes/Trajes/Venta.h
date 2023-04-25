#pragma once
#include<iostream>
#include <sstream>
#include "Cliente.h"
using namespace std;

class Venta{
private:
	string fecha;
	string motivo;
	double precioBase;
	double gananciaTraje;
	double costoEnvio;
	double IVA;

public:
	Venta();
	Venta(string, double, double);
	string getMotivo();
	double getPrecio();
	double getGanancia();
	double getCostoEnvio();
	double calculaCostoEnvio(string);
	string verFactura();
	string verSinGanancia();
	string verConGanancia();
};

