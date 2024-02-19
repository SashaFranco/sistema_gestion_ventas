#include "Proveedor.h"

void Proveedor::mostrarEncabezado()
{
	cout << left;
	cout << setw(5) << "ID";
	cout << setw(15) << "DNI";
	cout << setw(20) << "NOMBRES";
	cout << setw(20) << "APELLIDOS";
	cout << setw(35) << "EMAIL";
	cout << setw(45) << "DOMICILIO";
	cout << setw(55) << "FECHA DE ALTA" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Proveedor::mostrarEncabezado2()
{
	cout << left;
	cout << setw(15) << "DNI";
	cout << setw(20) << "NOMBRES";
	cout << setw(20) << "APELLIDOS";
	cout << setw(35) << "EMAIL";
	cout << setw(45) << "DOMICILIO";
	cout << setw(55) << "FECHA DE ALTA" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Proveedor::AltaProveedor()
{
	system("cls");
	cout << "INGRESE LOS DATOS DEL NUEVO PROVEEDOR:" << endl << endl;
	Proveedor proveedor;
	int id = _reg.ObtenerUltimoIdProveedor();
	proveedor.setId(id);
	proveedor.Cargar();
	system("cls");
	cout << "Corrobore los datos:" << endl;
	setConsoleSize(20, 170);
	mostrarEncabezado2();
	proveedor.Mostrar2();
	char opc;
	cout << endl << endl;
	cout << "DATOS CORRECTOS? (S/N)" << endl;
	cin >> opc;
	if (opc == 's' || opc == 'S')
	{
		bool alta;
		alta = _reg.AltaProveedor(proveedor);
		system("cls");
		if (alta)  cout << "PROVEEDOR CARGADO CON EXITO" << endl;
		system("pause");
		return;
	}
	else {
		system("cls");
		cout << "DESEA CARGAR DE NUEVO EL PROVEEDOR? (S/N)" << endl;
		char opc2;
		cin >> opc2;
		if (opc2 == 's' || opc2 == 'S')
		{
			AltaProveedor();
			return;
		}
		else
		{
			return;
		}
	}
}
void Proveedor::BajaProveedor()
{
	system("cls");
	Proveedor aux;
	bool borro = false;
	int ID_DNI;
	setConsoleSize(10, 60);
	cout << "Ingrese el ID o DNI del Proveedor a borrar: ";
	cin >> ID_DNI;
	cout << endl;

	aux = _reg.BuscarProveedor(ID_DNI);

	if (aux.getId() != -1)
	{
		setConsoleSize(20, 170);
		int opc;
		cout << endl;
		aux.mostrarEncabezado();
		aux.Mostrar();
		cout << endl;
		cout << "Se encontro Proveedor!" << " ¿Desea borrar?" << endl;
		cout << "1- SI" << endl;
		cout << "2- NO" << endl;
		cout << "Opcion elegida: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			system("cls");
			borro = _reg.BajaProveedor(aux.getId());

			if (borro)
			{
				system("cls");
				setConsoleSize(10, 60);
				cout << "Proveedor borrado" << endl;
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
		cout << "NO SE ENCUENTRA PROVEEDOR EN SISTEMA" << endl;
		system("pause");
	}
}
void Proveedor::ModificarProveedor()
{
	system("cls");
	Proveedor aux;
	bool modifico = false;
	char nombre[40], apellido[40], direccion[100], email[50];
	int id;

	setConsoleSize(10, 60);
	cout << "Ingrese el ID o DNI del Proveedr a modificar: ";
	cin >> id;
	cout << endl;

	aux = _reg.BuscarProveedor(id);

	if (aux.getId() != -1)
	{
		while (true)
		{
			system("cls");
			setConsoleSize(20, 170);
			aux.mostrarEncabezado();
			aux.Mostrar();
			cout << endl << endl;
			int opc, pos;
			pos = _reg.BuscarPosicion(aux);
			cout << "Se encontro Proveedor!" << " ¿Que desea cambiar?" << endl;
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

				modifico = _reg.ModificarProveedor(aux, pos);
				if (modifico)
				{
					system("cls");
					cout << "NOMBRE DE PROVEEDOR CAMBIADO CON EXITO" << endl;
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

				modifico = _reg.ModificarProveedor(aux, pos);
				if (modifico)
				{
					system("cls");
					cout << "APELLIDO DE PROVEEDOR CAMBIADO CON EXITO" << endl;
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

				modifico = _reg.ModificarProveedor(aux, pos);
				if (modifico)
				{
					system("cls");
					cout << "DIRECCION DE PROVEEDOR CAMBIADO CON EXITO" << endl;
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

				modifico = _reg.ModificarProveedor(aux, pos);
				if (modifico)
				{
					system("cls");
					cout << "EMAIL DE PROVEEDOR CAMBIADO CON EXITO" << endl;
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
void Proveedor::ListarProveedores()
{
	Proveedor proveedor;
	system("cls");
	setConsoleSize(60, 170);
	proveedor.mostrarEncabezado();
	_reg.ListarProveedor(proveedor);
	system("pause");
}
void Proveedor::BuscarProveedor()
{
	system("cls");
	cout << "INGRESE EL DNI O EL ID DEL PROVEEDOR A BUSCAR:" << endl << endl;
	int num;
	cin >> num;
	Proveedor proveedor;
	proveedor = _reg.BuscarProveedor(num);
	if (proveedor.getId() == -1)
	{
		cout << "NO SE ENCONTRO PROVEEDOR" << endl;
		system("pause");
		return;
	}
	system("cls");
	setConsoleSize(20, 170);
	cout << "PROVEEDOR ENCONTRADO: " << endl << endl;
	proveedor.mostrarEncabezado();
	proveedor.Mostrar();
	system("pause");
}
