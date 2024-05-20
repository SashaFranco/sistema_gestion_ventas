#include "Menu.h"


void Menu::MostrarEntrada()
{
    while (true)
    {
        system("cls");
        int opcion;
        cout << left;
        cout << "***********************" << endl;
        cout << "** " << _fechaSitema.toString() << " - " << _fechaSitema.getNombreDia() << " **" << endl;
        cout << "***********************" << endl << endl;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "-----------------BIENVENDIO-----------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú inicial
        cout << setw(40) << "1. ENTRAR AL SISTEMA" << endl;
        cout << setw(40) << "2. CREDITOS" << endl;
        cout << setw(40) << "0. SALIR" << endl;
        setConsoleSize(45, 45);

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            
            /*if (_manager.entradaAlSistema())
            {
                mostrar();
            }*/
            mostrar();
            break;
        case 2:
            cout << endl;
            cout << "Sasha Emanuel Franco" << endl;
            system("pause");
            break;
        case 0:
            return;
            break;
        default: "OPCION INCORRECTA, ELIJA DE NUEVO";
            system("pause");
            break;
        }
    }
    
}
void Menu::mostrar()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << "***********************" << endl;
        cout << "** " << _fechaSitema.toString() << " - " << _fechaSitema.getNombreDia() << " **" << endl;
        cout << "***********************" << endl << endl;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "--------BIENVENDIO AL MENU PRINCIPAL--------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú principal
        cout << setw(40) << "1. GESTIONAR COMPRAS - STOCK" << endl;
        cout << setw(40) << "2. REALIZAR VENTA" << endl;
        cout << setw(40) << "3. ABM" << endl;
        cout << setw(40) << "4. EMITIR REPORTES" << endl;
        cout << setw(40) << "5. GRESTION DE USUARIOS" << endl; //terminado
        cout << setw(40) << "6. BACKUP DE ARCHIVOS" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            mostrarCompras();
            break;
        case 2:
            mostrarVentas();
            break;
        case 3:
            mostrarABM();
            break;
        case 4:
            mostrarRreportes();
            break;
        case 5:
            mostrarUsuarios();
            break;
        case 6:
            mostrarBk();
            break;
        case 0:
            return;
            break;
        default: 
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}
void Menu::mostrarCompras()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "---------------MENU DE COMPRAS--------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de compras
        cout << setw(40) << "1. INGRESAR AL STOCK PRODUCTOS COMPRADOS" << endl;
        cout << setw(40) << "2. LISTAR STOCK DE PRODUCTOS" << endl;
        cout << setw(40) << "3. BUSCAR PRODUCTO" << endl;
        cout << setw(40) << "4. INGRESAR COMPRA" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("pause");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::mostrarVentas()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "---------------MENU DE VENTAS---------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ventas
        cout << setw(40) << "1. INGRESAR VENTA DE UN ARTICULO" << endl;
        cout << setw(40) << "2. INGRESAR VENTA DE VARIOS ARTICULOS" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            break;
        case 2:
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }

}

