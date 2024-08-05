SubAlgoritmo evaluarMayorMenor(num Por Valor, conjuntoDeMayores Por Referencia, indiceMayores Por Referencia, conjuntoDeMenores Por Referencia, indiceMenores Por Referencia)
    Si num > 15 y num < 45 Entonces
        conjuntoDeMayores[indiceMayores] <- num
        indiceMayores <- indiceMayores + 1
    SiNo
        conjuntoDeMenores[indiceMenores] <- num
        indiceMenores <- indiceMenores + 1
    Fin Si
FinSubAlgoritmo

Algoritmo calculoDePromedio
    Definir num, indiceMayores, indiceMenores Como Entero
    
	Dimension conjuntoDeMayores[40] 
	Dimension conjuntoDeMenores[40] 
    
    indiceMayores <- 0
    indiceMenores <- 0
    
    Para i = 0 Hasta 39 Con Paso 1 Hacer
        num <- Azar(100)
        evaluarMayorMenor(num, conjuntoDeMayores, indiceMayores, conjuntoDeMenores, indiceMenores)
    Fin Para
    
    // Mostrar los resultados
    Escribir "Dentro del rango: "
    Para i = 0 Hasta indiceMayores - 1 Con Paso 1 Hacer
        Escribir " | " conjuntoDeMayores[i] Sin Saltar
    Fin Para
    
	Escribir " "
	
    Escribir "Fuera del rango: "
    Para i = 0 Hasta indiceMenores - 1 Con Paso 1 Hacer
        Escribir " | " conjuntoDeMenores[i]  Sin Saltar
    Fin Para
FinAlgoritmo
