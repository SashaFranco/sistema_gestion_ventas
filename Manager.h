#pragma once

// Esta clase gestionara todos los objetos del programa
// para interactuar con ArchivosManager.h y el Menu.h

#include <iostream>
#include <iomanip>
#include "ArchivosManager.h"
#include "Usuarios.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Helpers.h"

class Manager
{
public:

	// METODOS PARA GESTIONAR USUARIOS
	void MostrarEncabezadoUsuario();

	bool entradaAlSistema();
	void AltaUsuarios();
	void BajaUsuario();
	void MoidificarUsuarios();
	void listarUsuarios();

	// METODOS PARA GESTIONAR PRODUCTOS
	void MostrarEncabezadoProductos();
	void mostrarEncabezado2();
	void AltaProducto();
	void BajaProducto();
	void MoidificarProducto();
	void listarProducto();

	void BuscarProductoXID();
	void BuscarProductoXNombre();


	// SETTERS
	void setUsuarios(Usuarios usuario);

private:

	// INSTANCIAS PARA GESTIONAR USUARIOS
	ArchivosManager _reg = ArchivosManager("Usuarios.dat");
	Usuarios _usuarios;

	// INSTANCIAS PARA GESTIONAR PRODUCTOS
	ArchivosManager _regProductos = ArchivosManager("Productos.dat");
	Producto _producto;
};

