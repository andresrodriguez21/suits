#pragma once
#include<iostream>
#include <sstream>
#include "InterfazMenu.h"
#include "Excepcion.h"

using namespace std;

class Menu{

private:
	InterfazMenu* delegar = new InterfazMenu();

public:
	Menu();
	bool verificaDatabase();
	void menuPrincipal();
	void mantenimiento();
};

