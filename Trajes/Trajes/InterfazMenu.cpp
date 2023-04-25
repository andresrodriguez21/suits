#include "InterfazMenu.h"

InterfazMenu::InterfazMenu() {
	database = database->cargarDatabase(database);
	cargar();
	ptrVenta = new Venta();
}

Lista<Prenda>* InterfazMenu::getDatabase() {
	return database;
}

Lista<Traje>* InterfazMenu::getStock() {
	return stock;
}

void InterfazMenu::limpiaVariables() {
	cin.clear();
	cin.ignore(255, '\n');
}

void InterfazMenu::notifica(string mensaje) {
	listaClientesEmpresa->setMensaje(mensaje);
	listaClientesFisicos->setMensaje(mensaje);
}

void InterfazMenu::escogerDelStock(double costoEnvio) {

	Lista<Traje>* carrito = new Lista<Traje>;
	string codigo, nada;
	int can = 0;
	double precioTraje = 0;

	verLista("			Stock", 1);

	cout << "Cantidad de trajes a comprar: ";

	try {

		if ((cin >> can) && (can > 0)) {

			for (int i = 0; i < can; i++) {

			flashpoint:

				limpiaVariables();
				verLista("			Stock", 1);

				cout << "Codigo del traje que desea comprar (" << i + 1 << "/" << can << "): ";
				getline(cin, codigo, '\n');

				if (stock->existe(codigo)) {

					stock->setVecesVendido(codigo);

					Traje* traje = nullptr;

					traje = stock->getObject(codigo);

					precioTraje += traje->getPrecio();

					carrito->insertar(traje);

					cout << endl;
					cout << "Traje agregado al carrito";

				}
				else {
					cout << endl;
					cout << "Error. El traje no existe." << endl;
					system("pause");
					goto flashpoint;
				}

			}//for

			ingresaNuevaVenta(carrito, precioTraje, costoEnvio);

		}// cin>>can

		else {
			throw new Excepcion();
		}

	}//try

	catch (Excepcion* e) {
		e->palabraDigitada();
		limpiaVariables();

	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		limpiaVariables();
	}

}

void InterfazMenu::crearYcomprar(double costoEnvio) {
	Lista<Traje>* carrito = new Lista<Traje>;
	carrito = crearTrajeAMedida(carrito);
	double precio = carrito->getTotaldePrecioBase();
	ingresaNuevaVenta(carrito, precio, costoEnvio);
}

void InterfazMenu::ingresaNuevaVenta(Lista<Traje>* carrito, double precioTraje, double costoEnvio) {
	Venta* nuevaVenta = new Venta("Traje(s)   ", precioTraje, costoEnvio);
	system("cls");
	cout << endl;
	cout << "			F A C T U R A" << endl << endl;
	cout << carrito->toString();
	cout << nuevaVenta->verFactura();
	listaVentas->insertar(nuevaVenta);
	system("pause");
}

void InterfazMenu::ventaDirecta() {
	system("cls");
	string id;
	cout << endl;
	cout << "	Venta directa" << endl << endl;
	getline(cin, id, '\n');
	cout << "Digite la cedula del cliente: ";
	getline(cin, id, '\n');
	if (listaClientesFisicos->existe(id) || listaClientesEmpresa->existe(id)) {
		escogerDelStock(0);
	}
	else {
		cout << endl;
		cout << "El cliente no existe" << endl;
		system("pause");
	}

}

void InterfazMenu::ventaEnLinea() {
	system("cls");
	cout << endl;
	cout << "	Venta en linea" << endl << endl;
	double costoEnvio = existeCliente();

	if (costoEnvio == 0) {
		cout << endl;
		cout << "El cliente no existe" << endl;
		system("pause");
	}
	else {
		menuEnLinea(costoEnvio);
	}
}

double InterfazMenu::existeCliente() {
	Cliente* cliente = nullptr;
	string nada, id, ciudad;
	double costoEnvio = 0;

	getline(cin, nada, '\n');
	cout << "Ingrese su cedula: ";
	getline(cin, id, '\n');

	if (listaClientesFisicos->existe(id)) {

		cliente = listaClientesFisicos->getObject(id);
		ciudad = cliente->getCiudad();
		costoEnvio = ptrVenta->calculaCostoEnvio(ciudad);

	}
	if (listaClientesEmpresa->existe(id)) {

		cliente = listaClientesEmpresa->getObject(id);
		ciudad = cliente->getCiudad();
		costoEnvio = ptrVenta->calculaCostoEnvio(ciudad);
	}

	if (cliente != nullptr) {
	system("cls");
	cout << cliente->toString() << endl;
	cout << "-------------------------------------------------" << endl;
	system("pause");
	}

	return costoEnvio;

}

void InterfazMenu::menuEnLinea(double costoEnvio) {
flashpoint:
	system("cls");
	Lista<Traje>* trajesAmedida = nullptr;
	int opc = 0;
	system("cls");
	cout << endl;
	cout << "      Venta en linea" << endl << endl;
	cout << "  1. Comprar traje(s) en stock" << endl;
	cout << "  2. Crear traje(s) a medida y comprarlo(s)" << endl << endl;
	cout << "  Digite la opcion: ";

	if (cin >> opc) {

		switch (opc) {
		case 1:
			escogerDelStock(costoEnvio);
			break;

		case 2:
			crearYcomprar(costoEnvio);
			break;

		default:
			break;
		}
	}
	else {
		limpiaVariables();
		goto flashpoint;
	}
}


