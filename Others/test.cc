#include "pattern_search.h"

Automata::Automata(int argc, char* argv[]) {
  pattern      = argv[1];
  infile_name  = argv[2];
  outfile_name = argv[3];
  state = (pattern.length() + 1);
}

Automata::~Automata() {}

std::string Automata::GetPattern(void) { 
  return pattern; 
}

std::string Automata::GetInfileName(void) { 
  return infile_name; 
}

std::string Automata::GetOutfileName(void) { 
  return outfile_name; 
}

int Automata::GetState(void) { 
  return state; 
}

bool Automata::TestPattern(){
  int ascii_char;
  for (unsigned i = 0; i < pattern.size(); i++) {
    ascii_char = pattern[i] - 97;
    //std::cout << ascii_char << std::endl;
    if (ascii_char > 25 || ascii_char < 0){
      return false;
    }
  }
  return true;
}

void Automata::Run(){
  ReadFileImput();
  for (unsigned i = 0; i < vector_string.size(); i++) {
    std::cout << "Conjunto: "<< vector_string[i] << std::endl;
    if (testSet(i)){
      Nodo(i);
    } else {
      vector_word_output[i] = "Error";
    }
  }
  WriteFileOutput();
}

bool Automata::testSet(int iterator_string){
  int ascii_char;
  for (unsigned i = 0; i < vector_string[iterator_string].size(); i++) {
    ascii_char = vector_string[iterator_string][i] - 97;
    //std::cout << ascii_char << std::endl;
    if (ascii_char > 25 || ascii_char < 0){
      return false;
    }
  }
  return true;
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

//bool Automata::ComprobarNodo(int iterator_string) {}
void Automata::Nodo(int iterator_string) {
  unsigned a = 0;
  int b = 0;
  int numero_estados = vector_string[iterator_string].size() + 1;
  for (int i = 0; i < numero_estados; i++) {
    if (vector_string[iterator_string][i] == pattern[a]) {
      a++;
    } else {
      a = 0;
    }
    if (a == pattern.size()){
      b++;
      a = 0;
    }
  }
  if (b > 0)
    
  else
   vector_word_output[iterator_string] = "No";
}

void Automata::WriteFileOutput() {
  std::ofstream output_file_program(outfile_name);
  for (unsigned i = 0; i < vector_word_output.size(); ++i)
    output_file_program << vector_word_output[i] << std::endl;
  output_file_program.close();
}















///////////////////////////////////////////////////////////////////////////////////////////
#include "pattern_search.h"

Automata::Automata(int argc, char* argv[]) {
  pattern      = argv[1];
  infile_name  = argv[2];
  outfile_name = argv[3];
  state = (pattern.length() + 1);
}

Automata::~Automata() {}

std::string Automata::GetPattern(void) { 
  return pattern; 
}

std::string Automata::GetInfileName(void) { 
  return infile_name; 
}

std::string Automata::GetOutfileName(void) { 
  return outfile_name; 
}

int Automata::GetState(void) { 
  return state; 
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

///////////////////////////////////////
void Automata::Run(){
  ReadFileImput();
  for (unsigned i = 0; i < vector_string.size(); i++) {
    std::cout << "Conjunto: "<< vector_string[i] << std::endl;
    if (testSet(i)){
      Nodo(i);
    } else {
      vector_word_output[i] = "Error";
    }
  }
  //WriteFileOutput();
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

//bool Automata::ComprobarNodo(int iterator_string) {}
void Automata::Nodo(int iterator_string) {
  unsigned a = 0;
  int b = 0;
  int numero_estados = vector_string[iterator_string].size() + 1;
  for (int i = 0; i < numero_estados; i++) {
    if (vector_string[iterator_string][i] == pattern[a]) {
      a++;
    } else {
      a = 0;
    }
    if (a == pattern.size()){
      b++;
      a = 0;
    }
  }
  std::cout << "Ha encontrado " << b << std::endl;
}

//int Automata::Simbolo(int i, int j) {}