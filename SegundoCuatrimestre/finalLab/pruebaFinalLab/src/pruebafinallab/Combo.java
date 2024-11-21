package pruebafinallab;

/**
 *
 * @author engrohm
 */
import java.util.ArrayList;
import java.util.List;

public class Combo extends Comida {
    private final List<Comida> items;

    public Combo(String nombre) {
        super(nombre);
        this.items = new ArrayList<>();
    }

    // Método para agregar un item al combo
    public void agregarItem(Comida comida) {
        items.add(comida);
    }

    // Obtener la lista de items en el combo
    public List<Comida> getItems() {
        return items;
    }

    @Override
    public String getNombre() {
        StringBuilder descripcion = new StringBuilder(nombre + ": ");
        for (Comida item : items) {
            descripcion.append(item.getNombre()).append(", ");
        }
        // Elimina la última coma y espacio
        if (!items.isEmpty()) {
            descripcion.setLength(descripcion.length() - 2);
        }
        return descripcion.toString();
    }
}
