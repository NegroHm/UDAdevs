#include <iostream>

using namespace std;

void cargarArreglo(int arreglo[], int tamanio);
void promedioArreglo(int arreglo[], int tamanio);
void mostrarMasChioc(int arreglo[], int tamanio);
void mostrarMasGrande(int arreglo[], int tamanio);
void numIguales(int arreglo[], int tamanio);

int main()
{
    int tamanio = 10;
    int array[tamanio];

    cargarArreglo(array, tamanio);
    promedioArreglo(array, tamanio);
    mostrarMasChioc(array, tamanio);
    mostrarMasGrande(array, tamanio);
    numIguales(array, tamanio);

    return 0;
}

void cargarArreglo(int arreglo[], int tamanio){
    
    for (int i = 0; i < tamanio; i++){
        cout << "Ingrese el numero en la posicion " << i+1 << " : " << endl; 
        cin >> arreglo[i];
    }

}

void promedioArreglo(int arreglo[], int tamanio){
    int suma = 0; 
    for (int i = 0; i < tamanio; i++){
        suma += arreglo[i];
    }
    float promedio = suma / tamanio; 
    cout << "Este es el promedio: " << promedio << endl; 
}

void mostrarMasChioc(int arreglo[], int tamanio){
    int i;
    int aux;
    int masChico;

        for (int i = 0; i < tamanio; i++)
        {
            if (masChico > arreglo[i]){
                masChico = arreglo[i];
                aux = i+1; 
            }   
        }
    cout << "Mas chico " << masChico << " posicion " << i+1 << endl;
    }

void mostrarMasGrande(int arreglo[], int tamanio){
    int aux;
    int masGrande = arreglo[0];

        for (int i = 0; i < tamanio; i++)
        {
            if (masGrande < arreglo[i]){
                masGrande = arreglo[i];
                aux = i+1; 
            };    
        };
        cout << "Mas grande " << masGrande << " posicion " << aux << endl;  
    }


void numIguales(int arreglo[], int tamanio){
    int igual[tamanio];
    bool igualEncontrado= false; 

    for (int i = 0; i < tamanio; i++){
    
        for (int j = i+1; j < (tamanio-1); j++)
        {
            if (arreglo[i] == arreglo[j])
            {
                cout << "Igual " << arreglo[i] << " en la posicion " << i+1 << " y en " << j+1 << endl;
                igualEncontrado = true;
            }
        }
    }
    if (!igualEncontrado){
        cout << "no se encontro numero igual " << endl; 
    }
}