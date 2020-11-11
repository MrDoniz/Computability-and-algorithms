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

// Constructor, guardo en variables privadas los agurmentos pasados por la línea
// de comandos
Pattern::Pattern(int argc, char* argv[]) {
  pattern      = argv[1];
  infile_name  = argv[2];
  outfile_name = argv[3];
  state_end    = pattern.size();
}

// Destructor
Pattern::~Pattern() {}

// Getter, cadena de pattern pasada por línea de comando
std::string Pattern::GetPattern(void) { 
  return pattern; 
}

// Getter, número de estados
int Pattern::GetStateEnd(void) { 
  return state_end; 
}

// Llamo a la función ReadFileImput(), la cual devulve un vector de conjuntos.
// Recorro el vector de conjunto, compruebo si cada conjunto pertenece al
// lenguaje del  pattern, si no pertenece escribo Error en el fichero de salida.
// A continuación creo un objeto de la clase AutomataFinito al cual le paso el
// conjunto que estoy analizando, el pattern y el número de estados. Llamo al
// método Search de la clase AutomataFinito, si devuelve TRUE, el conjunto
// contiene una subcadena de pattern y escribo Si en el fichero de salida, si
// devuelve FALSE,el conjunto no contiene una subcadena de pattern  y escribo No
// en el fichero de salida. Finalmente llamo al método WriteFileOutput(), el
// cual escribirá los resultados obtenidos.
void Pattern::Run() {
  ReadFileImput();
  for (unsigned i = 0; i < vector_conjuntos.size(); i++) {
    std::cout << "Conjunto: " << vector_conjuntos[i] << "\t\t";
    if (TestSet(i)) {
      AutomataFinito AutomataFinitoFirst(vector_conjuntos[i], pattern,
                     state_end);
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

// Guarda el contenido del fichero de entrada en un vector de cadenas.
void Pattern::ReadFileImput() {
  vector_conjuntos.clear();
  std::string line;
  std::string word = "";
  std::ifstream input_file_program(infile_name);
  while (getline(input_file_program, line, '\n')) {
    std::string word = "";
    for (auto x : line) {
      if (x == ' ') {
        vector_conjuntos.push_back(word);
        word = "";
      } else {
        word = word + x;
      }
    }
    vector_conjuntos.push_back(word);
  }
  input_file_program.close();
}

// Escribe en el fichero de salida el contenido de un vector de cadenas el cual
// almacena los resultados obtenidos.
void Pattern::WriteFileOutput() {
  std::ofstream output_file_program(outfile_name);
  for (unsigned i = 0; i < vector_word_output.size(); ++i)
    output_file_program << vector_word_output[i] << std::endl;
  output_file_program.close();
}

// Compruebo que el pattern a utilizar pertenezca al lenguaje indicado
// a - z, los cuales en ascii son 97 - 122
bool Pattern::TestPattern() {
  int ascii_char;
  for (unsigned i = 0; i < pattern.size(); i++) {
    ascii_char = pattern[i] - 97;
    if (ascii_char > 25 || ascii_char < 0)
      return false;
  }
  return true;
}

// Compruebo que el conjunto a analizar pertenezca al lenguaje indicado
// a - z, los cuales en ascii son 97 - 122
bool Pattern::TestSet(int iterator_string) {
  int ascii_char;
  for (unsigned i = 0; i < vector_conjuntos[iterator_string].size(); i++) {
    ascii_char = vector_conjuntos[iterator_string][i] - 97;
    if (ascii_char > 25 || ascii_char < 0)
      return false;
  }
  return true;
}