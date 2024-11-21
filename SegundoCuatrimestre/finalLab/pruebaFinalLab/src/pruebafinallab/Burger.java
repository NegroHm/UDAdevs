package pruebafinallab;

// La clase Burger se extiende de la clase abstracta Comida
public class Burger extends Comida {
    // Enumeración para representar los diferentes tamaños de hamburguesa
    public enum Tamaño {CHICA, MEDIANA, GRANDE}
    // Variable de instancia para almacenar el tamaño de la hamburguesa
    private final Tamaño tamaño;

    // Constructor que recibe el tamaño de la hamburguesa y llama al constructor de la clase padre
    public Burger(Tamaño tamaño) {
        // Llama al constructor de la clase padre con el nombre de la hamburguesa
        super("Hamburguesa " + tamaño);
        // Asigna el tamaño recibido a la variable de instancia
        this.tamaño = tamaño;
    }

    // Método que devuelve el tamaño de la hamburguesa
    public Tamaño getTamaño() {
        return tamaño;
    }
}