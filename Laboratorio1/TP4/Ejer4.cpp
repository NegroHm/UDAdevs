// 4.	Desarrollar un programa que solicite la carga de 10 notas en
// un procedimiento. Luego otro procedimiento que
// devuelva todas las notas mayores al número que se le pase al procedimiento.
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
