SubAlgoritmo evaluarMayorMedor(num por valor)
 	Definir mayorNum, menorNum Como Entero
	
	mayorNum = 0
	Si num > 15 y num < 45 Entonces
		mayorNum = num 
		Escribir "Mayor de 15 y menor a 45: " mayorNum
	SiNo
		menorNum = num
		Escribir "Menor de 15 o mayor a 45: " menorNum
	Fin Si
FinSubAlgoritmo

Algoritmo calculoDePromedio
	Definir num Como Entero
	
	Para i = 0 Hasta 40 Con Paso 1 Hacer
		num = azar(100) 
		evaluarMayorMedor(num)
	Fin Para
	
FinAlgoritmo
