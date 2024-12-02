package model;

// Clase Burger que extiende de la clase abstracta Comida.
public class Burger extends Comida {
    // Enumeración para representar los diferentes tamaños de hamburguesa.
    public enum Tamaño {CHICA, MEDIANA, GRANDE}
    private final Tamaño tamaño;

    // Constructor que recibe el tamaño de la hamburguesa.
    public Burger(Tamaño tamaño) {
        super("Hamburguesa " + tamaño);
        this.tamaño = tamaño;
    }

    // Método que devuelve el tamaño de la hamburguesa.
    public Tamaño getTamaño() {
        return tamaño;
    }
}
