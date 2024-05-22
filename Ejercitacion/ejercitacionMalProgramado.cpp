#include <iostream>
#include <string.h>

using namespace std;

	int main(){
	int rep;
	string palabra;
	int longitud;
	int x;
	bool estado = true;

	do{		
		cout << "Ingrese una palabra: ";
		cin >> palabra;
		longitud = palabra.length();

		for(int i = 0; i < longitud; i++){
			x = longitud - i;
			if(palabra[i] == palabra[x-1]){
				estado = true;
			} else if(palabra[i] != palabra[x-1]){
				estado = false;
			}
		}
	
	if(estado = true){
		cout << "Palabara palindroma" << endl;
	} else if(estado == false){
		cout << "Palabra no palindroma" << endl;
	}

	cout << "¿Desea con continuar?: ";
	cout << "1 Para reiniciar" << endl << "2 para salir " << endl;
	cin  >> rep;


	}while(rep = 1);

    return 0;


}
