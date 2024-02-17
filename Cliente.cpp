#include "Cliente.h"

void Cliente::mostrarEncabezado()
{
	cout << left;
	cout << setw(5) << "ID";
	cout << setw(15) << "DNI";
	cout << setw(20) << "NOMBRES";
	cout << setw(20) << "APELLIDOS";
	cout << setw(20) << "EMAIL";
	cout << setw(45) << "DOMICILIO";
	cout << setw(75) << "FECHA DE ALTA" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Cliente::mostrarEncabezado2()
{
	cout << left;
	cout << setw(15) << "DNI";
	cout << setw(20) << "NOMBRES";
	cout << setw(20) << "APELLIDOS";
	cout << setw(20) << "EMAIL";
	cout << setw(45) << "DOMICILIO";
	cout << setw(75) << "FECHA DE ALTA" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
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
	setConsoleSize(20, 160);
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

void Cliente::ListarClientes()
{
	Cliente cliente;
	system("cls");
	setConsoleSize(20, 160);
	cliente.mostrarEncabezado();
	_reg.ListarCliente(cliente);
	system("pause");
}
