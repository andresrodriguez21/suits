#pragma once
#include<iostream>
#include <sstream>
#include "Cliente.h"
using namespace std;

class Empresa:public Cliente{
private:
	bool frecuente;
public:
	Empresa(string);
	Empresa(double, string, string, string, string, string, bool);
	void actualizar(string);
	bool getFrecuente();
	string toString();
};