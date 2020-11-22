#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>  // std::setw

#include "estado.h"

class NFA{
  public:
    NFA();
    ~NFA();
    
    bool     ReadFileNFA(const std::string& nfa_file_name);
    bool  AnalizarCadena(const std::string& cadena);
    
    void             Run(const std::string& infile_name, const std::string& outfile_name);
    void   ReadFileImput(const std::string& infile_name);
    void WriteFileOutput(const std::string& outfile_name);

  private:
    unsigned numero_de_estados;
    char estado_inicial;
    std::set<char> alfabeto;
    std::set<Estado> conjunto_estados;
    std::vector<std::string> vector_cadenas;
    std::vector<std::string> vector_word_output;
};