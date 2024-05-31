#include <iostream>
#include <cstring>

using namespace  std; 

void llenarMatriz(char matrix[4][20]);
void deslazarUno(char matrix[4][20], char matriz[4][20]);
void desplazarPar(char matrix[4][20], char matriz[4][20]);

int main()
{
	
	char encriptedWord[4][20];
	char desEncriptedWord[4][20];
	
	llenarMatriz(encriptedWord);
	deslazarUno(encriptedWord, desEncriptedWord);
	

	for (int i = 0; i < 4; ++i)
	{
		cout<< desEncriptedWord[i]<< endl;
	}

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

    desplazarPar(matriz, matriz); // DESPLAZA EN POSICIONES PARES

    
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
}