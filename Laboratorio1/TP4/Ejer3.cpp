// 3.	Desarrolle una Función que devuelva el salario mensual de
// un trabajador si se tienen como datos el número de horas trabajadas, el precio
// de la hora y además se sabe que se le descuenta el 10% por concepto 
// de caja de ahorro. Pasar por valor las horas, el precio por hora y el descuento.

#include <iostream>

using namespace std;

// Función para calcular el salario mensual
double calcularSalarioMensual(int horasTrabajadas, double precioPorHora, double descuento) {
    double salarioBruto = horasTrabajadas * precioPorHora;
    double salarioNeto = salarioBruto - (salarioBruto * descuento / 100);
    return salarioNeto;
}

int main() {
    int horasTrabajadas;
    double precioPorHora;
    const double DESCUENTO = 10.0; // 10%

    cout << "Ingrese el número de horas trabajadas: ";
    cin >> horasTrabajadas;
    cout << "Ingrese el precio por hora: ";
    cin >> precioPorHora;

    double salarioMensual = calcularSalarioMensual(horasTrabajadas, precioPorHora, DESCUENTO);
    cout << "El salario mensual es: " << salarioMensual << endl;

    return 0;
}
