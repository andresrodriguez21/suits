#include "Empresa.h"

Empresa::Empresa(string id) : Cliente() {
	cedula = id;
	pagoSubs = 400;
	frecuente = false;
	mensajePeticion();
	cout << "Suscripcion: $" << pagoSubs << endl << endl;
	system("pause");
}

Empresa::Empresa(double pg, string nom, string id, string email, string pai, string ciud, bool f):Cliente() {
	pagoSubs = pg;
	nombre = nom;
	cedula = id;
	correo = email;
	pais = pai;
	ciudad = ciud;
	frecuente = f;
}

void Empresa::actualizar(string nuevo) {
	mensaje = nuevo;
}

bool Empresa::getFrecuente() {
	return frecuente;
}

string Empresa::toString() {
	stringstream s;

	s << Cliente::toString();
	s << endl;
	if (frecuente) {
		s << "Cliente frecuente" << endl << endl;
	}
	else {
		s << "Cliente no frecuente" << endl << endl;
	}
	s << "-------------------------------------------------" << endl;
	return s.str();

}