// Inicialización de la clase principal
package pruebafinallab;

import controller.GestorDePedidos;
import view.VentanaFormulario;
import view.VentanaColaPreparacion;
import javax.swing.*;

public class pruebafinallab{
    // Objeto de tipo GestorDePedidos
    // 1. Crear el gestor de pedidos
    // El gestor es el encargado de manejar la cola de pedidos (agregar, procesar, etc.)
    private final GestorDePedidos gestorDePedidos;

    // Constructor de la clase
    public pruebafinallab() {
        // Crear objeto GestorDePedidos
        gestorDePedidos = new GestorDePedidos();
        // Iniciar ventanas
        iniciarVentanas();
    }

    // Método para iniciar ventanas
    private void iniciarVentanas() {
        // Crear ventanas
        // 2. Crear la ventana de la cola de preparación
        // Esta ventana mostrará todos los pedidos en una cola visual
        VentanaColaPreparacion ventanaColaPreparacion = new VentanaColaPreparacion(gestorDePedidos);

        // 3. Crear la ventana del formulario
        // Esta ventana permite ingresar nuevos pedidos con detalles específicos
        VentanaFormulario ventanaFormulario = new VentanaFormulario(gestorDePedidos, ventanaColaPreparacion);

        // Mostrar ventanas
        // 4. Mostrar ambas ventanas
        // - La ventana del formulario es para la entrada de datos.
        ventanaColaPreparacion.setVisible(true);
        // - La ventana de la cola muestra los pedidos activos en tiempo real.
        ventanaFormulario.setVisible(true);
    }

    // Método main
    public static void main(String[] args) {
        // Ejecutar en hilo de interfaz gráfica
        SwingUtilities.invokeLater(pruebafinallab::new);
    }
}