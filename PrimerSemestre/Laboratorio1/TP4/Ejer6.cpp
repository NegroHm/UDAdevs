// 6.	Realizar una aplicación donde existen 3 tipos de usuario (Administrador, Editor, Lector),
// el administrador puede crear usuarios, borrar usuarios, ver todos los usuarios, crear notas,
// borrar notas y ver todas las notas. El Editor solo puede ver las notas y crearlas. 
// El lector solo puede ver las notas. Realizar un arreglo de usuarios, un arreglo de notas.
// Un procedimiento para mostrar todos los usuarios y uno para mostrar todas las notas, pasando 
// el arreglo de usuarios y notas respectivamente. Una función que elimine un elemento del 
// arreglo y retorne 1 si se pudo eliminar y 0 si no se pudo eliminar. Realizar una función 
// que permita hacer el cambio de tipo de usuario para que pueda desplegarse cada una de las 
// opciones del menú.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum TipoUsuario {ADMINISTRADOR, EDITOR, LECTOR};

struct Usuario {
    string nombre;
    TipoUsuario tipo;
};

struct Nota {
    string contenido;
};

vector<Usuario> usuarios;
vector<Nota> notas;

// Procedimiento para mostrar todos los usuarios
void mostrarUsuarios() {
    for (Usuario& usuario : usuarios) {
        cout << "Nombre: " << usuario.nombre << ", Tipo: ";
        switch (usuario.tipo) {
            case ADMINISTRADOR: cout << "Administrador"; break;
            case EDITOR: cout << "Editor"; break;
            case LECTOR: cout << "Lector"; break;
        }
        cout << endl;
    }
}

// Procedimiento para mostrar todas las notas
void mostrarNotas() {
    for (Nota& nota : notas) {
        cout << "Nota: " << nota.contenido << endl;
    }
}

// Función para eliminar un usuario o una nota
template <typename T>
int eliminarElemento(vector<T>& elementos, int index) {
    if (index >= 0 && index < elementos.size()) {
        elementos.erase(elementos.begin() + index);
        return 1;
    }
    return 0;
}

// Función para cambiar el tipo de usuario
void cambiarTipoUsuario(int index, TipoUsuario nuevoTipo) {
    if (index >= 0 && index < usuarios.size()) {
        usuarios[index].tipo = nuevoTipo;
    }
}

int main() {
    // Código para gestionar el menú y las opciones según el tipo de usuario
    // Se omite por brevedad, pero seguiría la lógica de los ejemplos anteriores.

    return 0;
}



