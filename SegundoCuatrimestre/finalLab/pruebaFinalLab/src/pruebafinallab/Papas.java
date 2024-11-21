package pruebafinallab;

// Clase Papas que hereda de Comida
public class Papas extends Comida {
    // Enumeración para el tamaño de las papas
    public enum Tamaño {CHICAS, MEDIANAS, GRANDES}
    // Atributo tamaño de tipo Tamaño
    private final Tamaño tamaño;

    // Constructor de la clase Papas
    public Papas(Tamaño tamaño) {
        // Llama al constructor de la clase Comida con el nombre de la comida
        super("Papas " + tamaño);
        // Inicializa el atributo tamaño
        this.tamaño = tamaño;
    }

    // Método para obtener el tamaño de las papas
    public Tamaño getTamaño() {
        // Retorna el tamaño de las papas
        return tamaño;
    }
}