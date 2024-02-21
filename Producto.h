#pragma once
#include <iostream>
using namespace std;
#include "Fecha.h"
#include <iomanip>
#include "Helpers.h"
#include "Cliente.h"
#include "Proveedor.h"

class Producto
{
public:

	Producto();
	Producto(int id, 
		const char* nombre, 
		int precioVenta, 
		int precioCompra, 
		Cliente cliente,
		Proveedor proveedor);

	void CargarProducto();
	void MostrarProducto();
	void MostrarProducto2();

	void SetId(int id);
	void SetNombre(const char * nombre);
	void SetCantidad(int cantidad);
	void SetCliente(Cliente cliente);
	void SetProveedor(Proveedor proveedor);
	void SetFecha();
	void SetEstado(bool estado);
	void SetPrecioVenta(float precioVenta);
	void SetPrecioCompra(float precioCompra);
	void SetDescripcion(const char* desc);
	

	int GetId() const;
	char* GetNombre();
	char* GetDescripcion();
	int GetCantidad() const;
	Cliente GetCliente() const;
	Proveedor GetProveedor() const;
	Fecha GetFecha() const;
	bool GetEstado() const;
	float GetPrecioVenta() const;
	float GetPrecioCompra() const;
	

private:
	int _id, _cantidad;
	float _precioVenta, _precioCompra;
	char _nombre[40], _descripcion[100];
	Cliente _cliente;
	Proveedor _proveedor;
	Fecha _fecha;
	bool _estado;
};

