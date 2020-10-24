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
 * DATE:    2 Oct 2020
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

#include <math.h>
#include <string.h>

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/FibonacciWords.h"

// Ejecución principal del programa. Inicialmente compruebo si puede ocurrir
// algun problema con los parametros, posteriormente leo el fichero de entrada e
// introduzco los caracteres en un vector de cadenas. Continuo creando un vector
// de cadenas el cual contiene la misma cantidad de palabras de fibonacci como
// de palabras recogió el vector de entrada. Finalmente comparo ambos vectores,
// imprimo y escribo simultaneamente.
int main(int argc, char* argv[]) {
  if (ArgumentConditionError(argc, argv)) {
    std::string input_file_name = argv[1];
    std::string output_file_name = argv[2];
    std::vector<std::string> ary_string_input;
    ary_string_input = ReadFileImput(ary_string_input, input_file_name);

    std::cout << "Input words:     ";
    Print(ary_string_input);

    unsigned ary_size = ary_string_input.size();
    std::vector<std::string> ary_string_fibonacci;
    ary_string_fibonacci = CreateFibonacciAry(ary_string_fibonacci, ary_size);

    std::cout << "Fibonacci words: ";
    Print(ary_string_fibonacci);

    CompareAndWriteFileOutput(ary_string_fibonacci, ary_string_input,
                              output_file_name);
  }
  return 0;
}
