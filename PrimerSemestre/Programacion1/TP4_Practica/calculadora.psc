//1. Realizar una calculadora que realice suma, resta, multiplicación y división. 
//Cada cálculo se debe realizar en funciones pasando los números por valor.

Funcion div <- divCaluladora ( numero1, numero2 )
	Definir div como Real
	div = (numero1/numero2) 
Fin Funcion

Funcion multiplicacion <- multiCalculadora ( numero1, numero2 )
	Definir multiplicacion como entero
	multiplicacion = (numero1*numero2)
Fin Funcion

Funcion resta <- restaCalculadora ( numero1, numero2 )
	Definir resta Como Entero
	resta = (numero1-numero2)
Fin Funcion

Funcion suma <- sumaCalculadora(numero1, numero2)
	Definir suma Como Entero
	suma = (numero1+numero2)
FinFuncion


Algoritmo calculadora
	Definir numero1, numero2, resultado  Como Entero
	Escribir "Ingrese el primer numero: "
	Leer numero1
	Escribir "Ingrese el segundo numero: "
	leer numero2
	
	
	Escribir sumaCalculadora(numero1 , numero2)	
	Escribir restaCalculadora(numero1 , numero2)
	Escribir multiCalculadora(numero1 , numero2)
	Escribir divCaluladora(numero1, numero2)
FinAlgoritmo


