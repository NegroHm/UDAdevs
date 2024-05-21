//es la tercera vez que lo hago la concha de la lora 

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std; 

void generateNumber(int number, int vector[]);
void comparar(int posterior[], int anterior[], int auxiliar[]); 
void mostrar(int number, int vector[]);

int main()
{
    int vector1[6], vector2[6], vector3[6];
    srand (time(NULL));

    generateNumber(6, vector1);
    generateNumber(6, vector2);
    comparar(vector1, vector2, vector3);
    cout<<"Primero: ";
    mostrar (6, vector1);
    cout << endl;
    cout<<"Segundo: " ;
    mostrar (6, vector2);
    cout << endl;
    cout << "Mayor:  " ;
    mostrar (6, vector3);


    return 0;
}


void generateNumber(int number, int vector[]){
    for (int i = 0; i < number; i++)
    {
        vector[i] = rand()%10; 
    }
}

void comparar(int posterior[], int anterior[], int auxiliar[]){
    for (int i = 0; i<6; i++)
    {
        if ( posterior[i]>anterior[i])
        {
            auxiliar[i] = posterior[i];
        } else {
            auxiliar[i] = anterior[i];
        }   
    }
}

void mostrar(int number, int vector[]){
    for (int i=0; i<number; i++){
        cout<<vector[i]<<" ";
    }
}