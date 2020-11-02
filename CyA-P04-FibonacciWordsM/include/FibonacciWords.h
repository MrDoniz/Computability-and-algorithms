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

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

/** @brief representa una suceción de Fibonnaci
 *
 * Proporciona métodos para que las palabras de Fibonnaci puedan ser leidas,
 * creadas, impresas y comparadas.
 */
class Fibonacci {
 public:
  /** @brief Crea una nueva suceción.
   *  @param input_file_name String con el archivo que tiene asociado la
   * suceción.
   */
  Fibonacci(std::string input_file_name);
  /** @brief Destruye la suceción creada.
   */
  ~Fibonacci();
  /** @brief Lee el archivo asociado y almacena la información en la suceción. 
   */
  void ReadFileImput();
  /** @brief Crea la suceción de Fibonnaci del tamaño de la suceción de entrada.
   *  @param ary_input_size Entero de palabras leidas por la suceción de
   * entrada.
   */
  void CreateFibonacciAry(int lower_limit, int upper_limit);
  /** @brief Imprime una suceción por consola.
   */
  void Print();
  /** @brief Compara las suceciones y escribe las conclusiones.
   * @param ary_string Suceción para comparar.
   */
  void CompareAndWriteFileOutput();
  /** @brief Método que permite acceder al tamaño de una suceción
   * @returns Entero que contiene la cantidad de palabras que tiene la suceción.
   */
  int GetSize(void);
  /** @brief Método que permite acceder a una suceción de cadenas.
   * @returns Vector de cadenas que contiene una succeción de palabras.
   */
  std::vector<std::string> GetAryString(void);

 private:
  std::string file_name;
  std::vector<std::string> ary_string;
  int ary_size;
};

/** @brief Comprueba si puede ocurrir algun error con los argumentos
 *  @returns True si no ha ocurrido ningún error y False si ha ocurrido algun
 * error.
 */
bool ArgumentConditionError(int argc, char* argv[]);