#pragma once
#include<iostream>
#include <sstream>
using namespace std;

//observa
class Cliente{	//Abstracta-> al menos un metodo virtual puro

protected:
	string mensaje;
	double pagoSubs;
	string nombre;
	string cedula;
	string correo;
	string pais;
	string ciudad;

public:
	Cliente();
	string getNombre();
	string getID();
	string getCorreo();
	double getpagoSubs();
	string getPais();
	string getCiudad();
	void residencia();
	void mensajePeticion();
	virtual void actualizar(string) = 0;
	string toString();
};

