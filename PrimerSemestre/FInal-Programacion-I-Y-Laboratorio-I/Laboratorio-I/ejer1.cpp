#include <iostream>
#include <stdlib.h>

using namespace std;

struct Talumno{
int id;     //numero unico
char sex;       //m o f
double marks[3];   //notas
bool approve;   //f si desaprobo v si aprobo
};

void IngresarId(Talumno Alumno[5], int Tamanio);
void IngresarSex(Talumno Alumno[5], int Tamanio);
void IngresarMarks(Talumno Alumno[5], int Tamanio);
void IngresarApprove(Talumno Alumno[5], int Tamanio);

int main(){
    
const int tamanio=5;
struct Talumno alumno[tamanio];

IngresarId(alumno , tamanio);
IngresarSex(alumno , tamanio);
IngresarMarks(alumno , tamanio);
IngresarApprove(alumno , tamanio);
}

void IngresarId(Talumno Alumno[5], int Tamanio){
    cout<<"Ingrese el id del alumno"<<endl;
   
    for(int i=0;i<Tamanio;i++){
        cout<<"id alumno: "<<i+1<<endl;
        cin>>Alumno[i].id;
    }
}

void IngresarSex(Talumno Alumno[5], int Tamanio){

cout<<"Ingrese el sexo de la persona (M o F)";
     for(int i=0;i<Tamanio;i++){
        cout<<"Sexo del alumno "<<i+1<<endl;
             do{
            cin>>Alumno[i].sex;
            }while(!(Alumno[i].sex =='f'||Alumno[i].sex =='m'));
    }
}

void IngresarMarks(Talumno Alumno[5], int Tamanio){
cout<<"Ingrese las notas de los alumnos: " << endl;

for (int i=0;i<Tamanio;i++){
    cout<<"alumno "<<i+1<<endl;
    for(int j=0;j<3;j++){
        cin>>Alumno[i].marks[j];
   
    }
}
}
void IngresarApprove(Talumno Alumno[5], int Tamanio){
double promedio[5]={0},promedioTotal[5]={0};

for (int i=0;i<Tamanio;i++){
    Alumno[i].approve=false;
         for(int j=0;j<3;j++){
          promedio[i]+=Alumno[i].marks[j];   
        }
            promedioTotal[i]=promedio[i]/3;
                    if(promedioTotal[i]>6){
                        Alumno[i].approve=true;
                    }
                    if(Alumno[i].approve==true){
                        cout<<"El alumno: "<<i+1<<"esta aprobado"<<endl;
                    }else{
                        cout<<"El alumno: "<<i+1<<"esta desaprobado"<<endl;
                    }
}
}