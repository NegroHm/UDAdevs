//2. Cargar un arreglo de 20 n�meros en un procedimiento y realizar el 
//c�lculo de promedio de los n�meros en una funci�n pasando el arreglo al mismo.
Algoritmo cargarUnArreglo
	Dimension vector[19] 
	vector[1] = 0 
	average(vector)
FinAlgoritmo

SubAlgoritmo generateNumber(vector)
	Para i = 0 Hasta 19 Con Paso 1 Hacer
		vector = Aleatorio(1, 20)
	Fin Para
FinSubAlgoritmo	


SubAlgoritmo average(vector)
	//Dimension vector[19] 
	Definir suma Como Entero
	Para i = 0 Hasta 19 Con Paso 1 Hacer
		suma = vector[i] + vector[i+1]
		vector[i] = suma
	Fin Para
	
FinSubAlgoritmo