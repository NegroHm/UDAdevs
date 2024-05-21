#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void llenarVectores(int n, int vector[]);
void compararVectores(int v[], int c[], int t[]);
void mostrarVector (int n, int vector[]);


int main (){

int vectorA[6], vectorB[6], vectorC[6];

srand (time(NULL));

llenarVectores(6,vectorA);
llenarVectores(6,vectorB);
compararVectores(vectorA, vectorB, vectorC);
cout<< "El vectorA tiene los siguientes valores: ";
mostrarVector (6, vectorA);
cout<< "\nEl vectorB tiene los siguientes valores: ";
mostrarVector (6, vectorB);
cout<< "\nEl vectorC tiene los siguientes valores: ";
mostrarVector (6, vectorC);

return 0;
}



void llenarVectores(int n,int vector[]){ //LLENO LOS VECTORES CON NUM ALEATORIOS

for (int i=0; i<n;i++){
vector[i] = rand()% 10;
}
}

void compararVectores(int v[], int c[], int t[]){ //COMPARO Y ENCUENTRO EN MAYOR DE CADA POSICION

for (int i=0; i<6;i++){

if (v[i]>c[i]){
t[i] = v[i];

}else{
t[i]= c[i];
}
}
}

void mostrarVector (int n, int vector[]){ //MUESTRO LOS VECTORES

for (int i = 0; i<n ; i++){
cout << vector[i] << ",";

}

}