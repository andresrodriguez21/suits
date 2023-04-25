#pragma once
#include "Tnodo.h"
#include <fstream>
#include "Traje.h"
#include "TrajeDeportivo.h"
#include "TrajeEjecutivo.h"
#include "TrajeTrabajo.h"
#include "Camiseta.h"
#include "ConCuadros.h"
#include "MangaLarga.h"
#include "Pantaloneta.h"
#include "Jeans.h"
#include "DeVestir.h"
#include "Bota.h"
#include "Ejecutivo.h"
#include "Tenni.h"
#include "Cliente.h"
#include "Persona.h"
#include "Empresa.h"

#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include "Zapato.h"
#include "Venta.h"

template<class T>
class Lista{
private:
	Tnodo<T>* actual;
	string mensaje;
	int cont = 0;

public:
	Lista();
	~Lista();
	Tnodo<T>* getActual();
	bool tieneElementos();

	void setMensaje(string);
	void notificar();

	string convierteAstring(double);
	double convierteAdouble(string);
	string boolAstring(bool);
	bool stringAbool(string);

	T* getObject(string);
	bool existe(string);
	void insertar(T*);
	void eliminarTraje(string);
	double getPrecioDeDatabase(string);
	double getTotaldePrecioBase();
	double ventasSinGanancia();
	double ventasConGanancia();
	void setVecesVendido(string);
	string verTrajeMasVendido();
	string toString();

	void guardarDatabase();
	void guardarTrajes();
	void guardarClientesFisicos();
	void guardarClientesEmpresa();
	void guardarVentas();

	Lista<T>* cargarTrajes(Lista<T>*);
	Lista<T>* cargarDatabase(Lista<T>*);
	Lista<T>* cargarClientesFisicos(Lista<T>*);
	Lista<T>* cargarClientesEmpresa(Lista<T>*);
	Lista<T>* cargarVentas(Lista<T>*);
};

template<class T>
Lista<T>::Lista(){
	actual = NULL;
}

template<class T>
string Lista<T>::convierteAstring(double num) {
	string numero(to_string(num));
	return numero;
}

template<class T>
double Lista<T>::convierteAdouble(string num) {
	stringstream s(num);
	double numero;
	s >> numero;
	return numero;
}

template<class T>
string Lista<T>::boolAstring(bool tiene) {

	string x = "";
	if (tiene) {
		x = "T";
	}
	else {
		x = "F";
	}
	return x;
}

template<class T>
bool Lista<T>::stringAbool(string tiene) {
	bool x = true;
	if (tiene == "T") {
		x = true;
	}
	else {
		x = false;
	}
	return x;
}


template<class T>
T* Lista<T>::getObject(string id) {
	Tnodo<T>* primero = actual;
	Tnodo<T>* aux;

	while (actual != NULL) {
		if (actual->getData()->getID() == id) {
			aux = actual;
			actual = primero;
			return aux->getData();
		}
		else {
			this->actual = actual->getSig();
		}
	}
	actual = primero;

}

template<class T>
bool Lista<T>::tieneElementos() {
	if (actual == NULL) {
		return false;
	}
	else {
		return true;
	}
}



template<class T>
void Lista<T>::setMensaje(string mens) {
	mensaje = mens;
	notificar();
}

template<class T>
void Lista<T>::notificar() {
	Tnodo<T>* primero = actual;

	while (actual != NULL) {

		actual->getData()->actualizar(mensaje);
		actual = actual->getSig();

	}
	actual = primero;
}

template<class T>
void Lista<T>::insertar(T* objPtr) {
	Tnodo<T>* ptrNodo = new Tnodo<T>(objPtr, actual);
	ptrNodo->setData(objPtr);
	ptrNodo->setSig(actual);
	actual = ptrNodo;
	cont++;
}




template<class T>
Tnodo<T>* Lista<T>::getActual(){
	return actual;
}


template<class T>
void Lista<T>::eliminarTraje(string id) {
	Tnodo<T>* auxBorrar = actual;
	Tnodo<T>* anterior = NULL;

	while ((auxBorrar != NULL) && ((auxBorrar->getData()->getID()) != id)) {
		anterior = auxBorrar;
		auxBorrar = auxBorrar->getSig();
	}

	if (auxBorrar == NULL) {
		cout << endl;
		cout << "Traje no encontrado" << endl << endl;
		system("pause");
	}
	else if (anterior == NULL) {//esta de primero
		actual = actual->getSig();
		cout << endl;
		cout << "Traje eliminado" << endl << endl;
		system("pause");
	}

	else {//esta en medio o ultimo
		anterior->setSig(auxBorrar->getSig());
		cout << endl;
		cout << "Traje eliminado" << endl << endl;
		system("pause");
	}
}


