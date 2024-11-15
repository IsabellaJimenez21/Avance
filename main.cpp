#include "Biblioteca.hpp"
#include "Libro.hpp"
#include "Revista.hpp"
#include <iostream>

int main() {
    Biblioteca biblioteca;

    // Crear instancias de Libro y Revista, y agregarlas a la biblioteca
    std::shared_ptr<Libro> libro1 = std::make_shared<Libro>("Contenido del Libro 1", 1, "Libro Uno");
    std::shared_ptr<Libro> libro2 = std::make_shared<Libro>("Contenido del Libro 2", 2, "Libro Dos");
    std::shared_ptr<Revista> revista1 = std::make_shared<Revista>("Contenido de la Revista 1", 3, "Revista Uno");
    std::shared_ptr<Revista> revista2 = std::make_shared<Revista>("Contenido de la Revista 2", 4, "Revista Dos");

    biblioteca.agregarRecurso(libro1);
    biblioteca.agregarRecurso(libro2);
    biblioteca.agregarRecurso(revista1);
    biblioteca.agregarRecurso(revista2);

    // Mostrar todos los recursos en la biblioteca
    std::cout << "Mostrando todos los recursos en la biblioteca:\n";
    for (const auto& recurso : biblioteca.obtenerRecursos()) {
        std::cout << recurso->toString() << std::endl;
    }

    // Buscar un recurso por ID
    int idBuscar = 2;
    std::cout << "\nBuscando el recurso con ID " << idBuscar << ":\n";
    std::shared_ptr<Recurso> recursoBuscado = biblioteca.buscarRecursoPorId(idBuscar);
    if (recursoBuscado) {
        std::cout << recursoBuscado->toString() << std::endl;
    } else {
        std::cout << "Recurso con ID " << idBuscar << " no encontrado.\n";
    }

    // Eliminar un recurso por ID
    int idEliminar = 3;
    std::cout << "\nEliminando el recurso con ID " << idEliminar << "...\n";
    if (biblioteca.eliminarRecursoPorId(idEliminar)) {
        std::cout << "Recurso eliminado exitosamente.\n";
    } else {
        std::cout << "No se encontró el recurso con ID " << idEliminar << " para eliminar.\n";
    }

    // Mostrar todos los recursos después de la eliminación
    std::cout << "\nMostrando todos los recursos después de la eliminación:\n";
    for (const auto& recurso : biblioteca.obtenerRecursos()) {
        std::cout << recurso->toString() << std::endl;
    }

    // Contar el total de recursos en la biblioteca
    std::cout << "\nTotal de recursos en la biblioteca: " << biblioteca.contarRecursos() << std::endl;

    // Contar solo libros y solo revistas
    std::cout << "Total de libros en la biblioteca: " << biblioteca.contarLibros() << std::endl;
    std::cout << "Total de revistas en la biblioteca: " << biblioteca.contarRevistas() << std::endl;

    // Obtener y mostrar solo los libros
    std::cout << "\nMostrando solo los libros en la biblioteca:\n";
    for (const auto& libro : biblioteca.obtenerLibros()) {
        std::cout << libro->toString() << std::endl;
    }

    // Obtener y mostrar solo las revistas
    std::cout << "\nMostrando solo las revistas en la biblioteca:\n";
    for (const auto& revista : biblioteca.obtenerRevistas()) {
        std::cout << revista->toString() << std::endl;
    }

    return 0;
}
