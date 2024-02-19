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
}

void Proveedor::ModificarProveedor()
{
}

void Proveedor::ListarProveedores()
{
}

void Proveedor::BuscarProveedor()
{
}
