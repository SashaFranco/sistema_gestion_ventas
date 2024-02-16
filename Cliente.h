#pragma once
#include "Persona.h"
#include "ArchivosManager.h"


class Cliente :
    public Persona
{
	int ObtenerUltimoId() const;
	Cliente BuscarUsuario(const char* usuario, const char* passw) const;
	bool AltaUsuario(Cliente reg);
	bool BajaUsuario(int id);
	bool ModificarUsuario(int id, const char* nuevoUsuario, const char* nuevaPassw);
	bool ListarUsuarios(Cliente reg);

private:
	ArchivosManager _reg = ArchivosManager("Clientes.dat");
};

