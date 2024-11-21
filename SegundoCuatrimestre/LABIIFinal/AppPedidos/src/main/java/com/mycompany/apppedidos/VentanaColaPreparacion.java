    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.apppedidos;

import javax.swing.*;
import java.awt.*;

public class VentanaColaPreparacion extends JFrame {
    private JPanel panelColaPreparacion;
    private final GestorDePedidos gestorDePedidos;

    public VentanaColaPreparacion(GestorDePedidos gestorDePedidos) {
        this.gestorDePedidos = gestorDePedidos;
        inicializarUI();
    }

    private void inicializarUI() {
        setTitle("Cola de Preparación");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        panelColaPreparacion = new JPanel();
        panelColaPreparacion.setLayout(new BoxLayout(panelColaPreparacion, BoxLayout.Y_AXIS));
        JScrollPane scrollPane = new JScrollPane(panelColaPreparacion);
        add(scrollPane);
    }

    public void actualizarColaPreparacion() {
        panelColaPreparacion.removeAll();

        for (Pedido pedido : gestorDePedidos.getColaPedidos()) {
            JPanel panelPedido = crearPanelPedido(pedido);
            panelColaPreparacion.add(panelPedido);
        }

        panelColaPreparacion.revalidate();
        panelColaPreparacion.repaint();
    }

    private JPanel crearPanelPedido(Pedido pedido) {
        JPanel panelPedido = new JPanel(new BorderLayout());
        panelPedido.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        setColorPorEstado(panelPedido, pedido.getEstado());

        JLabel labelPedido = new JLabel("Pedido " + pedido.getNumPedido() + ": " + pedido.getNombre());
        JComboBox<Pedido.Estado> comboEstado = new JComboBox<>(Pedido.Estado.values());
        comboEstado.setSelectedItem(pedido.getEstado());
        comboEstado.addActionListener(e -> {
            Pedido.Estado nuevoEstado = (Pedido.Estado) comboEstado.getSelectedItem();
            pedido.setEstado(nuevoEstado);
            setColorPorEstado(panelPedido, nuevoEstado);
            panelColaPreparacion.revalidate();
            panelColaPreparacion.repaint();
        });

        panelPedido.add(labelPedido, BorderLayout.CENTER);
        panelPedido.add(comboEstado, BorderLayout.SOUTH);

        return panelPedido;
    }

    private void setColorPorEstado(JPanel panel, Pedido.Estado estado) {
        switch (estado) {
            case PREPARACION -> panel.setBackground(Color.YELLOW);
            case PAUSADO -> panel.setBackground(Color.RED);
            case TERMINADO -> panel.setBackground(Color.GREEN);
        }
    }
}
