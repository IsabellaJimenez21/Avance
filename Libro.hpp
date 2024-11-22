#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "Recurso.hpp"
#include <string>

/**
 * @class Libro
 * @brief Representa un libro como un recurso específico en el sistema.
 * 
 * La clase `Libro` hereda de la clase base abstracta `Recurso`.
 * Define atributos y métodos específicos para manejar información relevante a libros, 
 * como género, edición y autor.
 */
class Libro : public Recurso { 

private:
    std::string genero; ///< Género literario del libro (e.g., "Ficción", "Ciencia").
    int edicion;        ///< Número de edición del libro.
    std::string autor;  ///< Nombre del autor del libro.

public:
    /**
     * @brief Constructor parametrizado para inicializar un libro.
     * 
     * @param contenido Contenido del libro (texto descriptivo).
     * @param id Identificador único del libro.
     * @param titulo Título del libro.
     * @param genero Género literario del libro.
     * @param edicion Número de edición del libro.
     * @param autor Autor del libro.
     * 
     * @note Utiliza inicialización de lista para llamar al constructor de la clase base `Recurso`.
     */
    Libro(const std::string& contenido, int id, const std::string& titulo, const std::string& genero, int edicion, const std::string& autor)
        : Recurso(contenido, id, titulo) {
        this->genero = genero;
        this->edicion = edicion;
        this->autor = autor;
    }

    /**
     * @brief Genera una representación en cadena del libro.
     * 
     * @return Una cadena de texto que contiene los atributos del libro.
     * 
     * @details Este método sobrescribe la función virtual pura `toString()` de la clase base `Recurso`.
     */
    std::string toString() const override {
        return "Libro - Titulo: " + getTitulo() + 
               ", ID: " + std::to_string(getId()) + 
               ", Contenido: " + getContenido() +
               ", Genero: " + getGenero() +
               ", Edicion: " + std::to_string(getEdicion()) + 
               ", Autor: " + getAutor();
    }

    /**
     * @brief Obtiene el género literario del libro.
     * @return El género del libro.
     */
    std::string getGenero() const { return genero; }

    /**
     * @brief Obtiene el número de edición del libro.
     * @return La edición del libro.
     */
    int getEdicion() const { return edicion; }

    /**
     * @brief Obtiene el nombre del autor del libro.
     * @return El autor del libro.
     */
    std::string getAutor() const { return autor; }

    /**
     * @brief Establece el género del libro.
     * @param genero Nuevo género literario.
     */
    void setGenero(std::string genero) {
        this->genero = genero;  
    }

    /**
     * @brief Establece el número de edición del libro.
     * @param edicion Nuevo número de edición.
     */
    void setEdicion(int edicion) {
        this->edicion = edicion;
    }

    /**
     * @brief Establece el nombre del autor del libro.
     * @param autor Nuevo autor del libro.
     */
    void setAutor(std::string autor) {
        this->autor = autor;
    }
};

#endif
