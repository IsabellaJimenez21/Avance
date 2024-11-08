#include <iostream>  
#include <vector>    
#include <memory>  
#include <string>

class Revista : public Recurso {
private:
    std::string titulo;
    int numeroEdicion;

public:
    Revista(const std::string& titulo, int numeroEdicion)
        : titulo(titulo), numeroEdicion(numeroEdicion) {}

    // Getters
    std::string getTitulo() const { return titulo; }
    int getNumeroEdicion() const { return numeroEdicion; }

    // Setters
    void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
    void setNumeroEdicion(int nuevoNumeroEdicion) { numeroEdicion = nuevoNumeroEdicion; }

    void mostrarInformacion() const override {
        std::cout << "Revista - Título: " << titulo
                  << ", Número de edición: " << numeroEdicion << std::endl;
    }
};
