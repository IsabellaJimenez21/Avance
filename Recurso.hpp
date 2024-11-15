#ifndef RECURSO_HPP
#define RECURSO_HPP

using namespace std;

#include <string>

class Recurso {
protected:
    std::string contenido;
    int id;
    std::string titulo;

public:
    Recurso(const std::string& contenido, int id, const std::string& titulo)
        : contenido(contenido), id(id), titulo(titulo) {}

    std::string getContenido() const { return contenido; }
    int getId() const { return id; }
    std::string getTitulo() const { return titulo; }

    void setContenido(string contenido) {
        this->contenido = contenido;
    }

    void setId(int nuevoId) {
        this->id = nuevoId;
    }

    void setTitulo(string titulo) {
        this->contenido = titulo;
    }

    // Método virtual puro para obtener la información en formato de texto
    virtual std::string toString() const = 0;

    virtual ~Recurso() = default;
};

#endif
