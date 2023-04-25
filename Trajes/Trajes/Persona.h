#pragma once
#include<iostream>
#include <sstream>
#include "Cliente.h"
using namespace std;

class Persona :public Cliente {
private:
	string nacionalidad;
public:
	Persona(string);
	Persona(double, string, string, string, string, string, string);
	void actualizar(string);
	string getNacionalidad();
	string toString();
};

