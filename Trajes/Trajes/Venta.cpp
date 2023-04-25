#include "Venta.h"

Venta::Venta() {
	precioBase = 0;
	costoEnvio = 0;
	gananciaTraje = 0;
	IVA = 0;
}

Venta::Venta(string mot, double traje, double costo) {
	motivo = mot;
	precioBase = traje;
	costoEnvio = costo;
	IVA = precioBase * 0.15;
	if (motivo == "Suscripcion") {
		gananciaTraje = 0;
	}
	else {
		gananciaTraje = precioBase * 0.8;
	}
}

string Venta::getMotivo() {
	return motivo;
}

double Venta::getPrecio() {
	return precioBase;
}

double Venta::getCostoEnvio() {
	return costoEnvio;
}

double Venta::getGanancia() {
		return gananciaTraje;
}

double Venta::calculaCostoEnvio(string ciudad) {
	if (ciudad == "New York") { return 100; }
	if (ciudad == "Paris") { return 200; }
	if (ciudad == "Milan") { return 250; }
	if (ciudad == "Brasilia") { return 150; }
	if (ciudad == "Buenos Aires") { return 175; }
	if (ciudad == "Ontairo") { return 160; }
	if (ciudad == "Londres") { return 200; }
	if (ciudad == "California") { return 150; }

	else {
		return 50; //Cualquier lugar de Costa Rica
	}
}

string Venta::verFactura() {
	stringstream s;

	double total = precioBase + gananciaTraje + IVA + costoEnvio;

	s << "Traje(s)      : $" << precioBase << endl;
	s << "IVA           : $" << IVA << endl;
	s << "Ganancia      : $" << gananciaTraje << endl;
	if (costoEnvio != 0) {
		s << "Costo de envio: $" << costoEnvio << endl;
	}
	s << "-------------------------" << endl;
	s << "TOTAL         : $" << total << endl << endl;

	return s.str();
}

string Venta::verSinGanancia() {
	stringstream s;
	if (motivo!="Suscripcion") {
		s << motivo << " de $" << precioBase << endl << endl;
	}
	
	return s.str();
}

string Venta::verConGanancia() {
	stringstream s;
	if (motivo != "Suscripcion") {
		s << motivo << " de $" << precioBase << " + ganancia de $" << gananciaTraje << endl << endl;
	}
	else {
		s << motivo << " de $" << precioBase << endl << endl;
	}
	
	return s.str();
}