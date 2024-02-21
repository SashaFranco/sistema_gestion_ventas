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
    system("cls");
    if (_reg.ListarUsuarios(_usuarios))
    {
        _reg.ListarUsuarios(_usuarios);

    }
    system("pause");
}

void Manager::MostrarEncabezadoProductos()
{
    cout << left;
    cout << setw(5) << "ID";
    cout << setw(15) << "NOMBRE";
    cout << setw(45) << "DESCRIPCION";
    cout << setw(20) << "PRECIO DE VENTA";
    cout << setw(35) << "PRECIO DE COMPRA";
    cout << setw(55) << "FECHA DE ALTA" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Manager::mostrarEncabezado2()
{
    cout << left;
    cout << setw(15) << "NOMBRE";
    cout << setw(45) << "DESCRIPCION";
    cout << setw(20) << "PRECIO DE VENTA";
    cout << setw(35) << "PRECIO DE COMPRA";
    cout << setw(55) << "FECHA DE ALTA" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void Manager::AltaProducto()
{
    system("cls");
    cout << "INGRESE LOS DATOS DEL NUEVO PRODUCTO:" << endl << endl;
    Producto producto;
    int id = _regProductos.ObtenerUltimoIdProducto();
    producto.SetId(id);
    producto.CargarProducto();
    system("cls");
    cout << "Corrobore los datos:" << endl;
    setConsoleSize(20, 170);
    mostrarEncabezado2();
    producto.MostrarProducto2();
    char opc;
    cout << endl << endl;
    cout << "DATOS CORRECTOS? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        bool alta;
        alta = _regProductos.AltaProducto(producto);
        system("cls");
        if (alta)  cout << "PRODUCTO CARGADO CON EXITO" << endl;
        system("pause");
        return;
    }
    else {
        system("cls");
        cout << "DESEA CARGAR DE NUEVO EL PRODUCTO? (S/N)" << endl;
        char opc2;
        cin >> opc2;
        if (opc2 == 's' || opc2 == 'S')
        {
            AltaProducto();
            return;
        }
        else
        {
            return;
        }
    }
}
void Manager::BajaProducto()
{
    system("cls");
    Producto aux;
    bool borro = false;
    int id;
    setConsoleSize(10, 60);
    cout << "Ingrese el ID: ";
    cin >> id;
    cout << endl;

    aux = _regProductos.BuscarProducto(id);

    if (aux.GetId() != -1)
    {
        setConsoleSize(20, 170);
        int opc;
        cout << endl;
        MostrarEncabezadoProductos();
        aux.MostrarProducto();
        cout << endl;
        cout << "Se encontro Producto!" << " ¿Desea borrar?" << endl;
        cout << "1- SI" << endl;
        cout << "2- NO" << endl;
        cout << "Opcion elegida: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            borro = _reg.BajaProducto(aux.GetId());

            if (borro)
            {
                system("cls");
                setConsoleSize(10, 60);
                cout << "Producto borrado" << endl;
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
        cout << "NO SE ENCUENTRA CLIENTE EN SISTEMA" << endl;
        system("pause");
    }
}

void Manager::MoidificarProducto()
{
    system("cls");
    Producto aux;
    bool modifico = false;
    char nombre[40], desc[100];
    float precioVenta, precioCompra;
    int id;

    setConsoleSize(10, 60);
    cout << "Ingrese el ID del producto a modificar: ";
    cin >> id;
    cout << endl;

    aux = _regProductos.BuscarProducto(id);

    if (aux.GetId() != -1)
    {

        while (true)
        {
            system("cls");
            setConsoleSize(20, 170);
            MostrarEncabezadoProductos();
            aux.MostrarProducto();
            cout << endl << endl;
            int opc, pos;
            pos = _regProductos.BuscarPosicion(aux);
            cout << "Se encontro Cliente!" << " ¿Que desea cambiar?" << endl;
            cout << "1- Nombre" << endl;
            cout << "2- Apellido" << endl;
            cout << "3- Direcion" << endl;
            cout << "4- Email" << endl;
            cout << "0- Cancelar" << endl;
            cout << "Opcion elegida: ";
            cin >> opc;
            switch (opc)
            {
            case 1:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO NOMBRE: " << endl;

                cin.ignore();
                cin.getline(nombre, sizeof(nombre));
                aux.setNombre(nombre);

                modifico = _reg.ModificarCliente(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "NOMBRE DE CLIENTE CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 2:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO APELLIDO: " << endl;

                cin.ignore();
                cin.getline(apellido, sizeof(apellido));
                aux.setApellido(apellido);

                modifico = _reg.ModificarCliente(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "APELLIDO DE CLIENTE CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 3:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVA DIRECCION: " << endl;

                cin.ignore();
                cin.getline(direccion, sizeof(direccion));
                aux.setDomicilio(direccion);

                modifico = _reg.ModificarCliente(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "DIRECCION DE CLIENTE CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                return;
                break;
            case 4:
                system("cls");
                setConsoleSize(10, 60);
                cout << "INGRESE NUEVO EMAIL: " << endl;

                cin.ignore();
                cin.getline(email, sizeof(email));
                aux.setEmail(email);

                modifico = _reg.ModificarCliente(aux, pos);
                if (modifico)
                {
                    system("cls");
                    cout << "EMAIL DE CLIENTE CAMBIADO CON EXITO" << endl;
                    system("pause");
                }
                else {
                    cout << "ERROR AL MODIFICAR REGISTRO" << endl;
                    system("pause");
                }
                break;
            case 0:
                return;
                break;
            default:
                system("cls");
                setConsoleSize(10, 60);
                cout << "OPCION INVALIDA" << endl;
                system("pause");
                break;
            }
        }
    }
    else
    {
        system("cls");
        setConsoleSize(10, 60);
        cout << "NO SE ENCUENTRA CLIENTE EN SISTEMA" << endl;
        system("pause");
    }
}

void Manager::listarProducto()
{
    Producto producto;
    system("cls");
    setConsoleSize(60, 170);
    MostrarEncabezadoProductos();
    _regProductos.ListarProducto(producto);
    system("pause");
}