template<class T>
Lista<T>::~Lista(){
	//while (actual != NULL)
		//this->eliminar("0");
}

template<class T>
bool Lista<T>::existe(string id) {
	Tnodo<T>* primero = actual;

	while (actual != NULL) {

		if (actual->getData()->getID() == id) {
			actual = primero;
			return true;
		}
		else {
			this->actual = actual->getSig();
		}
	}
	actual = primero;
	return false;
}


template<class T>
double Lista<T>::getPrecioDeDatabase(string codigo) {
	double precio = 0;
	Tnodo<T>* primero = actual;

	while (actual != NULL) {

		if (actual->getData()->getID() == codigo) {

			precio = actual->getData()->getPrecio();
			actual = primero;
			return precio;

		}
		else {
			this->actual = actual->getSig();
		}
	}
	actual = primero;
	return precio;

}

template<class T>
//devuelve la suma del precio de los trajes que estan dentro de una lista
double Lista<T>::getTotaldePrecioBase() {
	Tnodo<T>* primero = actual;
	double monto = 0;

	while (actual != NULL) {

		monto += actual->getData()->getPrecio();

		actual = actual->getSig();
	}

	actual = primero;
	return monto;
}


template<class T>
double Lista<T>::ventasSinGanancia() {
	Tnodo<T>* primero = actual;
	double total = 0;

	while (actual != NULL) {
			//total = precioBase de trajes
			//no suma las suscripciones -> ganancias
		if (actual->getData()->getMotivo() != "Suscripcion") {
			total += actual->getData()->getPrecio();
			cout << actual->getData()->verSinGanancia();
		}
		actual = actual->getSig();
	}
	actual = primero;

	return total;
}

template<class T>
double Lista<T>::ventasConGanancia() {
	Tnodo<T>* primero = actual;
	double total = 0;

	while (actual != NULL) {
		//total = (precioBase + gananciaTraje) o suscripciones
		total += (actual->getData()->getPrecio()) + (actual->getData()->getGanancia());
		cout << actual->getData()->verConGanancia();
		actual = actual->getSig();

	}
	actual = primero;
	return total;

}

template<class T>
void Lista<T>::setVecesVendido(string id) {
	Tnodo<T>* primero = actual;

	while (actual != NULL) {

		if (actual->getData()->getID() == id) {
			actual->getData()->setVecesVendido();
			break;
		}
		else {
			this->actual = actual->getSig();
		}
	}
	actual = primero;
	
}

template<class T>
string Lista<T>::verTrajeMasVendido() {
	stringstream s;
	Tnodo<T>* primero = actual;
	Traje* ganador = nullptr;
	double vecesVendido = 0;
	double anterior = 0;

	while (actual != NULL) {

		vecesVendido = actual->getData()->getVecesVendido();

		//si no es el ultimo...
		if (actual->getSig() != NULL) {

			if ((vecesVendido > actual->getSig()->getData()->getVecesVendido()) && 
				(vecesVendido > anterior)) {
				ganador = actual->getData();
				anterior = vecesVendido;
			}

			else {
				anterior = vecesVendido;
			}

		}

		else {//si es el ultimo

			if (vecesVendido > anterior) {

				if ((ganador == nullptr) || (vecesVendido > ganador->getVecesVendido())) {
					ganador = actual->getData();
				}
				else {
					//nada
				}

			}
			else {
				s << "PD: Cantidad de veces vendido entre algunos trajes se repite" << endl << endl;
				break;
			}

		}

		actual = actual->getSig();

	}
	actual = primero;

	if (ganador != nullptr) {
			s << ganador->toString();
	}
	return s.str();

}

/*		cont++;
s << "Traje numero " << cont << endl;
s << "Cantidad de veces vendido: " << vecesVendido << endl;
s << "Cantidad de veces vendido del traje anterior: " << anterior << endl << endl;*/


