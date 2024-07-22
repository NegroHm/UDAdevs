// 8. Calcular el promedio de notas de una clase
// a. Tu tarea es escribir una función promedio(). La firma de tu función
// debería ser: double average (double marks[], int size)
// b. El input array marks[] contendrá las notas de todos los alumnos de la
// clase. Tu tarea es calcular el promedio de notas de la clase y retornarlo
// como salida. Asumimos que el valor de cada nota será mayor a cero.
// c. La fórmula básica para calcular el promedio de los valores es la
// siguiente: promedio = suma de todos los valores / número total de
// valores
// d.

#include <iostream>

using namespace std;

// a. Declaración de la función promedio
double promedio(double marks[], int size) {
    double suma = 0;

    // c. Calcular la suma de todos los valores
    for (int i = 0; i < size; i++) {
        suma += marks[i];
    }

    // Calcular y retornar el promedio
    return suma / size;
}

int main() {
    // Ejemplo de notas
    const int SIZE = 5;
    double notas[SIZE] = {85.5, 90.0, 78.5, 92.0, 88.0};

    // Llamada a la función promedio y mostrar el resultado
    double resultado = promedio(notas, SIZE);
    cout << "El promedio de las notas es: " << resultado << endl;

    return 0;
}
