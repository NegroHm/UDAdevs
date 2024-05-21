#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void generateNumber(int n, int vector[]);
void mostrar(int n, int vector[]);
void suma(int n, int vectorA[], int vectorB[], int vectorC[]);

int main()
{
     int vectorA[10], vectorB[10], vectorC[10];
    srand(time(NULL));

    generateNumber(10, vectorA);
    mostrar(10, vectorA);

    generateNumber(10, vectorB);
    mostrar(10, vectorB);

    suma(10, vectorA, vectorB, vectorC);
    mostrar(10, vectorC);
    
    
    return 0;
}

void generateNumber(int n, int vector[]){

    for (int i = 0; i < n; i++)
    {
        vector[i] = rand()% 10;
    }   
}

void mostrar(int n, int vector[]) {
    for (int i = 0; i < n; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

void suma(int n, int vectorA[], int vectorB[], int vectorC[]){
    for (int i = 0; i < n; i++)
    {
        vectorC[i] = (vectorA[i] + vectorB[i]);  
    }
}
