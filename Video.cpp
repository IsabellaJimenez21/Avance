#include <iostream>  
#include <vector>    
#include <memory>    
#include <string>

class Video : public Recurso {
private:
    std::string titulo;
    int duracion;

public:
    Video(const std::string& titulo, int duracion)
        : titulo(titulo), duracion(duracion) {}

    // Getters
    std::string getTitulo() const { return titulo; }
    int getDuracion() const { return duracion; }

    // Setters
    void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
    void setDuracion(int nuevaDuracion) { duracion = nuevaDuracion; }

    void mostrarInformacion() const override {
        std::cout << "Video - Título: " << titulo
                  << ", Duración: " << duracion << " minutos" << std::endl;
    }
};
