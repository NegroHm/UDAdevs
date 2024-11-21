package pruebafinallab;

// Java Swing
// JPanel = Organizar los componenetes graficos como botones, etiquetas o campos de entrada y etc.
// JFrame = Es un tipo de ventana principal que contiene todos los elementos la interface grafica.
// JButton = Es un boton con una funcionalidad para que el usuario pueda agregar por ejemplo el pedido.
// JScrollPane = Nos permite hacer scroll en los componentes que no entren completos en la ventana.

import javax.swing.*;// Con el * estoy importando JFrame, JPanel, JButton, JLabel y etc, se hace esto para importar todas las clases del paquete
import java.awt.*;// Usamos la biblioteca esta para crear interfaces graficas de usuario
                  // Con el * nos evitamos importar todas estas clases FlowLayout, GridLayout, BorderLayout y etc.
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class VentanaFormulario extends JFrame {
    private final GestorDePedidos gestorDePedidos;
    private final VentanaColaPreparacion ventanaColaPreparacion;

    public VentanaFormulario(GestorDePedidos gestorDePedidos, VentanaColaPreparacion ventanaColaPreparacion) {
        this.gestorDePedidos = gestorDePedidos;
        this.ventanaColaPreparacion = ventanaColaPreparacion;
        inicializarUI();
    }

    private void inicializarUI() {
        setTitle("Formulario de Pedido");
        setSize(350, 350);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        JPanel panelFormulario = crearPanelFormulario();
        add(panelFormulario);
    }

    private JPanel crearPanelFormulario() {
    JPanel panel = new JPanel(new GridBagLayout());

    // Cambiar el color de fondo del JPanel
    panel.setBackground(Color.LIGHT_GRAY); // Cambia a cualquier color que desees

    GridBagConstraints gbc = new GridBagConstraints();
    gbc.insets = new Insets(5, 5, 5, 5); // Espaciado entre los componentes
    gbc.fill = GridBagConstraints.HORIZONTAL;

    // Campo Nombre Cliente
    gbc.gridx = 0;
    gbc.gridy = 0;
    panel.add(new JLabel("Nombre Cliente:"), gbc);
    gbc.gridx = 1;
    gbc.gridy = 0;
    JTextField campoNombreCliente = new JTextField();
    panel.add(campoNombreCliente, gbc);

    // Campo Pedido (Hamburguesa)
    gbc.gridx = 0;
    gbc.gridy = 1;
    panel.add(new JLabel("Pedido (Hamburguesa):"), gbc);
    gbc.gridx = 1;
    gbc.gridy = 1;
    JComboBox<Burger.Tamaño> comboBurger = new JComboBox<>(Burger.Tamaño.values());
    panel.add(comboBurger, gbc);

    // Campo Acompañamiento (Papas)
    gbc.gridx = 0;
    gbc.gridy = 2;
    panel.add(new JLabel("Acompañamiento (Papas):"), gbc);
    gbc.gridx = 1;
    gbc.gridy = 2;
    JComboBox<Papas.Tamaño> comboPapas = new JComboBox<>(Papas.Tamaño.values());
    panel.add(comboPapas, gbc);

    // Campo Bebida
    gbc.gridx = 0;
    gbc.gridy = 3;
    panel.add(new JLabel("Bebida:"), gbc);
    gbc.gridx = 1;
    gbc.gridy = 3;
    JComboBox<Bebida.Tipo> comboBebida = new JComboBox<>(Bebida.Tipo.values());
    panel.add(comboBebida, gbc);

    // Campo Forma de Pago
    gbc.gridx = 0;
    gbc.gridy = 4;
    panel.add(new JLabel("Forma de Pago:"), gbc);
    gbc.gridx = 1;
    gbc.gridy = 4;
    JComboBox<String> comboFormaPago = new JComboBox<>(new String[]{"Efectivo", "Transferencia", "Tarjeta Débito/Crédito"});
    panel.add(comboFormaPago, gbc);

    // Campo Ubicación del Cliente
    gbc.gridx = 0;
    gbc.gridy = 5;
    panel.add(new JLabel("Ubicación del Cliente:"), gbc);
    gbc.gridx = 1;
    gbc.gridy = 5;
    JComboBox<String> comboUbicacion = new JComboBox<>(new String[]{"Delivery", "Come en el Local"});
    panel.add(comboUbicacion, gbc);

    // Botón Agregar Pedido
    gbc.gridx = 0;
    gbc.gridy = 6;
    gbc.gridwidth = 2;
    JButton botonAgregarPedido = new JButton("Agregar Pedido");
    panel.add(botonAgregarPedido, gbc);

    // Acción del botón
    // Acción del botón
    botonAgregarPedido.addActionListener(new ActionListener() {
    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            String nombreCliente = campoNombreCliente.getText();
            if (nombreCliente.isEmpty()) {
                throw new IllegalArgumentException("El nombre del cliente no puede estar vacío.");
            }
            String formaPago = (String) comboFormaPago.getSelectedItem();
            boolean esDelivery = "Delivery".equals(comboUbicacion.getSelectedItem());

            // Crear los objetos Comida según la selección del usuario
            Burger burger = new Burger((Burger.Tamaño) comboBurger.getSelectedItem());
            Papas papas = new Papas((Papas.Tamaño) comboPapas.getSelectedItem());
            Bebida bebida = new Bebida((Bebida.Tipo) comboBebida.getSelectedItem());

            // Crear un Combo con los items seleccionados
            Combo combo = new Combo("Combo");
            combo.agregarItem(burger);
            combo.agregarItem(papas);
            combo.agregarItem(bebida);

            // Crear el pedido con el combo
            Pedido nuevoPedido = new Pedido(nombreCliente, combo, formaPago, esDelivery);
            gestorDePedidos.agregarPedido(nuevoPedido);

            // Actualizar la cola de preparación
            ventanaColaPreparacion.actualizarColaPreparacion();
        } catch (IllegalArgumentException ex) {
            JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "Ocurrió un error inesperado: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
});

    return panel;
}
}
