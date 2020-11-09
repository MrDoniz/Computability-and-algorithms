/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 4
 *
 * TITLE:   Fibonacci Words
 *
 * AUTHOR:  Dóniz García Daniel
 * DATE:    3 Nov 2020
 * EMAIL:   alu0101217277@ull.edu.es
 * VERSION: 1
 * BRIEF: 
 *
 * SEE: https://en.wikipedia.org/wiki/Fibonacci_number
 *
 * FOLDER:      cd Computability-and-algorithms/CyA-P06-Patterns
 * COMPILATION: make
 * REMOVEBUILD: make clean
 * EXECUTION:   ./pattern_search pattern infile.txt outfile.txt
 *
 */

#include "pattern_search.h"
#include "addons.h"

int main(int argc, char* argv[]) {
  if (ArgumentConditionError(argc, argv)) {
    Automata first_automata(argc, argv);
    if(first_automata.TestPattern()){
      first_automata.Run();
    }
    
    //Iniciar reconocimiento línea a línea
      //Si llega al estado 4, escribe Si en el outfile.txt
      //Si llega a 0 en algun momento, debe reiniciar y seguir buscando subcadenas.
      //Si termina la lina y no llega al 4, escribe No en el outfile.txt
      //Si la línea contiene simbolos que no estén en el pattern, escribe Error en el outfile.txt
  }
  return 0;
}