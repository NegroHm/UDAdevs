// 3. Determinar cuál es el número que más se repite en un array de 100 elementos.

#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <map>      // Para map

using namespace std;

int main() {
    const int SIZE = 100;
    int arr[SIZE];
    map<int, int> frequency;

    // Inicializar la semilla para los números aleatorios
    srand(time(0));

    // Llenar el arreglo con números aleatorios entre 1 y 50
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 50 + 1;
    }

    // Calcular la frecuencia de cada número
    for (int i = 0; i < SIZE; i++) {
        frequency[arr[i]]++;
    }

    // Encontrar el número que más se repite
    int maxFreq = 0, mostFrequentNumber = arr[0];
    for (auto& pair : frequency) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFrequentNumber = pair.first;
        }
    }

    cout << "El número que más se repite es: " << mostFrequentNumber << " con una frecuencia de " << maxFreq << endl;

    return 0;
}
