#ifndef REVISTA_HPP
#define REVISTA_HPP

#include "Recurso.hpp"
#include <string>

/**
 * @class Revista
 * @brief Representa una revista como un recurso específico en el sistema.
 * 
 * La clase `Revista` hereda de la clase base abstracta `Recurso`. 
 * Define atributos y métodos específicos para manejar información relevante a revistas, 
 * como periodicidad, número de ejemplar y tema principal.
 */
class Revista : public Recurso {

private:
    std::string periodicidad; ///< Periodicidad de la revista (mensual, semanal, etc.).
    int numEjemplar;          ///< Número del ejemplar de la revista.
    std::string tema;         ///< Tema principal de la revista.

public:
    /**
     * @brief Constructor para inicializar una revista.
     * 
     * @param contenido Contenido de la revista (texto descriptivo).
     * @param id Identificador único de la revista.
     * @param titulo Título de la revista.
     * @param periodicidad Frecuencia de publicación (e.g., "mensual").
     * @param numEjemplar Número de edición o ejemplar.
     * @param tema Tema principal de la revista.
     * 
     * @note Utiliza inicialización de lista para llamar al constructor de la clase base `Recurso`.
     */
    Revista(std::string contenido, int id, std::string titulo, std::string periodicidad, int numEjemplar, std::string tema)
        : Recurso(contenido, id, titulo) {
        this->periodicidad = periodicidad;
        this->numEjemplar = numEjemplar;
        this->tema = tema;
    }

    /**
     * @brief Genera una representación en cadena de la revista.
     * 
     * @return Una cadena de texto que contiene los atributos de la revista.
     * 
     * @details Este método sobrescribe la función virtual pura `toString()` de la clase base `Recurso`.
     */
    std::string toString() {
        return "Revista - Titulo: " + getTitulo() + 
               ", ID: " + std::to_string(getId()) + 
               ", Contenido: " + getContenido() + 
               ", Periodicidad: " + getPeriodicidad() + 
               ", Numero del Ejemplar: " + std::to_string(getEjemplar()) +
               ", Tema principal: " + getTema();
    }

    /**
     * @brief Obtiene la periodicidad de la revista.
     * @return La periodicidad de la revista.
     */
    std::string getPeriodicidad() { 
        return periodicidad; 
    }

    /**
     * @brief Obtiene el número del ejemplar de la revista.
     * @return El número del ejemplar.
     */
    int getEjemplar() { 
        return numEjemplar; 
    }

    /**
     * @brief Obtiene el tema principal de la revista.
     * @return El tema principal.
     */
    std::string getTema() { 
        return tema; 
    }

    /**
     * @brief Establece la periodicidad de la revista.
     * @param periodicidad Nueva periodicidad.
     */
    void setPeriodicidad(std::string periodicidad) {
        this->periodicidad = periodicidad; 
    }

    /**
     * @brief Establece el número del ejemplar de la revista.
     * @param numEjemplar Nuevo número del ejemplar.
     */
    void setEjemplar(int numEjemplar) {
        this->numEjemplar = numEjemplar; 
    }

    /**
     * @brief Establece el tema principal de la revista.
     * @param tema Nuevo tema principal.
     */
    void setTema(std::string tema) {
        this->tema = tema; 
    }
};

#endif
