#include "Usuarios.h"


void Usuarios::SetUsuario(){ cargarCadena(_usuario, 16); }
void Usuarios::SetPassw(){ cargarCadena(_passw, 16); }

const char* Usuarios::GetNombre() const {return _usuario;}
const char* Usuarios::GetPassw() const {return _passw;}

void Usuarios::Mostar() const
{
	cout << setw(5) << GetNombre() << endl;
  //cout << "Passw: " << GetPassw() << endl;
}


