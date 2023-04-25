#include "Persona.h"

Persona::Persona(string id):Cliente() {
	string nada;
	cedula = id;
	pagoSubs = 200;
	mensajePeticion();
	getline(cin, nada, '\n');
	cout << "Nacionalidad: ";
	getline(cin, nacionalidad, '\n');
	cout << "Suscripcion: $" << pagoSubs << endl << endl;
	system("pause");

}

Persona::Persona(double pg, string nom, string id, string email, string pai, string ciud, string nac) {
	pagoSubs = pg;
	nombre = nom;
	cedula = id;
	correo = email;
	pais = pai;
	ciudad = ciud;
	nacionalidad = nac;
}

void Persona::actualizar(string nuevo) {
	mensaje = nuevo;
}

string Persona::getNacionalidad() {
	return nacionalidad;
}

string Persona::toString() {
	stringstream s;

	s << Cliente::toString();
	s << nacionalidad << endl << endl;
	s << "-------------------------------------------------" << endl;

	return s.str();
}