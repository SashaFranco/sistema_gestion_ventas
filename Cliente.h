#pragma once
#include "Persona.h"
#include "ArchivosManager.h"
#include "Helpers.h";


class Cliente :
    public Persona
{
public:
	void mostrarEncabezado();
	void mostrarEncabezado2();

	void AltaCliente();
	void BajaCliente();
	void ModificarCliente();
	void ListarClientes();
	void BuscarCliente();

private:
	ArchivosManager _reg = ArchivosManager("Clientes.dat");
};

