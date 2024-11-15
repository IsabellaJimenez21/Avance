#ifndef REVISTA_HPP
#define REVISTA_HPP

#include "Recurso.hpp"
#include <string>

class Revista : public Recurso {
public:
    Revista(const std::string& contenido, int id, const std::string& titulo)
        : Recurso(contenido, id, titulo) {}

    // Implementación de toString para el libro
    std::string toString() const override {
        return "Libro - Título: " + getTitulo() + 
               ", ID: " + std::to_string(getId()) + 
               ", Contenido: " + getContenido();
    }
};

#endif
