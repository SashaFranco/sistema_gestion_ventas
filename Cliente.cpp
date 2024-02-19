#include "Cliente.h"

void Cliente::mostrarEncabezado()
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
void Cliente::mostrarEncabezado2()
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
void Cliente::AltaCliente()
{
	system("cls");
	cout << "INGRESE LOS DATOS DEL NUEVO CLIENTE:" << endl << endl;
	Cliente cliente;
	int id = _reg.ObtenerUltimoIdCliente();
	cliente.setId(id);
	cliente.Cargar();
	system("cls");
	cout << "Corrobore los datos:" << endl;
	setConsoleSize(20, 170);
	mostrarEncabezado2();
	cliente.Mostrar2();
	char opc;
	cout << endl << endl;
	cout << "DATOS CORRECTOS? (S/N)" << endl;
	cin >> opc;
	if (opc == 's' || opc == 'S')
	{
		bool alta;
		alta = _reg.AltaCliente(cliente);
		system("cls");
		if (alta)  cout << "CLIENTE CARGADO CON EXITO" << endl;
		system("pause");
		return;
	}
	else {
		system("cls");
		cout << "DESEA CARGAR DE NUEVO EL CLIENTE? (S/N)" << endl;
		char opc2;
		cin >> opc2;
		if (opc2 == 's' || opc2 == 'S')
		{
			AltaCliente();
			return;
		}
		else
		{
			return;
		}
	}
}
void Cliente::BajaCliente()
{
	system("cls");
	Cliente aux;
	bool borro = false;
	int ID_DNI;
	setConsoleSize(10, 60);
	cout << "Ingrese el ID o DNI del cliente a borrar: ";
	cin >> ID_DNI;
	cout << endl;

	aux = _reg.BuscarCliente(ID_DNI);

	if (aux.getId() != -1)
	{
		setConsoleSize(20, 170);
		int opc;
		cout << endl;
		aux.mostrarEncabezado();
		aux.Mostrar();
		cout << endl;
		cout << "Se encontro cliente!" << " ¿Desea borrar?" << endl;
		cout << "1- SI" << endl;
		cout << "2- NO" << endl;
		cout << "Opcion elegida: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			system("cls");
			borro = _reg.BajaCliente(aux.getId());

			if (borro)
			{
				system("cls");
				setConsoleSize(10, 60);
				cout << "Cliente borrado" << endl;
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
void Cliente::ModificarCliente()
{
	
	system("cls");
	Cliente aux;
	bool modifico = false;
	char nombre[40], apellido[40], direccion[100], email[50];
	int id;

	setConsoleSize(10, 60);
	cout << "Ingrese el ID o DNI del cliente a modificar: ";
	cin >> id;
	cout << endl;

	aux = _reg.BuscarCliente(id);

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
void Cliente::ListarClientes()
{
	Cliente cliente;
	system("cls");
	setConsoleSize(60, 170);
	cliente.mostrarEncabezado();
	_reg.ListarCliente(cliente);
	system("pause");
}
void Cliente::BuscarCliente()
{
	system("cls");
	cout << "INGRESE EL DNI O EL ID DEL CLIENTE A BUSCAR:" << endl << endl;
	int num;
	cin >> num;
	Cliente cliente;
	cliente = _reg.BuscarCliente(num);
	if (cliente.getId()==-1)
	{
		cout << "NO SE ENCONTRO CLIENTE" << endl;
		system("pause");
		return;
	}
	system("cls");
	setConsoleSize(20, 170);
	cout << "CLIENTE ENCONTRADO: " << endl << endl;
	cliente.mostrarEncabezado();
	cliente.Mostrar();
	system("pause");
}

