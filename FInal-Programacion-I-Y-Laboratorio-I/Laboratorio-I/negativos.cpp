#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

int main()
{
    srand(time(NULL));
    int number = 4;
    int vector[4];
    float vector1[4];

    for(int i=0; i<number; i++){
        vector[i] = (rand()%21)-10;
        cout << " * " << vector[i] << " * " << " De -10 a 10 " << endl;
    };

    cout << "----------------" << endl;

// Segundo bucle: genera números flotantes aleatorios en el rango [-3.5, 5.5]
    for(int i = 0; i < number; i++) {
        // Genera un número aleatorio en el rango [0, 1)
        float randomValue = static_cast<float>(rand()) / RAND_MAX;
        // Escala y desplaza el número para que esté en el rango [-3.5, 5.5]
        // randomValue * 9.0 escala el valor a [0, 9); -3.5 desplaza el rango a [-3.5, 5.5]
        vector1[i] = -3.5 + randomValue * 9.0;
        cout << " * " << vector1[i] << " * " << " De -3.5 a 5.5 " << endl;
    };
    
    return 0;
};