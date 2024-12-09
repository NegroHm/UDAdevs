package controller;

import model.Pedido;
import model.Burger;
import model.Papas;
import model.Bebida;
import model.Combo;

import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class GestorDePedidos {
    private final Queue<Pedido> colaPedidos = new LinkedList<>();
    private static final String FILE_PATH = "src/controller/pedidos.txt";

    // Constructor que carga los pedidos desde el archivo
    public GestorDePedidos() {
        cargarPedidos();
    }

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
        guardarPedidos(); // Guarda los pedidos en el archivo
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

    // Método para guardar los pedidos en un archivo
    private void guardarPedidos() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_PATH))) {
            for (Pedido pedido : colaPedidos) {
                writer.write(pedido.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("Error al guardar los pedidos: " + e.getMessage());
        }
    }

    // Método para cargar los pedidos desde un archivo
    private void cargarPedidos() {
        File file = new File(FILE_PATH);
        if (!file.exists()) return; // Si el archivo no existe, no hace nada

        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_PATH))) {
            String line;
            while ((line = reader.readLine()) != null) {
                Pedido pedido = Pedido.fromString(line); // Implementa un método `fromString` en Pedido
                colaPedidos.add(pedido);
            }
        } catch (IOException e) {
            System.err.println("Error al cargar los pedidos: " + e.getMessage());
        }
    }
}
