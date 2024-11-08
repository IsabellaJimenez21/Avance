#include <iostream>
#include <vector>
#include <memory>

class Recurso {
public:
    virtual void mostrarInformacion() const = 0;
    virtual ~Recurso() = default;
};

class Libro : public Recurso {
private:
    std::string titulo;
    std::string autor;
    int numPaginas;

public:
    Libro(const std::string& titulo, const std::string& autor, int numPaginas)
        : titulo(titulo), autor(autor), numPaginas(numPaginas) {}

    void mostrarInformacion() const override {
        std::cout << "Libro - Título: " << titulo << ", Autor: " << autor
                  << ", Número de páginas: " << numPaginas << std::endl;
    }
};

class Revista : public Recurso {
private:
    std::string titulo;
    int numeroEdicion;

public:
    Revista(const std::string& titulo, int numeroEdicion)
        : titulo(titulo), numeroEdicion(numeroEdicion) {}

    void mostrarInformacion() const override {
        std::cout << "Revista - Título: " << titulo
                  << ", Número de edición: " << numeroEdicion << std::endl;
    }
};

class Video : public Recurso {
private:
    std::string titulo;
    int duracion;

public:
    Video(const std::string& titulo, int duracion)
        : titulo(titulo), duracion(duracion) {}

    void mostrarInformacion() const override {
        std::cout << "Video - Título: " << titulo
                  << ", Duración: " << duracion << " minutos" << std::endl;
    }
};

class Biblioteca {
private:
    std::vector<std::shared_ptr<Recurso>> recursos;

public:
    void agregarRecurso(const std::shared_ptr<Recurso>& recurso) {
        recursos.push_back(recurso);
    }

    void mostrarRecursos() const {
        std::cout << "Lista de recursos en la biblioteca digital:\n";
        for (const auto& recurso : recursos) {
            recurso->mostrarInformacion();
        }
    }
};

int main() {
    Biblioteca biblioteca;

    auto libro = std::make_shared<Libro>("Cien años de soledad", "Gabriel García Márquez", 417);
    auto revista = std::make_shared<Revista>("National Geographic", 202);
    auto video = std::make_shared<Video>("Documental del Universo", 90);

    biblioteca.agregarRecurso(libro);
    biblioteca.agregarRecurso(revista);
    biblioteca.agregarRecurso(video);

    std::cout << "Consultando información de cada recurso:\n";
    libro->mostrarInformacion();
    revista->mostrarInformacion();
    video->mostrarInformacion();

    std::cout << "\nMostrando todos los recursos en la biblioteca:\n";
    biblioteca.mostrarRecursos();

    return 0;
}
