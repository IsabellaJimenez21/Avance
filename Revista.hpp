#ifndef REVISTA_HPP
#define REVISTA_HPP

#include "Recurso.hpp"
#include <string>

class Revista : public Recurso {

private:
    std::string periodicidad;
    int numEjemplar;
    std::string tema;

public:
    Revista(const std::string& contenido, int id, const std::string& titulo, const std::string& periodicidad, int numEjemplar, const std::string& tema) /* & es una referencia, si cambia afuera tambein lo cambia adentro*/
        : Recurso(contenido, id, titulo) {
            this->periodicidad = periodicidad;
            this->numEjemplar = numEjemplar;
            this->tema = tema;
        } 

    // Implementación de toString para el libro
    std::string toString() const override {
        return "Revista - Titulo: " + getTitulo() + 
               ", ID: " + std::to_string(getId()) + 
               ", Contenido: " + getContenido() + 
               ", Periodicidad: " + getPeriodicidad() + 
               ", Numero del Ejemplar: " + std::to_string(getEjemplar()) +
               ", Tema principal: " + getTema();
    }

    std::string getPeriodicidad() const { return periodicidad; }
    int getEjemplar() const { return numEjemplar; }
    std::string getTema() const { return tema; }

    void setPeriodicidad(string periodicidad) {
        this->periodicidad = periodicidad; 
    }

    void setEjemplar(int numEjemplar) {
        this->numEjemplar = numEjemplar; 
    }

    void setTema(string tema) {
        this->tema = tema; 
    }

};


#endif
