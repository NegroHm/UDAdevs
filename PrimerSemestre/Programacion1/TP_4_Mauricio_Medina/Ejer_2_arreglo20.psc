//2. Cargar un arreglo de 20 n�meros en un procedimiento y realizar el 
//c�lculo de promedio de los n�meros en una funci�n pasando el arreglo al mismo.
Algoritmo cargarUnArreglo
	Dimension vector[20] 
	generateNumber(vector)
	average(vector)
FinAlgoritmo

SubAlgoritmo generateNumber(vector)
	Para i = 0 Hasta 19 Con Paso 1 Hacer
		vector[i] = Aleatorio(1, 20)
		Escribir vector[i]
	Fin Para
FinSubAlgoritmo	


SubAlgoritmo average(vector)
	//Dimension vector[19] 
	Definir suma Como Entero
	suma= 0
	Para i = 0 Hasta 19 Con Paso 1 Hacer
		suma = suma + vector[i] 
	Fin Para
	
	Escribir "Suma " suma/20
	
FinSubAlgoritmo