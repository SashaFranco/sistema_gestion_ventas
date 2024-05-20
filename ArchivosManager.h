#pragma once
#include <iostream>

class Usuarios;
class Cliente;
class Proveedor;
class Producto;
class Stock;

using namespace std;

class ArchivosManager
{
public:

	ArchivosManager(const char* n);

	// METODOS PARA Usuario
	int ObtenerUltimoId() const;
	Usuarios BuscarUsuario(const char* usuario, const char* passw) const;
	bool AltaUsuario(Usuarios reg);
	bool BajaUsuario(int id);
	bool ModificarUsuario(int id, const char* nuevoUsuario, const char* nuevaPassw);
	bool ListarUsuarios(Usuarios reg);

	// METODOS PARA Cliente
	int ObtenerUltimoIdCliente() const;
	bool AltaCliente(Cliente reg);
	bool BajaCliente(int id);
	bool ModificarCliente( Cliente reg, int pos);
	bool ListarCliente(Cliente reg) const;
	bool sobreEscribirRegistro(Cliente reg, int pos);
	int BuscarClienteXID(int id, FILE *p) const;
	int BuscarCLienteXDNI(int dni, FILE *P) const;
	int BuscarPosicion(Cliente reg);
	Cliente BuscarCliente(int n) const;


	// METODOS PARA Proveedor

	int ObtenerUltimoIdProveedor() const;
	bool AltaProveedor(Proveedor reg);
	bool BajaProveedor(int id);
	bool ModificarProveedor(Proveedor reg, int pos);
	bool ListarProveedor(Proveedor reg) const;
	bool sobreEscribirRegistroProveedor(Proveedor reg, int pos);
	int BuscarProveedorXID(int id, FILE *p) const;
	int BuscarProveedorXDNI(int dni, FILE* p) const;
	int BuscarPosicion(Proveedor reg);
	Proveedor BuscarProveedor(int n) const;

	// METODOS PARA Producto

	int ObtenerUltimoIdProducto() const;
	bool AltaProducto(Producto reg);
	bool BajaProducto(int id);
	bool ModificarProducto(Producto reg, int pos);
	bool ListarProducto(Producto reg) const;
	bool sobreEscribirRegistroProducto(Producto reg, int pos);
	int BuscarProductoXID(int id, FILE* p) const;
	int BuscarProductoXNombre(const char* nombre) const;
	int BuscarPosicion(Producto reg);
	Producto BuscarProducto(int n) const;

	// METODOS PARA EL STOCK
	int ObtenerUltimoIdStock() const;
	bool AltaStock(Stock reg);
	bool ListarStock(Stock reg) const;
	bool ModificarStock(Stock reg, int pos);
	int BuscarPosicionStock(Stock reg);
	int BuscarStockXID(int id, FILE* p) const;
	/*Stock BuscarStockFecha(Fecha fecha) const;
	Stock BuscarStock(int n) const;*/

private:
	char _nombreArchivo[30];
};

