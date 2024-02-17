#include "ArchivosManager.h"
#include "Usuarios.h"
#include "Cliente.h"
#include "Proveedor.h"

ArchivosManager::ArchivosManager(const char* n){
	strcpy_s(_nombreArchivo, n);
}

// METODOS PARA USUARIOS
int ArchivosManager::ObtenerUltimoId() const
{
    int pos;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;

    fseek(p, 0, SEEK_END);
    pos = ftell(p);
    int ultimoRegistro = pos - sizeof(Usuarios);
    fseek(p, ultimoRegistro, SEEK_SET);

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

// METODOS PARA CLIENTES
int ArchivosManager::ObtenerUltimoIdCliente() const
{
    int pos;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;

    fseek(p, 0, SEEK_END);
    pos = ftell(p);
    int ultimoRegistro = pos - sizeof(Cliente);
    fseek(p, ultimoRegistro, SEEK_SET);

    Cliente reg;
    if (fread(&reg, sizeof(Cliente), 1, p) != 1) {
        fclose(p);
        return -1;
    }

    fclose(p);
    return reg.getId();
}
bool ArchivosManager::AltaCliente(Cliente reg)
{
    reg.setId(ObtenerUltimoIdCliente() + 1);
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;

    fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return true;
}
bool ArchivosManager::BajaCliente(int id)
{
    int pos = BuscarClienteXID(id);
    if (pos == -1)
    {
        cout << "NO SE ENCONTRO REGISTRO" << endl;
        return false;
    }
    Cliente reg = BuscarCliente(id);
    reg.Mostrar();
    char opc;
    cout << "desea borrar el registro? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        reg.setEstado(false);
        bool quePaso = sobreEscribirRegistro(reg, pos);
        return quePaso;
    }
    return false;
}
bool ArchivosManager::ModificarCliente(Cliente reg, int pos)
{
    char opc;
    cout << "Desea sobre escribir el registro? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        bool quePaso = sobreEscribirRegistro(reg, pos);
        return quePaso;
    }
    return false;
}
bool ArchivosManager::ListarCliente(Cliente reg) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&reg, sizeof(Cliente), 1, p) == 1)
    {
        reg.Mostrar();
    }
    fclose(p);
    return true;
}
bool ArchivosManager::sobreEscribirRegistro(Cliente reg, int pos)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Cliente) * pos, 0);
    bool escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}
int ArchivosManager::BuscarClienteXID(int id) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }

    int i = 0;
    Cliente reg;
    while (fread(&reg, sizeof(Cliente), 1, p) == 1)
    {
        if (reg.getId() == id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
int ArchivosManager::BuscarCLienteXDNI(int dni) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }

    int i = 0;
    Cliente reg;
    while (fread(&reg, sizeof(Cliente), 1, p) == 1)
    {
        if (reg.getDNI() == dni)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
Cliente ArchivosManager::BuscarCliente(int n) const
{
    Cliente reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return reg;
    }
    int pos;

    if (n>999999)
    {
        pos = BuscarCLienteXDNI(n);
    } else { 
        pos = BuscarClienteXID(n); 
    }
    
    fseek(p, sizeof(Cliente) * pos, 0);
    fread(&reg, sizeof(Cliente), 1, p);

    if (pos != -1)
    {
        fclose(p);
        return reg;
    }
    return reg;
    fclose(p);
}


// METODOS PARA PROVEEDORES
int ArchivosManager::ObtenerUltimoIdProveedor() const
{
    int pos;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;

    fseek(p, 0, SEEK_END);
    pos = ftell(p);
    int ultimoRegistro = pos - sizeof(Proveedor);
    fseek(p, ultimoRegistro, SEEK_SET);

    Proveedor reg;
    if (fread(&reg, sizeof(Proveedor), 1, p) != 1) {
        fclose(p);
        return -1;
    }

    fclose(p);
    return reg.getId();;
}
bool ArchivosManager::AltaProveedor(Proveedor reg)
{
    reg.setId(ObtenerUltimoIdProveedor() + 1);
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;

    fwrite(&reg, sizeof(Proveedor), 1, p);
    fclose(p);
    return true;
}
bool ArchivosManager::BajaProveedor(int id)
{
    int pos = BuscarProveedorXID(id);
    if (pos == -1)
    {
        cout << "NO SE ENCONTRO REGISTRO" << endl;
        return false;
    }
    Proveedor reg = BuscarProveedor(id);
    reg.Mostrar();
    char opc;
    cout << "desea borrar el registro? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        reg.setEstado(false);
        bool quePaso = sobreEscribirRegistroProveedor(reg, pos);
        return quePaso;
    }
    return false;
}
bool ArchivosManager::ModificarProveedor(Proveedor reg, int pos)
{
    char opc;
    cout << "Desea sobre escribir el registro? (S/N)" << endl;
    cin >> opc;
    if (opc == 's' || opc == 'S')
    {
        bool quePaso = sobreEscribirRegistroProveedor(reg, pos);
        return quePaso;
    }
    return false;
}
bool ArchivosManager::ListarProveedor(Proveedor reg) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return false;
    }

    while (fread(&reg, sizeof(Proveedor), 1, p) == 1)
    {
        reg.Mostrar();
    }
    fclose(p);
    return true;
}
bool ArchivosManager::sobreEscribirRegistroProveedor(Proveedor reg, int pos)
{
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Proveedor) * pos, 0);
    bool escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}
int ArchivosManager::BuscarProveedorXID(int id) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }

    int i = 0;
    Proveedor reg;
    while (fread(&reg, sizeof(Proveedor), 1, p) == 1)
    {
        if (reg.getId() == id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
int ArchivosManager::BuscarProveedorXDNI(int dni) const
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }

    int i = 0;
    Proveedor reg;
    while (fread(&reg, sizeof(Proveedor), 1, p) == 1)
    {
        if (reg.getDNI() == dni)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
Proveedor ArchivosManager::BuscarProveedor(int n) const
{
    Proveedor reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return reg;
    }
    int pos;

    if (n > 999999)
    {
        pos = BuscarProveedorXDNI(n);
    }
    else {
        pos = BuscarProveedorXID(n);
    }

    fseek(p, sizeof(Proveedor) * pos, 0);
    fread(&reg, sizeof(Proveedor), 1, p);

    if (pos != -1)
    {
        fclose(p);
        return reg;
    }
    return reg;
    fclose(p);
}



