#include "Biblioteca.hpp"
#include "Libro.hpp"
#include "Revista.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <limits>

/**
 * @class Interfaz
 * @brief Controla la interacción entre el usuario y el sistema de biblioteca virtual.
 * 
 * La clase `Interfaz` gestiona el flujo principal del programa, mostrando menús y manejando
 * las opciones seleccionadas por el usuario. Permite crear, buscar, eliminar y listar recursos
 * como libros y revistas.
 */
class Interfaz {

private:
    Biblioteca biblioteca; ///< Instancia de la clase Biblioteca que contiene los recursos.

    /**
     * @brief Muestra el menú principal al usuario.
     * 
     * Proporciona opciones para interactuar con los recursos de la biblioteca, como crear,
     * buscar, eliminar, y listar libros y revistas.
     */
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

    /**
     * @brief Limpia el flujo de entrada para manejar errores de entrada del usuario.
     * 
     * Este método se utiliza para descartar entradas inválidas y limpiar errores en el
     * flujo estándar `std::cin`, garantizando un funcionamiento correcto.
     */
    void limpiarInput() {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    /**
     * @brief Permite al usuario crear y agregar un nuevo libro a la biblioteca.
     * 
     * Solicita al usuario información sobre el contenido, ID, título, género, número de
     * páginas y autor del libro. Después, lo agrega a la biblioteca.
     */
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

    /**
     * @brief Permite al usuario crear y agregar una nueva revista a la biblioteca.
     * 
     * Solicita al usuario información sobre el contenido, ID, título, periodicidad,
     * número de páginas y tema de la revista. Luego, lo agrega a la biblioteca.
     */
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
    /**
     * @brief Inicia la ejecución de la interfaz.
     * 
     * Muestra el menú principal en un bucle y permite al usuario seleccionar
     * y ejecutar diversas opciones. Se detiene cuando el usuario selecciona la opción de salida.
     */
    void ejecutar() {
        int opcion;

        do {
            mostrarMenu();
            std::cin >> opcion;

            if (std::cin.fail()) { 
                limpiarInput();
                std::cout << "Por favor, selecciona una opcion valida.\n";
                continue; 
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
