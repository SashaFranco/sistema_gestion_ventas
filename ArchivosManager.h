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
	bool BajaUsuario(int id);
	bool ModificarUsuario(int id, const char* nuevoUsuario, const char* nuevaPassw);
	bool ListarUsuarios(Usuarios reg);
	

private:
	char _nombreArchivo[30];
};

