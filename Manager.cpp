#include "Manager.h"

void Manager::MostrarEncabezadoUsuario()
{
	cout << left;
	cout << setw(5) << "USUARIOS" << endl;
	cout << "--------------------------------";
}

bool Manager::entradaAlSistema()
{
    char inputUsuario[16];
    char inputPassw[16];

    cout << "Ingrese su usuario: ";
    cin >> inputUsuario;
    cout << endl;
    cout << "Ingrese su contraseña: ";
    cin >> inputPassw;
    cout << endl;

    Usuarios aux(inputUsuario, inputPassw);
    setUsuarios(_reg.BuscarUsuario(inputUsuario, inputPassw));

    if (_usuarios == aux)
    {
        cout << "Inicio de sesión exitoso. ¡Bienvenido!" << endl;
        return true;
    }

    else {
        cout << "Inicio de sesión fallido. Credenciales incorrectas." << endl;
        return false;
    }
    
}

void Manager::setUsuarios(Usuarios usuario){ _usuarios = usuario; }

void Manager::AltaUsuarios()
{
    _usuarios.Cargar();
    bool cargo = _reg.AltaUsuario(_usuarios);
    if (cargo)
    {
        cout << "Usuario dado de alta con exito" << endl;
        system("pause");
    }
    else {
        cout << "ERROR AL DAR DE ALTA USUARIO" << endl;
    }

}

void Manager::listarUsuarios()
{
    _reg.ListarUsuarios(_usuarios);
    system("pause");
}
