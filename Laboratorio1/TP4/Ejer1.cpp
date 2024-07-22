// 1.	Realizar una calculadora que realice suma, resta, multiplicación y 
//división. Cada cálculo se debe realizar en funciones pasando los números por valor.
#include <iostream>

using namespace std;

// Función para sumar dos números
double suma(double a, double b) {
    return a + b;
}

// Función para restar dos números
double resta(double a, double b) {
    return a - b;
}

// Función para multiplicar dos números
double multiplicacion(double a, double b) {
    return a * b;
}

// Función para dividir dos números
double division(double a, double b) {
    if (b == 0) {
        cout << "Error: División por cero." << endl;
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2;
    char operacion;

    cout << "Ingrese dos números: ";
    cin >> num1 >> num2;
    cout << "Ingrese la operación (+, -, *, /): ";
    cin >> operacion;

    switch (operacion) {
        case '+':
            cout << "Resultado: " << suma(num1, num2) << endl;
            break;
        case '-':
            cout << "Resultado: " << resta(num1, num2) << endl;
            break;
        case '*':
            cout << "Resultado: " << multiplicacion(num1, num2) << endl;
            break;
        case '/':
            cout << "Resultado: " << division(num1, num2) << endl;
            break;
        default:
            cout << "Operación no válida." << endl;
            break;
    }

    return 0;
}
