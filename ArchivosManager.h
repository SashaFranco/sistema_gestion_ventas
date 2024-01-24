#pragma once
#include <iostream>
#include "Usuarios.h"

class ArchivosManager
{
public:
	
	ArchivosManager(const char* n);

	// METODOS PARA UsuarioManager
	void ListarUsuarios();
	void AltaUsuario();
	void BajaUsuario();
	void ModificarUsuario();

	

private:
	char _nombreArchivo[30];

};

