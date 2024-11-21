package pruebafinallab;

// Clase abstracta que representa un tipo de comida
public abstract class Comida {
    // Atributo que almacena el nombre de la comida
    protected String nombre;

    // Constructor que inicializa el nombre de la comida
    public Comida(String nombre) {
        this.nombre = nombre;
    }

    // Método que devuelve el nombre de la comida
    public String getNombre() {
        return nombre;
    }
}