#pragma once
#include<iostream>
#include <sstream>
using namespace std;

class Camisa{
protected:
	double precio = 0;
	string talla;
	string color;
	string codigo;
public:
	Camisa() {}
	virtual double getPrecio() = 0;
	virtual string getTalla() = 0;
	virtual string getColor() = 0;
	virtual string getCodigo() = 0;
	virtual bool getX() = 0;
	virtual string toString() = 0;
};