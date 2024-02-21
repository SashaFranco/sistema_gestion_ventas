#include "Stock.h"

Stock::Stock()
{
	_id = -1;
	_cantidad = 0;
	_producto = Producto();
	_fecha = Fecha(0, 0, 0);
}

void Stock::CargarStock(Producto &p)
{
	int cantidad;

	cout << "CARGAR CANTIDAD DEL ARTICULO: " << endl;
	cout << "CANTIDAD: ";
	cin >> cantidad;
	cout << endl;

	SetCantidad(cantidad);
	_producto = p;
}

void Stock::MostrarStock()
{

	cout << setw(5) << GetId();
	cout << setw(5) << _producto.GetId();
	cout << setw(15) << _producto.GetNombre();
	cout << setw(45) << _producto.GetDescripcion();
	cout << setw(20) << _producto.GetPrecioVenta();
	cout << setw(20) << _producto.GetPrecioCompra();
	cout << setw(35) << GetCantidad();
	cout << setw(55) << GetFecha().toString() << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}

void Stock::SetId(int id){_id = id;}
void Stock::SetCantidad(int cantidad){_cantidad = cantidad;}
void Stock::SetProducto(Producto p){_producto = p;}
void Stock::SetFecha(){_fecha.FechaActual();}

int Stock::GetId() const{return _id;}
int Stock::GetCantidad() const{return _cantidad;}
Producto Stock::GetProdcuto() const{return _producto;}
Fecha Stock::GetFecha() const {return _fecha;}
