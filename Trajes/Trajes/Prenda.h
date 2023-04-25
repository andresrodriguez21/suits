#pragma once
#include<iostream>
#include <sstream>
using namespace std;

class Prenda{
private:
	string codigo;
	double precio;

public:
	Prenda(string, double);
	string getID();
	double getPrecio();
	string toString();
};

