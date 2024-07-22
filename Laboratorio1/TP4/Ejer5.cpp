// 5.	Realizar una aplicación que pueda cargar 20 nombres de usuario en un procedimiento. 
// Luego en otro procedimiento retornar la cantidad de cada letra que existe en todos los 
// nombres y determinar cuál es la letra que más se repite. Utilizar todos los subprogramas y
//  funciones necesarios.


#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;
int notas[SIZE];

// Procedimiento para cargar 10 notas
void cargarNotas() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Ingrese la nota " << i + 1 << ": ";
        cin >> notas[i];
    }
}

// Procedimiento para mostrar notas mayores a un número dado
void mostrarNotasMayores(int numero) {
    cout << "Notas mayores que " << numero << ":\n";
    for (int i = 0; i < SIZE; i++) {
        if (notas[i] > numero) {
            cout << notas[i] << endl;
        }
    }
}

int main() {
    int numero;

    cargarNotas();

    cout << "Ingrese el número para comparar: ";
    cin >> numero;

    mostrarNotasMayores(numero);

    return 0;
}
