#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Recurso.hpp"
#include "Libro.hpp"
#include "Revista.hpp"
#include <vector>
#include <memory>
#include <algorithm>

/**
 * @class Biblioteca
 * @brief Clase que representa una colección de recursos, como libros y revistas, en una biblioteca virtual.
 * 
 * La clase `Biblioteca` permite gestionar recursos de manera eficiente, incluyendo su
 * almacenamiento, búsqueda, eliminación, y filtrado por tipo.
 */
class Biblioteca {
private:
    std::vector<std::shared_ptr<Recurso>> recursos; ///< Contenedor que almacena los recursos de la biblioteca.

public:
    /**
     * @brief Agrega un nuevo recurso a la biblioteca.
     * 
     * El recurso solo se agrega si su ID no existe previamente en la colección.
     * 
     * @param recurso Puntero compartido al recurso que se desea agregar.
     */
    void agregarRecurso(const std::shared_ptr<Recurso>& recurso) {
        if (buscarRecursoPorId(recurso->getId()) == nullptr) {
            recursos.push_back(recurso);
        }
    }

    /**
     * @brief Busca un recurso por su ID.
     * 
     * @param id Identificador único del recurso.
     * @return Un puntero compartido al recurso si se encuentra, o nullptr si no existe.
     */
    std::shared_ptr<Recurso> buscarRecursoPorId(int id) const {
        for (const auto& recurso : recursos) {
            if (recurso->getId() == id) {
                return recurso;
            }
        }
        return nullptr;
    }

    /**
     * @brief Elimina un recurso por su ID.
     * 
     * @param id Identificador único del recurso a eliminar.
     * @return `true` si el recurso fue eliminado exitosamente, `false` si no se encontró.
     */
    bool eliminarRecursoPorId(int id) {
        auto it = std::remove_if(recursos.begin(), recursos.end(),
                                 [id](const std::shared_ptr<Recurso>& recurso) {
                                     return recurso->getId() == id;
                                 });
        if (it != recursos.end()) {
            recursos.erase(it, recursos.end());
            return true;
        }
        return false;
    }

    /**
     * @brief Obtiene la cantidad total de recursos en la biblioteca.
     * 
     * @return Número total de recursos.
     */
    int contarRecursos() const {
        return recursos.size();
    }

    /**
     * @brief Cuenta la cantidad de libros en la biblioteca.
     * 
     * @return Número total de libros.
     */
    int contarLibros() const {
        int count = 0;
        for (const auto& recurso : recursos) {
            if (std::dynamic_pointer_cast<Libro>(recurso)) {
                count++;
            }
        }
        return count;
    }

    /**
     * @brief Cuenta la cantidad de revistas en la biblioteca.
     * 
     * @return Número total de revistas.
     */
    int contarRevistas() const {
        int count = 0;
        for (const auto& recurso : recursos) {
            if (std::dynamic_pointer_cast<Revista>(recurso)) {
                count++;
            }
        }
        return count;
    }

    /**
     * @brief Obtiene todos los libros en la biblioteca.
     * 
     * @return Vector de punteros compartidos a los libros.
     */
    std::vector<std::shared_ptr<Recurso>> obtenerLibros() const {
        std::vector<std::shared_ptr<Recurso>> libros;
        for (const auto& recurso : recursos) {
            if (std::dynamic_pointer_cast<Libro>(recurso)) {
                libros.push_back(recurso);
            }
        }
        return libros;
    }

    /**
     * @brief Obtiene todas las revistas en la biblioteca.
     * 
     * @return Vector de punteros compartidos a las revistas.
     */
    std::vector<std::shared_ptr<Recurso>> obtenerRevistas() const {
        std::vector<std::shared_ptr<Recurso>> revistas;
        for (const auto& recurso : recursos) {
            if (std::dynamic_pointer_cast<Revista>(recurso)) {
                revistas.push_back(recurso);
            }
        }
        return revistas;
    }

    /**
     * @brief Obtiene todos los recursos almacenados en la biblioteca.
     * 
     * @return Vector de punteros compartidos a los recursos.
     */
    std::vector<std::shared_ptr<Recurso>> obtenerRecursos() const {
        return recursos;
    }
};

#endif
