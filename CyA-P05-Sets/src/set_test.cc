/*
 * School:   Universidad De La Laguna.
 * Subject:  Computabilidad y Algoritmia - CyA.
 * Practice: La clase Set.
 * Author:   Hugo Fernández Solís.
 * Contact:  alu0101112664@ull.edu.es
 *
 * File:     set_test.cc - Implements a small program to test the functionality of the class 'Set'.
 * Date:     28/10/2020
 * Brief:    A set is a well-defined collection of distinct objects, considered
 *           as an object in its own right, in which the arrangement of the 
 *           objects in the set does not matter.
 *
 * References:
 *        Wikipedia:  https://en.wikipedia.org/wiki/Set_(mathematics)
 *        Fstream:    http://www.cplusplus.com/reference/fstream/
 */

#include <string.h>

#include <fstream>

#include "Set.h"


void print_help(const char* use);       // Displays a little help for the program.
std::ostream& analyze_line_2(const std::string& line, std::ostream& os);         // Transforms the passed line into sets.

/*
 * Main function of the set test.
 * Checks the passed arguments. If 1 argument is given will check if its the help argument, if
 * it is so, the program will print a small guide and exit with EXIT_SUCCESS. Otherwise it will
 * end with EXIT_FAILURE.
 * When 2 arguments are given it will asume they are both filenames and open them as fstream. The
 * first one as input and the second as output. Then translate the lines into sets and it operation
 * and will print the result on the ostream.
 */
int main(int argc, char* argv[]) {
  std::ifstream infile;
  std::ofstream outfile;
  switch (argc) {
    case 2: {
      if (strcmp(argv[1], "-h") == 0) {
        print_help(argv[0]);
        return EXIT_SUCCESS;
      }
      std::cout << "[ERROR] No se reconocen los argumentos introducidos!\n";
      std::cout << "Utilice la opción '-h' para más información." << std::endl;
      return EXIT_FAILURE;
    }
    case 3: {
      infile.open(argv[1]);
      if (!infile.is_open()) {
        std::cout << "[ERROR] No se puede abrir el fichero \"" << argv[1] << "\"." << std::endl;
        return EXIT_FAILURE;
      }
      outfile.open(argv[2]);
      if (!outfile.is_open()) {
        std::cout << "[ERROR] No se puede abrir el fichero \"" << argv[2] << "\"." << std::endl;
        return EXIT_FAILURE;
      }
      break;
    }
    default: {
      std::cout << "[ERROR] No se reconocen los argumentos introducidos!\n";
      std::cout << "Utilice la opción '-h' para más información." << std::endl;
      return EXIT_FAILURE;
    }
  }
  std::string line;
  while (getline(infile, line)) {
    cya::Set set1;
    cya::Set set2;
    cya::Set set3;
    char oper = analyze_line(line, set1, set2, set3);
    if (oper != cya::COMPLEMENT) {
      outfile << set1 << " " << oper << " " << set2 << " = " << set3 << std::endl;
    }
    else {
      outfile << set1 << " " << oper << " = " << set3 << std::endl;
    }
    analyze_line_2(line, std::cout);
  }
}

// Displays a little help for the program.
void print_help(const char* use) {
  std::cout
  << "Bienvenido a la guía de uso del programa de prueba de la clase Set.\n"
  << "En este programa usted introducirá un fichero de entrada y otro de salida\n"
  << "que contendrán la información sobre las operaciones.\n\n"
  << "Modo de empleo:\n"
  << "\t$ " << use << " 'inputfile' 'outputfile'\n\n"
  << "El fichero de entrada contendrá las operaciones a realizar en cada linea de la forma:\n"
  << "\t{set1} *operación* {set2}\n\n"
  << "El fichero de salida contendrá los resultados de las operaciones de la forma:\n"
  << "\t{set1} *operación* {set2} = {resultado}\n\n"
  << "NOTA: La forma de los sets en el fichero de entrada deberá seguir el siguiente estilo:\n"
  << "Con una coma y un espacio tras cada elemento y abriendo y cerrando con corchetes.\n"
  << "> {1, 2, 3, 4}\n"
  << "En caso contrario no se leerá correctamente los sets y el resultado será erroneo." << std::endl;
}

 std::ostream& analyze_line_2(const std::string& line, std::ostream& os) {
    std::vector<char> operands;
    cya::Set aux_set;
    std::vector<cya::Set> sets_vector;
    std::string aux_string;
    for (const char& character : line) {
      switch (character) {
        case ' ': {
          break;
        }
        case '{': {
          aux_string.clear();
          break;
        }
        case ',': {
          aux_set.insert(std::stoi(aux_string));
          aux_string.clear();
          break;
        }
        case '}': {
          aux_set.insert(std::stoi(aux_string));
          aux_string.clear();
          sets_vector.push_back(aux_set);
          break;
        }
        case '\n': {
          break;
        }
        default: {
          if (isdigit(character)) {
            aux_string.push_back(character);
          }
          else {
            operands.push_back(character);
          }
          break;
        }
      }
    }
    switch (operands[0]) {
      case cya::UNION:
      aux_set = sets_vector[0] + sets_vector[1];
      break;
      case cya::RELATIVE_COMPLEMENT:
        aux_set = sets_vector[0] - sets_vector[1];
        break;
      case cya::INTERSECTION:
        aux_set = sets_vector[0] * sets_vector[1];
        break;
      default:
        break;
    }
    for (size_t i = 2; i < sets_vector.size(); i++) {
      switch (operands[i - 1]) {
        case cya::UNION:
        aux_set = aux_set + sets_vector[1];
        break;
        case cya::RELATIVE_COMPLEMENT:
          aux_set = aux_set - sets_vector[1];
          break;
        case cya::INTERSECTION:
          aux_set = aux_set * sets_vector[1];
          break;
        default:
          break;
      }
    }
    os << sets_vector[0];
    for(size_t i = 0; i < operands.size(); i++) {
      os << " " << operands[i] << " " << sets_vector[i + 1];
    }
    return os;
  }