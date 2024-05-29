#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

int main(){
    char arregloUno[5];
    char arregloDos[5];
    int pointer = -1;

    arregloUno = {'A', 'B', 'C', 'D', 'E'}; 
    arregloDos = {'C', 'E', 'A', 'B', 'C'};


for (int i = 0; i < 5; i++){
    if (arregloUno[0] == arregloDos[i]) {
    pointer = 1; 
    break;
    }
}

if (pointer == -1)
{
    cout << "Los arreglos son... ";
}
    
for (int i = 1; i < 5; i++){
    if (pointer + i < 5)
    if (arregloUno[i] == arregloDos[pointer + i]){ 
        pointer= -1;
        break;                     
    } 
}else {
    if (arregloUno[i]== arregloDos[pointer + i - 5])
    pointer= -1;
    break;
}




    return 0;
}




