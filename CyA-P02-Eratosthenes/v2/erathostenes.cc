/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 2
 *
 * AUTHOR:  Dóniz García Daniel
 * DATE:    6 Oct 2020
 * EMAIL:   alu0101217277@ull.edu.es
 * VERSION: 1
 * BRIEF:   Sieve of Eratosthenes is an ancient algorithm for finding all prime
 * numbers up to any given limit.
 *
 * SEE: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 *
 * FOLDER:      cd Computability-and-algorithms/CyA-P02-Eratosthenes/v2
 * COMPILATION: g++ -std=c++14 -g -Wall -o erathostenes erathostenes.cc
 * EXECUTION:   ./erathostenes 20
 *
 */
#include <math.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

std::ostream& kBoldOff(std::ostream& os) { 
  return os << "\e[0m"; 
}

std::ostream& kBoldOn(std::ostream& os) { 
  return os << "\e[1m"; 
}

std::ostream& kWhite(std::ostream& os) { 
  return os << "\033[0;37m"; 
}

std::ostream& kRed(std::ostream& os) { 
  return os << "\033[0;31m"; 
}

std::ostream& kYellow(std::ostream& os) { 
  return os << "\033[0;33m"; 
}

// Recorre la lista a partir del número primo recibido y marca como 0 todos los
// múltiplos de ese número. Envía
void Remove(std::vector<int>& ary, int prime_numbers) {
  for (unsigned i = prime_numbers; i < ary.size(); i++)
    if (ary[++i] % prime_numbers == 0) 
      ary[i] = 0;
}

// Recorre la lista y llama a la función Remove cuando encuentra un número primo
// que su exponente al cuadrado es inferior al número máximo de la lista.
void Sieve(std::vector<int>& ary) {
  for (unsigned i = 2; i < ary.size(); i++)
    if (pow(ary[i], 2) < ary.size() ) 
      Remove(ary, i);
}

// Recorre la lista moviendo a la posición de un 0 el siguiente número de la
// lista distinto de 0.
void FixList(std::vector<int>& ary) {
  auto end = ary.end();
  for (auto i = ary.begin(); i != end; ++i) 
    end = std::remove(i + 1, end, 0);
  ary.erase(end, ary.end() );
}

// Imprime por consola una lista de números que reciba pasada por parámetro
// junto al tamaño de la lista.
void Print(std::vector<int>& ary) {
  for (unsigned i = 0; i < ary.size(); ++i) 
    std::cout << " " << ary[i];
  std::cout << "." << std::endl;
}

void PrintHelp() {
  std::cout << "Introduce el comando de ejecución: " << kYellow << kBoldOn
            << "./erathostenes N" << std::endl;
  std::cout << kWhite << kBoldOff << "Donde N debe ser un numero natural."
            << std::endl;
}

// Crea una lista ascendente de números comprendida de los valores de 1 a un
// número natural que es introducido por línea de comandos. Posteriormente llama
// a las funciones Print, Sieve y FixList.
int main(int argc, char* argv[] ) {

  if (argc == 2 && (strcmp(argv[1], "-h") == 0) ) {
    PrintHelp();
    return 0;
  }

  if (argc > 2 || argc < 2) {
    std::cout << kRed << kBoldOn << "Error." << std::endl;
    std::cout << kWhite << kBoldOff << "Introduce el comando -h" << std::endl;
    return 0;
  }

  char *p;
  long conv = strtol(argv[1], &p, 10);
  if (*p != '\0' || conv > 9999) {
    std::cout << kRed << kBoldOn << "Error." << std::endl;
    std::cout << kWhite << kBoldOff << "Introduce el comando -h" << std::endl;
    return 0;
  }

  int size = atoi(argv[1]);
  std::vector<int> ary(size);

  for (unsigned i = 0; i < ary.size(); i++) 
    ary[i] = i + 1;

  std::cout << "Lista de todos los numeros:";
  Print(ary);

  Sieve(ary);

  // std::cout << "Lista de numeros primos:   ";
  // Print(ary);

  FixList(ary);

  std::cout << "Lista de numeros primos:   ";
  Print(ary);

  return 0;
}
