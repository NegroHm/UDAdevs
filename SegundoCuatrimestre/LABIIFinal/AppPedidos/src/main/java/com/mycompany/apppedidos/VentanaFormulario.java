package com.mycompany.apppedidos;

// Java Swing
// JPanel = Organizar los componenetes graficos como botones, etiquetas o campos de entrada y etc.
// JFrame = Es un tipo de ventana principal que contiene todos los elementos la interface grafica.
// JButton = Es un boton con una funcionalidad para que el usuario pueda agregar por ejemplo el pedido.
// JScrollPane = Nos permite hacer scroll en los componentes que no entren completos en la ventana.

import javax.swing.*; // Con el * estoy importando JFrame, JPanel, JButton, JLabel y etc, se hace esto para importar todas las clases del paquete
import java.awt.*; // Usamos la biblioteca esta para crear interfaces graficas de usuario
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
        // Aca se puede modificar el tamaño de la ventana
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JPanel panelFormulario = crearPanelFormulario();
        add(panelFormulario);
    }

    private JPanel crearPanelFormulario() {
        JPanel panel = new JPanel(new GridLayout(5, 2));

        JTextField campoNombreCliente = new JTextField(); // Aca se ingresa el nombre del pedido
        // Agregar nuevos pedidos 
            // Aca se usa el JComboBox para agregar el combo 
        JComboBox<String> comboPedido = new JComboBox<>(new String[]{"Burger + Papas", "2 Burgers + Papas Grandes", "Megadibu + Gaseosa", "Papas + Pancho + Gaseosa"});
        // Tipo de pega
        JComboBox<String> comboFormaPago = new JComboBox<>(new String[]{"Efectivo", "Transferencia", "Tarjeta Débito/Crédito"});
        // Envio o comer en el local
        JComboBox<String> comboUbicacion = new JComboBox<>(new String[]{"Delivery", "Come en el Local"});
        
        JButton botonAgregarPedido = new JButton("Agregar Pedido"); // Boton para agregar el pedido = JButton
        botonAgregarPedido.addActionListener(new ActionListener() { // Se agrega el pedido creando como un objeto Pedido y es agregado la colaé
            @Override 
            public void actionPerformed(ActionEvent e) {
                String nombreCliente = campoNombreCliente.getText();
                String formaPago = (String) comboFormaPago.getSelectedItem();
                boolean esDelivery = "Delivery".equals(comboUbicacion.getSelectedItem());

                // Crear un pedido y añadirlo a la cola
                Comida comida = new Burger(); // Puedes ajustar esto según la selección real
                Pedido nuevoPedido = new Pedido(nombreCliente, comida, formaPago, esDelivery);
                gestorDePedidos.agregarPedido(nuevoPedido);
 
                // Llama al método de instancia para actualizar la cola de preparación
                ventanaColaPreparacion.actualizarColaPreparacion();
            }
        });
        // El panel.add() su usa para agregar componente graficos
                      // Usamo el JLabel para mostrar etiquetas de texto
        panel.add(new JLabel("Nombre Cliente:"));
        panel.add(campoNombreCliente);
        panel.add(new JLabel("Pedido:"));
        panel.add(comboPedido);
        panel.add(new JLabel("Forma de Pago:"));
        panel.add(comboFormaPago);
        panel.add(new JLabel("Ubicación del Cliente:"));
        panel.add(comboUbicacion);
        panel.add(botonAgregarPedido);

        return panel;
    }
}
