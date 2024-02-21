#pragma once
#include <iostream>
#include "Producto.h"
#include "Fecha.h"
using namespace std;

class Stock
{
public:

    Stock();

    void CargarStock(Producto &producto);
    void MostrarStock();

    void SetId(int id);
    void SetCantidad(int cantidad);
    void SetProducto(Producto p);
    void SetFecha();


    int GetId() const;
    int GetCantidad() const;
    Producto GetProdcuto() const;
    Fecha GetFecha() const;

private:

    int _id, _cantidad;
    Producto _producto;
    Fecha _fecha;
};