//3.1
void InterfazMenu::ingresarCliente() {
	Persona* fisico = nullptr;
	Empresa* empresa = nullptr;
	Venta* nuevaVenta = nullptr;
	string cedula, nada = "";
	int opc = 0;
	system("cls");
	cout << endl;
	cout << "      Ingresar cliente" << endl << endl;
	cout << "  1. Cliente fisico" << endl;
	cout << "  2. Cliente empresa" << endl << endl;
	cout << "  Digite la opcion: ";

	try {

	if (cin >> opc) {

	getline(cin, nada, '\n');
	cout << endl;
	cout << "	Registro" << endl;
	cout << "Cedula: ";
	getline(cin, cedula, '\n');

	if ((listaClientesFisicos->existe(cedula)) || (listaClientesEmpresa->existe(cedula))) {

		cout << "Error. El cliente ya existe" << endl;
		system("pause");

	}

	else {

		switch (opc) {
		case 1:
			fisico = new Persona(cedula);
			listaClientesFisicos->insertar(fisico);
			nuevaVenta = new Venta("Suscripcion", 200, 0);
			listaVentas->insertar(nuevaVenta);
			break;

		case 2:
			empresa = new Empresa(cedula);
			listaClientesEmpresa->insertar(empresa);
			nuevaVenta = new Venta("Suscripcion", 400, 0);
			listaVentas->insertar(nuevaVenta);
			break;

		}

	}

	}

	else {
		throw new Excepcion();
	}

	}

	catch (Excepcion* e) {
		e->palabraDigitada();
		limpiaVariables();
	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		limpiaVariables();
	}

}

//3.2
void InterfazMenu::ingresarTraje() {
	this->stock = crearTrajeAMedida(stock);
	notifica("agregado");
}


Lista<Traje>* InterfazMenu::crearTrajeAMedida(Lista<Traje>* lista) {
	Traje* deportivo = nullptr;
	Traje* ejecutivo = nullptr;
	Traje* trabajo = nullptr;
	int opc = 0;
	system("cls");
	cout << endl;
	cout << "      Crear traje" << endl << endl;
	cout << "  1. Traje deportivo" << endl;
	cout << "  2. Traje ejecutivo" << endl;
	cout << "  3. Traje de trabajo" << endl << endl;
	cout << "  Digite la opcion: ";

	try {

		if (cin >> opc) {

			switch (opc) {

			case 1:
				deportivo = new TrajeDeportivo("deportivo", 0);
				lista->insertar(deportivo);
				system("pause");
				return lista;

			case 2:
				ejecutivo = new TrajeEjecutivo("ejecutivo", 0);
				lista->insertar(ejecutivo);
				system("pause");
				return lista;

			case 3:
				trabajo = new TrajeTrabajo("trabajo", 0);
				lista->insertar(trabajo);
				system("pause");
				return lista;
			}

		}

		else {
			throw new Excepcion();
		}

	}

	catch (Excepcion* e) {
		e->palabraDigitada();
		limpiaVariables();
	}

	catch (...) {
		cout << "Error indeterminado" << endl;
		limpiaVariables();
	}

}


//3.3
void InterfazMenu::eliminarTraje() {
	string code;
	//getline(cin, nada, '\n');
	verLista("			Stock", 1);
	cout << "Digite el codigo del traje a eliminar: ";
	cin >> code;

	this->stock->eliminarTraje(code);
	notifica("eliminado");

	verLista("			Stock", 1);
	system("pause");

}

//3.4	| 3.5	| 3.6	| 3.7	| 3.8	| 3.9	| 3.10

void InterfazMenu::verLista(string titulo, int lista) {
	double total = 0;
	system("cls");
	cout << endl;
	cout << titulo << endl << endl;

	switch (lista) {
	case 1:
		cout << this->stock->toString();
		mensajeAdvertencia();
		break;

	case 2:
		cout << listaClientesFisicos->toString();
		system("pause");
		break;

	case 3:
		cout << listaClientesEmpresa->toString();
		system("pause");
		break;

	case 4:
		total = listaVentas->ventasSinGanancia();
		cout << "        Total: $" << total << endl << endl;
		system("pause");
		break;

	case 5:
		
		total = listaVentas->ventasConGanancia();
		cout << "        Total: $" << total << endl << endl;
		system("pause");
		break;

	case 6:
		total = listaVentas->ventasConGanancia() - listaVentas->ventasSinGanancia();
		system("cls");
		cout << endl;
		cout << titulo << endl << endl;
		cout << "Ventas con ganancia - ventas sin ganancia = $" << total << endl << endl;
		system("pause");
		break;

	case 7:
		cout << stock->verTrajeMasVendido();
		system("pause");
		break;

	case 8:
		cout << database->toString();
		system("pause");

	}
}

void InterfazMenu::mensajeAdvertencia() {
	cout << "	ganancia, iva y costo de envio NO incluido" << endl << endl;
}

bool InterfazMenu::verificaDatabase() {
	if (database->tieneElementos()) {
		return true;
	}
	else {
		return false;
	}
}

void InterfazMenu::cargar() {
	stock = stock->cargarTrajes(stock);

	listaClientesFisicos = listaClientesFisicos->cargarClientesFisicos(listaClientesFisicos);
	
	listaClientesEmpresa = listaClientesEmpresa->cargarClientesEmpresa(listaClientesEmpresa);

	listaVentas = listaVentas->cargarVentas(listaVentas);
}


void InterfazMenu::guardar() {
	database->guardarDatabase();

	if (stock->tieneElementos()) {
	stock->guardarTrajes();
	}
	if (listaClientesFisicos->tieneElementos()) {
		listaClientesFisicos->guardarClientesFisicos();
	}
	if (listaClientesEmpresa->tieneElementos()) {
	listaClientesEmpresa->guardarClientesEmpresa();
	}
	if (listaVentas->tieneElementos()) {
	listaVentas->guardarVentas();
	}
}

