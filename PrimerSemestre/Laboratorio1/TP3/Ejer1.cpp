// 1 Ejercicio básico de arreglos
    // a. Crear un arreglo de 10 números.
    // b. Cargar con valores aleatorios.
    // c. Mostrar cada valor por pantalla junto a la posición que ocupa en el
    // arreglo.
    // d. Mostrar el promedio de los mismos.
    // e. Mostrar el número más alto y la posición que ocupa en el arreglo.
    // f. Mostrar el número más bajo y la posición que ocupa en el arreglo.

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void generateNum(int n, int vector[]);
void show(int n, int vector[]);
void average(int n, int vector[]);
void bigger(int n, int vector[]);
void smaller(int n, int vector[]);

int main()
{
    int vector[10];

    srand(time(NULL));

    generateNum(10, vector); // genera el array
    show(10, vector); // muestra el vector
    //average(10, vector); // los promedia
    cout << " " << endl;
    bigger(10, vector);
    average(10, vector); // los promedia
    smaller(10, vector);

    return 0;
}

void generateNum(int n, int vector[]){
    for(int i=0; i<n; i++){
        vector[i] = rand()%100;
    }
}

void show(int n, int vector[]){
    for(int i=0; i<n; i++){
        cout << vector[i] << " ";
        }
}

void average(int n, int vector[]){
    int sum = 0;
    int aver = 0; 
    for(int i = 0; i<n; i++){
        sum += vector[i];
    }
    aver = sum/n;
    cout << "Promedio: " << aver << endl;
}

void bigger(int n, int vector[]) {
    int max = vector[0]; // Supongamos que el primer elemento es el más grande
    int pos = 0; // Variable para almacenar la posición del número más grande
    
    for (int i = 1; i < n; i++) {
        if (vector[i] > max) { // Si encontramos un número más grande
            max = vector[i]; // Actualizamos el máximo
            pos = i; // Actualizamos la posición
        }
    }
    
    cout << "El numero mas grande es: " << max << " y se encuentra en la posicion: " << pos+1 << endl; 
}

void smaller(int n, int vector[]) {
    int max = vector[0]; // Supongamos que el primer elemento es el más grande
    int pos = 0; // Variable para almacenar la posición del número más grande
    
    for (int i = 1; i < n; i++) {
        if (vector[i] < max) { // Si encontramos un número más grande
            max = vector[i]; // Actualizamos el máximo
            pos = i; // Actualizamos la posición
        }
    }
    
    cout << "El numero mas chico es: " << max << " y se encuentra en la posicion: " << pos+1 << endl; 
}