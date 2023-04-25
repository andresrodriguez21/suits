#pragma once
#include "Camiseta.h"
#include "ConCuadros.h"
#include "MangaLarga.h"
#include "Pantaloneta.h"
#include "Jeans.h"
#include "DeVestir.h"
#include "Bota.h"
#include "Ejecutivo.h"
#include "Tenni.h"


class InterfazTraje{

private:
    static double precio;
    static string talla;
    static string color;
    static string codigo;
    static bool X;

public:
    static Camisa* crearCamiseta();
    static Camisa* crearConCuadros();
    static Camisa* crearMangaLarga();

    static Pantalon* crearPantaloneta();
    static Pantalon* crearJeans();
    static Pantalon* crearVestir();

    static Zapato* crearBota();
    static Zapato* crearEjecutivo();
    static Zapato* crearTenni();

    static void mensajePeticion(string, string, int);
    static string convierteAstring(int);
    static string creaCodigo(string, int, bool);

};

