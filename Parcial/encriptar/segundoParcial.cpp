#include <iostream>
#include <cstring>
using namespace std;

// Función para desplazamiento en uno hacia adelante
void desplazamientoUno(char &c) {
    c = (c - 'a' + 1) % 26 + 'a';
}

// Función para desplazamiento adicional en las posiciones pares
void desplazamientoAdicionalPares(char arr[], int size) {
    for (int i = 1; i < size; i += 2) {
        arr[i] = (arr[i] - 'a' + 1) % 26 + 'a';
    }
}

// Función para encriptar la palabra
void encriptarPalabra(char palabra[], char encriptada[]) {
    int size = strlen(palabra);

    // Desplazamiento en uno hacia adelante para todas las letras
    for (int i = 0; i < size; ++i) {
        encriptada[i] = palabra[i];
        desplazamientoUno(encriptada[i]);
    }

    // Desplazamiento adicional para las posiciones pares
    desplazamientoAdicionalPares(encriptada, size);
    encriptada[size] = '\0'; // Añadir el carácter nulo al final de la palabra encriptada
}

// Función para encriptar un conjunto de palabras
void encriptarPalabras(char palabras[][100], char encriptadas[][100], int numPalabras) {
    for (int i = 0; i < numPalabras; ++i) {
        encriptarPalabra(palabras[i], encriptadas[i]);
    }
}

int main() {
    const int MAX_LENGTH = 100;
    const int MAX_PALABRAS = 10;
    char palabras[MAX_PALABRAS][MAX_LENGTH];
    char encriptadas[MAX_PALABRAS][MAX_LENGTH];

    int numPalabras;
    cout << "Ingrese el número de palabras a encriptar: ";
    cin >> numPalabras;

    for (int i = 0; i < numPalabras; ++i) {
        cout << "Ingrese la palabra " << i + 1 << ": ";
        cin >> palabras[i];
    }

    encriptarPalabras(palabras, encriptadas, numPalabras);

    cout << "Palabras encriptadas:" << endl;
    for (int i = 0; i < numPalabras; ++i) {
        cout << encriptadas[i] << endl;
    }

    return 0;
}
