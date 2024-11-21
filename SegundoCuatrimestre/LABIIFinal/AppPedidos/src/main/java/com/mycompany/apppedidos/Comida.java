/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.apppedidos;

public abstract class Comida {
    protected String nombre;

    public Comida(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }
}