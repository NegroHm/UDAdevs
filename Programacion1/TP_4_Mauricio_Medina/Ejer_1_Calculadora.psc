//1. Realizar una calculadora que realice suma, resta, multiplicación y división.
//Cada cálculo se debe realizar en funciones pasando los números por valor.

Algoritmo calculadora
	Definir numeroA, numeroB Como Entero
	Definir opcion Como Entero
	Escribir "Ingrese el primer numero: "
	Leer numeroA
	Escribir "Ingrese el segundo numero: "
	Leer numeroB
	
	funSuma=suma(numeroA, numeroB)
	funResta=resta(numeroA, numeroB) 
	funMult=multiplicacion(numeroA, numeroB)
	funDiv=ivision(numeroA, numeroB)
	
	Escribir "Que tipo de calculo desea realizar: "
	Escribir "1 - Suma" 
	Escribir "2 - Resta" 
	Escribir "3 - Multiplicacion " MULT
	Escribir "4 - Div" div
	
	
FinAlgoritmo

//Suma
Funcion Suma=suma(numeroA, numeroB)
	Definir sumar Como Entero
	sumar = numeroA + numeroB
FinFuncion


//Resta
Funcion Resta=resta(numeroA, numeroB)
	Definir restar Como Entero
	restar = numeroA - numeroB
	
FinFuncion

//Multiplicacion
Funcion MULT=multiplicacion(numeroA, numeroB)
	Definir mult Como Entero
	mult = numeroA * numeroB	
FinFuncion

//Division
Funcion DIV=division(numeroA, numeroB)
	Definir div Como Real
	div = numeroA/numeroB

FinFuncion
	