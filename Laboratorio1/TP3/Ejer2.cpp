// 2. Cree un programa simple para sumar los valores de 2 vectores A y B, y poner el
// resultado en un tercer vector C.
// Para ello sume los valores ubicados en la misma posición del primer y segundo
// vector y coloque el resultado en c, en la misma posición.
// Llenar los vectores A y B con números aleatorios.
// Mostrar el contenido del vector C.

#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

using namespace std;

int main() {
    const int SIZE = 10;
    int A[SIZE], B[SIZE], C[SIZE];

    // Inicializar la semilla para los números aleatorios
    srand(time(0));

    // Llenar los vectores A y B con números aleatorios
    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % 100 + 1; // Números aleatorios entre 1 y 100
        B[i] = rand() % 100 + 1;
    }

    // Sumar los valores ubicados en la misma posición y poner el resultado en C
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }

    // Mostrar el contenido del vector C
    cout << "Contenido del vector C:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Posición " << i << ": " << C[i] << endl;
    }

    return 0;
}
