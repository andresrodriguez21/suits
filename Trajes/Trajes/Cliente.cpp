#include "Cliente.h"

Cliente::Cliente() {
	mensaje = "null";
	pagoSubs = 0;
}

string Cliente::getNombre(){
	return nombre;
}

string Cliente::getID() {
	return cedula;
}

string Cliente::getCorreo(){
	return correo;
}

double Cliente::getpagoSubs(){
	return pagoSubs;
}

string Cliente::getPais(){
	return pais;
}

string Cliente::getCiudad() {
	return ciudad;
}

void Cliente::residencia() {
	flashpoint:
	system("cls");
	string nada;
	int opc = 0;
	cout << "			Residencia" << endl;
	cout << "1. New York, Estados Unidos  | 6. Ontairo, Canada" << endl;
	cout << "2. Paris, Francia            | 7. Londres, Inglaterra" << endl;
	cout << "3. Milan, Italia             | 8. California, Estados Unidos" << endl;
	cout << "4. Brasilia, Brasil          | 9. Costa Rica" << endl;
	cout << "5. Buenos Aires, Argentina" << endl << endl;
	cout << "Digite el numero de la residencia: ";
	if (cin>>opc) {
		switch (opc) {
		case 1:
			pais = "Estados Unidos";
			ciudad = "New York";
			break;
		case 2:
			pais = "Francia";
			ciudad = "Paris";
			break;
		case 3:
			pais = "Italia";
			ciudad = "Milan";
			break;
		case 4:
			pais = "Brasil";
			ciudad = "Brasilia";
			break;
		case 5:
			pais = "Argentina";
			ciudad = "Buenos Aires";
			break;
		case 6:
			pais = "Canada";
			ciudad = "Ontairo";
			break;
		case 7:
			pais = "Inglaterra";
			ciudad = "Londres";
			break;
		case 8:
			pais = "Estados Unidos";
			ciudad = "California";
			break;

		case 9:
			pais = "Costa Rica";
			cout << "Ciudad: ";
			getline(cin, nada, '\n');
			getline(cin, ciudad, '\n');
			break;

		default:
			goto flashpoint;
		}
	}
	else {
		cin.clear();
		cin.ignore(255, '\n');
		goto flashpoint;
	}

}

void Cliente::mensajePeticion() {
	cout << "Nombre: ";
	getline(cin, nombre, '\n');
	cout << "Correo: ";
	getline(cin, correo, '\n');
	residencia();
}


string Cliente::toString() {
	stringstream s;
	s << "-------------------------------------------------" << endl << endl;
	if (mensaje != "null") {
		s << "Se ha " << mensaje << " un traje" << endl << endl;
	}
	else {
		s << "No hay mensaje nuevo." << endl << endl;
	}
	s << nombre << " | ID: " << cedula << endl;
	s << correo << " | Suscripcion: " << pagoSubs << endl;
	s << ciudad << ", " << pais << ". ";
	return s.str();
}