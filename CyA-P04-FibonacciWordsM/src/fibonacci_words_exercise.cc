/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 4
 *
 * TITLE:   Fibonacci Words
 *
 * AUTHOR:  Dóniz García Daniel
 * DATE:    24 Oct 2020
 * EMAIL:   alu0101217277@ull.edu.es
 * VERSION: 1
 * BRIEF: Crea una sucección con un archivo de entrada y la compara con la
 * suceción de Fibonacci.
 *
 * SEE: https://en.wikipedia.org/wiki/Fibonacci_number
 *
 * FOLDER:      cd Computability-and-algorithms/CyA-P04-FibonacciWords/build
 * COMPILATION: make
 * REMOVEBUILD: make clean
 * EXECUTION:   ./FibonacciWords input.txt output.txt
 *
 */

#include "../include/FibonacciWords.h"

std::ostream& kBoldOff(std::ostream& os) { 
  return os << "\e[0m"; 
}

std::ostream& kBoldOn(std::ostream& os) { 
  return os << "\e[1m"; 
}

std::ostream& kWhite(std::ostream& os) { 
  return os << "\033[0;37m"; 
}

std::ostream& kCyan(std::ostream& os) { 
  return os << "\033[0;36m"; 
}

std::ostream& kGreen(std::ostream& os) { 
  return os << "\033[0;32m"; 
}

std::ostream& kRed(std::ostream& os) { 
  return os << "\033[0;31m"; 
}

std::ostream& kYellow(std::ostream& os) { 
  return os << "\033[0;33m"; 
}

/// Compruebo que si los argumentos de entrada son correctos la función devuelve
/// true, de lo contrario si hay algún argumento que pueda causar algún error la
/// función devuelve false.
bool ArgumentConditionError(int argc, char* argv[]) {
  switch (argc) {
    case 3: {
      std::string input_file_name = argv[1];
      std::string output_file_name = argv[2];
      if (input_file_name.length() > 4 && output_file_name.length() > 4) {
        // if (input_file_name == "input.txt" && output_file_name ==
        // "output.txt") {
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
        //}
      }
    }
    case 4: {
      return true;
    }
    case 2: {
      std::string command = argv[1];
      if (command == "--help")
        std::cout << "Este programa dada una secuencia de palabras que estan \n"
                     "escritas en un archivo .txt indique si son palabras de \n"
                     "Fibonacci o no. Para aquellas que lo sean, el programa \n"
                     "ha de indicar su posición en la secuencia."
                  << std::endl
                  << kCyan << kBoldOn
                  << "-------------------------------------------------------"
                  << std::endl
                  << std::endl
                  << kYellow << kBoldOn << "Ejemplo de uso:" << std::endl
                  << kWhite << "$ " << argv[0] << " input.txt output.txt"
                  << std::endl
                  << std::endl;
      else
        std::cout << kYellow << kBoldOn << "Modo de empleo:" << kWhite
                  << " ./FibonacciWords input.txt output.txt\n"
                  << "Pruebe " << argv[0] << " --help' para más información.\n";
      return false;
      break;
    }
    default: {
      std::cout << kYellow << kBoldOn << "Modo de empleo: " << kWhite
                << "This program prints all the Fibonacci words with length between two limits. It requires two numeric parameters indicating the length limit for the words and a third parameter indicating the output file\n"
                << "Usage: ./fibonacci_words_exercise lower_limit upper_limit output.txt\n";
      return false;
      break;
    }
  }
}
/// Constructor
Fibonacci::Fibonacci(std::string input_file_name) {
  file_name = input_file_name;
}

/// Destructor
Fibonacci::~Fibonacci() { ary_string.clear(); }

// Getter tamaño vector de cadenas.
int Fibonacci::GetSize(void) { 
  return ary_size; 
}

// Getter vector de cadenas.
std::vector<std::string> Fibonacci::GetAryString(void) { 
  return ary_string; 
}

/// Abro el fichero de entrada y voy almacenando cada línea en un string
/// almacenado por un vector. Finalmente cierro el archivo de entrada, imprimo
/// el número de palabras que ha leído y devuelvo el vector que almacena las
/// cadenas.
void Fibonacci::ReadFileImput() {
  std::string line;
  std::ifstream input_file_program(file_name);
  while (getline(input_file_program, line, '\n')) {
    if (line.size() != 0) 
      ary_string.push_back(line);
  }
  input_file_program.close();
  ary_size = ary_string.size();
  std::cout << "Read " << ary_size << " words." << std::endl << std::endl;
}

/// Imprime lo que hay almacenado en cada posición del vector.
void Fibonacci::Print() {
  for (int i = 0; i < ary_size; ++i) 
    std::cout << ary_string[i] << "\t";
  std::cout << std::endl;
}

/// Desarollo las palabras de Fibonacci y las almaceno en un vector de cadenas.
void Fibonacci::CreateFibonacciAry(int lower_limit, int upper_limit) {

  std::string first_line("a");
  std::string second_line("b");


  //ary_string.length()
  int i = 0;
  do {+
    if (ary_string[i].length() > lower_limit){
    if (i == 0) 
      ary_string.push_back(first_line);
    if (i == 1) 
      ary_string.push_back(second_line);
    if (i > 1) 
      ary_string.push_back(ary_string[i - 2] + ary_string[i - 1]);
    }

  } while (ary_string[i].length() < upper_limit);
  for (int i = 0; i < 10; ++i) {
    if (i == 0) 
      ary_string.push_back(first_line);
    if (i == 1) 
      ary_string.push_back(second_line);
    if (i > 1) 
      ary_string.push_back(ary_string[i - 2] + ary_string[i - 1]);
  
  }
}

/// Recorro el vector de cadenas de fibonacci comparando sus cadenas con las del
/// vector de entrada, si ambos vectores tienen la misma palabra en la misma
/// posición indico que trata de una palabra de fibonacci
/// imprimiendo/escribiendo, de mismo modo con las que no son palabras de
/// fibonacci. Finalmente cierro el archivo de salida.
void Fibonacci::CompareAndWriteFileOutput() {
  std::cout << std::endl;
  std::ofstream output_file_program(file_name);
  for (unsigned i = 0; i < ary_string.size(); ++i) {
  }
  output_file_program.close();
}