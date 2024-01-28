#pragma once
#include <iostream>

class Usuarios;

using namespace std;

class ArchivosManager
{
public:

	ArchivosManager(const char* n);

	// METODOS PARA UsuarioManager
	int ObtenerUltimoId() const;
	Usuarios BuscarUsuario(const char* usuario, const char* passw) const;
	bool AltaUsuario(Usuarios reg);
	bool ListarUsuarios(Usuarios reg);

	/*void BajaUsuario();
	void ModificarUsuario();*/

private:
	char _nombreArchivo[30];
};

