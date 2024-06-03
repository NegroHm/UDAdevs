#include <iostream>
#include <cstring>

using namespace  std; 

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



    switch (userOption)
    {
    case 1:
        //LLenar matriz
        llenarMatriz(encriptedWord);
        break;
    case 2:
        //Encriptar con movimiento en -1
        deslazarUno(encriptedWord, desEncriptedWord);
        break;
    case 3:
        //Encriptar en posicion par -1
        desplazarPar(encriptedWord, desEncriptedWord);
        break;
    case 4:
        //Encriptar con ambas tecnicas y mostrar el resultado
        deslazarUno(encriptedWord, desEncriptedWord);
        desplazarPar(encriptedWord, desEncriptedWord);
        break;
    default:
        break;
    }
	} while (userOption >= 5);
	
	

	// for (int i = 0; i < 4; ++i)
	// {
	// 	cout<< desEncriptedWord[i]<< endl;
	// }

	return 0;
}



void llenarMatriz(char matrix[4][20]){ //CON ESTE SUBPROGRAMA LLENO LA MATRIZ CON EL MENSAJE ENCRIPTADO

	for (int i = 0; i < 4; ++i)
	{
		cout << "Ingrese una palabra: ";
		cin >> matrix[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		cout<< matrix[i]<< endl;
	}


}

void deslazarUno(char matrix[4][20], char matriz[4][20]){ //CON ESTE RETROCEDO UNO, SEGUN EL CODIGO ASCII 

	 for (int i = 0; i < 4; ++i) {
        int len = strlen(matrix[i]);

        for (int j = 0; j < len; ++j) {

            matriz[i][j] = matrix[i][j] - 1; // MOVEMOS UNO PARA ATRAS

            if (matriz[i][j] < 'a') // SI SE PASA DE LA 'A' VUELVE A LA 'Z'

                matriz[i][j] = 'z' - ( 'a'- matriz[i][j] - 1);
        }
        matriz[i][len] = '\0'; // AGREGAMOS CARACTER NULO
    }
    //Mostrar palabra
    for (int i = 0; i < 4; ++i)
	{
		cout<< matriz[i]<< endl;
	}

}

void desplazarPar(char matrix[4][20], char matriz[4][20]) { //CON ESTE SI LA POSICION ES PAR AVANZA UNO MAS
    for (int i = 0; i < 4; ++i) {	
    	int len = strlen(matrix[i]);

        for (int j = 0; j < len; ++j) {

            if ((j + 1) % 2 == 0) { // AVERIGUA SI LA POSICION ES PAR O NO 

                matriz[i][j] = matrix[i][j] - 1; // SI ES PAR RETOCEDE UNO MAS

               if (matriz[i][j] < 'a') // SI SE PASA DE LA 'A' VUELVE A LA 'Z'
            	
                matriz[i][j] = 'z' - ( 'a'- matriz[i][j] - 1);
            }
        }
    }
    //Mostrar palabra
    for (int i = 0; i < 4; ++i)
	{
		cout<< matriz[i]<< endl;
	}
}