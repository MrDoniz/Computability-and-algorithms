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
#include "pattern_search.h"
#include "automata_finito.h"

int main(int argc, char* argv[]) {
  if (ArgumentConditionError(argc, argv)) {
    Pattern pattern_search(argc, argv);
    if (pattern_search.TestPattern()) {
      pattern_search.Run();
    } else {
      std::cout << "Los simbolos de pattern no pertenecen al afabeto" << std::endl;
    }
  }
  return 0;
}