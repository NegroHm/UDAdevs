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

    // Método para serializar un pedido a una cadena de texto.
    @Override
    public String toString() {
        return numPedido + ";" + nombreCliente + ";" + formaPago + ";" +
               esDelivery + ";" + estado + ";" + nombre;
    }

    // Método para deserializar un pedido desde una cadena de texto.
    public static Pedido fromString(String data) {
        String[] parts = data.split(";");
        if (parts.length < 6) {
            throw new IllegalArgumentException("Formato de datos inválido para Pedido.");
        }

        String nombreCliente = parts[1];
        String formaPago = parts[2];
        boolean esDelivery = Boolean.parseBoolean(parts[3]);
        Estado estado = Estado.valueOf(parts[4]);
        String nombreComida = parts[5];

        // Nota: Aquí asumimos que el nombre de la comida es suficiente para recrear la comida.
        // Si necesitas detalles más específicos, deberás deserializar Comida o sus subclases.
        Comida comida = new Comida(nombreComida) {};

        Pedido pedido = new Pedido(nombreCliente, comida, formaPago, esDelivery);
        pedido.setEstado(estado);
        return pedido;
    }
}
