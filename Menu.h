#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Helpers.h"

using namespace std;
#include "Fecha.h"


class Menu
{
public:

	// MOSTRAR MENU PRINCIPAL (NIVEL 1)
	void mostrar();

	// MOSTRAR SUBMENUS (NIVEL 2)
	void mostrarCompras();
	void mostrarVentas();
	void mostrarABM();
	void mostrarRreportes();
	void mostrarUsuarios();
	void mostrarBk();

private:
	Fecha _fechaSitema;
	

};

