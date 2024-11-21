/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.apppedidos;

public class Pedido extends Comida {
    private static int contador = 0;
    private final int numPedido;
    private final String nombreCliente;
    private final String formaPago;
    private final boolean esDelivery;
    private Estado estado;

    public enum Estado {
        PREPARACION, PAUSADO, TERMINADO
    }

    public Pedido(String nombreCliente, Comida comida, String formaPago, boolean esDelivery) {
        super(comida.getNombre());
        this.numPedido = ++contador;
        this.nombreCliente = nombreCliente;
        this.formaPago = formaPago;
        this.esDelivery = esDelivery;
        this.estado = Estado.PREPARACION;
    }

    public int getNumPedido() {
        return numPedido;
    }

    public Estado getEstado() {
        return estado;
    }

    public void setEstado(Estado estado) {
        this.estado = estado;
    }

    public String getNombreCliente() {
        return nombreCliente;
    }
}
