#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "Recurso.hpp"
#include <string>

class Libro : public Recurso {  /*Esto es la herencia*/
private:
    std::string genero;
    int edicion;
    std::string autor;

public:
    Libro(const std::string& contenido, int id, const std::string& titulo, const std::string& genero, int edicion, const std::string& autor)
        : Recurso(contenido, id, titulo) {
            this->genero = genero;
            this->edicion = edicion;
            this->autor = autor;
        }

    // Implementación de toString para el libro
    std::string toString() const override {
        return "Libro - Titulo: " + getTitulo() + 
               ", ID: " + std::to_string(getId()) + 
               ", Contenido: " + getContenido() +
               ", Genero: " + getGenero() +
               ", Edicion: " + std::to_string(getEdicion()) + 
               ", Autor: " + getAutor();
    }

    std::string getGenero() const { return genero; }
    int getEdicion() const { return edicion; }
    std::string getAutor() const { return autor; }

    void setGenero(string genero){
        this->genero = genero;    /*Con la flecha puedes acceder al contenido*/
    }

    void setEdicion(int edicion){
        this->edicion = edicion;
    }

    void setAutor(string autor){
        this->autor = autor;
    }


};



#endif
