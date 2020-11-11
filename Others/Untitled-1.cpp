/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 6
 *
 * @tittle:   Patterm Search
 *
 * @author: Dóniz García Daniel
 * @date:   3 Nov 2020
 * @email:  alu0101217277@ull.edu.es
 * @brief: Esta aplicación es utilizada para buscar subcadenas de cadenas
 * introducidas en un archivo de entrada. La subcadena de busqueda introducida
 * debe contener caracteres que sean letras minúsculas (sin incluir la ñ).
 *
 * @folder:      cd Computability-and-algorithms/CyA-P06-Patterns
 * @compilation: make
 * @removebuild: make clean
 * @execution:   ./pattern_search pattern infile.txt outfile.txt
 *
 */

#include "pattern_search.h"

Pattern::Pattern(int argc, char* argv[]) {
  pattern = argv[1];
  infile_name = argv[2];
  outfile_name = argv[3];
}

Pattern::~Pattern() {}

void Pattern::Run() {
  ReadFileImput();
  for (unsigned i = 0; i < vector_conjuntos.size(); i++) {
    std::cout << "Conjunto: " << vector_conjuntos[i] << "\t\t";
    if (TestSet(i)) {
      if (Nodo(i)) {
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

bool Pattern::Nodo(int iterator_string) {
  unsigned j = 0;
  int numero_estados = vector_conjuntos[iterator_string].size();
  for (int i = 0; i < numero_estados; i++) {
    if (vector_conjuntos[iterator_string][i] == pattern[j]) {
      j++;
    } else {
      j = 0;
    }
    if (j == pattern.size()) {
      return true;
    }
  }
  return false;
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


///////////////////////////////////////


bool Pattern::Nodo(int iterator_string) {
  int encontro = 0;
  std::string txt = vector_conjuntos[iterator_string];
  std::string pat = pattern;
  int M = pat.size();
  int N = txt.size();
  int automata_finito[M+1][NO_OF_CHARS];
  RunAutomataFinito(automata_finito);
  int i, state = 0; 
  for (i = 0; i < N; i++) {
    state = automata_finito[state][vector_conjuntos[iterator_string][i]];
    if (state == M){
      
      return true; 
    }
  }
  return false;
}

void Pattern::RunAutomataFinito(int automata_finito[][NO_OF_CHARS]) { 
  int state, x;
  for (state = 0; state <= state_end; ++state)  
    for (x = 0; x < NO_OF_CHARS; ++x)  
      automata_finito[state][x] = getNextState(state, x);
} 

int Pattern::getNextState(int state, int x) { 
  if (state < state_end && x == pattern[state])  
    return state+1;   
  int ns, i;  
  for (ns = state; ns > 0; ns--) {  
    if (pattern[ns-1] == x) {  
      for (i = 0; i < ns-1; i++)  
        if (pattern[i] != pattern[state-ns+1+i])  
          break;  
      if (i == ns-1)  
        return ns;  
    }  
  }
  return 0;  
}