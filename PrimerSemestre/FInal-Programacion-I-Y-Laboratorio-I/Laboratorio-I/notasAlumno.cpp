#include <iostream>
#include <stdlib.h>

using namespace std;

struct NotasAlum{   
    int id; //ID 
    char sex; //Sexo
    int nota; // Notas
    double notas[3]; //Notas
    bool approve; //Aprobado
};

void AlumnoID(NotasAlum alumno[5], int tamanio);
void AlumnoSex(NotasAlum alumno[5], int tamanio);
void AlumnoNotas(NotasAlum alumno[5], int tamanio);
void AlumnoApprove(NotasAlum alumno[5], int tamanio);

int main(){
    
    const int tamanio = 5;
    struct NotasAlum alumno[tamanio];

    AlumnoID(alumno , tamanio);
    AlumnoSex(alumno , tamanio);
    AlumnoNotas(alumno , tamanio);
    AlumnoApprove(alumno , tamanio);

    return 0;
}
//Ingresa el ID del alumno
void AlumnoID(NotasAlum alumno[5], int tamanio){
    for (int i = 0; i < tamanio; i++){
        cout << "Ingrese el ID del alumno N-" << (i + 1) << endl;
        cin >> alumno[i].id;
    }
}

//Ingresa el sexo del alumno
void AlumnoSex(NotasAlum alumno[5], int tamanio){
    cout << "Ingrese el sexo de la personas (M o F)" << endl;
    for (int i = 0; i < tamanio; i++){
        cout << "Sexo del alumno N-" << i+1 << endl;
        do
        {
            cin >> alumno[i].sex;
        } while (!(alumno[i].sex == 'f' || alumno[i].sex == 'm'));   
    }
} 

//Ingresa las notas del alumno
void AlumnoNotas(NotasAlum alumno[5], int tamanio){
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Ingrese la nota del alumno N-" << i+1 << endl;
        for (int j = 0; j < 3; j++){
            cin >> alumno[i].notas[j];
        }
    }
}

//Aca se realiza la evaluacion si el alumno esta aprobado
void AlumnoApprove(NotasAlum alumno[5], int tamanio){
    double promedio[5]={0},promedioTotal[5]={0};
    for (int i = 0; i < tamanio; i++){
        alumno[i].approve=false;
        for (int j = 0; j < 3; j++){
            promedio[i]+=alumno[i].notas[j];
        }
        promedioTotal[i]=promedio[i]/3;
        if (promedioTotal[i]>6){
            alumno[i].approve=true;
        }if (alumno[i].approve==true){
            cout << "El alumno N-" << i+1 << " esta aprobado. Felicidades." << endl;
        } else {
            cout << "El alumno N-" << i+1 << " esta desaprobado. Buena suerte la proxima." << endl;
        }
        
        
    }
}
