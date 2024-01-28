#pragma once
#include <iostream>
#include <iomanip>
#include "Helpers.h"

using namespace std;

#include "ArchivosManager.h"

class Usuarios
{
public:

	Usuarios();
	Usuarios(const char* usuario, const char* passw); 
	bool verificarCredenciales(const char* usuario, const char* passw) const;

	void SetUsuario();
	void SetPassw();
	void SetId(int id);

	const char* GetNombre() const;
	const char* GetPassw() const;
	int GetId() const;
	bool getEstado() const;

	void Mostar() const;
	void Cargar();

	// SOBRECARGA DE OPERADORES PARA USAR OBJETOS USUARIOS
	bool operator==(const Usuarios& otro) const;

private:
	int _id;
	char _usuario[16];
	char _passw[16];
	bool _estado;
};

