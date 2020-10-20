/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 2
 *
 * TITLE:   Archivo Principal
 *
 * AUTHOR:  Dóniz García Daniel
 * DATE:    15 Oct 2020
 * EMAIL:   alu0101217277@ull.edu.es
 * VERSION: 1
 * BRIEF:   Dado un número entero 'n > 0', encuentre los números capicúas
 * resultantes de multiplicar dos números de 'n' dígitos cada uno.
 *
 * SEE: https://es.wikipedia.org/wiki/Palíndromo
 *
 * FOLDER:      cd Computability-and-algorithms/CyA-P03-ProductosCapicua
 * COMPILATION: make
 * REMOVEBUILD: make clean
 * EXECUTION:   build/palindrome_prod 1 output.txt
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

// Text style.
std::ostream& kBoldOff(std::ostream& os) { return os << "\e[0m"; }

std::ostream& kBoldOn(std::ostream& os) { return os << "\e[1m"; }

std::ostream& kWhite(std::ostream& os) { return os << "\033[0;37m"; }

std::ostream& kCyan(std::ostream& os) { return os << "\033[0;36m"; }

std::ostream& kRed(std::ostream& os) { return os << "\033[0;31m"; }

std::ostream& kYellow(std::ostream& os) { return os << "\033[0;33m"; }

// Imprime por consola ayuda para la ejecución del programa o indica que ha
// ocurrido un error.
void PrintHelpAndErrors(char* argv[], bool help) {
  if (help) {
    std::cout << "Introduce el comando de ejecución: " << kYellow << kBoldOn
              << "build/palindrome_prod 10 output.txt" << std::endl
              << kWhite << kBoldOff << "Donde N debe ser un numero natural."
              << std::endl;
  } else {
    std::cout << kRed << kBoldOn << "Error." << std::endl
              << kWhite << kBoldOff << "Introduce el comando: " << kYellow
              << kBoldOn << argv[0] << " -h" << kWhite << kBoldOff << std::endl;
  }
  exit(EXIT_FAILURE);
}

// Comprueba si ha ocurrido alguno de los errores de los que tengo en cuenta que
// pueden ocurrir al pasar los parametros.
void ArgumentConditionError(int argc, char* argv[]) {
  if (argc == 2 && (strcmp(argv[1], "-h") == 0)) 
    PrintHelpAndErrors(argv, true);

  if (argc != 3) 
    PrintHelpAndErrors(argv, false);

  if (atoi(argv[1]) < 1) 
    PrintHelpAndErrors(argv, false);

  std::string output_file_name = argv[2];
  std::string extencion_grama =
      output_file_name.substr(output_file_name.length() - 4, 4);
  if (extencion_grama != ".txt") 
    PrintHelpAndErrors(argv, false);

  std::ofstream myfile("build/" + output_file_name);
  if (myfile.is_open()) {
    myfile.close();
  } else {
    std::cout << kRed << kBoldOn << "No se pudo abir el fichero." << kWhite
              << std::endl;
    PrintHelpAndErrors(argv, false);
  }
}

// Recorro la lista de resultados marcando con un 0 los números NO capicúa,
// estos los hallo con un algoritmo de repetición.
void MarkPalindromicNumber(std::vector<int>& product) {
  int number_copy, number_check, rest;
  for (unsigned i = 0; i < product.size(); ++i) {
    number_copy = product[i];
    number_check = 0;
    rest = 0;
    while (number_copy != 0) {
      rest = number_copy % 10;
      number_copy = number_copy / 10;
      number_check = number_check * 10 + rest;
    }
    if (number_check != product[i]) 
      product[i] = 0;
  }
}

// Recorro la lista de resultados marcando con un 0 los números repetidos.
void MarkRepeatNumber(std::vector<int>& product) {
  for (unsigned i = 0; i < product.size() - 1; ++i)
    for (unsigned j = 0; j < i; ++j)
      if (product[j] == product[i]) 
        product[j] = 0;
}

// Recorre la lista de resultados moviendo a la posición de un 0 el siguiente
// número de la lista distinto de 0.
void RemoveMark(std::vector<int>& product) {
  auto end = product.end();
  for (auto i = product.begin(); i != end; ++i)
    end = std::remove(i + 1, end, 0);
  product.erase(end, product.end());
}

// Recorre el vector de números e imprime estos por consola.
void Print(std::vector<int>& product) {
  for (unsigned i = 0; i < product.size(); ++i) 
    std::cout << " " << product[i];
  std::cout << "." << std::endl;
}

// Recorre la lista de resultados escribiendo en el fichero pasado por parametro
// las operaciones y resultados. Finalmente cierra el fichero que previamente
// fue abierto.
void WriteInFile(std::string output_file_name, std::vector<int> product,
                 std::vector<int> multiplicand, std::vector<int> multiplier) {
  std::ofstream myfile("build/" + output_file_name);
  if (myfile.is_open()) {
    std::cout << kYellow << kBoldOn << "Fichero abierto." << kWhite
              << std::endl;
    for (unsigned i = 0; i < product.size(); ++i)
      myfile << multiplicand[i] << " * " << multiplier[i] << " = " << product[i]
             << std::endl;
    std::cout << kCyan << "Se han guardado las operaciones." << kWhite
              << std::endl;
    myfile.close();
    std::cout << kRed << kBoldOn << "Fichero cerrado." << kWhite << std::endl;
  }
}

// Ejecucion principal
int main(int argc, char* argv[]) {
  ArgumentConditionError(argc, argv);

  int number_of_digits = pow(10, atoi(argv[1]));
  int product_number_max = number_of_digits * number_of_digits;
  std::vector<int> product(product_number_max);
  std::vector<int> multiplicand(product_number_max);
  std::vector<int> multiplier(product_number_max);

  int position = 0;
  for (int i = 0; i < number_of_digits; ++i)
    for (int j = 0; j < number_of_digits; ++j) {
      product[position] = i * j;
      multiplicand[position] = i;
      multiplier[position] = j;
      position++;
    } 

  std::cout << "Product all :";
  Print(product);

  MarkPalindromicNumber(product);

  MarkRepeatNumber(product);

  RemoveMark(product);

  std::cout << "Product     :";
  Print(product);

  std::string output_file_name = argv[2];
  WriteInFile(output_file_name, product, multiplicand, multiplier);

  return 0;
}