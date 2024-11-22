package pruebafinallab;

import javax.swing.*;
import java.awt.*;

public class VentanaColaPreparacion extends JFrame {
    // Panel principal para mostrar los pedidos en la cola de preparación
    private JPanel panelColaPreparacion;
    
    // Referencia al gestor de pedidos que contiene la cola de pedidos
    private final GestorDePedidos gestorDePedidos;

    // Constructor que inicializa la ventana y el gestor de pedidos
    public VentanaColaPreparacion(GestorDePedidos gestorDePedidos) {
        this.gestorDePedidos = gestorDePedidos;
        inicializarUI(); // Configura la interfaz gráfica
    }

    // Configura la interfaz gráfica de la ventana
    private void inicializarUI() {
        setTitle("Cola de Preparación"); // Título de la ventana
        setSize(300, 400); // Tamaño de la ventana
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Cierra la aplicación al cerrar la ventana
        setLocationRelativeTo(null); // Centra la ventana en la pantalla

        // Panel donde se mostrarán los pedidos, con un diseño vertical (BoxLayout)
        panelColaPreparacion = new JPanel();
        panelColaPreparacion.setLayout(new BoxLayout(panelColaPreparacion, BoxLayout.Y_AXIS));
        
        // Scroll para desplazarse si los pedidos exceden el tamaño visible
        JScrollPane scrollPane = new JScrollPane(panelColaPreparacion);
        add(scrollPane); // Agrega el scroll al JFrame
    }

    // Actualiza la lista de pedidos en la cola de preparación
    public void actualizarColaPreparacion() {
        // Manejo de errores para prevenir fallos durante la actualización
        try {
            panelColaPreparacion.removeAll(); // Elimina todos los componentes del panel
            
            // Agrega cada pedido de la cola al panel de preparación
            for (Pedido pedido : gestorDePedidos.getColaPedidos()) {
                JPanel panelPedido = crearPanelPedido(pedido); // Crea un panel individual para cada pedido
                panelColaPreparacion.add(panelPedido); // Añade el panel al panel principal
            }

            // Refresca la interfaz para mostrar los cambios
            panelColaPreparacion.revalidate();
            panelColaPreparacion.repaint();
        } catch (NullPointerException ex) {
            // Muestra un mensaje si ocurre un error debido a datos nulos
            JOptionPane.showMessageDialog(this, 
                "No se pudo actualizar la cola de preparación: " + ex.getMessage(), 
                "Error", 
                JOptionPane.ERROR_MESSAGE);
        } catch (Exception ex) {
            // Captura cualquier otro error inesperado
            JOptionPane.showMessageDialog(this, 
                "Ocurrió un error inesperado: " + ex.getMessage(), 
                "Error", 
                JOptionPane.ERROR_MESSAGE);
        }
    }

    // Crea un panel individual para representar un pedido en la cola
    private JPanel crearPanelPedido(Pedido pedido) {
        // Panel para mostrar los detalles de un pedido con diseño BorderLayout
        JPanel panelPedido = new JPanel(new BorderLayout());
        panelPedido.setBorder(BorderFactory.createLineBorder(Color.BLACK)); // Borde negro para separar visualmente
        setColorPorEstado(panelPedido, pedido.getEstado()); // Establece el color según el estado del pedido
        
        // Etiqueta que muestra el número y nombre del pedido
        JLabel labelPedido = new JLabel("Pedido " + pedido.getNumPedido() + ": " + pedido.getNombre());
        
        // Menú desplegable para cambiar el estado del pedido
        JComboBox<Pedido.Estado> comboEstado = new JComboBox<>(Pedido.Estado.values());
        comboEstado.setSelectedItem(pedido.getEstado()); // Selecciona el estado actual del pedido
        
        // Evento que actualiza el estado del pedido al cambiar la selección
        comboEstado.addActionListener(e -> {
            Pedido.Estado nuevoEstado = (Pedido.Estado) comboEstado.getSelectedItem(); // Obtiene el nuevo estado
            pedido.setEstado(nuevoEstado); // Actualiza el estado en el pedido
            setColorPorEstado(panelPedido, nuevoEstado); // Cambia el color del panel según el nuevo estado
            
            // Refresca la interfaz para reflejar el cambio
            panelColaPreparacion.revalidate();
            panelColaPreparacion.repaint();
        });

        // Añade los componentes al panel del pedido
        panelPedido.add(labelPedido, BorderLayout.CENTER); // Etiqueta en el centro
        panelPedido.add(comboEstado, BorderLayout.SOUTH); // Menú desplegable en la parte inferior

        return panelPedido; // Retorna el panel configurado
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
