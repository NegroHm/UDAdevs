package view;

import model.Pedido;
import javax.swing.*;
import java.awt.*;
import controller.GestorDePedidos;

// Ventana para mostrar y manejar la cola de pedidos en preparación
public class VentanaColaPreparacion extends JFrame {
    private JPanel panelColaPreparacion; // Panel para mostrar los pedidos
    private final GestorDePedidos gestorDePedidos; // Referencia al controlador

    // Constructor que inicializa la ventana y el controlador
    public VentanaColaPreparacion(GestorDePedidos gestorDePedidos) {
        this.gestorDePedidos = gestorDePedidos;
        inicializarUI(); // Configura la interfaz gráfica
    }

    // Configura la interfaz gráfica de la ventana
    private void inicializarUI() {
        setTitle("Cola de Preparación"); // Título de la ventana
        setSize(500, 700); // Tamaño de la ventana
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Cierra la aplicación al cerrar la ventana
        setLocationRelativeTo(null); // Centra la ventana en la pantalla

        // Panel principal con diseño vertical
        panelColaPreparacion = new JPanel();
        panelColaPreparacion.setLayout(new BoxLayout(panelColaPreparacion, BoxLayout.Y_AXIS));

        // Agrega un JScrollPane para manejar listas largas de pedidos
        JScrollPane scrollPane = new JScrollPane(panelColaPreparacion);
        add(scrollPane); // Añade el scroll al JFrame
    }

    // Actualiza la lista de pedidos en la cola de preparación
    public void actualizarColaPreparacion() {
        try {
            panelColaPreparacion.removeAll(); // Limpia el panel antes de actualizar

            // Agrega cada pedido de la cola al panel de preparación
            for (Pedido pedido : gestorDePedidos.getColaPedidos()) {
                JPanel panelPedido = crearPanelPedido(pedido); // Crea un panel individual para cada pedido
                panelColaPreparacion.add(panelPedido); // Añade el panel al contenedor principal
            }

            // Refresca la interfaz para mostrar los cambios
            panelColaPreparacion.revalidate();
            panelColaPreparacion.repaint();
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this,
                    "Ocurrió un error al actualizar la cola: " + ex.getMessage(),
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
        }
    }

    // Crea un panel individual para representar un pedido en la cola
    private JPanel crearPanelPedido(Pedido pedido) {
        JPanel panelPedido = new JPanel(new BorderLayout()); // Diseño para organizar componentes
        panelPedido.setBorder(BorderFactory.createLineBorder(Color.BLACK)); // Borde para resaltar el pedido
        setColorPorEstado(panelPedido, pedido.getEstado()); // Establece el color según el estado del pedido

        // Etiqueta que muestra información del pedido
        JLabel labelPedido = new JLabel("Pedido " + pedido.getNumPedido() + ": " + pedido.getNombre());

        // Menú desplegable para cambiar el estado del pedido
        JComboBox<Pedido.Estado> comboEstado = new JComboBox<>(Pedido.Estado.values());
        comboEstado.setSelectedItem(pedido.getEstado()); // Selecciona el estado actual del pedido

        // Evento que actualiza el estado del pedido al cambiar la selección
        comboEstado.addActionListener(e -> {
            Pedido.Estado nuevoEstado = (Pedido.Estado) comboEstado.getSelectedItem();
            pedido.setEstado(nuevoEstado); // Actualiza el estado en el modelo
            setColorPorEstado(panelPedido, nuevoEstado); // Cambia el color del panel
        });

        // Añade la etiqueta y el menú desplegable al panel
        panelPedido.add(labelPedido, BorderLayout.CENTER); // Etiqueta en el centro
        panelPedido.add(comboEstado, BorderLayout.SOUTH); // Menú desplegable abajo

        return panelPedido; // Devuelve el panel configurado
    }

    // Cambia el color del panel según el estado del pedido
  private void setColorPorEstado(JPanel panel, Pedido.Estado estado) {
    switch (estado) {
        case PREPARACION:
            panel.setBackground(Color.YELLOW); // Amarillo para preparación
            break;
        case PAUSADO:
            panel.setBackground(Color.RED); // Rojo para pausado
            break;
        case TERMINADO:
            panel.setBackground(Color.GREEN); // Verde para terminado
            break;
    }
}

}
