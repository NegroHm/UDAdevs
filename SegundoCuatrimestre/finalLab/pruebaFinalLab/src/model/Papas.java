package model;

// Clase Papas que hereda de Comida.
public class Papas extends Comida {
    // Enumeración para el tamaño de las papas.
    public enum Tamaño {CHICAS, MEDIANAS, GRANDES}
    private final Tamaño tamaño;

    // Constructor de la clase Papas.
    public Papas(Tamaño tamaño) {
        super("Papas " + tamaño);
        this.tamaño = tamaño;
    }

    // Método para obtener el tamaño de las papas.
    public Tamaño getTamaño() {
        return tamaño;
    }
}
