#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Recurso.hpp"
#include "Libro.hpp"
#include "Revista.hpp"
#include <vector>
#include <iostream>

/**
 * @class Biblioteca
 * @brief Clase que representa una colección de recursos, como libros y revistas, en una biblioteca virtual.
 * 
 * La clase `Biblioteca` permite gestionar recursos de manera eficiente, incluyendo su
 * almacenamiento, búsqueda, eliminación, y filtrado por tipo.
 */
class Biblioteca {
private:
    std::vector<Libro> libros;
    std::vector<Revista> revistas;

public:
    /**
     * @brief Agrega un nuevo libro a la biblioteca.
     * 
     * @param libro Libro que se desea agregar.
     */
    void agregarLibro(Libro libro) {
        libros.push_back(libro);
    }

    /**
     * @brief Agrega una nueva revista a la biblioteca.
     * 
     * @param revista Revista que se desea agregar.
     */
    void agregarRevista(Revista revista) {
        revistas.push_back(revista);
    }

    /**
     * @brief Busca un libro por su ID.
     * 
     * @param id Identificador único del libro.
     */
    void imprimirLibroPorId(int id) {
        for (Libro libro : libros) {
            if (libro.getId() == id) {
                cout << libro.toString() << endl;
                return;
            }
        }
        cout << "No se encontro el libro" << endl;
    }

    /**
     * @brief Busca una revista por su ID.
     * 
     * @param id Identificador único de la revista.
     */
    void imprimirRevistaPorId(int id) {
        for (Revista revista : revistas) {
            if (revista.getId() == id) {
                cout << revista.toString() << endl;
                return;
            }
        }
        cout << "No se encontro la revista" << endl;
    }

    /**
     * @brief Obtiene la cantidad total de recursos en la biblioteca.
     * 
     * @return Número total de recursos.
     */
    int contarRecursos() {
        return libros.size() + revistas.size();
    }

    /**
     * @brief Cuenta la cantidad de libros en la biblioteca.
     * 
     * @return Número total de libros.
     */
    int contarLibros() {
        return libros.size();
    }

    /**
     * @brief Cuenta la cantidad de revistas en la biblioteca.
     * 
     * @return Número total de revistas.
     */
    int contarRevistas() {
        return revistas.size();
    }
    
    /**
     * @brief Obtiene todos los libros almacenados en la biblioteca.
     * 
     * @return Vector libros en la biblioteca.
     */
    std::vector<Libro> obtenerLibros() {
        return libros;
    }
    
    /**
     * @brief Obtiene todos los libros almacenados en la biblioteca.
     * 
     * @return Vector libros en la biblioteca.
     */
    std::vector<Revista> obtenerRevistas() {
        return revistas;
    }
};

#endif
