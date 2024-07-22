// 5. Supongamos que tenemos dos cadenas de texto. Necesitamos un método que
// devuelva true si una cadena de texto está contenida dentro de otra. O sea, si
// tenemos un string “palanca”, y queremos saber si la cadena “pala” está
// contenida dentro de “palanca”, el método devolverá true, en caso contrario
// devolverá false.
#include <iostream>
#include <string>

using namespace std;

bool contieneCadena(string texto, string subtexto) {
    return texto.find(subtexto) != string::npos;
}

int main() {
    string texto, subtexto;
    cout << "Ingrese la cadena principal: ";
    getline(cin, texto);
    cout << "Ingrese la cadena a buscar: ";
    getline(cin, subtexto);

    if (contieneCadena(texto, subtexto)) {
        cout << "La cadena \"" << subtexto << "\" está contenida en \"" << texto << "\"." << endl;
    } else {
        cout << "La cadena \"" << subtexto << "\" no está contenida en \"" << texto << "\"." << endl;
    }

    return 0;
}
