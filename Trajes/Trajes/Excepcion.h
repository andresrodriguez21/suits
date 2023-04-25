#pragma once
#include<iostream>
#include <sstream>
#include<exception>
using namespace std;

class Excepcion : public exception {
public:
	Excepcion();
	void palabraDigitada();
	void guardaArchivo(string);
	void cargaArchivo(string);
};

