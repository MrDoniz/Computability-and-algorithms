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
 * FOLDER:      cd Computability-and-algorithms/CyA-P04-FibonacciWordsM/build
 * COMPILATION: make
 * REMOVEBUILD: make clean
 * EXECUTION:   ./FibonacciWords input.txt output.txt
 *
 */

#include "../include/FibonacciWords.h"

/// Ejecución principal del programa. Inicialmente compruebo si puede ocurrir
/// algun problema con los parametros, posteriormente leo el fichero de entrada
/// e introduzco los caracteres en un vector de cadenas. Continuo creando un
/// vector de cadenas el cual contiene la misma cantidad de palabras de
/// fibonacci como de palabras recogió el vector de entrada. Finalmente comparo
/// ambos vectores, imprimo y escribo simultaneamente.
int main(int argc, char* argv[]) {
  if (ArgumentConditionError(argc, argv)) {
    int lower_limit = atoi(argv[1]);
    int upper_limit = atoi(argv[2]);
    std::string output_file_name = argv[3];

    Fibonacci ary_string_fibonacci(output_file_name);
    ary_string_fibonacci.CreateFibonacciAry(lower_limit, upper_limit);
    std::cout << "Suceción Fibonacci :" << std::endl;
    ary_string_fibonacci.Print();

    //ary_string_fibonacci.CompareAndWriteFileOutput();
  }
  return 0;
}
