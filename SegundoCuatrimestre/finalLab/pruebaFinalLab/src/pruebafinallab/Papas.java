/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pruebafinallab;

public class Papas extends Comida {
    public enum Tamaño {CHICAS, MEDIANAS, GRANDES}
    private final Tamaño tamaño;

    public Papas(Tamaño tamaño) {
        super("Papas " + tamaño);
        this.tamaño = tamaño;
    }

    public Tamaño getTamaño() {
        return tamaño;
    }
}
