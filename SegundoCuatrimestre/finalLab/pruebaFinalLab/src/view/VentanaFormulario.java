package view;

import controller.GestorDePedidos;
import javax.swing.*;
import java.awt.*;

// Ventana para ingresar un nuevo pedido al sistema
public class VentanaFormulario extends JFrame {
    private final GestorDePedidos gestorDePedidos; // Controlador que maneja los pedidos
    private final VentanaColaPreparacion ventanaColaPreparacion; // Referencia a la ventana de la cola

    // Constructor que inicializa la ventana con el controlador y otra ventana
    public VentanaFormulario(GestorDePedidos gestorDePedidos, VentanaColaPreparacion ventanaColaPreparacion) {
        this.gestorDePedidos = gestorDePedidos;
        this.ventanaColaPreparacion = ventanaColaPreparacion;
        inicializarUI(); // Configura la interfaz gráfica
    }

    // Configura la interfaz gráfica de la ventana
    private void inicializarUI() {
        setTitle("Formulario de Pedido"); // Título de la ventana
        setSize(600, 700); // Tamaño del formulario ajustado
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Cierra la aplicación al cerrar
        setLocationRelativeTo(null); // Centra la ventana en la pantalla

        // Establece un layout principal
        setLayout(new BorderLayout());

        // Añade la imagen en la parte superior
        JLabel labelImagen = new JLabel();
        ImageIcon icono = new ImageIcon("src/imagen/ImagenDecoratio.png"); // Ruta de la imagen
        labelImagen.setIcon(icono);
        labelImagen.setHorizontalAlignment(SwingConstants.CENTER); // Centra la imagen
        add(labelImagen, BorderLayout.NORTH);

        // Crear y añadir el panel principal del formulario
        JPanel panelFormulario = crearPanelFormulario();
        add(panelFormulario, BorderLayout.CENTER);
    }

    // Crea el panel principal del formulario
    private JPanel crearPanelFormulario() {
        JPanel panel = new JPanel(new GridBagLayout()); // Layout para organizar componentes
        panel.setBackground(new Color(45, 45, 45)); // Fondo oscuro (gris)

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10); // Espaciado entre los componentes
        gbc.fill = GridBagConstraints.HORIZONTAL;

        // Campo para ingresar el nombre del cliente
        gbc.gridx = 0;
        gbc.gridy = 0;
        JLabel labelNombre = new JLabel("Nombre Cliente:");
        labelNombre.setForeground(Color.WHITE); // Cambia el texto a blanco
        panel.add(labelNombre, gbc);
        gbc.gridx = 1;
        JTextField campoNombreCliente = new JTextField(20);
        campoNombreCliente.setPreferredSize(new Dimension(200, 30)); // Tamaño preferido
        panel.add(campoNombreCliente, gbc);

        // Campo para seleccionar el tipo de hamburguesa
        gbc.gridy++;
        gbc.gridx = 0;
        JLabel labelBurger = new JLabel("Pedido (Hamburguesa):");
        labelBurger.setForeground(Color.WHITE); // Cambia el texto a blanco
        panel.add(labelBurger, gbc);
        gbc.gridx = 1;
        JComboBox<String> comboBurger = new JComboBox<>(gestorDePedidos.obtenerTamañosBurger());
        comboBurger.setPreferredSize(new Dimension(200, 30)); // Tamaño preferido
        panel.add(comboBurger, gbc);

        // Campo para seleccionar el tamaño de las papas
        gbc.gridy++;
        gbc.gridx = 0;
        JLabel labelPapas = new JLabel("Acompañamiento (Papas):");
        labelPapas.setForeground(Color.WHITE); // Cambia el texto a blanco
        panel.add(labelPapas, gbc);
        gbc.gridx = 1;
        JComboBox<String> comboPapas = new JComboBox<>(gestorDePedidos.obtenerTamañosPapas());
        comboPapas.setPreferredSize(new Dimension(200, 30)); // Tamaño preferido
        panel.add(comboPapas, gbc);

        // Campo para seleccionar la bebida
        gbc.gridy++;
        gbc.gridx = 0;
        JLabel labelBebida = new JLabel("Bebida:");
        labelBebida.setForeground(Color.WHITE); // Cambia el texto a blanco
        panel.add(labelBebida, gbc);
        gbc.gridx = 1;
        JComboBox<String> comboBebida = new JComboBox<>(gestorDePedidos.obtenerTiposBebidas());
        comboBebida.setPreferredSize(new Dimension(200, 30)); // Tamaño preferido
        panel.add(comboBebida, gbc);

        // Campo para seleccionar la forma de pago
        gbc.gridy++;
        gbc.gridx = 0;
        JLabel labelFormaPago = new JLabel("Forma de Pago:");
        labelFormaPago.setForeground(Color.WHITE); // Cambia el texto a blanco
        panel.add(labelFormaPago, gbc);
        gbc.gridx = 1;
        JComboBox<String> comboFormaPago = new JComboBox<>(new String[]{"Efectivo", "Transferencia", "Tarjeta"});
        comboFormaPago.setPreferredSize(new Dimension(200, 30)); // Tamaño preferido
        panel.add(comboFormaPago, gbc);

        // Campo para seleccionar la ubicación del cliente
        gbc.gridy++;
        gbc.gridx = 0;
        JLabel labelUbicacion = new JLabel("Ubicación del Cliente:");
        labelUbicacion.setForeground(Color.WHITE); // Cambia el texto a blanco
        panel.add(labelUbicacion, gbc);
        gbc.gridx = 1;
        JComboBox<String> comboUbicacion = new JComboBox<>(new String[]{"Delivery", "Local"});
        comboUbicacion.setPreferredSize(new Dimension(200, 30)); // Tamaño preferido
        panel.add(comboUbicacion, gbc);

        // Botón para agregar el pedido
        gbc.gridy++;
        gbc.gridx = 0;
        gbc.gridwidth = 2;
        JButton botonAgregarPedido = new JButton("Agregar Pedido");
        botonAgregarPedido.setPreferredSize(new Dimension(200, 40)); // Tamaño del botón
        panel.add(botonAgregarPedido, gbc);

        // Acción del botón para enviar el pedido
        botonAgregarPedido.addActionListener(e -> {
            try {
                String nombreCliente = campoNombreCliente.getText().trim();

                // Validación del nombre
                if (nombreCliente.isEmpty()) {
                    throw new IllegalArgumentException("El nombre del cliente no puede estar vacío.");
                }

                String formaPago = comboFormaPago.getSelectedItem().toString();
                boolean esDelivery = comboUbicacion.getSelectedItem().equals("Delivery");

                // Crear el pedido
                gestorDePedidos.crearPedido(
                        nombreCliente,
                        formaPago,
                        esDelivery,
                        comboBurger.getSelectedItem(),
                        comboPapas.getSelectedItem(),
                        comboBebida.getSelectedItem()
                );

                ventanaColaPreparacion.actualizarColaPreparacion(); // Refrescar la cola
                JOptionPane.showMessageDialog(this, "Pedido agregado correctamente.");
            } catch (IllegalArgumentException ex) {
                JOptionPane.showMessageDialog(this, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, "Error inesperado: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        return panel;
    }
}
