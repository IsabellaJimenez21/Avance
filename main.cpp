#include "Biblioteca.hpp"
#include "Libro.hpp"
#include <iostream>

int main() {
    Biblioteca biblioteca;

    // Crear instancias de Libro y agregarlas a la biblioteca
    std::shared_ptr<Libro> libro1 = std::make_shared<Libro>("Contenido del Libro 1", 1, "Libro Uno");
    std::shared_ptr<Libro> libro2 = std::make_shared<Libro>("Contenido del Libro 2", 2, "Libro Dos");

    biblioteca.agregarRecurso(libro1);
    biblioteca.agregarRecurso(libro2);

    // Mostrar todos los recursos en la biblioteca desde el main
    std::cout << "Mostrando los recursos en la biblioteca:\n" << std::endl;
    for (const auto& recurso : biblioteca.obtenerRecursos()) {
        std::cout << recurso->toString() << std::endl;
    }

    return 0;
}
