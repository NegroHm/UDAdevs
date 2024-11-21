/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.apppedidos;

import java.util.LinkedList;
import java.util.Queue;

public class GestorDePedidos {
    private final Queue<Pedido> colaPedidos;

    public GestorDePedidos() {
        colaPedidos = new LinkedList<>();
    }

    public void agregarPedido(Pedido pedido) {
        colaPedidos.add(pedido);
    }

    public Queue<Pedido> getColaPedidos() {
        return colaPedidos;
    }
}
