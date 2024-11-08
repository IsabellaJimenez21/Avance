#include <libro.h>
#include <revista.h>
#include <video.h>

int main() {
    Biblioteca biblioteca;

    auto libro = std::make_shared<Libro>("Cien años de soledad", "Gabriel García Márquez", 417);
    auto revista = std::make_shared<Revista>("National Geographic", 202);
    auto video = std::make_shared<Video>("Documental del Universo", 90);

    // Usando setters para actualizar la información de los recursos
    libro->setTitulo("El amor en los tiempos del cólera");
    video->setDuracion(95);

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
