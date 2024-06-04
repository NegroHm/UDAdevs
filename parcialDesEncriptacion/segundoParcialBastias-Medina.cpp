#include <iostream> // Biblioteca estándar para operaciones de entrada/salida
#include <cstring>  // Biblioteca estándar para manejo de cadenas de caracteres

using namespace std;

// Declaración de funciones
void llenarMatriz(char matrix[4][20]); // Función para llenar la matriz con palabras ingresadas por el usuario
void deslazarUno(char matrix[4][20], char matriz[4][20]); // Función para desplazar caracteres en una matriz según el código ASCII
void desplazarPar(char matrix[4][20], char matriz[4][20]); // Función para desplazar caracteres en posiciones pares de una matriz

int main()
{
    // Declaración de matrices para la palabra encriptada y desencriptada
    char encriptedWord[4][20];
    char desEncriptedWord[4][20];
    int userOption;

    do
    {
        cout << "Ingrese una de las siguientes opciones para desencriptar su palabra: " << endl; 
        cout << "1 _ Cargar Matriz 4x20 (4 palabras de 20 caracteres maximo)" << endl;
        cout << "2 _ Paso -1" << endl;
        cout << "3 _ Cuando la posicion de la palabra es par, el paso es -1." << endl;
        cout << "4 _ Con ambas tecnicas." << endl;
        cout << "5 _ Salir del programa" << endl;
        cin >> userOption;

        //! Validar el ingleso de la matriz
        //! Validar que la matriz no este vacia
        //! Validar que la matriz no tenga numeros
        //! Validar el ingreso de las 


        switch (userOption)
        {
        case 1:
            // Llenar matriz
            llenarMatriz(encriptedWord);
            break;
        case 2:
            // Desencriptar con movimiento en -1
            deslazarUno(encriptedWord, desEncriptedWord);
            break;
        case 3:
            // Desencriptar en posicion par -1
            desplazarPar(encriptedWord, desEncriptedWord);
            break;
        case 4:
            // Desencriptar con ambas técnicas y mostrar el resultado
            deslazarUno(encriptedWord, desEncriptedWord);
            desplazarPar(desEncriptedWord, desEncriptedWord);
            break;
        case 5:
            // Salir del programa
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
            break;
        }

    } while (userOption != 5);

    return 0;
}

void llenarMatriz(char matrix[4][20]) { // Función para llenar la matriz con el mensaje encriptado
    for (int i = 0; i < 4; ++i) {
        cout << "Ingrese una palabra: ";
        cin >> matrix[i];
    }

    // Mostrar las palabras ingresadas
    cout << "Palabras ingresadas:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << matrix[i] << endl;
    }
}

void deslazarUno(char matrix[4][20], char matriz[4][20]) { // Función para retroceder un carácter según el código ASCII
    for (int i = 0; i < 4; ++i) {
        int len = strlen(matrix[i]);
        for (int j = 0; j < len; ++j) {
            matriz[i][j] = matrix[i][j] - 1; // Mover un carácter hacia atrás
            if (matriz[i][j] < 'a') // Si se pasa de la 'a', volver a la 'z'
                matriz[i][j] = 'z' - ('a' - matriz[i][j] - 1);
        }
        matriz[i][len] = '\0'; // Agregar carácter nulo al final de la palabra
    }

    // Mostrar la matriz desencriptada
    cout << "Palabras desencriptadas con paso -1:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << matriz[i] << endl;
    }
}

void desplazarPar(char matrix[4][20], char matriz[4][20]) { // Función para desplazar caracteres en posiciones pares de la matriz
    for (int i = 0; i < 4; ++i) {
        int len = strlen(matrix[i]);
        for (int j = 0; j < len; ++j) {
            if ((j + 1) % 2 == 0) { // Verificar si la posición es par
                matriz[i][j] = matrix[i][j] - 1; // Retroceder un carácter adicional
                if (matriz[i][j] < 'a') // Si se pasa de la 'a', volver a la 'z'
                    matriz[i][j] = 'z' - ('a' - matriz[i][j] - 1);
            } else {
                matriz[i][j] = matrix[i][j]; // Mantener el carácter sin cambios
            }
        }
        matriz[i][len] = '\0'; // Agregar carácter nulo al final de la palabra
    }

    // Mostrar la matriz desencriptada
    cout << "Palabras desencriptadas con desplazamiento en posiciones pares:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << matriz[i] << endl;
    }
}
