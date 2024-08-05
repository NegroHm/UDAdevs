#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void generateNumber(int n, int vector[]);
void show(int n, int vector[]);
int average(int n, int vector[], int aux);

int main()
{
    int number[100];
    int aux = 0;

    generateNumber(100, number);
    show(100, number);
    cout << endl;
    cout << "El numero que mas se repite es el: " << average(100, number, aux);
    

    return 0;
}

void generateNumber(int n, int vector[]){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        vector[i] = rand() % 99;
    }
}

void show(int n, int vector[]){
    for(int i = 0; i < n; i++){
        cout << vector[i] << " ";
    }
}

// int average(int n, int vector[], int aux){
// for (int i = 0; i < n; i++){
//     if (vector[i] = vector[i++])
//     {
//         aux = vector[i];   
//     }
//     }
// return aux;
// }   
int average(int n, int vector[], int aux) {
    // Crear un array para contar las frecuencias de los números
    int frecuencia[100] = {0}; // Asumiendo que los números en el array están en el rango [0, 99]

    // Contar las frecuencias de cada número en el array
    for (int i = 0; i < n; i++) {
        frecuencia[vector[i]]++;
    }

    // Encontrar el número con la mayor frecuencia
    int max_frecuencia = 0;
    for (int i = 0; i < 100; i++) {
        if (frecuencia[i] > max_frecuencia) {
            max_frecuencia = frecuencia[i];
            aux = i;
        }
    }

    return aux;
}