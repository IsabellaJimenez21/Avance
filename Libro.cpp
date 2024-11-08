#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Libro : public Recurso {
private:
    std::string titulo;
    std::string autor;
    int numPaginas;

public:
    Libro(const std::string& titulo, const std::string& autor, int numPaginas)
        : titulo(titulo), autor(autor), numPaginas(numPaginas) {}

    // Getters
    std::string getTitulo() const { return titulo; }
    std::string getAutor() const { return autor; }
    int getNumPaginas() const { return numPaginas; }

    // Setters
    void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
    void setAutor(const std::string& nuevoAutor) { autor = nuevoAutor; }
    void setNumPaginas(int nuevoNumPaginas) { numPaginas = nuevoNumPaginas; }

    void mostrarInformacion() const override {
        std::cout << "Libro - Título: " << titulo << ", Autor: " << autor
                  << ", Número de páginas: " << numPaginas << std::endl;
    }
};
