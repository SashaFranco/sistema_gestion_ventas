#pragma once
#include <iostream>
#include <iomanip>
#include "Helpers.h"

using namespace std;

#include "ArchivosManager.h"

class Usuarios
{
public:

	

	void SetUsuario();
	void SetPassw();

	const char* GetNombre() const;
	const char* GetPassw() const;

	void Mostar() const;


private:
	char _usuario[16];
	char _passw[16];

};

