// 7. Un equipo de fútbol de la UDA realiza en la temporada regular 10 juegos,
// almacene en una matriz de orden 10x2 los resultados de cada uno de los juegos.
// La columna 0 contiene la cantidad de goles realizados por UDA y la columna 1
// contiene los goles realizados por su oponente.
// a. Determine el promedio de goles anotados y recibidos durante toda la
// campaña regular.
// b. Indique además en qué fecha el equipo de la UDA hizo más goles, y en
// cual recibió más goles.
// c. Indique cuántos partidos ganó y cuantos perdió.
// d. Realice la carga mediante la función random, con un valor máximo de 6.

#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

using namespace std;

int main() {
    const int JUEGOS = 10;
    int resultados[JUEGOS][2];

    // Inicializar la semilla para los números aleatorios
    srand(time(0));

    // Llenar la matriz con valores aleatorios entre 0 y 6
    for (int i = 0; i < JUEGOS; i++) {
        resultados[i][0] = rand() % 7;
        resultados[i][1] = rand() % 7;
    }

    int sumaGolesAnotados = 0, sumaGolesRecibidos = 0;
    int maxGolesAnotados = resultados[0][0], maxGolesRecibidos = resultados[0][1];
    int fechaMaxAnotados = 0, fechaMaxRecibidos = 0;
    int partidosGanados = 0, partidosPerdidos = 0;

    // Procesar los resultados
    for (int i = 0; i < JUEGOS; i++) {
        int golesAnotados = resultados[i][0];
        int golesRecibidos = resultados[i][1];

        sumaGolesAnotados += golesAnotados;
        sumaGolesRecibidos += golesRecibidos;

        if (golesAnotados > maxGolesAnotados) {
            maxGolesAnotados = golesAnotados;
            fechaMaxAnotados = i;
        }

        if (golesRecibidos > maxGolesRecibidos) {
            maxGolesRecibidos = golesRecibidos;
            fechaMaxRecibidos = i;
        }

        if (golesAnotados > golesRecibidos) {
            partidosGanados++;
        } else if (golesAnotados < golesRecibidos) {
            partidosPerdidos++;
        }
    }

    // a. Promedio de goles anotados y recibidos
    double promedioGolesAnotados = static_cast<double>(sumaGolesAnotados) / JUEGOS;
    double promedioGolesRecibidos = static_cast<double>(sumaGolesRecibidos) / JUEGOS;

    cout << "Promedio de goles anotados: " << promedioGolesAnotados << endl;
    cout << "Promedio de goles recibidos: " << promedioGolesRecibidos << endl;

    // b. Fecha en que UDA hizo más goles y recibió más goles
    cout << "Fecha en que UDA hizo más goles: " << fechaMaxAnotados + 1 << " (Goles: " << maxGolesAnotados << ")" << endl;
    cout << "Fecha en que UDA recibió más goles: " << fechaMaxRecibidos + 1 << " (Goles: " << maxGolesRecibidos << ")" << endl;

    // c. Cantidad de partidos ganados y perdidos
    cout << "Partidos ganados: " << partidosGanados << endl;
    cout << "Partidos perdidos: " << partidosPerdidos << endl;

    return 0;
}
