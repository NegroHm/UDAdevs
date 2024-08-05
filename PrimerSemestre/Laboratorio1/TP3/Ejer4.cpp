//4. Determinar si una cadena de texto es palíndromo. Es decir, que se lee igual de
//derecha a izquierda, que de izquierda a derecha. Por ejemplo: “NEUQUEN”,
//“SOMOS”.
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void ingresarPalabra(char palabra);
void voltear(char palabra);

int main()
{
    char palabra; 
    ingresarPalabra( palabra);
    voltear(palabra);

    return 0;
}

//Ingrese la palabra
void ingresarPalabra(char palabra){
    cout<<"Ingrese la palabra: ";
    cin>>palabra;
}

//Volterar la palabra
void voltear(char palabra){
    int i=0; 
    for (int i= 0; i < palabra; i++)
    {
        for (int i = 0; i < palabra; i--)
        {
            cout << palabra << endl;
        }
        
    }
    
}

