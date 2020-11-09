#include "pattern_search.h"

Automata::Automata(int argc, char* argv[]) {
  pattern      = argv[1];
  infile_name  = argv[2];
  outfile_name = argv[3];
}

Automata::~Automata() {}

void Automata::Run(){
  ReadFileImput();
  for (unsigned i = 0; i < vector_string.size(); i++) {
    std::cout << "Conjunto: "<< vector_string[i] << "\t\t";
    if (testSet(i)){
      if (Nodo(i)){
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

void Automata::ReadFileImput() {
  vector_string.clear();
  std::string line;
  std::ifstream input_file_program(infile_name);
  while (getline(input_file_program, line, '\n')) {
    if (line.size() != 0) 
      vector_string.push_back(line);
  }
  input_file_program.close();
}

void Automata::WriteFileOutput() {
  std::ofstream output_file_program(outfile_name);
  for (unsigned i = 0; i < vector_word_output.size(); ++i)
    output_file_program << vector_word_output[i] << std::endl;
  output_file_program.close();
}

bool Automata::Nodo(int iterator_string) {
  unsigned a = 0;
  int numero_estados = vector_string[iterator_string].size();
  for (int i = 0; i < numero_estados; i++) {
    if (vector_string[iterator_string][i] == pattern[a]) {
      a++;
    } else {
      a = 0;
    }
    if (a == pattern.size()){
      return true;
    }
  }
  return false;
}

bool Automata::testSet(int iterator_string){
  int ascii_char;
  for (unsigned i = 0; i < vector_string[iterator_string].size(); i++) {
    ascii_char = vector_string[iterator_string][i] - 97;
    if (ascii_char > 25 || ascii_char < 0){
      return false;
    }
  }
  return true;
}

bool Automata::TestPattern(){
  int ascii_char;
  for (unsigned i = 0; i < pattern.size(); i++) {
    ascii_char = pattern[i] - 97;
    if (ascii_char > 25 || ascii_char < 0){
      return false;
    }
  }
  return true;
}

std::string Automata::GetPattern(void) { 
  return pattern; 
}

std::string Automata::GetInfileName(void) { 
  return infile_name; 
}

std::string Automata::GetOutfileName(void) { 
  return outfile_name; 
}