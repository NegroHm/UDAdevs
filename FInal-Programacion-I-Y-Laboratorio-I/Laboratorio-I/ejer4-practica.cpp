//! Ejercicio 4:
// Desarrolle una estructura que guarde los datos de los n alumnos de la materia programación en
// Lenguaje C, y los muestres por pantalla, la estructura debe tener (legajo, nombre, apellido, edad,
// profesión, lugar de nacimiento, dirección y teléfono).
// Una vez finalizada la carga, por medio de un menú permitirme buscar a un determinado alumno y poder
// ver sus datos.
#include <iostream>


using namespace std; 

struct direAlumnos{
    char ubiNacimiento[20];
    int direccion;
};

struct Talumnos{
    int legajo;
    char nombre[20];
    char apellido[20];
    int edad;
    char profesion[20];
    int telefono;

    direAlumnos direccionAlumnos;
};


void subidaDeDatos(Talumnos alum[], int tamanioA);
void mostrarDatos(Talumnos alum[], int tamanioA);

int main(){
    int tamanioA;
    
    cout << "Ingrese la cantidad de alumnos que desea ingresar: " << endl; 
    cin >> tamanioA;

    Talumnos alum[tamanioA]; 


    cin.ignore();// Limpiar el buffer

    subidaDeDatos(alum, tamanioA);
    cin.ignore();// Limpiar el buffer

    mostrarDatos(alum, tamanioA);

    return 0;
}


void subidaDeDatos(Talumnos alum[], int tamanioA){   
    for (int i = 0; i < tamanioA; i++){
        cout << "Ingrese el legajo del alumno N- " << i+1 << ": " << endl; 
        cin >> alum[i].legajo;
        
        cin.ignore();// Limpiar el buffer
        cout << "Ingrese el nombre del alumno N- (char)" << i+1 << ": " << endl;
        cin.getline(alum[i].nombre, 20);

        cout << "Ingrese el apellido del alumno N- (char)" << i+1 << ": " << endl; 
        cin.getline(alum[i].apellido,20);

        cout << "Ingrese la edad del alumno N- " << i+1 << ": " << endl; 
        cin >> alum[i].edad;
//        cin.ignore();// Limpiar el buffer

        cout << "Ingrese la profesion del alumno N- (char) " << i+1 << ": " << endl; 
        cin.getline(alum[i].profesion,20);

        cout << "Ingrese ubicaciion del alumno N- (char)" << i+1 << ": " << endl; 
        cin.getline(alum[i].direccionAlumnos.ubiNacimiento,20);

//        cin.ignore();// Limpiar el buffer
        cout << "Ingrese la direcciond el alumno N- (char)" << i+1 << ": " << endl; 
        cin >> alum[i].direccionAlumnos.direccion;
//        cin.ignore();// Limpiar el buffer

        cout << "Ingrese el numero de telefono del alumno N- " << i+1 << ": " << endl; 
        cin >> alum[i].telefono; 
//        cin.ignore();// Limpiar el buffer
    }
}

void mostrarDatos(Talumnos alum[], int tamanioA){
    for (int i = 0; i < tamanioA; i++){
        cout << "Datos de " << alum[i].nombre << " " <<  alum[i].apellido << endl; 
        cout << "Legajo del alumno N- " << i+1 << alum[i].legajo << endl;
        cout << "Nombre " << alum[i].nombre << " y el apellido " << alum[i].apellido << " del alumno " << i+1 << endl; 
        cout << "Edad del alumno N- "<< i+1 << ": " << alum[i].edad << endl;  
        cout << "Numero de telefono: " << alum[i].telefono << endl; 
        cout << "Ubicacion " << alum[i].direccionAlumnos.ubiNacimiento << " y su direccion es: " << alum[i].direccionAlumnos.direccion << endl;

    }
    
}