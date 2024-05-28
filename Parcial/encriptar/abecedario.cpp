#include <iostream>
using namespace std;

int main() {
    // Declarar una matriz 2x20 de caracteres
    char matriz[2][20];

    // Rellenar la matriz con las letras del alfabeto
    char letra = 'A'; // Inicializamos con la primera letra del alfabeto
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 20; j++) {
            if (letra <= 'Z') {
                matriz[i][j] = letra; // Asignar la letra actual a la matriz
                letra++; // Pasar a la siguiente letra del alfabeto
            } else {
                matriz[i][j] = ' '; // Si se terminan las letras del alfabeto, rellenar con espacios
            }
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 20; j++) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
