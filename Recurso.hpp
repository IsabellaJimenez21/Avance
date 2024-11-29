#ifndef RECURSO_HPP
#define RECURSO_HPP

using namespace std;

#include <string>

/**
 * @class Recurso
 * @brief Clase abstracta que representa un recurso genérico en el sistema.
 * 
 * La clase `Recurso` define los atributos y métodos comunes a todos los recursos
 * que se pueden almacenar en la biblioteca, como libros, revistas, etc.
 */
class Recurso {
protected:
    std::string contenido; ///< Contenido del recurso (texto descriptivo).
    int id; ///< Identificador único del recurso.
    std::string titulo; ///< Título del recurso.

public:
    /**
     * @brief Constructor para inicializar un recurso.
     * 
     * @param contenido Contenido del recurso (texto descriptivo).
     * @param id Identificador único del recurso.
     * @param titulo Título del recurso.
     */
    Recurso(std::string contenido, int id, std::string titulo)
        : contenido(contenido), id(id), titulo(titulo) {}

    /**
     * @brief Obtiene el contenido del recurso.
     * @return El contenido del recurso.
     */
    std::string getContenido() { 
        return contenido; 
    }
    
    /**
     * @brief Obtiene el ID del recurso.
     * @return El ID del recurso.
     */
    int getId() { 
        return id; 
    }

    /**
     * @brief Obtiene el título del recurso.
     * @return El título del recurso.
     */
    std::string getTitulo() { 
        return titulo; 
    }

    /**
     * @brief Establece el contenido del recurso.
     * @param contenido El contenido del recurso.
     */
    void setContenido(string contenido) {
        this->contenido = contenido;
    }

    /**
     * @brief Establece el ID del recurso.
     * @param id El ID del recurso.
     */
    void setId(int nuevoId) {
        this->id = nuevoId;
    }

    /**
     * @brief Establece el título del recurso.
     * @param titulo El título del recurso.
     */
    void setTitulo(string titulo) {
        this->contenido = titulo;
    }
};

#endif
