#include"InterfazTraje.h"
#include "InterfazMenu.h"

double InterfazTraje::precio = 0;
string InterfazTraje::talla = "";
bool InterfazTraje::X = true;
string InterfazTraje::color = "";
string InterfazTraje::codigo = "";


Camisa* InterfazTraje::crearCamiseta() {
	mensajePeticion("la camiseta", "Tiene cuello V", 1);
	return new Camiseta(precio, talla, color, codigo, X);
}

Camisa* InterfazTraje::crearConCuadros() {
	mensajePeticion("la camisa con cuadros", "Tiene cuadros grandes", 2);
	return new ConCuadros(precio, talla, color, codigo, X);
}

Camisa* InterfazTraje::crearMangaLarga() {
	mensajePeticion("la camisa de manga larga", "Es lisa", 3);
	return new MangaLarga(precio, talla, color, codigo, X);
}

Pantalon* InterfazTraje::crearPantaloneta() {
	mensajePeticion("la pantaloneta", "Es estampada", 4);
	return new Pantaloneta(precio, talla, color, codigo, X);
}

Pantalon* InterfazTraje::crearJeans() {
	mensajePeticion("los jeans", "Es ajustado", 5);
	return new Jeans(precio, talla, color, codigo, X);
}

Pantalon* InterfazTraje::crearVestir() {
	mensajePeticion("el pantalon de vestir", "Es de tela casimir", 6);
	return new DeVestir(precio, talla, color, codigo, X);
}

Zapato* InterfazTraje::crearBota() {
	mensajePeticion("las botas", "Son botas altas", 7);
	return new Bota(precio, talla, color, codigo, X);
}

Zapato* InterfazTraje::crearEjecutivo() {
	mensajePeticion("los zapatos ejecutivos", "Son finos", 8);
	return new Ejecutivo(precio, talla, color, codigo, X);
}

Zapato* InterfazTraje::crearTenni() {
	mensajePeticion("las tennis", "Son adidas", 9);
	return new Tenni(precio, talla, color, codigo, X);
}

void InterfazTraje::mensajePeticion(string prenda, string pregunta,int codPrenda) {
	InterfazMenu IM;

	double p = 0;
	string nada, colorin, opc, cod, tall;
	getline(cin, nada, '\n');
	cout << endl;
	cout << "Ingrese datos para " << prenda << endl;
	cout << pregunta << "? (s = si): ";
	getline(cin, opc, '\n');

	if ((opc == "S") || (opc == "s")) {
		X = true;
	}
	else {
		X = false;
	}

	cout << "Ingrese el color: ";
	getline(cin, colorin, '\n');
	color = colorin;

	flashpoint:
	cout << "Ingrese la talla ( A, B, C, D ): ";
	getline(cin, tall, '\n');
	talla = tall;

	codigo = creaCodigo(talla, codPrenda, X);

	precio = IM.getDatabase()->getPrecioDeDatabase(codigo);

	if (precio == 0) {
		cout << endl;
		cout << "Error. Talla incorrecta. Verifique las mayusculas." << endl << endl;
		goto flashpoint;
	}

	else {
	cout << "Codigo: " << codigo << endl;
	cout << "Precio: $" << precio << endl;
	}


}

string InterfazTraje::creaCodigo(string talla, int codPrenda, bool X) {
	string prenda, tiene, codigo;
	if (X) {
		tiene = "T"; //True -> Si tiene
	}
	else {
		tiene = "F"; //False -> No tiene
	}
	prenda = convierteAstring(codPrenda);

	codigo = prenda + talla + tiene;
	return codigo;

}

string InterfazTraje::convierteAstring(int num) {
	string numero(to_string(num));
	return numero;
}