void Menu::mostrarABM()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "----------------MENU PARA ABM---------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ABM
        cout << setw(40) << "1. ABM DE CLIENTES" << endl;
        cout << setw(40) << "2. ABM DE PROVEEDORES" << endl;
        cout << setw(40) << "3. ABM DE PRODUCTOS" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            mostrarABMCLientes();
            break;
        case 2:
            mostrarABMProveedores();
            break;
        case 3:
            mostrarABMProductos();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::mostrarRreportes()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "----------------MENU REPORTES---------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de reportes
        cout << setw(40) << "1. LISTAR CLIENTES" << endl;
        cout << setw(40) << "2. LISTAR PROVEEDORES" << endl;
        cout << setw(40) << "3. LISTAR PRODUCTOS" << endl;
        cout << setw(40) << "4. LISTADO DE VENTAS" << endl;
        cout << setw(40) << "5. EMITIR REPORTE DE CAJA" << endl;
        cout << setw(40) << "6. EXPORTAR REPORTES A CSV" << endl; // REVISAR COMO HACER
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _cliente.ListarClientes();
            break;
        case 2:
            _proveedor.ListarProveedores();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            // REVISAR COMO EXPORTAR DE BINARIOS A XLS
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::mostrarUsuarios()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "----------------MENU USUARIOS---------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de usuarios del sistema
        cout << setw(40) << "1. LISTAR USUARIOS" << endl;
        cout << setw(40) << "2. CREAR NUEVO USUARIO" << endl;
        cout << setw(40) << "3. MODIFICAR USUARIO" << endl;
        cout << setw(40) << "4. ELIMINAR USUARIO" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _manager.listarUsuarios();
            break;
        case 2:
            _manager.AltaUsuarios();
            break;
        case 3:
            _manager.MoidificarUsuarios();
            break;
        case 4:
            _manager.BajaUsuario();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::mostrarBk()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE HALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "-----------------MENU BUCKUP----------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú para BK
        cout << setw(40) << "1. BUCKUP CLIENTES" << endl;
        cout << setw(40) << "2. BUCKUP PROVEEDORES" << endl;
        cout << setw(40) << "3. BUCKUP PRODUCTOS" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::mostrarABMCLientes()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "--------------MENU ABM CLIENTES-------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ABM
        cout << setw(40) << "1. ALTA DE CLIENTE NUEVO" << endl;
        cout << setw(40) << "2. BAJA DE CLIENTE" << endl;
        cout << setw(40) << "3. MODIFICAR CLIENTE" << endl;
        cout << setw(40) << "4. LISTAR CLIENTES" << endl;
        cout << setw(40) << "5. BUSCAR CLIENTE POR ID O DNI" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _cliente.AltaCliente();
            break;
        case 2:
            _cliente.BajaCliente();
            break;
        case 3:
            _cliente.ModificarCliente();
            break;
        case 4:
            _cliente.ListarClientes();
            break;
        case 5:
            _cliente.BuscarCliente();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }

}

void Menu::mostrarABMProveedores()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "------------MENU ABM PROVEEDORES------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ABM
        cout << setw(40) << "1. ALTA DE PROVEEDOR NUEVO" << endl;
        cout << setw(40) << "2. BAJA DE PROVEEDOR" << endl;
        cout << setw(40) << "3. MODIFICAR PROVEEDOR" << endl;
        cout << setw(40) << "4. LISTAR PROVEEDOR" << endl;
        cout << setw(40) << "5. BUSCAR PROVEEDOR POR ID O DNI" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _proveedor.AltaProveedor();
            break;
        case 2:
            _proveedor.BajaProveedor();
            break;
        case 3:
            _proveedor.ModificarProveedor();
            break;
        case 4:
            _proveedor.ListarProveedores();
            break;
        case 5:
            _proveedor.BuscarProveedor();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

void Menu::mostrarABMProductos()
{
    while (true)
    {
        system("cls");
        int opc;
        cout << left;
        cout << setw(40) << "SISTEMA DE GESTION PARA LA VENTA DE ALMACEN" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "------------MENU ABM PRODUCTOS--------------" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        // Opciones del menú de ABM
        cout << setw(40) << "1. ALTA DE PRODUCTO NUEVO" << endl;
        cout << setw(40) << "2. BAJA DE PRODUCTO" << endl;
        cout << setw(40) << "3. MODIFICAR PRODUCTO" << endl;
        cout << setw(40) << "4. LISTAR PRODUCTOS" << endl;
        cout << setw(40) << "5. BUSCAR PRODUCTO POR ID" << endl;
        cout << setw(40) << "6. BUSCAR PRODUCTO POR NOMBRE" << endl;
        cout << setw(40) << "--------------------------------------------" << endl;
        cout << setw(40) << "0. VOLVER AL MENU PRINCIPAL" << endl;
        setConsoleSize(45, 45);
        cin >> opc;

        switch (opc)
        {
        case 1:
            _manager.AltaProducto();
            break;
        case 2:
            _manager.BajaProducto(); // REVISAR POR QUE NO DA DE BAJA LOS PRODUCTOS
            break;
        case 3:
            _manager.MoidificarProducto();
            break;
        case 4:
            _manager.listarProducto();
            break;
        case 5:
            _manager.BuscarProductoXID();
            break;
        case 6:
            _manager.BuscarProductoXNombre();
            break;
        case 0:
            return;
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }

}
