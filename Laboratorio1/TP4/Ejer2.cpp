// 2.	Cargar un arreglo de 20 números en un 
// procedimiento y realizar el cálculo de promedio de los números en una función pasando el arreglo al mismo.
#include <iostream>

using namespace std;

const int SIZE = 20;

// Procedimiento para cargar un arreglo con 20 números
void cargarArreglo(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Ingrese un número para la posición " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Función para calcular el promedio de los números en el arreglo
double calcularPromedio(int arr[], int size) {
    int suma = 0;
    for (int i = 0; i < size; i++) {
        suma += arr[i];
    }
    return static_cast<double>(suma) / size;
}

int main() {
    int numeros[SIZE];
    
    cargarArreglo(numeros, SIZE);

    double promedio = calcularPromedio(numeros, SIZE);
    cout << "El promedio de los números es: " << promedio << endl;

    return 0;
}
