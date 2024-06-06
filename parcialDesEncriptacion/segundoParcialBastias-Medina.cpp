#include <iostream> // Biblioteca estándar para operaciones de entrada/salida
#include <cstring>  // Biblioteca estándar para manejo de cadenas de caracteres

using namespace std;

// Declaración de funciones
void showMenu(int *opcion, bool matrizCargada); // Muestra el menú
void llenarMatriz(char matrix[4][20]); // Función para llenar la matriz con palabras ingresadas por el usuario
void deslazarUno(char matrix[4][20], char matriz[4][20]); // Función para desplazar caracteres en una matriz según el código ASCII
void desplazarPar(char matrix[4][20], char matriz[4][20]); // Función para desplazar caracteres en posiciones pares de una matriz

int main()
{
    // Declaración de matrices para la palabra encriptada y desencriptada
    char encriptedWord[4][20];
    char desEncriptedWord[4][20];
    int userOption;
    bool matrizCargada = false;

    do
    {
        showMenu(&userOption, matrizCargada);
        switch (userOption)
        {
        case 1:
            // Llenar matriz
            llenarMatriz(encriptedWord);
            matrizCargada = true;
            break;
        case 2:
            // Desencriptar con movimiento en -1
            if (matrizCargada)
                deslazarUno(encriptedWord, desEncriptedWord);
            else
                cout << "Primero debes cargar la matriz." << endl;
            break;
        case 3:
            // Desencriptar en posición par -1
            if (matrizCargada)
                desplazarPar(encriptedWord, desEncriptedWord);
            else
                cout << "Primero debes cargar la matriz." << endl;
            break;
        case 4:
            // Desencriptar con ambas técnicas y mostrar el resultado
            if (matrizCargada)
            {
                deslazarUno(encriptedWord, desEncriptedWord);
                desplazarPar(desEncriptedWord, desEncriptedWord);
            }
            else
                cout << "Primero debes cargar la matriz." << endl;
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

void showMenu(int *opcion, bool matrizCargada)
{
    do
    {   
        // Esto es para que no pueda seleccionar ninguna de las otras opciones sin antes cargar la matriz

        cout << "Ingrese una de las siguientes opciones para desencriptar su palabra: " << endl;
        cout << "1 _ Cargar Matriz 4x20 (4 palabras de 20 caracteres máximo)" << endl;
        if (matrizCargada)
        {
            cout << "2 _ Paso -1" << endl;
            cout << "3 _ Cuando la posición de la letra es par, el paso es -1." << endl;
            cout << "4 _ Con ambas técnicas." << endl;
        }
        cout << "5 _ Salir del programa" << endl;
        cin >> *opcion;

        if (!matrizCargada && (*opcion == 2 || *opcion == 3 || *opcion == 4))
        {
            cout << "Primero debes cargar la matriz (opción 1)." << endl; // Si no esta cargada muestra este mensaje
            *opcion = 0; // Si no esta cargada vuelve el loop a 0
        }

    } while (*opcion < 1 || *opcion > 5);
}

void llenarMatriz(char matrix[4][20])
{
    // Función para llenar la matriz con el mensaje encriptado
    bool palabraValida;

    for (int i = 0; i < 4; ++i)
    {
        do
        {
            palabraValida = true;
            cout << "Ingrese la palabra " << i + 1 << ": ";
            cin >> matrix[i];

            for (int j = 0; j < strlen(matrix[i]); j++) // Con esto averiguo si hay algun numero u otro caracter
            {
                cout << "caracter: " << matrix[i][j] << " " << int(matrix[i][j]) << endl;
                if (matrix[i][j] < 97 || matrix[i][j] > 122)
                {
                    cout << "caracter malo" << endl;
                    palabraValida = false;
                }
            }
        } while (!palabraValida);
    }

    // Mostrar las palabras ingresadas
    cout << "Palabras ingresadas:" << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << matrix[i] << endl;
    }
}

void deslazarUno(char matrix[4][20], char matriz[4][20])
{
    // Función para retroceder un carácter según el código ASCII
    for (int i = 0; i < 4; ++i)
    {
        int len = strlen(matrix[i]);
        for (int j = 0; j < len; ++j)
        {
            matriz[i][j] = matrix[i][j] - 1; // Mover un carácter hacia atrás
            if (matriz[i][j] < 'a') // Si se pasa de la 'a', volver a la 'z'
                matriz[i][j] = 'z' - ('a' - matriz[i][j] - 1);
        }
        matriz[i][len] = '\0'; // Agregar carácter nulo al final de la palabra
    }

    // Mostrar la matriz desencriptada
    cout << "Palabras desencriptadas con paso -1:" << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << matriz[i] << endl;
    }
}

void desplazarPar(char matrix[4][20], char matriz[4][20])
{
    // Función para desplazar caracteres en posiciones pares de la matriz
    for (int i = 0; i < 4; ++i)
    {
        int len = strlen(matrix[i]);
        for (int j = 0; j < len; ++j)
        {
            if ((j + 1) % 2 == 0)
            { // Verificar si la posición es par
                matriz[i][j] = matrix[i][j] - 1; // Retroceder un carácter adicional
                if (matriz[i][j] < 'a') // Si se pasa de la 'a', volver a la 'z'
                    matriz[i][j] = 'z' - ('a' - matriz[i][j] - 1);
            }
            else
            {
                matriz[i][j] = matrix[i][j]; // Mantener el carácter sin cambios
            }
        }
        matriz[i][len] = '\0'; // Agregar carácter nulo al final de la palabra
    }

    // Mostrar la matriz desencriptada
    cout << "Palabras desencriptadas con desplazamiento en posiciones pares:" << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << matriz[i] << endl;
    }
}