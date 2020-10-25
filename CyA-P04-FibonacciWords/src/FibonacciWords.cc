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
 * BRIEF:
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

#include "../include/colors.h"

/// Compruebo que si los argumentos de entrada son correctos la función devuelve
/// true, de lo contrario si hay algún argumento que pueda causar algún error la
/// función devuelve false.
bool ArgumentConditionError(int argc, char* argv[]) {
  std::string AYUDA = "--help";
  std::string ARCHIVO_TXT = ".txt";
  switch (argc) {
    case 3: {
      std::string input_file_name = argv[1];
      std::string output_file_name = argv[2];
      if (input_file_name.length() > 4 && output_file_name.length() > 4) {
        if (input_file_name == "input.txt") {
          if (output_file_name == "output.txt") {
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
    }
    case 2: {
      std::string command = argv[1];
      if (command == AYUDA)
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
      std::cout << kYellow << kBoldOn << "Modo de empleo:" << kWhite
                << " ./FibonacciWords input.txt output.txt\n"
                << "Pruebe " << argv[0] << " --help' para más información.\n";
      return false;
      break;
    }
  }
}

/// Abro el fichero de entrada y voy almacenando cada línea en un string
/// almacenado por un vector. Finalmente cierro el archivo de entrada, imprimo
/// el número de palabras que ha leído y devuelvo el vector que almacena las
/// cadenas.
std::vector<std::string> ReadFileImput(
    std::vector<std::string> ary_string_input, std::string input_file_name) {
  std::string line;
  ary_string_input.clear();
  std::ifstream input_file_program(input_file_name);
  while (getline(input_file_program, line, '\n'))
    ary_string_input.push_back(line);
  input_file_program.close();
  std::cout << "Read " << ary_string_input.size() << " words." << std::endl
            << std::endl;
  return ary_string_input;
}

/// Imprime lo que hay almacenado en cada posición del vector.
void Print(std::vector<std::string> ary_string_input) {
  for (unsigned i = 0; i < ary_string_input.size(); ++i)
    std::cout << ary_string_input[i] << "\t";
  std::cout << std::endl;
}

/// Desarollo las palabras de Fibonacci y las almaceno en un vector de cadenas.
std::vector<std::string> CreateFibonacciAry(
    std::vector<std::string> ary_string_fibonacci,
    std::vector<std::string> ary_string_input) {
  unsigned size = 0;
  for (unsigned i = 0; i < ary_string_input.size(); ++i)
    if (ary_string_input[i].length() > size)
      size = ary_string_input[i].length();
  
  std::string first_line("a");
  std::string second_line("b");
  ary_string_fibonacci.clear();
  int i = -1;
  do {
    i++;
    if (i == 0) ary_string_fibonacci.push_back(first_line);
    if (i == 1) ary_string_fibonacci.push_back(second_line);
    if (i > 1)
      ary_string_fibonacci.push_back(ary_string_fibonacci[i - 2] +
                                     ary_string_fibonacci[i - 1]);
  } while (ary_string_fibonacci[i].length() < size);

  return ary_string_fibonacci;
}

/// Recorro el vector de cadenas de fibonacci comparando sus cadenas con las del
/// vector de entrada, si ambos vectores tienen la misma palabra en la misma
/// posición indico que trata de una palabra de fibonacci
/// imprimiendo/escribiendo, de mismo modo con las que no son palabras de
/// fibonacci. Finalmente cierro el archivo de salida.
void CompareAndWriteFileOutput(std::vector<std::string> ary_string_fibonacci,
                               std::vector<std::string> ary_string_input,
                               std::string output_file_name) {
  std::cout << std::endl;
  std::ofstream output_file_program(output_file_name);
  int word_number = 1;
  for (unsigned i = 0; i < ary_string_fibonacci.size(); ++i) {
    if (ary_string_fibonacci[i].compare(ary_string_input[i])) {
      std::cout << ary_string_input[i] << kRed << " is not a Fibonacci word"
                << kWhite << std::endl;
      output_file_program << ary_string_input[i] << " is not a Fibonacci word"
                          << std::endl;
    } else {
      std::cout << ary_string_input[i] << kGreen << " is the word number "
                << word_number << kWhite << std::endl;
      output_file_program << ary_string_input[i] << " is the word number "
                          << word_number << std::endl;
    }
    word_number++;
  }
  output_file_program.close();
}