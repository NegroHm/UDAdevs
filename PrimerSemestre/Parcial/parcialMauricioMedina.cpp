    #include <iostream>
    #include <stdlib.h>
    #include <ctime>

    using namespace std;

    void dado(int n, int vector[]); 
    void vecesSalioUNORojoNegro(int n, int vectorA[], int vectorB[]);
    void average(int n, int vector[]);
    void show(int n, int vector[]);

    int main()
    {
        int dadoRojo[100], dadoNegro[100];
        srand(time(NULL));

        //A partir de aca se muestra las tiradas de los dados
        cout << "TIRADA DEL DADO ROJO: " << endl; 
        dado(100, dadoRojo);
        show(100, dadoRojo);
        
        cout << endl;
        
        cout << "Promedio dado rojo: ";
        average(100, dadoRojo);

        cout << endl;

        cout << "TIRADA DEL DADO NEGRO: " << endl;
        dado(100, dadoNegro);
        show(100, dadoNegro);
        cout << endl;
        cout << "Promedio dado Negro: ";
        average(100, dadoNegro);
        // ----------------------------------------------------

        //vecesSalioUNO(100, dadoNegro);
        cout << " " << endl;

        vecesSalioUNORojoNegro(100, dadoRojo, dadoNegro);    
        return 0;
    }

    //tirar los dados, esta tiene que generar 100 tiradas 
    //generar los numeros aleatorios del 1 al 6, esto por las caras del dado
    void dado(int n, int vector[]){
        //Agregar +1 para que no genere un numero 0
        for (int i = 0; i < n; i++){
            vector[i] = rand()%6 + 1;
        }
    }

    //Calcular el promedio de las caras que salieron
    void average(int n, int vector[]){
        int suma = 0;
        int aver;
        for (int i = 0; i < n; i++){
            suma += vector[i];
        }
        aver = (suma/n); 
        cout << aver;
    }

    //Mostrar

    void show(int n, int vector[]){
        for (int i = 0; i < n; i++)
        {
            cout << vector[i] << " ";
        }
        
    }

    //Sub programa que me arroja el dado que mas veces genero 1

    void vecesSalioUNORojoNegro(int n, int vectorA[], int vectorB[]){
        int vecesRojo = 0;
        int vecesNegro = 0;
        for (int i = 0; i < n; i++){
            if (vectorA[i] == 1){
                vecesRojo += 1;
            }
        }
        
        for (int i = 0; i < n; i++){
            if (vectorB[i] == 1){
                vecesNegro += 1;
            }
        }
        cout << "Estas son las veces que salio 1 en dado Rojo: " << vecesRojo << endl;
        cout << "Estas son las veces que salio 1 en dado Negro: " << vecesNegro << endl;

        if (vecesRojo > vecesNegro)
        {
            cout << "El dado que mas veces salio la cara 1(UNO) es en el dado ROJO: " << vecesRojo << endl; 
        } else {
            cout << "El dado que mas veces salio la cara 1(UNO) es en el dado NEGRO: " << vecesNegro << endl;
        }
    }