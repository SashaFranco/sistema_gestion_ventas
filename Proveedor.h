#pragma once
#include "Persona.h"
#include "ArchivosManager.h"

class Proveedor :
    public Persona
{
private:
    ArchivosManager _reg = ArchivosManager("Proveedores.dat");
};

