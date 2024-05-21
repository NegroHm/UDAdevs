#include <iostream>
#include <string.h>

using namespace std;

void invertirPalabra(string palabraIngresada, string& palabraInvertida);
void verificarPalabrapalindroma(string palabraIngresada, string& palabraInvertida);

int main () {

        
    string palabraIngresada, palabraInvertida;


    cout << "Ingrse una palabra: ";
    cin >> palabraIngresada;

    invertirPalabra(palabraIngresada, palabraInvertida);
    verificarPalabrapalindroma(palabraIngresada, palabraInvertida);

    return 0;

}

void invertirPalabra(string palabraIngresada, string& palabraInvertida){


    for (int i = palabraIngresada.size() -1 ; i>= 0;--i)
    {
        palabraInvertida += palabraIngresada[i];
    }

    cout << "\nLa palabra invertida queda de la siguiente forma: " << palabraInvertida;

}

void verificarPalabrapalindroma(string palabraIngresada, string& palabraInvertida){


    if (palabraIngresada == palabraInvertida)
    {
        cout << "\nLa palabra ingresada es palindroma.";
    } else{

        cout << "\nLa palabra ingresada no es palindroma.";
    }

}