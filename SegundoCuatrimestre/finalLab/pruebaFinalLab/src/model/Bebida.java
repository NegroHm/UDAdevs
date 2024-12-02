package model;

// Clase que representa una bebida, extendiendo de la clase Comida.
public class Bebida extends Comida {
    // Enumeración que define los tipos de bebidas disponibles.
    public enum Tipo {COCA_COLA, PEPSI, FANTA}
    private final Tipo tipo;

    // Constructor que inicializa la bebida con un tipo específico.
    public Bebida(Tipo tipo) {
        super("Bebida: " + tipo);
        this.tipo = tipo;
    }

    // Método que devuelve el tipo de bebida.
    public Tipo getTipo() {
        return tipo;
    }
}
