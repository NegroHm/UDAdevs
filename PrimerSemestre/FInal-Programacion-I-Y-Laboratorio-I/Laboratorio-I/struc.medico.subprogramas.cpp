#include <iostream>
#include <conio.h>  
#include <cstring> 

using namespace std;

struct Medico{
    int id;
    char nombreApellido[20];
    int dni;
};

struct DONANTE{ 
    char nombre[20]; 
    int dni;
    int numeroTel;
    int sangre;
    struct Medico medicoCabecera;    
};

void donanteDatos(DONANTE donante[], int tamanio);
void mostrarDatos(DONANTE donante[], int tamanio);

int main()
{
    // donante donante1; 
    // strcpy(donante1.nombre, "Negro");
    // donante1.dni = 46433333;
    // donante1.numeroTel = 2610122202;
    // donante1.sangre[6]  = 3;
    // donante1.medicoCabecera.id = 01; 
    // donante1.medicoCabecera.dni = 46221234; 
    // strcpy(donante1.medicoCabecera.nombreApellido, "Doc.Negro");
    // cout << "DNI: " << donante1.dni << endl; 
    // cout << "Nombre: " << donante1.nombre << endl; 
    // cout << "Numero de telefono: " << donante1.numeroTel << endl; 
    // cout << "Sangre: " << donante1.sangre[6] << endl;
    // cout << "MEDICO DE CABECERA " << endl;
    // cout << "ID: " << donante1.medicoCabecera.id << endl; 
    // cout << "Nombre: " << donante1.medicoCabecera.nombreApellido << endl;
    // cout << "DNI: " << donante1.medicoCabecera.dni << endl; 
    int tamanio;
    

    cout << "Ingrese la cantidad de donantes: "; cin >> tamanio;
    DONANTE donante[tamanio];
    cin.ignore();
    donanteDatos(donante, tamanio); 
    mostrarDatos(donante, tamanio); 
    

    return 0;
};


//Ingresar datos de donante
void donanteDatos(DONANTE donante[], int tamanio){

    for (int i = 0; i < tamanio; i++){
    
    cout << "DNI: "; 
    cin >> donante[i].dni;
    cin.ignore();//vaciar buffer 
    cout << "Nombre:  ";
    cin.getline(donante[i].nombre,20);
    cout << "Telefono: ";
    cin >> donante[i].numeroTel;
    cout << "Sangre: "; 
    cin >> donante[i].sangre;
    cin.ignore(); //vaciar buffer
    cout << "Ingrese el ID del medico: ";   
    cin >> donante[i].medicoCabecera.id;
    cout << "Ingrese el DNI del medico: ";
    cin >> donante[i].medicoCabecera.dni;
    cin.ignore(); //vaciar buffer
    cout << "Ingrese el nombre: ";
    cin.getline(donante[i].medicoCabecera.nombreApellido,20);
    };   
}

void mostrarDatos(DONANTE donante[], int tamanio){
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Datos del donante: " << donante[i].nombre << endl; 
    cout << "Nombre donante: " << donante[i].nombre << endl;
    cout << "DNI del donante: " << donante[i].dni << endl;
    cout << "Numero de telefono: " << donante[i].numeroTel << endl; 
    cout << "Sangre: " << donante[i].sangre << endl; 


        cout << "\n Datos del medico de cabecera \n" << donante[i].medicoCabecera.nombreApellido << endl;
    cout << "ID: " << donante[i].medicoCabecera.id << endl; 
    cout << "DNI: " << donante[i].medicoCabecera.dni << endl; 
    cout << "Nombre: " << donante[i].medicoCabecera.nombreApellido << endl;
    }
}