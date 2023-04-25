#pragma once
#include<iostream>
#include <sstream>
#include "Excepcion.h"
#include "Lista.h"
#include "Prenda.h"

using namespace std;

class InterfazMenu{
private:
	Lista<Prenda>* database = new Lista<Prenda>;
	Lista<Traje>* stock = new Lista<Traje>;
	Lista<Persona>* listaClientesFisicos = new Lista<Persona>;
	Lista<Empresa>* listaClientesEmpresa = new Lista<Empresa>;
	Lista<Venta>* listaVentas = new Lista<Venta>;
	Venta* ptrVenta;


public:
	InterfazMenu();
	Lista<Prenda>* getDatabase();
	Lista<Traje>* getStock();
	void limpiaVariables();
	void notifica(string);

	void ingresaNuevaVenta(Lista<Traje>*, double, double);
	//1
	void ventaDirecta();
	//2
	void ventaEnLinea();
	double existeCliente();
	void menuEnLinea(double);
	void escogerDelStock(double);
	void crearYcomprar(double);

	//3
	void ingresarCliente();
	void ingresarTraje();
	Lista<Traje>* crearTrajeAMedida(Lista<Traje>*);
	void eliminarTraje();
	void verLista(string, int);
	void mensajeAdvertencia();
	bool verificaDatabase();
	void cargar();
	void guardar();	
};

