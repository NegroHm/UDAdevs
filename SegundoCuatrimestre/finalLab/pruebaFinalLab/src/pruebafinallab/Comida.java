package pruebafinallab;

public abstract class Comida {
    protected String nombre;

    public Comida(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }
}
