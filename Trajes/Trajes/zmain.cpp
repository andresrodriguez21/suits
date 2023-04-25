//Andres Rodriguez Castro (402390116)
//20 junio 2022 Listo para entregar

#include <iostream>
#include <sstream>
#include "Menu.h"

using namespace std;

int main() {
	system("color F0");
	Menu m;
	if (m.verificaDatabase()) {
	m.menuPrincipal();
	}
	else {
		cout << endl;
		cout << "Error grave, no existe una base de datos de precios y codigos" << endl << endl;
		system("pause");
	}

	return 0;
}
