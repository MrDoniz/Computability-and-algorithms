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

#include "pattern_search.h"
#include "automata_finito.h"

Pattern::Pattern(int argc, char* argv[]) {
  pattern = argv[1];
  infile_name = argv[2];
  outfile_name = argv[3];
  state_end = pattern.size();
}

std::string Pattern::GetPattern(void) {
  return pattern;
}

int Pattern::GetStateEnd(void) {
  return state_end;
}

Pattern::~Pattern() {}

void Pattern::Run() {
  ReadFileImput();
  for (unsigned i = 0; i < vector_conjuntos.size(); i++) {
    std::cout << "Conjunto: " << vector_conjuntos[i] << "\t\t";
    if (TestSet(i)) {
      AutomataFinito AutomataFinitoFirst(vector_conjuntos[i], pattern, state_end);
      if (AutomataFinitoFirst.Search()) {
        vector_word_output.push_back("Si");
        std::cout << "Si" << std::endl;
      } else {
        vector_word_output.push_back("No");
        std::cout << "No" << std::endl;
      }
    } else {
      vector_word_output.push_back("Error");
      std::cout << "Error" << std::endl;
    }
  }
  WriteFileOutput();
}

void Pattern::ReadFileImput() {
  vector_conjuntos.clear();
  std::string line;
  std::ifstream input_file_program(infile_name);
  while (getline(input_file_program, line, '\n')) {
    if (line.size() != 0) vector_conjuntos.push_back(line);
  }
  input_file_program.close();
}

void Pattern::WriteFileOutput() {
  std::ofstream output_file_program(outfile_name);
  for (unsigned i = 0; i < vector_word_output.size(); ++i)
    output_file_program << vector_word_output[i] << std::endl;
  output_file_program.close();
}

bool Pattern::TestSet(int iterator_string) {
  int ascii_char;
  for (unsigned i = 0; i < vector_conjuntos[iterator_string].size(); i++) {
    ascii_char = vector_conjuntos[iterator_string][i] - 97;
    if (ascii_char > 25 || ascii_char < 0) {
      return false;
    }
  }
  return true;
}

bool Pattern::TestPattern() {
  int ascii_char;
  for (unsigned i = 0; i < pattern.size(); i++) {
    ascii_char = pattern[i] - 97;
    if (ascii_char > 25 || ascii_char < 0) {
      return false;
    }
  }
  return true;
}