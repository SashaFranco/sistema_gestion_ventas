#include "Usuarios.h"


Usuarios::Usuarios() {
	_id = -1;
	_estado = false;
}

Usuarios::Usuarios(const char* usuario, const char* passw)
{
	strncpy(_usuario, usuario, sizeof(_usuario) - 1);
	_usuario[sizeof(_usuario) - 1] = '\0';

	strncpy(_passw, passw, sizeof(_passw) - 1);
	_passw[sizeof(_passw) - 1] = '\0';

	_estado = true;
}

bool Usuarios::verificarCredenciales(const char* usuario, const char* passw) const
{
	return (strcmp(_usuario, usuario) == 0 && strcmp(_passw, passw) == 0);
}

void Usuarios::SetUsuario(){ cargarCadena(_usuario, 16); }
void Usuarios::SetPassw(){ cargarCadena(_passw, 16); }
void Usuarios::SetId(int id){ _id = id; }

const char* Usuarios::GetNombre() const {return _usuario;}
const char* Usuarios::GetPassw() const {return _passw;}

int Usuarios::GetId() const{ return _id; }

bool Usuarios::getEstado() const
{
	return _estado;
}

void Usuarios::Mostar() const
{
	cout << setw(5) << GetNombre() << endl;
    //cout << "Passw: " << GetPassw() << endl;
}

void Usuarios::Cargar()
{
	cin.ignore();
	cout << "ingrese nombre de usuario: ";
	SetUsuario();
	cout << endl;
	cout << "ingrese contraseña: ";
	SetPassw();
	cout << endl;
	_estado = true;
}

bool Usuarios::operator==(const Usuarios& otro) const
{
	return (std::strcmp(_usuario, otro._usuario) == 0) && (std::strcmp(_passw, otro._passw) == 0);
}


