#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Recurso.hpp"
#include <vector>
#include <memory>

class Biblioteca {
private:
    std::vector<std::shared_ptr<Recurso>> recursos;

public:
    void agregarRecurso(const std::shared_ptr<Recurso>& recurso) {
        recursos.push_back(recurso);
    }

    std::vector<std::shared_ptr<Recurso>> obtenerRecursos() const {
        return recursos;
    }
};

#endif
