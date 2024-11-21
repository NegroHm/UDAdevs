// Esta clase nos permite modificar el tamaño de las bebidas que vamos a solicitar en el formulario
package pruebafinallab;

   // Clase que representa una bebida, extendiendo de la clase Comida.
   // Permite especificar el tipo de bebida.
public class Bebida extends Comida {
    // Enumeración que define los tipos de bebidas disponibles.
    public enum Tipo {COCA_COLA, PEPSI, FANTA}
    private final Tipo tipo;
    
    // Constructor que inicializa la bebida con un tipo específico.
    // @param tipo El tipo de bebida.
    public Bebida(Tipo tipo) {
        // Inicializa la bebida con un tipo específico y un nombre descriptivo.
        super("Bebida: " + tipo);
        // Asigna el tipo de bebida a la variable de instancia.
        this.tipo = tipo;
    }

    
    // Método que devuelve el tipo de bebida.
    // @return El tipo de bebida.
    public Tipo getTipo() {
        // Devuelve el tipo de bebida seleccionado.
        return tipo;
    }
}