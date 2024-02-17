#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "Helpers.h"
#include "Fecha.h"
#include "Manager.h"
#include "Cliente.h"
#include "Proveedor.h"


class Menu
{
public:

	// MOSTRAR ENTRADA AL SISTEMA (NIVEL 0)

	void MostrarEntrada();

	// MOSTRAR MENU PRINCIPAL (NIVEL 1)
	void mostrar();

	// MOSTRAR SUBMENUS (NIVEL 2)
	void mostrarCompras();
	void mostrarVentas();
	void mostrarABM();
	void mostrarRreportes();
	void mostrarUsuarios();
	void mostrarBk();

	// MOSTRAR ULTIMOS MENUS (NIVEL 3)
	void mostrarABMCLientes();
	void mostrarABMProveedores();
	void mostrarABMProductos();

private:
	Fecha _fechaSitema;
	Manager _manager;
	Cliente _cliente;
	Proveedor _proveedor;
};

