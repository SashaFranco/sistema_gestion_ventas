#include "Producto.h"

Producto::Producto()
{
	_id = -1;
	_cantidad = 0;
	_precio = 0.0;
	strcpy_s(_nombre, "");
	_cliente = Cliente();
	_proveedor = Proveedor();
	_fecha = Fecha(0, 0, 0);
	_estado = true;
	_compraVenta = -1;
}

void Producto::CargarVentaProducto()
{
}

void Producto::CargarCompraProducto()
{
}

void Producto::MostrarProducto()
{
}

void Producto::SetId(int id)
{
}

void Producto::SetNombre(const char* nombre)
{
}

void Producto::SetCantidad(int cantidad)
{
}

void Producto::SetCliente(Cliente cliente)
{
}

void Producto::SetProveedor(Proveedor proveedor)
{
}

void Producto::SetFecha(Fecha fecha)
{
}

void Producto::SetEstado(bool estado)
{
}

void Producto::SetPrecio(float precio)
{
}

void Producto::SetCompraVenta(int compraVenta)
{
}



int Producto::GetId() const
{
	return 0;
}

char* Producto::GetNombre() const
{
	return nullptr;
}

int Producto::GetCantidad() const
{
	return 0;
}

Cliente Producto::GetCliente() const
{
	return Cliente();
}

Proveedor Producto::GetProveedor() const
{
	return Proveedor();
}

Fecha Producto::GetFecha() const
{
	return Fecha();
}

bool Producto::GetEstado() const
{
	return false;
}

float Producto::GetPrecio() const
{
	return 0.0f;
}

int Producto::GetCompraVenta() const
{
	return 0;
}


