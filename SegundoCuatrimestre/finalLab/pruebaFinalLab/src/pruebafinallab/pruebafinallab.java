//Class Main 
package pruebafinallab;

import javax.swing.*;

public class pruebafinallab{
    private final GestorDePedidos gestorDePedidos;

    public pruebafinallab() {
        gestorDePedidos = new GestorDePedidos();
        iniciarVentanas();
    }

    private void iniciarVentanas() {
        // Crear e inicializar las ventanas
        VentanaColaPreparacion ventanaColaPreparacion = new VentanaColaPreparacion(gestorDePedidos);
        VentanaFormulario ventanaFormulario = new VentanaFormulario(gestorDePedidos, ventanaColaPreparacion);

        // Mostrar ambas ventanas
        ventanaColaPreparacion.setVisible(true);
        ventanaFormulario.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(pruebafinallab::new);
    }
}
