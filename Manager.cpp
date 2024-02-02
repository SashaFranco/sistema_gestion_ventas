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

    setConsoleSize(10, 60);
    if (_usuarios == aux)
    {
        system("cls");
        cout << "Inicio de sesion exitoso. Bienvenido!" << endl << endl;
        system("pause");
        return true;
    }

    else {
        system("cls");
        cout << "Inicio de sesion fallido. Credenciales incorrectas." << endl << endl;
        system("pause");
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

void Manager::BajaUsuario()
{
    system("cls");
    Usuarios aux;
    bool borro = false;
    char inputUsuario[16];
    char inputPassw[16];
    setConsoleSize(10, 60);
    cout << "Ingrese el usuario que desea borrar: ";
    cin >> inputUsuario;
    cout << endl;
    cout << "Ingrese su contraseña: ";
    cin >> inputPassw;
    cout << endl;

    aux = _reg.BuscarUsuario(inputUsuario, inputPassw);

    if (aux.GetId() != -1)
    {
        setConsoleSize(10, 60);
        int opc;
        cout << "Se encontro usuario!" << " ¿Desea borrar?" << endl;
        cout << "1- SI" << endl;
        cout << "2- NO" << endl;
        cout << "Opcion elegida: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            setConsoleSize(10, 60);
            borro = _reg.BajaUsuario(aux.GetId());
           
            if (borro)
            {
                system("cls");
                cout << "Usuario borrado" << endl;
                system("pause");
            }
            break;
        case 2:
            return;
            break;
        default:
            system("cls");
            setConsoleSize(10, 60);
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            return;
            break;
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA USUARIO EN SISTEMA" << endl;
        system("pause");
    }


}

void Manager::MoidificarUsuarios()
{
    system("cls");
    Usuarios aux;
    bool modifico = false;
    char inputUsuario[16];
    char inputPassw[16];
    char NuevoUsuario[16];
    char NuevaPassw[16];
    setConsoleSize(10, 60);
    cout << "Ingrese el usuario que desea modificar: ";
    cin >> inputUsuario;
    cout << endl;
    cout << "Ingrese su contraseña: ";
    cin >> inputPassw;
    cout << endl;


    aux = _reg.BuscarUsuario(inputUsuario, inputPassw);
    if (aux.GetId() != -1)
    {
        setConsoleSize(10, 60);
        int opc;
        cout << "Se encontro usuario!" << " ¿Que desea cambiar?" << endl;
        cout << "1- Usuario" << endl;
        cout << "2- Passw" << endl;
        cout << "Opcion elegida: ";
        cin >> opc;
        
        switch (opc)
        {
        case 1:
            system("cls");
            setConsoleSize(10, 60);
            cout << "INGRESE NUEVO USUARIO: " << endl;
            cin >> NuevoUsuario;
            modifico = _reg.ModificarUsuario(aux.GetId(), NuevoUsuario, nullptr);
            if (modifico)
            {
                system("cls");
                cout << "Usuario cambiado con exito" << endl;
                system("pause");
            }
            break;
        case 2:
            system("cls");
            setConsoleSize(10, 60);
            cout << "INGRESE NUEVA PASSW: " << endl;
            cin >> NuevaPassw;
            modifico = _reg.ModificarUsuario(aux.GetId(), nullptr, NuevaPassw);
            if (modifico)
            {
                system("cls");
                cout << "Passw cambiada con exito" << endl;
                system("pause");
            }
            break;
        default:
            system("cls");
            setConsoleSize(10, 60);
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            return;
            break;
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA USUARIO EN SISTEMA" << endl;
        system("pause");
    }
}

void Manager::listarUsuarios()
{
    _reg.ListarUsuarios(_usuarios);
    system("pause");
}