template<class T>
string Lista<T>::toString() {
	stringstream s;
	Tnodo<T>* primero = actual;
	while (actual != NULL) {
		
		s << actual->getData()->toString();
		this->actual = actual->getSig();
	}
	actual = primero;
	return s.str();
}


template<class T>
void Lista<T>::guardarDatabase() {
	Prenda* objPrenda = NULL;
	Tnodo<T>* primero = actual;

	ofstream Archivo("database.txt");
	//try {
		if (Archivo) {
			while (actual != NULL) {

				objPrenda = actual->getData();

				double pr = objPrenda->getPrecio();
				string codigo = objPrenda->getID();
				string precio = convierteAstring(pr);

				if (codigo != "" && pr > 0) {
					Archivo << codigo << '/' << precio << '\n';
				}

				actual = actual->getSig();

			}
		}
	delete objPrenda;
	Archivo.close();
	actual = primero;
}

template<class T>
void Lista<T>::guardarTrajes() {

	Tnodo<T>* primero = actual;

	Traje* objTraje = nullptr;

	ofstream Archivo("stock.txt");

	if (Archivo) {

		while (actual != NULL) {

			objTraje = actual->getData();

			string tipo = objTraje->getTipo();
			double vecesVendido = objTraje->getVecesVendido();

			Camisa* objCamisa = objTraje->getCamisa();
			Pantalon* objPantalon = objTraje->getPantalon();
			Zapato* objZapato = objTraje->getZapato();

			//camisa
			double precioDC = objCamisa->getPrecio();
			string tallaC = objCamisa->getTalla();
			string colorC = objCamisa->getColor();
			string codigoC = objCamisa->getCodigo();
			bool tieneC = objCamisa->getX();
			//pantalon
			double precioDP = objPantalon->getPrecio();
			string tallaP = objPantalon->getTalla();
			string colorP = objPantalon->getColor();
			string codigoP = objPantalon->getCodigo();
			bool tieneP = objPantalon->getX();
			//zapatos
			double precioDZ = objZapato->getPrecio();
			string tallaZ = objZapato->getTalla();
			string colorZ = objZapato->getColor();
			string codigoZ = objZapato->getCodigo();
			bool tieneZ = objZapato->getX();

			//conversiones
			string XC = boolAstring(tieneC);
			string precioC = convierteAstring(precioDC);
			string XP = boolAstring(tieneP);
			string precioP = convierteAstring(precioDP);
			string XZ = boolAstring(tieneZ);
			string precioZ = convierteAstring(precioDZ);
			string vecesVendidoS = convierteAstring(vecesVendido);

			if (tipo != "" && precioDC > 0) {
				Archivo << tipo << "/" << vecesVendidoS << "/";

				Archivo << precioC << "/" << tallaC << "/" << colorC << "/" << codigoC << "/" << XC << "/";

				Archivo << precioP << "/" << tallaP << "/" << colorP << "/" << codigoP << "/" << XP << "/";

				Archivo << precioZ << "/" << tallaZ << "/" << colorZ << "/" << codigoZ << "/" << XZ << '\n';
			}

			delete objCamisa, objPantalon, objZapato;
			actual = actual->getSig();

		}//while

	}//if
	Archivo.close();
	delete objTraje;
	actual = primero;
}


template<class T>
void Lista<T>::guardarClientesFisicos() {

	Tnodo<T>* primero = actual;

	Persona* cliente = nullptr;

	ofstream Archivo("clientesfisicos.txt");

	if (Archivo) {

		while (actual != NULL) {

			cliente = actual->getData();

			double pagoSubsD = cliente->getpagoSubs();

			string pagoSubs = convierteAstring(pagoSubsD);
			string nombre = cliente->getNombre();
			string cedula = cliente->getID();
			string correo = cliente->getCorreo();
			string pais = cliente->getPais();
			string ciudad = cliente->getCiudad();
			string nacionalidad = cliente->getNacionalidad();

			if (nombre != "" && pagoSubsD > 0) {
				Archivo << nombre << "/" << cedula << "/" << correo << "/" << pais << "/" << ciudad << "/" << nacionalidad << "/" << pagoSubs << '\n';
			}
			actual = actual->getSig();

		}//while


	}//if Archivo

	Archivo.close();
	delete cliente;
	actual = primero;
}

