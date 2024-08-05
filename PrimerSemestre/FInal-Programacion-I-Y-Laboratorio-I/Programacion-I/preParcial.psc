// Mostrar el arreglo 
// Se pasa el arreglo por referencia para evitar copiar el arreglo completo (eficiencia) 
// y para que cualquier modificación en el arreglo sea reflejada en el original.
// 'tamanio' se pasa por valor porque solo se necesita su valor para controlar el bucle,
// y no se modifica dentro del subproceso.
SubProceso mostrarNum(arreglo por referencia, tamanio por valor)
    Definir i Como entero	
    Para i = 0 hasta tamanio-1 con paso 1 Hacer
        Escribir " | " arreglo[i] " | " Sin Saltar
    FinPara
FinSubProceso

// Llenar el arreglo
// Se pasa el arreglo por referencia para llenarlo con valores, ya que las modificaciones deben reflejarse en el arreglo original.
// 'tamanio' se pasa por valor porque solo se necesita su valor para controlar el bucle,
// y no se modifica dentro del subproceso.
SubProceso llenarArreglo(arreglo por referencia, tamanio por valor)
    Definir i Como Entero
    
    Para i = 0 hasta tamanio-1 con paso 1 Hacer
        arreglo[i] = Aleatorio(10,40)
    FinPara
FinSubProceso

// Función que retorna el valor de promedio
// Se pasa el arreglo por referencia para evitar copiar el arreglo completo 
// y para trabajar directamente con el arreglo original.
// 'tamanio' se pasa por valor porque solo se necesita su valor para controlar el bucle
// y calcular el promedio, y no se modifica dentro de la función.
Funcion promedio <- promedioSuma(arreglo Por Referencia, tamanio por valor)
    Definir i, suma Como Entero
    Definir promedio Como Real
    suma = 0
    Para i = 0 Hasta tamanio-1 con paso 1 Hacer
        suma = arreglo[i] + suma
    FinPara
    promedio = suma/tamanio
FinFuncion

// Ordenar arreglo
// Se pasa el arreglo por referencia para ordenar el arreglo directamente 
// y que los cambios se reflejen en el arreglo original.
// 'tamanio' se pasa por valor porque solo se necesita su valor para controlar los bucles,
// y no se modifica dentro del subalgoritmo.
SubAlgoritmo ordenarArray(arreglo por referencia, tamanio Por Valor)
    Definir aux Como Entero
    Para i = 0 Hasta tamanio-1 Con Paso 1 Hacer
        Para j = 0 Hasta tamanio-2 Con Paso 1 Hacer
            
            Si arreglo[j] > arreglo[j+1] Entonces
                aux = arreglo[j]
                arreglo[j] = arreglo[j+1]
                arreglo[j+1] = aux
            FinSi
        FinPara
    FinPara
    Escribir " "
    Escribir "Ordenamiento del arreglo: "
    Para i = 0 Hasta tamanio-1 Con Paso 1 Hacer
        Escribir " | " arreglo[i]  " | " Sin Saltar
    FinPara
FinSubAlgoritmo

// Más chico y más grande
// Se pasa el arreglo por referencia para buscar los valores mayor y menor en el arreglo original.
// 'mayor' y 'menor' se pasan por referencia para actualizar estos valores y que los cambios sean reflejados en las variables originales.
// 'tamanio' se pasa por valor porque solo se necesita su valor para controlar el bucle,
// y no se modifica dentro del subalgoritmo.
SubAlgoritmo masGrandeyChico(arreglo por referencia, tamanio por valor, mayor Por Referencia, menor Por Referencia)
    
    mayor = arreglo[0]
    menor = arreglo[0]
    
    Para i = 0 Hasta tamanio-1 Con Paso 1 Hacer
        Si (arreglo[i] > mayor) Entonces
            mayor = arreglo[i]
        FinSi
        Si (arreglo[i] < menor) Entonces
            menor = arreglo[i]
        FinSi    
    FinPara
FinSubAlgoritmo

// Encontrar los números dentro del array que estén entre el 10 y el 20
// Se pasa el arreglo por referencia para trabajar con los datos originales.
// 'buenRan' y 'malRan' se pasan por referencia para llenar estos arreglos y reflejar los cambios en los originales.
// 'tamanio' se pasa por valor porque solo se necesita su valor para controlar el bucle,
// y no se modifica dentro del subalgoritmo.
SubAlgoritmo rangoDeNum(arreglo por referencia, tamanio por valor, buenRan por referencia, malRan por referencia)
    Definir rangoBueno, rangoMalo Como Entero
    rangoBueno = 0 
    rangoMalo = 0 
    
    Para i = 0 hasta tamanio-1 con paso 1 hacer 
        Si (arreglo[i] >= 10 y arreglo[i] <= 20)  Entonces
            buenRan[rangoBueno] =  arreglo[i]
            rangoBueno = rangoBueno+1
        SiNo
            malRan[rangoMalo] = arreglo[i]
            rangoMalo= rangoMalo+1
        FinSi
    FinPara
    Escribir " "
    Escribir "Rango bueno"
    Para i = 0 Hasta rangoBueno-1 Con Paso 1 Hacer
        Escribir Sin Saltar " + " buenRan[i] 
    FinPara
    
    Escribir " "
    Escribir "Rango malo"
    Para i=0 Hasta rangoMalo-1 Con Paso 1 Hacer
        Escribir Sin saltar " - " malRan[i] 
    FinPara
	
FinSubAlgoritmo

/// Programa principal
Algoritmo preParcial
    Definir arregloEjem, i, mayor, menor, buenRango, malRango Como Entero
    Dimension arregloEjem[40]
    Dimension malRango[40]
    Dimension buenRango[40]
    
    llenarArreglo(arregloEjem, 40)
    mostrarNum(arregloEjem, 40)
    Escribir " "
    ordenarArray(arregloEjem, 40)
    masGrandeyChico(arregloEjem, 40, mayor, menor)
    rangoDeNum(arregloEjem, 40, buenRango, malRango)
    
    Escribir " " 
    Escribir "Este es el promedio: " promedioSuma(arregloEjem, 40)
    Escribir "El numero MAYOR es: " mayor
    Escribir "El numero MENOR es: " menor
    
FinAlgoritmo
