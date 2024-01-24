#include "Helpers.h"
#include <iostream>
using namespace std;

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