template<class T>
void Lista<T>::guardarClientesEmpresa() {

	Tnodo<T>* primero = actual;

	Empresa* cliente = nullptr;

	ofstream Archivo("clientesempresa.txt");

	if (Archivo) {

		while (actual != NULL) {

			cliente = actual->getData();

			double pagoSubsD = cliente->getpagoSubs();

			string pagoSubs = convierteAstring(pagoSubsD);
			string nombre = cliente->getNombre();
			string cedula = cliente->getID();
			string correo = cliente->getCorreo();
			string pais = cliente->getPais();
			string ciudad = cliente->getCiudad();
			bool tiene = cliente->getFrecuente();
			string frecuente = boolAstring(tiene);

			if (nombre != "" && pagoSubsD > 0) {
				Archivo << nombre << "/" << cedula << "/" << correo << "/" << pais << "/" << ciudad << "/" << frecuente << "/" << pagoSubs << '\n';
			}
			actual = actual->getSig();

		}//while

	}//if Archivo

	Archivo.close();
	delete cliente;
	actual = primero;
}

template<class T>
void Lista<T>::guardarVentas() {

	Tnodo<T>* primero = actual;

	Venta* venta = nullptr;

	ofstream Archivo("ventas.txt");

	if (Archivo) {

		while (actual != NULL) {

			venta = actual->getData();

			string motivo = venta->getMotivo();
			double montoD = venta->getPrecio();
			double costoEnvioD = venta->getCostoEnvio();
			
			string monto = convierteAstring(montoD);
			string costoEnvio = convierteAstring(costoEnvioD);

			if (motivo != "" && montoD > 0) {
				Archivo << motivo << "/" << montoD << "/" << costoEnvio << '\n';
			}
			actual = actual->getSig();

		}//while

	}//if Archivo

	Archivo.close();
	actual = primero;
}


template<class T>
Lista<T>* Lista<T>::cargarDatabase(Lista<T>* lista) {
	string codigo, precioS;

	ifstream Archivo("database.txt", ios::in);

		if (Archivo) {

			while (!Archivo.eof()) {
				getline(Archivo, codigo, '/');
				getline(Archivo, precioS, '\n');

				double precio = convierteAdouble(precioS);

				if (codigo != "" && precio > 0) {
					Prenda* prenda = new Prenda(codigo, precio);
					lista->insertar(prenda);
				}

			}//while

		}//if

	Archivo.close();
	return lista;
}


template<class T>
Lista<T>* Lista<T>::cargarTrajes(Lista<T>* lista) {

	string tipo, vecesVendidoS;
	string precioCS, tallaC, colorC, codigoC, tieneC, precioPS, tallaP, colorP, codigoP, tieneP;
	string precioZS, tallaZ, colorZ, codigoZ, tieneZ;

	Traje* traje = nullptr;
	Camisa* camisa = nullptr;
	Pantalon* pantalon = nullptr;
	Zapato* zapatos = nullptr;

	ifstream Archivo("stock.txt", ios::in);

	if (Archivo) {

		while (!Archivo.eof()) {

			getline(Archivo, tipo, '/');
			getline(Archivo, vecesVendidoS, '/');

			getline(Archivo, precioCS, '/');
			getline(Archivo, tallaC, '/');
			getline(Archivo, colorC, '/');
			getline(Archivo, codigoC, '/');
			getline(Archivo, tieneC, '/');

			getline(Archivo, precioPS, '/');
			getline(Archivo, tallaP, '/');
			getline(Archivo, colorP, '/');
			getline(Archivo, codigoP, '/');
			getline(Archivo, tieneP, '/');

			getline(Archivo, precioZS, '/');
			getline(Archivo, tallaZ, '/');
			getline(Archivo, colorZ, '/');
			getline(Archivo, codigoZ, '/');
			getline(Archivo, tieneZ, '\n');

			double precioC = convierteAdouble(precioCS);
			double precioP = convierteAdouble(precioPS);
			double precioZ = convierteAdouble(precioZS);
			double vecesVendido = convierteAdouble(vecesVendidoS);

			bool XC = stringAbool(tieneC);
			bool XP = stringAbool(tieneP);
			bool XZ = stringAbool(tieneZ);
		
			if (tipo == "deportivo" && tipo != "" && precioC > 0) {
				camisa = new Camiseta(precioC, tallaC, colorC, codigoC, XC);
				pantalon = new Pantaloneta(precioP, tallaP, colorP, codigoP, XP);
				zapatos = new Tenni(precioZ, tallaZ, colorZ, codigoZ, XZ);
				traje = new TrajeDeportivo(tipo, vecesVendido, camisa, pantalon, zapatos);
				lista->insertar(traje);
			}

			if (tipo == "ejecutivo" && tipo != "" && precioC > 0) {
				camisa = new MangaLarga(precioC, tallaC, colorC, codigoC, XC);
				pantalon = new DeVestir(precioP, tallaP, colorP, codigoP, XP);
				zapatos = new Ejecutivo(precioZ, tallaZ, colorZ, codigoZ, XZ);
				traje = new TrajeEjecutivo(tipo, vecesVendido, camisa, pantalon, zapatos);
				lista->insertar(traje);
			}

			if (tipo == "trabajo" && tipo != "" && precioC > 0) {
				camisa = new ConCuadros(precioC, tallaC, colorC, codigoC, XC);
				pantalon = new Jeans(precioP, tallaP, colorP, codigoP, XP);
				zapatos = new Bota(precioZ, tallaZ, colorZ, codigoZ, XZ);
				traje = new TrajeTrabajo(tipo, vecesVendido, camisa, pantalon, zapatos);
				lista->insertar(traje);
			}

		}//while

	}
	
	Archivo.close();
	return lista;
	
}

