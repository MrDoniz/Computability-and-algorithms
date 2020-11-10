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

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

class Pattern {
 public:
  Pattern(int argc, char* argv[]);
  ~Pattern();

  void Run();
  void ReadFileImput();
  void WriteFileOutput();

  bool Nodo(int i);
  bool TestSet(int i);
  bool TestPattern();

 private:
  std::vector<std::string> vector_conjuntos;
  std::string pattern;
  std::vector<std::string> vector_word_output;
  std::string infile_name;
  std::string outfile_name;
};
