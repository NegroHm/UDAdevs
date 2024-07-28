
//Tipos de Datos abstractos
#include <iostream>
#include <cstring>

using namespace std;
struct FECHA{
    int dd,mm,aa;
};

struct ALUMNO{//Tipo de dato abstracto Alumno
        //campos miembros de la estructura
        char apellido[30];//campo apellido es tipo cadena
        float notas[5]; // campo notas es un arreglo de reales
        long dni;// campo dni es un entero
        char sexopersona;//m o f
        //struct FECHA fnacimiento;      
};

void cargardatos(int n, struct ALUMNO v[]);
void listaralumnos(int n, struct ALUMNO v[]);
void listar(int n, struct ALUMNO v[], char x);
void burbujaordenar(int n,struct ALUMNO v[]);
void notapromediodelosalumnos(int n, struct ALUMNO v[]);

//ALUMNO P;//eRROR conceptual

main(){
       int z;
       float j;
       
       struct ALUMNO x;// variable x de tipo ALUMNO
       struct ALUMNO curso[20];//arreglo curso de tipo Alumno
       int opcion,cantalum;
       char califsexo;
       char op;
//   proced(curso)
   
       
do{
        cout<<"1) Cargar"<<endl;
        cout<<"2) Listar"<<endl;
        cout<<"3) Listar por sexo"<<endl;
        cout<<"4) Ordenar por apellido"<<endl;
        cout<<"5) Nota Promedio de los alumnos"<<endl;
        cout<<"6) Salir";
        
        cin>>opcion;
       //op=getche();
    switch(opcion){
                    case 1:       
       
       
                        cout<<"Ingrese la cantidad de alumnos";
                        cin>>cantalum;
                        cargardatos(cantalum,curso);
                        break;
                    case 2:    
                        listaralumnos(cantalum,curso);
                        system("pause");
                        break;
                        case 3:
                            cout<<endl<<"Ingrese m o f para masculino o femenino";
                            cin>>califsexo; 
                            listar(cantalum,curso,califsexo);
                            break;

                    case 4:burbujaordenar(cantalum,curso);
                        break;
                                       //system("pause");
                    case 5:
                            notapromediodelosalumnos(cantalum, curso);
                            break;      
                    }
       
       }while(opcion!=6); 
       
       system("pause");
}//fin programa principal

////////
 void burbujaordenar(int n,struct ALUMNO v[]){
     
     bool ordenado;
     int i,aux;
     struct ALUMNO auxiliar;
     
     //"auto"<"casas"
     //"pato"> "palo"
   
     do{
        ordenado=true;
        for(i=0; i<(n-1);i++)//realizar una pasada intercambiando elementos adyacentes
        if(strcmp(v[i].apellido,v[i+1].apellido)>0)//intercambio de palabras
             //v[i].dni>v[i+1].dni
            {
                        auxiliar=v[i];
                        v[i]=v[i+1];
                        v[i+1]=auxiliar;
                        ordenado=false; //pongo en false porque hice algun intercambio
                        }
        }while(!ordenado);
}      
      
void cargardatos(int n, struct ALUMNO v[]){
     
     int i,j;
     for(i=0;i<n;i++)//apunta a cada alumno
       {
        cout<<"Ingrese el apellido";
        cin>>v[i].apellido;
        cout<<"Ingrese el dni del alumno";
        cin >>v[i].dni;
        cout<<"Ingrese m para masculino o f para femenino";
        cin>>v[i].sexopersona;
       
       //v[i].fnacimiento.aa
       
       
       cout<<"ingrese las 5 notas del alumno";
       
       for(j=0;j<5;j++)
        do{
            cin>>v[i].notas[j];
        }while(v[i].notas[j]<1||v[i].notas[j]>10);
    }
}           

void listaralumnos(int n, struct ALUMNO v[]){

    int i,j;
     for(i=0;i<n;i++)
       {
       cout<<"apellido"<<v[i].apellido<<endl;
       cout<<"El dni del alumno"<<v[i].dni<<endl;
       if (v[i].sexopersona=='m')
          cout<<"Es varon"<<endl;
       else
           cout<<"Es mujer"<<endl;
       cout<<"Las notas del alumno son"<<endl;
       for(j=0;j<5;j++)
           cout<<v[i].notas[j]<<endl;
       }
}           
          
void listar(int n, struct ALUMNO v[], char x){
     
     int i,j;
     for(i=0;i<n;i++)
       {
       if (v[i].sexopersona==x)
       {
                                              
       cout<<"apellido"<<v[i].apellido<<endl;
       cout<<"El dni del alumno"<<v[i].dni<<endl;
       if (v[i].sexopersona=='m')
          cout<<"Es varon"<<endl;
       else
           cout<<"Es mujer"<<endl;
       cout<<"Las notas del alumno son"<<endl;
       for(j=0;j<5;j++)
           cout<<v[i].notas[j]<<endl;
           }
       }
}           
   void notapromediodelosalumnos(int n, struct ALUMNO v[]){
     
     int i,j;
     float prom,suma;
     
     for(i=0;i<n;i++)
       {
                suma=0;
                for(j=0;j<5;j++)
                            suma=suma+v[i].notas[j];
                prom=suma/5.0;                   
       }             
       cout<<"apellido"<<v[i].apellido<<endl;
       cout<<"El dni del alumno"<<v[i].dni<<endl;
       cout<<"El promedio es"<<prom<<endl;
       
}             
       
       