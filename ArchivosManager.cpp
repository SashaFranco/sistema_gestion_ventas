#include "ArchivosManager.h"
#include "Usuarios.h"

ArchivosManager::ArchivosManager(const char* n){
	strcpy_s(_nombreArchivo, n);
}
int ArchivosManager::ObtenerUltimoId() const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;

    // se para en el principio del utimo registro
    fseek(p, sizeof(Usuarios), SEEK_END); 

    Usuarios reg;
    if (fread(&reg, sizeof(Usuarios), 1, p) != 1) {
        fclose(p);
        return -1;
    }

    fclose(p);
    return reg.GetId();
}
Usuarios ArchivosManager::BuscarUsuario(const char* usuario, const char* passw) const
{
    Usuarios reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cerr << "Error al abrir el archivo de usuarios." << endl;
        return reg;
    }

    while (fread(&reg, sizeof(Usuarios), 1, p) == 1) {
        if (reg.getEstado() == true && reg.verificarCredenciales(usuario, passw) == true)
        {
            fclose(p);
            return reg;
        }
    }
    fclose(p);
    reg.SetId(-1);
    return reg;
}
bool ArchivosManager::AltaUsuario(Usuarios reg)
{
    reg.SetId(ObtenerUltimoId() + 1);
	FILE* p = fopen(_nombreArchivo, "ab");
	if (p == nullptr) return false;

	fwrite(&reg, sizeof(Usuarios), 1, p);
	fclose(p);
	return true;
}
bool ArchivosManager::BajaUsuario(int id)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr) {
        cerr << "Error al abrir el archivo de usuarios." << endl;
        return false;
    }

    Usuarios reg;
    int pos = -1;

    while (fread(&reg, sizeof(Usuarios), 1, p) == 1) {
        pos++;
        if (reg.getEstado() && reg.GetId() == id) {
            fseek(p, sizeof(Usuarios) * pos, SEEK_SET);

            reg.setEstado(false);
            
            fwrite(&reg, sizeof(Usuarios), 1, p);
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool ArchivosManager::ModificarUsuario(int id, const char* nuevoUsuario, const char* nuevaPassw)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr) {
        cerr << "Error al abrir el archivo de usuarios." << endl;
        return false;
    }

    Usuarios reg;
    int pos = -1;

    while (fread(&reg, sizeof(Usuarios), 1, p) == 1) {
        pos++;
        if (reg.getEstado() && reg.GetId() == id) {
            fseek(p, sizeof(Usuarios) * pos, SEEK_SET);
            if (nuevoUsuario != nullptr) {
                cin.ignore();
                reg.cambiarUsuario(nuevoUsuario, nullptr);
                cout << endl;
            }
            if (nuevaPassw != nullptr) {
                reg.cambiarUsuario(nullptr, nuevaPassw);
                cout << endl;
            }
            fwrite(&reg, sizeof(Usuarios), 1, p);
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
bool ArchivosManager::ListarUsuarios(Usuarios reg)
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;

    while (fread(&reg, sizeof(Usuarios), 1, p) == 1)
    {
        if (reg.getEstado()==true)
        {
            reg.Mostar();
        }
    }
}
