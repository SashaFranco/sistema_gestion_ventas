#pragma once

// Esta clase gestionara todos los objetos del programa
// para interactuar con ArchivosManager.h y el Menu.h

#include <iostream>
#include <iomanip>
#include "ArchivosManager.h"
#include "Usuarios.h"

class Manager
{
public:

	// METODOS PARA GESTIONAR USUARIOS
	void MostrarEncabezadoUsuario();
	bool entradaAlSistema();
	void setUsuarios(Usuarios usuario);

	void AltaUsuarios();
	void listarUsuarios();

private:

	// INSTANCIAS PARA GESTIONAR USUARIOS
	ArchivosManager _reg = ArchivosManager("Usuarios.dat");
	Usuarios _usuarios;
};

