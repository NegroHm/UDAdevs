package controller;

import model.Pedido;
import model.Burger;
import model.Papas;
import model.Bebida;
import model.Combo;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class GestorDePedidos {
    private final Queue<Pedido> colaPedidos = new LinkedList<>();

    // Método para crear un pedido con datos proporcionados desde la vista
    public void crearPedido(String cliente, String formaPago, boolean delivery,
                            Object burger, Object papas, Object bebida) {
        // Crear objetos del modelo
        Burger nuevoBurger = new Burger(Burger.Tamaño.valueOf(burger.toString()));
        Papas nuevasPapas = new Papas(Papas.Tamaño.valueOf(papas.toString()));
        Bebida nuevaBebida = new Bebida(Bebida.Tipo.valueOf(bebida.toString()));

        // Crear combo y pedido
        Combo combo = new Combo("Combo");
        combo.agregarItem(nuevoBurger);
        combo.agregarItem(nuevasPapas);
        combo.agregarItem(nuevaBebida);

        Pedido pedido = new Pedido(cliente, combo, formaPago, delivery);
        colaPedidos.add(pedido);
    }

    // Método para obtener los tamaños de hamburguesas desde el modelo
    public String[] obtenerTamañosBurger() {
        return Arrays.stream(Burger.Tamaño.values())
                     .map(Enum::name)
                     .toArray(String[]::new);
    }

    // Método para obtener los tamaños de papas desde el modelo
    public String[] obtenerTamañosPapas() {
        return Arrays.stream(Papas.Tamaño.values())
                     .map(Enum::name)
                     .toArray(String[]::new);
    }

    // Método para obtener los tipos de bebidas desde el modelo
    public String[] obtenerTiposBebidas() {
        return Arrays.stream(Bebida.Tipo.values())
                     .map(Enum::name)
                     .toArray(String[]::new);
    }

    // Método para obtener la cola de pedidos
    public Queue<Pedido> getColaPedidos() {
        return colaPedidos;
    }
}
