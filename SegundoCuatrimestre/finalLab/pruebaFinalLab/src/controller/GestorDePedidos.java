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
    // Cola que almacena los pedidos en memoria
    private final Queue<Pedido> colaPedidos = new LinkedList<>();

    // Ruta del archivo donde se guardarán los pedidos
    private static final String FILE_PATH = "src/controller/pedidos.txt";

    // Constructor: Carga los pedidos desde el archivo al iniciar el programa
    public GestorDePedidos() {
        cargarPedidos();
    }

    // Método para crear un nuevo pedido
    public void crearPedido(String cliente, String formaPago, boolean delivery,
                            Object burger, Object papas, Object bebida) {
        // Crear los objetos de las opciones seleccionadas por el cliente
        Burger nuevoBurger = new Burger(Burger.Tamaño.valueOf(burger.toString()));
        Papas nuevasPapas = new Papas(Papas.Tamaño.valueOf(papas.toString()));
        Bebida nuevaBebida = new Bebida(Bebida.Tipo.valueOf(bebida.toString()));

        // Crear un combo y agregar los ítems seleccionados
        Combo combo = new Combo("Combo");
        combo.agregarItem(nuevoBurger);
        combo.agregarItem(nuevasPapas);
        combo.agregarItem(nuevaBebida);

        // Crear un nuevo pedido con los datos proporcionados
        Pedido pedido = new Pedido(cliente, combo, formaPago, delivery);
        colaPedidos.add(pedido); // Agregar el pedido a la cola

        // Guardar la cola de pedidos actualizada en el archivo
        guardarPedidos();
    }

    // Método para obtener los tamaños disponibles de hamburguesas
    public String[] obtenerTamañosBurger() {
        // Convierte los valores de la enumeración Tamaño a un arreglo de Strings
        return Arrays.stream(Burger.Tamaño.values())
                     .map(Enum::name)
                     .toArray(String[]::new);
    }

    // Método para obtener los tamaños disponibles de papas
    public String[] obtenerTamañosPapas() {
        // Convierte los valores de la enumeración Tamaño a un arreglo de Strings
        return Arrays.stream(Papas.Tamaño.values())
                     .map(Enum::name)
                     .toArray(String[]::new);
    }

    // Método para obtener los tipos disponibles de bebidas
    public String[] obtenerTiposBebidas() {
        // Convierte los valores de la enumeración Tipo a un arreglo de Strings
        return Arrays.stream(Bebida.Tipo.values())
                     .map(Enum::name)
                     .toArray(String[]::new);
    }

    // Método para obtener la cola de pedidos actual
    public Queue<Pedido> getColaPedidos() {
        return colaPedidos;
    }

    // Método para guardar los pedidos actuales en un archivo
    private void guardarPedidos() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_PATH))) {
            // Escribe cada pedido de la cola en una nueva línea del archivo
            for (Pedido pedido : colaPedidos) {
                writer.write(pedido.toString()); // Convierte el pedido a String
                writer.newLine(); // Salto de línea para separar los pedidos
            }
        } catch (IOException e) {
            // Manejo de errores en caso de problemas al escribir el archivo
            System.err.println("Error al guardar los pedidos: " + e.getMessage());
        }
    }

    // Método para cargar los pedidos desde un archivo
    private void cargarPedidos() {
        // Crea un objeto File para verificar la existencia del archivo
        File file = new File(FILE_PATH);

        // Si el archivo no existe, no hay nada que cargar
        if (!file.exists()) return;

        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_PATH))) {
            String line;

            // Lee cada línea del archivo y reconstruye el pedido
            while ((line = reader.readLine()) != null) {
                Pedido pedido = Pedido.fromString(line); // Convierte la línea a un objeto Pedido
                colaPedidos.add(pedido); // Agrega el pedido a la cola
            }
        } catch (IOException e) {
            // Manejo de errores en caso de problemas al leer el archivo
            System.err.println("Error al cargar los pedidos: " + e.getMessage());
        }
    }
}
    