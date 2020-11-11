/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 6
 *
 * @tittle: Patterm Search
 *
 * @author: Dóniz García Daniel
 * @date:   3 Nov 2020
 * @email:  alu0101217277@ull.edu.es
 * @brief:  Esta aplicación es utilizada para buscar subcadenas de cadenas
 * introducidas en un archivo de entrada. La subcadena de busqueda introducida
 * debe contener caracteres que sean letras minúsculas (sin incluir la ñ).
 * @see:    https://github.com/garamira/CyA-P06-Patterns
 *
 * @folder:      cd Computability-and-algorithms/CyA-P06-Patterns
 * @compilation: make
 * @removebuild: make clean
 * @execution:   ./pattern_search pattern infile.txt outfile.txt
 *
 */

#include "addons.h"
#include "automata_finito.h"
#include "pattern_search.h"

// Ejecución principal del programa. Inicialmente compruebo si puede ocurrir
// algun problema con los parametros, posteriormente creo un objeto de la clase
// Pattern, continuo comprobando si el patron contiene el alfabeto indicado con
// el método TestPattern(), si tiene el alfabeto indica, continua la ejecución
// llamando al método Run(), al terminar este método termina la ejecución del
// programa. De lo contrario si no se cumple la condición, indica por consola
// que los simbolos del patron no pertenecen al alfabeto.
int main(int argc, char* argv[]) {
  if (ArgumentConditionError(argc, argv)) {
    Pattern pattern_search(argc, argv);
    if (pattern_search.TestPattern()) {
      pattern_search.Run();
    } else {
      std::cout << "Los simbolos de pattern no pertenecen al afabeto"
        << std::endl;
    }
  }
  return 0;
}