#include <iostream>

using namespace std;

int main(){
	string input;
	int jk;
	int renzoProfe;
	int xts = true;
	bool ctne = true;

	do{
		std::cout << "Ingrese una palabra: ";
		std::cin >> input;

		jk = input.length();

		for(int i = 0; i < jk; i++){
			renzoProfe = jk - i;

	        if(input[i] == input[renzoProfe - 1]){
	            xts = true;
	        }

	        if(input[i] != input[renzoProfe - 1]){
	            xts = false;
	        }
		}
	    
	    if(xts){
	    	std::cout << "La palabra es palindromo";
	    }else if(xts == false){
	    	std::cout << "La palabra no es palindroma";
	    }

	    std::cout << "Continuar ? ";
		std::cin >> ctne;

	}while( ctne > 0);

	

    return 0;

}