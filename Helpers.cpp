#include "Helpers.h"
#include <iostream>
using namespace std;

//#include <xlslib.h>
#include "Cliente.h"
#include "Proveedor.h"
#include "Producto.h"

void setConsoleSize(int rows, int cols) {
    cout << "\x1b[8;" << rows << ";" << cols << "t"; // ANSI escape (funcion para controlar tamaño de consola)
}

void cargarCadena(char* pal, int tam)
{
    int i;
    fflush(stdin);
    for (i = 0; i < tam; i++)
    {
        pal[i] = cin.get();
        if (pal[i] == '\n') break;
    }
    pal[i] = '\0';
    fflush(stdin);
}

//void ExportarExcel(const char* nombreArchivo)
//{
//    WORKBOOK* libro = xls_newWorkbook();
//    WORKSHEET* hoja = xls_addWorksheet(libro, "Datos");
//
//    // Agrega encabezados
//    xls_writeStr(hoja, 0, 0, "Nombre");
//    xls_writeStr(hoja, 0, 1, "Apellido");
//    xls_writeStr(hoja, 0, 2, "DNI");
//
//    // Obtén datos de clientes y escribe en el archivo
//    // (Reemplaza con tu lógica específica para obtener los datos de tus clases)
//    Clientes cliente;
//    // ... lógica para abrir el archivo y leer los clientes
//    // Escribe los datos en el archivo Excel
//    xls_writeStr(hoja, 1, 0, cliente.GetNombre());
//    xls_writeStr(hoja, 1, 1, cliente.GetApellido());
//    xls_writeNum(hoja, 1, 2, cliente.GetDNI());
//
//    // Repite el proceso para Proveedores y Productos
//
//    // Guarda el archivo Excel
//    xls_save(libro, nombreArchivo);
//    xls_deleteWorkbook(libro);
//}
