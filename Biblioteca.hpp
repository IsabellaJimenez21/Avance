#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Recurso.hpp"
#include "Libro.hpp"
#include "Revista.hpp"
#include <vector>
#include <memory>
#include <algorithm>

class Biblioteca {
private:
    std::vector<std::shared_ptr<Recurso>> recursos;

public:
    // Agrega un recurso a la biblioteca
    void agregarRecurso(const std::shared_ptr<Recurso>& recurso) {
        recursos.push_back(recurso);
    }

    // Buscar recurso por ID
    std::shared_ptr<Recurso> buscarRecursoPorId(int id) const {
        for (const auto& recurso : recursos) {
            if (recurso->getId() == id) {
                return recurso;
            }
        }
        return nullptr; // Retorna nullptr si no se encuentra
    }

    // Eliminar recurso por ID
    bool eliminarRecursoPorId(int id) {
        auto it = std::remove_if(recursos.begin(), recursos.end(),
                                 [id](const std::shared_ptr<Recurso>& recurso) {
                                     return recurso->getId() == id;
                                 });
        if (it != recursos.end()) {
            recursos.erase(it, recursos.end());
            return true; // Recurso eliminado exitosamente
        }
        return false; // No se encontró el recurso
    }

    // Contar todos los recursos
    int contarRecursos() const {
        return recursos.size();
    }

    // Contar solo libros
    int contarLibros() const {
        int count = 0;
        for (const auto& recurso : recursos) {
            if (std::dynamic_pointer_cast<Libro>(recurso)) {
                count++;
            }
        }
        return count;
    }

    // Contar solo revistas
    int contarRevistas() const {
        int count = 0;
        for (const auto& recurso : recursos) {
            if (std::dynamic_pointer_cast<Revista>(recurso)) {
                count++;
            }
        }
        return count;
    }

    // Obtener solo libros
    std::vector<std::shared_ptr<Recurso>> obtenerLibros() const {
        std::vector<std::shared_ptr<Recurso>> libros;
        for (const auto& recurso : recursos) {
            if (std::dynamic_pointer_cast<Libro>(recurso)) {
                libros.push_back(recurso);
            }
        }
        return libros;
    }

    // Obtener solo revistas
    std::vector<std::shared_ptr<Recurso>> obtenerRevistas() const {
        std::vector<std::shared_ptr<Recurso>> revistas;
        for (const auto& recurso : recursos) {
            if (std::dynamic_pointer_cast<Revista>(recurso)) {
                revistas.push_back(recurso);
            }
        }
        return revistas;
    }

    std::vector<std::shared_ptr<Recurso>> obtenerRecursos() const {
        return recursos;
    }
};

#endif
