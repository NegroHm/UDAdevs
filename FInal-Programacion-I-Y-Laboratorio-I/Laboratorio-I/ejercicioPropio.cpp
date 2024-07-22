#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Cantidad de materias
//Pedir el nombre de la materia
// Nombre del profesor
// Cantidad de parciales
// Promedio de aprobacion
// Valor de cada una de las notas esto lo definimos segun la variable de cantidad de parciales

struct notasUda{
    int i = 0;
    char nombreMateria[20];
    int cantidadParciales;
    float notas[100];
    float  promedio;
    float valorNotas;
};

int main()
{

    notasUda materia1;  
    int cantidad; 
    int suma = 0; 

    cout << "Ingrese el nombre de la materia: " << endl; 
    cin >> materia1.nombreMateria;

    cout << "Ingrese la cantidad de parciales: " << endl; 
    cin >> materia1.cantidadParciales;

    for (int i = 0; i < materia1.cantidadParciales; i++)
    {
        cout << "Ingrese la nota " << (i+1) << " : ";
        cin >> materia1.notas[i];
    }
    
    for (int i = 0; i < materia1.cantidadParciales; i++){
        //materia1.promedioAprobacion = materia1.cantidadParciales / (materias1.notas[i] + )
        suma += materia1.notas[i];
    }   

    materia1.promedio = (suma / materia1.cantidadParciales);
    cout << "El promedio de las notas de los praciales es: " << materia1.promedio << " de la materia " << materia1.nombreMateria << endl;

    if (materia1.promedio < 6)
    {
        cout << "Usted no promociono la materia" << endl; 
    } else {
        cout << "Usted promociono la materia" << endl;
    }

    getch();
    return 0;
}