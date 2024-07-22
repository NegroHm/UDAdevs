// 6. Diseña una función lógica que dados dos vectores, devuelva true si son iguales y
// false en otro caso. Para este caso supondremos que dos vectores son iguales si
// contienen los mismos elementos y en el mismo orden relativo, suponiendo que
// el primer elemento sigue al último. Por ejemplo, si la entrada fuera:
// ['A', 'C', 'D', 'F', 'E']
// ['D', 'F', 'E', 'A', 'C']
// La función devolvería true.


#include <iostream>
#include <vector>

using namespace std;

bool sonIguales(vector<char> vec1, vector<char> vec2) {
    if (vec1.size() != vec2.size()) return false;

    int size = vec1.size();
    for (int i = 0; i < size; i++) {
        bool iguales = true;
        for (int j = 0; j < size; j++) {
            if (vec1[j] != vec2[(i + j) % size]) {
                iguales = false;
                break;
            }
        }
        if (iguales) return true;
    }
    return false;
}

int main() {
    vector<char> vec1 = {'A', 'C', 'D', 'F', 'E'};
    vector<char> vec2 = {'D', 'F', 'E', 'A', 'C'};

    if (sonIguales(vec1, vec2)) {
        cout << "Los vectores son iguales en orden cíclico." << endl;
    } else {
        cout << "Los vectores no son iguales en orden cíclico." << endl;
    }

    return 0;
}
