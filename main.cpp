#include "Interfaz.hpp"
#include <iostream>

/**
 * @brief Punto de entrada principal del programa.
 * @return Devuelve 0 al sistema operativo para indicar que el programa terminó exitosamente.
 */
int main() { 
    // Crea una instancia de la clase Interfaz, que contiene la lógica del menú y la interacción con la biblioteca.
    Interfaz interfaz;

    // Ejecuta la interfaz, iniciando el bucle principal del programa.
    interfaz.ejecutar();

    // Retorna 0 para indicar que el programa finalizó correctamente.
    return 0;
}
