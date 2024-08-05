Algoritmo ComparacionGrandeChico
	Dimensionar Array(5)
	Definir masChico, masGrande, auxiliar Como Entero
	
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		Array[i] <- aleatorio(0,100)
		Escribir '|', Array[i], '|'Sin Saltar
	FinPara
	
	masChico <- Array[0]
	Para i<-1 Hasta 4 Con Paso 1 Hacer
		Si masChico>Array[i] Entonces
			masChico <- Array[i]
		FinSi
	FinPara
	
	Escribir ''
	Escribir 'mas chico ', masChico
	
	masGrande <- Array[0]
	Para i<-1 Hasta 4 Con Paso 1 Hacer
		Si masGrande<Array[i] Entonces
			masGrande <- Array[i]
		FinSi
	FinPara
	
	Escribir 'mas grande ', masGrande
	
	// Algoritmo de ordenamiento tipo burbuja
	// Ordena un array de menor a mayor
	
	// Primer bucle: itera a través de todo el array varias veces
	Para i <- 0 Hasta 4 Con Paso 1 Hacer
		// Segundo bucle: realiza la comparación y el intercambio de elementos
		Para j <- 0 Hasta 3 Con Paso 1 Hacer
			// Compara el elemento actual (Array[j]) con el siguiente elemento (Array[j+1])
			Si Array[j] > Array[j+1] Entonces
				// Si el elemento actual es mayor que el siguiente, se intercambian
				auxiliar <- Array[j] // Guarda el valor del elemento actual en una variable auxiliar
				Array[j] <- Array[j+1] // Mueve el siguiente elemento a la posición actual
				Array[j+1] <- auxiliar // Mueve el valor guardado en auxiliar a la posición del siguiente elemento
			FinSi
		FinPara
	FinPara
	
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		Escribir '|', Array[i], '|'Sin Saltar
	FinPara
	
	Escribir ''
	
FinAlgoritmo