//Practicar lo que es pasar por valor y referencia (&)
#include <iostream>

using namespace std;

// Función que duplica el valor de un parámetro pasado por VALOR
void doblarValor(int valor) {
    valor = valor * 2;
    cout << "Dentro de doblarValor, valor es: " << valor << endl;
}

// Función que duplica el valor de un parámetro pasado por REFERNCIA
void doblarReferencia(int &valor) {
    valor = valor * 2;
    cout << "Dentro de doblarReferencia, valor es: " << valor << endl;
}

int main() {
    int numero1 = 5;
    int numero2 = 5;
    
    cout << "Antes de llamar a doblarValor, numero1 es: " << numero1 << endl;

        doblarValor(numero1);

    cout << "Despues de llamar a doblarValor, numero1 es: " << numero1 << endl;
    
        doblarValor(numero1);

    cout << "-----------------" << endl; 

    cout << "Antes de llamar a doblarReferencia, numero2 es: " << numero2 << endl;

        doblarReferencia(numero2);

    cout << "Despues de llamar a doblarReferencia, numero2 es: " << numero2 << endl;

        doblarReferencia(numero2);

    return 0;
}
