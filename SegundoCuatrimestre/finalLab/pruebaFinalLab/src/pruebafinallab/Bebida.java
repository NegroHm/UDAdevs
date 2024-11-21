//Esta class nos permite modificar el tamaño de las bebidas que vamos a solicitar en el formulario
package pruebafinallab;

public class Bebida extends Comida {
    public enum Tipo {COCA_COLA, PEPSI, FANTA}
    private final Tipo tipo;

    public Bebida(Tipo tipo) {
        super("Bebida: " + tipo);
        this.tipo = tipo;
    }

    public Tipo getTipo() {
        return tipo;
    }
}
