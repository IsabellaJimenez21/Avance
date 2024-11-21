#include "Biblioteca.hpp"
#include "Libro.hpp"
#include "Revista.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <limits>

class Interfaz {
private:
    Biblioteca biblioteca;

    void mostrarMenu() {
        std::cout << "\n=== Biblioteca Virtual ===\n";
        std::cout << "1. Mostrar todos los recursos\n";
        std::cout << "2. Buscar recurso por ID\n";
        std::cout << "3. Eliminar recurso por ID\n";
        std::cout << "4. Contar recursos\n";
        std::cout << "5. Crear nuevo libro\n";
        std::cout << "6. Crear nueva revista\n";
        std::cout << "7. Mostrar solo libros\n";
        std::cout << "8. Mostrar solo revistas\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
    }

    void limpiarInput() {
        std::cin.clear(); // Limpia los errores en el stream
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta el resto de la entrada
    }

    void crearLibro() {
        std::string contenido, titulo, genero, autor;
        int id, paginas;

        std::cout << "Ingrese el contenido del libro: ";
        std::cin.ignore();
        std::getline(std::cin, contenido);
        std::cout << "Ingrese el ID del libro: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Ingrese el titulo del libro: ";
        std::getline(std::cin, titulo);
        std::cout << "Ingrese el genero del libro: ";
        std::getline(std::cin, genero);
        std::cout << "Ingrese la cantidad de paginas del libro: ";
        std::cin >> paginas;
        std::cin.ignore();
        std::cout << "Ingrese el autor del libro: ";
        std::getline(std::cin, autor);

        auto libro = std::make_shared<Libro>(contenido, id, titulo, genero, paginas, autor);
        biblioteca.agregarRecurso(libro);
        std::cout << "Libro agregado exitosamente!\n";
    }

    void crearRevista() {
        std::string contenido, titulo, periodicidad, tema;
        int id, paginas;

        std::cout << "Ingrese el contenido de la revista: ";
        std::cin.ignore();
        std::getline(std::cin, contenido);
        std::cout << "Ingrese el ID de la revista: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Ingrese el titulo de la revista: ";
        std::getline(std::cin, titulo);
        std::cout << "Ingrese la periodicidad de la revista: ";
        std::getline(std::cin, periodicidad);
        std::cout << "Ingrese la cantidad de paginas de la revista: ";
        std::cin >> paginas;
        std::cin.ignore();
        std::cout << "Ingrese el tema de la revista: ";
        std::getline(std::cin, tema);

        auto revista = std::make_shared<Revista>(contenido, id, titulo, periodicidad, paginas, tema);
        biblioteca.agregarRecurso(revista);
        std::cout << "Revista agregada exitosamente!\n";
    }

public:
    void ejecutar() {
        int opcion;

        do {
            mostrarMenu();
            std::cin >> opcion;

            if (std::cin.fail()) { // Si el usuario ingresa algo invalido
                limpiarInput();
                std::cout << "Por favor, selecciona una opcion valida.\n";
                continue; // Reinicia el bucle correctamente
            }

            switch (opcion) {
                case 1:
                    for (const auto& recurso : biblioteca.obtenerRecursos()) {
                        std::cout << recurso->toString() << std::endl;
                    }
                    break;
                case 2: {
                    int id;
                    std::cout << "Ingrese el ID del recurso a buscar: ";
                    std::cin >> id;
                    auto recurso = biblioteca.buscarRecursoPorId(id);
                    if (recurso) {
                        std::cout << recurso->toString() << std::endl;
                    } else {
                        std::cout << "Recurso no encontrado.\n";
                    }
                    break;
                }
                case 3: {
                    int id;
                    std::cout << "Ingrese el ID del recurso a eliminar: ";
                    std::cin >> id;
                    if (biblioteca.eliminarRecursoPorId(id)) {
                        std::cout << "Recurso eliminado exitosamente.\n";
                    } else {
                        std::cout << "Recurso no encontrado.\n";
                    }
                    break;
                }
                case 4:
                    std::cout << "Total de recursos: " << biblioteca.contarRecursos() << std::endl;
                    break;
                case 5:
                    crearLibro();
                    break;
                case 6:
                    crearRevista();
                    break;
                case 7:
                    for (const auto& libro : biblioteca.obtenerLibros()) {
                        std::cout << libro->toString() << std::endl;
                    }
                    break;
                case 8:
                    for (const auto& revista : biblioteca.obtenerRevistas()) {
                        std::cout << revista->toString() << std::endl;
                    }
                    break;
                case 0:
                    std::cout << "Salida exitosa\n";
                    break;
                default:
                    std::cout << "Opcion invalida. Intente de nuevo.\n";
                    break;
            }
        } while (opcion != 0);
    }
};

