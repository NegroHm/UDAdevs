package pruebafinallab;

public class Burger extends Comida {
    public enum Tamaño {CHICA, MEDIANA, GRANDE}
    private final Tamaño tamaño;

    public Burger(Tamaño tamaño) {
        super("Hamburguesa " + tamaño);
        this.tamaño = tamaño;
    }

    public Tamaño getTamaño() {
        return tamaño;
    }
}
