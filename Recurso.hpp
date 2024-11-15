#ifndef RECURSO_HPP
#define RECURSO_HPP

#include <string>

class Recurso {
protected:
    const std::string contenido;
    const int id;
    const std::string titulo;

public:
    Recurso(const std::string& contenido, int id, const std::string& titulo)
        : contenido(contenido), id(id), titulo(titulo) {}

    std::string getContenido() const { return contenido; }
    int getId() const { return id; }
    std::string getTitulo() const { return titulo; }

    // Método virtual puro para obtener la información en formato de texto
    virtual std::string toString() const = 0;

    virtual ~Recurso() = default;
};

#endif
