#include <iostream>
#include <conio.h>
#include <cstring> 

using namespace std;

struct Medico{
    int id;
    char nombreApellido[20];
    int dni;
};

struct donante{
    char nombre[20]; 
    int dni;
    int numeroTel;
    int sangre[6];
    Medico medicoCabecera;    
};


int main()
{
    donante donante1; 

    strcpy(donante1.nombre, "Negro");
    donante1.dni = 46433333;
    donante1.numeroTel = 2610122202;
    donante1.sangre[6]  = 3;
    

    donante1.medicoCabecera.id = 01; 
    donante1.medicoCabecera.dni = 46221234; 
    strcpy(donante1.medicoCabecera.nombreApellido, "Doc.Negro");
    
    cout << "DNI: " << donante1.dni << endl; 
    cout << "Nombre: " << donante1.nombre << endl; 
    cout << "Numero de telefono: " << donante1.numeroTel << endl; 
    cout << "Sangre: " << donante1.sangre[6] << endl;
    
    cout << "MEDICO DE CABECERA " << endl;
    cout << "ID: " << donante1.medicoCabecera.id << endl; 
    cout << "Nombre: " << donante1.medicoCabecera.nombreApellido << endl;
    cout << "DNI: " << donante1.medicoCabecera.dni << endl; 

    return 0;
};
