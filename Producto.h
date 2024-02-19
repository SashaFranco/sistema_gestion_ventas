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

	void CargarVentaProducto();
	void CargarCompraProducto();
	void MostrarProducto();

	void SetId(int id);
	void SetNombre(const char * nombre);
	void SetCantidad(int cantidad);
	void SetCliente(Cliente cliente);
	void SetProveedor(Proveedor proveedor);
	void SetFecha(Fecha fecha);
	void SetEstado(bool estado);
	void SetPrecio(float precio);
	void SetCompraVenta(int compraVenta);

	int GetId() const;
	char* GetNombre() const;
	int GetCantidad() const;
	Cliente GetCliente() const;
	Proveedor GetProveedor() const;
	Fecha GetFecha() const;
	bool GetEstado() const;
	float GetPrecio() const;
	int GetCompraVenta() const;

private:
	int _id, _cantidad, _compraVenta; // 1 compra - 2 venta
	float _precio;
	char _nombre[40];
	Cliente _cliente;
	Proveedor _proveedor;
	Fecha _fecha;
	bool _estado;
};

