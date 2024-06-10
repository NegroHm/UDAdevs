//! librerias
#include <iostream> // Biblioteca estándar 
#include <cstring>  // Biblioteca usada para el manejo de strings
#include <limits> // Biblioteca usada para la validacion de ingreso en el menu

using namespace std;

//! Declaración de funciones
void showMenu(int *opcion, bool matrizCargada); // Muestra el menú
void llenarMatriz(char matrix[4][20]); // Función para llenar la matriz con palabras ingresadas por el usuario
void desplazarUno(char matrix[4][20], char matriz[4][20]); // Función para desplazar caracteres en una matriz según el código ASCII (paso -1)
void desplazarPar(char matrix[4][20], char matriz[4][20]); // Función para desplazar caracteres en posiciones pares de una matriz (paso -1)
void convertirMinusculas(char palabra[]);// Pasa todas las plabras ingresadas a minuscula, por si ingresa alguna mayuscula


//! MAIN

int main()
{
    // Declaración de matrices para la palabra encriptada y desencriptada
    char encriptedWord[4][20];
    char desEncriptedWord[4][20];
    //Declaracion para guardar la opcion del usuario
    int userOption;
    //Declaracion de variable para que no deje el usuario trabajar con una matriz vacia, por tema de errores
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
            // Desencriptar con movimiento en -1 y mostrar el resultado
            if (matrizCargada)
                desplazarUno(encriptedWord, desEncriptedWord);
            else
                cout << "Primero debes cargar la matriz." << endl;
            break;
        case 3:
            // Desencriptar en posición par -1 y mostrar el resultado
            if (matrizCargada)
                desplazarPar(encriptedWord, desEncriptedWord);
            else
                cout << "Primero debes cargar la matriz." << endl;
            break;
        case 4:
            // Desencriptar con ambas técnicas y mostrar el resultado
            if (matrizCargada)
            {
                desplazarUno(encriptedWord, desEncriptedWord);
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


//! Subprogramas

//* Mostrar el menu
void showMenu(int *opcion, bool matrizCargada)
{
    do
    {   
        cout << "Ingrese una de las siguientes opciones para desencriptar su palabra: " << endl;
        cout << "1 _ Cargar Matriz 4x20 (4 palabras de 20 caracteres máximo)" << endl;
        if (matrizCargada)
        {
            cout << "2 _ Paso -1" << endl;
            cout << "3 _ Cuando la posición de la letra es par, el paso es -1." << endl;
            cout << "4 _ Con ambas técnicas." << endl;
        }
        cout << "5 _ Salir del programa" << endl;

        // Leer la opción del usuario
        cin >> *opcion;

        // Validar si la entrada es un número entero
        if (cin.fail())
        {
            cout << "Entrada no válida. Por favor, ingrese un número." << endl;
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada no válida
            *opcion = 0; // Establecer una opción inválida para repetir el bucle
        }
        else if (!matrizCargada && (*opcion == 2 || *opcion == 3 || *opcion == 4))
        {
            cout << "Primero debes cargar la matriz (opción 1)." << endl;
            *opcion = 0; // Si no está cargada, vuelve el loop a 0 y no deja avanzar con el programa
        }

    } while (*opcion < 1 || *opcion > 5);
}


//* Minuculas
void convertirMinusculas(char palabra[]) {
    for (int i = 0; palabra[i] != '\0'; ++i) {
        //tolower es una funcion de <cctype> para pasar los caracteres ingresados a minusculas
        palabra[i] = tolower(palabra[i]);
    }
}


//* Llenar matriz
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

            if (strlen(matrix[i]) > 20) { // Esta corroboracion es por si ingresa una palabra de mas de 20 char
                cout << "Error!!";
                cout << "Ha ingresado una palabra de más de 20 caracteres" << endl;
                palabraValida=false;
            }
            
            convertirMinusculas(matrix[i]);

            for (int j = 0; j < strlen(matrix[i]); j++) // Con esto averiguo si hay algun numero u otro caracter
            {
                cout << "Caracter:" << matrix[i][j] << " " << int(matrix[i][j]) << endl; //Con esto muestra el codigo ASCII del carcater 
                if (matrix[i][j] < 97 || matrix[i][j] > 122) 
                { 
                    cout << '\n';
                    cout << "Caracter malo: " << matrix[i][j] << endl;
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


//* Desplazamiento en uno
void desplazarUno(char matrix[4][20], char matriz[4][20])
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

    
//* Desplazamiento par
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