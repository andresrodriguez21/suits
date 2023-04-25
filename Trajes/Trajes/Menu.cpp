#include "Menu.h"

Menu::Menu() {
}

bool Menu::verificaDatabase() {
	if (delegar->verificaDatabase()) {
		return true;
	}
	else {
		return false;
	}
}

void Menu::menuPrincipal() {
	int opc = 0;

	system("cls");
	cout << endl;
	cout << "      T R A J E S" << endl << endl;
	cout << "  1. Venta directa" << endl;
	cout << "  2. Venta en linea" << endl;
	cout << "  3. Mantenimiento" << endl;
	cout << "  4. Salir" << endl << endl;
	cout << "  Digite la opcion: ";

	try {

		if (cin >> opc) {

			switch (opc) {

			case 1:
				delegar->ventaDirecta();
				break;

			case 2:
				delegar->ventaEnLinea();
				break;

			case 3:
				mantenimiento();
				break;

			case 4:
				delegar->guardar();
				exit(0);
				break;

			default:
				menuPrincipal();
			}

		}

		else {
			throw new Excepcion();
		}

	}//try

	catch (Excepcion* e) {
	e->palabraDigitada();
	delegar->limpiaVariables();
	}

	catch (...) {
	cout << "Error indeterminado" << endl;
	delegar->limpiaVariables();
	}
	
	menuPrincipal();
}

//3
void Menu::mantenimiento() {
	int opc = 0;
	system("cls");
	cout << endl;
	cout << "      Mantenimiento" << endl << endl;
	cout << "  1.  Ingresar cliente" << endl;
	cout << "  2.  Ingresar traje" << endl;
	cout << "  3.  Eliminar traje" << endl;
	cout << "  4.  Ver trajes" << endl;
	cout << "  5.  Ver clientes fisicos" << endl;
	cout << "  6.  Ver clientes empresa" << endl;
	cout << "  7.  Ventas totales sin ganancia" << endl;
	cout << "  8.  Ventas totales con ganancia" << endl;
	cout << "  9.  Ganancia neta de la tienda" << endl;
	cout << " 10.  Traje mas vendido" << endl << endl;
	cout << "  Digite la opcion: ";

	try {

		if (cin >> opc) {

			switch (opc) {

			case 1:
				delegar->ingresarCliente();
				break;

			case 2:
				delegar->ingresarTraje();
				break;

			case 3:
				delegar->eliminarTraje();
				break;

			case 4:
				delegar->verLista("			Stock", 1);
				system("pause");
				break;

			case 5:
				delegar->verLista("	Clientes fisicos", 2);
				break;

			case 6:
				delegar->verLista("	Clientes empresa", 3);
				break;

			case 7:
				delegar->verLista("	Ventas sin ganancia", 4);
				break;

			case 8:
				delegar->verLista("	Ventas con ganancia", 5);
				break;

			case 9:
				delegar->verLista("		Ganancia neta de tienda", 6);
				break;

			case 10:
				delegar->verLista("			Traje mas vendido", 7);
				break;

			case 11:
				delegar->verLista("	Database",8);
				break;

			default:
				menuPrincipal();

			}

		}

		else {
			throw new Excepcion();
		}

	}//try

	catch (Excepcion* e) {
		e->palabraDigitada();
		delegar->limpiaVariables();

	}

	catch (...) {
		cout << "Error indeterminado" << endl;
			delegar->limpiaVariables();
	}

	menuPrincipal();

}