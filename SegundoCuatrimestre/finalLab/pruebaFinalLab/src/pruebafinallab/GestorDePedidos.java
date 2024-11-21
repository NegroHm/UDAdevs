package pruebafinallab;

import java.util.LinkedList;
import java.util.Queue;

public class GestorDePedidos {
    private final Queue<Pedido> colaPedidos;

    public GestorDePedidos() {
        colaPedidos = new LinkedList<>();
    }

    public void agregarPedido(Pedido pedido) {
        colaPedidos.add(pedido);
    }

    public Queue<Pedido> getColaPedidos() {
        return colaPedidos;
    }
}

