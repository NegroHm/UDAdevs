package model;

// Clase Pedido que extiende de Comida.
public class Pedido extends Comida {
    private static int contador = 0;
    private final int numPedido;
    private final String nombreCliente;
    private final String formaPago;
    private final boolean esDelivery;
    private Estado estado;

    // Enumeración para los estados del pedido.
    public enum Estado {PREPARACION, PAUSADO, TERMINADO}

    // Constructor para inicializar un pedido.
    public Pedido(String nombreCliente, Comida comida, String formaPago, boolean esDelivery) {
        super(comida.getNombre());
        this.numPedido = ++contador;
        this.nombreCliente = nombreCliente;
        this.formaPago = formaPago;
        this.esDelivery = esDelivery;
        this.estado = Estado.PREPARACION;
    }

    // Método para obtener el número de pedido.
    public int getNumPedido() {
        return numPedido;
    }

    // Método para obtener el estado del pedido.
    public Estado getEstado() {
        return estado;
    }

    // Método para actualizar el estado del pedido.
    public void setEstado(Estado estado) {
        this.estado = estado;
    }

    // Método para obtener el nombre del cliente.
    public String getNombreCliente() {
        return nombreCliente;
    }
}
