/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 8
 *
 * @tittle: Estado
 *
 * @author: Dóniz García Daniel
 * @date:   19 Nov 2020
 * @email:  alu0101217277@ull.edu.es
 * @brief:  Colores y comprobación de agurmentos.
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

std::ostream& kBoldOff(std::ostream& os) {return os << "\e[0m";}
std::ostream& kBoldOn (std::ostream& os) {return os << "\e[1m";}
std::ostream& kWhite  (std::ostream& os) {return os << "\033[0;37m";}
std::ostream& kCyan   (std::ostream& os) {return os << "\033[0;36m";}
std::ostream& kGreen  (std::ostream& os) {return os << "\033[0;32m";}
std::ostream& kRed    (std::ostream& os) {return os << "\033[0;31m";}
std::ostream& kYellow (std::ostream& os) {return os << "\033[0;33m";}
std::ostream& kPurple (std::ostream& os) {return os << "\033[0;35m";}

bool ArgumentConditionError(int argc, char* argv[]) {
  switch (argc) {
    case 4: {
      std::string nfa_file_name = argv[1];
      std::string input_file_name = argv[2];
      std::string output_file_name = argv[3];
      if (nfa_file_name == "input.nfa") {
        if (input_file_name == "input.txt" && 
        output_file_name == "output.txt") {
          std::ofstream output_file_program(output_file_name);
          std::ifstream input_file_program(input_file_name);
          if (output_file_program.is_open() && input_file_program.is_open()) {
            output_file_program.close();
            input_file_program.close();
            return true;
          } else {
            std::cout << kRed << kBoldOn
                      << "Ha ocurrido un error con los ficheros." << kWhite
                      << std::endl;
          }
        }
      }
    }
    case 2: {
      std::string command = argv[1];
      if (command == "--help")
        std::cout << "Esta aplicación es utilizada para la simulación \n"
                     "de un NFA cargado desde un fichero de entrada \n"
                     "pasado por parametro y su comportamiento para  \n"
                     "una lista de cadenas introducidas en un archivo."
                  << std::endl
                  << kCyan << kBoldOn
                  << "-------------------------------------------------------"
                  << std::endl
                  << std::endl
                  << kYellow << kBoldOn << "Ejemplo de uso:" << std::endl
                  << kWhite << "$ " << argv[0]
                  << " input.nfa input.txt output.txt\n";
      else
        std::cout << kYellow << kBoldOn << "Modo de empleo:" << kWhite
                  << " ./nfa_simulation input.nfa input.txt output.txt\n"
                  << "Pruebe '" << argv[0] << " --help' para más información.\n";
      return false;
      break;
    }
    default: {
      std::cout << kYellow << kBoldOn << "Modo de empleo:" << kWhite
                << " ./nfa_simulation input.nfa input.txt output.txt\n"
                << "Pruebe '" << argv[0] << " --help' para más información.\n";
      return false;
      break;
    }
  }
}