#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

int main(){
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
   
    
        for(int i=0; i<number; i++){
            vector1[i] = -3 + rand()/(5.5- (3.5));
            cout << " * " << vector1[i] << " * " << " De -10 a 10 " << endl;
        };
    
    return 0;
};