template<class T>
Lista<T>* Lista<T>::cargarClientesFisicos(Lista<T>* lista) {

	Persona* fisico = nullptr;

	string pagoSubsS, nombre, cedula, correo, pais, ciudad, nacionalidad;

	ifstream Archivo("clientesfisicos.txt", ios::in);

	if (Archivo) {

		while (!Archivo.eof()) {

			getline(Archivo, nombre, '/');
			getline(Archivo, cedula, '/');
			getline(Archivo, correo, '/');
			getline(Archivo, pais, '/');
			getline(Archivo, ciudad, '/');
			getline(Archivo, nacionalidad, '/');
			getline(Archivo, pagoSubsS, '\n');

			//conversiones
			double pagoSubs = convierteAdouble(pagoSubsS);

			if (nombre != "" && pagoSubs > 0) {
				fisico = new Persona(pagoSubs, nombre, cedula, correo, pais, ciudad, nacionalidad);
				lista->insertar(fisico);
			}


		}//while

	}//if
	Archivo.close();
	return lista;

}

template<class T>
Lista<T>* Lista<T>::cargarClientesEmpresa(Lista<T>* lista) {

	Empresa* empresa = nullptr;

	string pagoSubsS, nombre, cedula, correo, pais, ciudad, tiene;

	ifstream Archivo("clientesempresa.txt", ios::in);

	if (Archivo) {

		while (!Archivo.eof()) {

			getline(Archivo, nombre, '/');
			getline(Archivo, cedula, '/');
			getline(Archivo, correo, '/');
			getline(Archivo, pais, '/');
			getline(Archivo, ciudad, '/');
			getline(Archivo, tiene, '/');
			getline(Archivo, pagoSubsS, '\n');

			//conversiones
			double pagoSubs = convierteAdouble(pagoSubsS);
			bool frecuente = stringAbool(tiene);

			if (nombre != "" && pagoSubs > 0) {
				empresa = new Empresa(pagoSubs, nombre, cedula, correo, pais, ciudad, frecuente);
				lista->insertar(empresa);
			}
		}//while

	}//if
	Archivo.close();
	return lista;
}


template<class T>
Lista<T>* Lista<T>::cargarVentas(Lista<T>* lista) {

	Venta* venta = nullptr;

	string motivo, montoS, costoEnvioS;

	ifstream Archivo("ventas.txt", ios::in);

	if (Archivo) {

		while (!Archivo.eof()) {
			getline(Archivo, motivo, '/');
			getline(Archivo, montoS, '/');
			getline(Archivo, costoEnvioS, '\n');

			//conversiones
			double monto = convierteAdouble(montoS);
			double costoEnvio = convierteAdouble(costoEnvioS);

			if (motivo != "" && monto > 0) {
				venta = new Venta(motivo, monto, costoEnvio);
				lista->insertar(venta);
			}
		}//while

	}//if
	Archivo.close();
	return lista;
}