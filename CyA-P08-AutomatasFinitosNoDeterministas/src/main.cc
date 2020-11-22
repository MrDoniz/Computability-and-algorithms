/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 8
 *
 * @tittle: NFA Simulation
 *
 * @author: Dóniz García Daniel
 * @date:   19 Nov 2020
 * @email:  alu0101217277@ull.edu.es
 * @brief:  Esta aplicación es utilizada para la simulación de un NFA cargado
 * desde un fichero de entrada pasado por parametro y su comportamiento para una
 * lista de cadenas introducidas en un archivo."
 * @see:    P08.pdf
 *
 * @folder:      cd
 * Computability-and-algorithms/CyA-P08-AutomatasFinitosNoDeterministas
 * @compilation: make
 * @removebuild: make clean
 * @execution:   ./nfa_simulation input.nfa input.txt output.txt
 *
 */

#include "../lib/NFA.h"
#include "../lib/addons.h"

int main(int argc, char* argv[]) {
  if (ArgumentConditionError(argc, argv)) {
    const std::string& nfa_file_name = argv[1];
    const std::string& infile_name   = argv[2];
    const std::string& outfile_name  = argv[3];

    NFA nfa;
    if (nfa.ReadFileNFA(nfa_file_name)) {
      nfa.Run(infile_name, outfile_name);
    } else {
      std::cout << "Error al cargar el NFA" << std::endl;
    }
  }
  return 0;
}