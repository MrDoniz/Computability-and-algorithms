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
 * FOLDER:      cd Computability-and-algorithms/CyA-P02-Eratosthenes
 * COMPILATION: g++ -std=c++14 -g -Wall -o erathostenes erathostenes.cc
 * EXECUTION:   ./erathostenes 20
 * 
 */

#include <iostream>
#include <math.h>

// Recorre la lista a partir del número primo recibido y marca como 0 todos los
// múltiplos de ese número. Envía
void Remove(int* ary, int size, int prime_numbers) {
  for (int i = prime_numbers; i < size; ++i) {
    ++i;
    if (ary[i] % prime_numbers == 0) 
      ary[i] = 0;
  }
}

// Recorre la lista y llama a la función Remove cuando encuentra un número primo
// que su exponente al cuadrado es inferior al número máximo de la lista.
void Sieve(int ary[], int size) {
  for (int i = 2; i < size; ++i)
    if (pow(ary[i], 2) < size) 
      Remove(ary, size, i);
}

// Recorre la lista moviendo a la posición de un 0 el siguiente número de la
// lista distinto de 0.
int fixList(int* ary, int size) {
  for (int j = 0; j < size; ++j)
    if (ary[j] == 0) {
      for (int k = j; k < size - 1; ++k) 
        std::swap(ary[k], ary[k + 1]);
      --size;
      --j;
    }
  return size;
}

// Imprime por consola una lista de números que reciba pasada por parámetro
// junto al tamaño de la lista.
void Print(int ary[], int size) {
  for (int i = 0; i < size; ++i) 
    std::cout << " " << ary[i];
  std::cout << "." << std::endl;
}

// Crea una lista ascendente de números comprendida de los valores de 1 a un
// número natural que es introducido por línea de comandos. Posteriormente llama
// a las funciones Print, Sieve y fixList.
int main(int argc, char* argv[]) {
  int size = atoi(argv[1]);
  int ary[size];
  int value = 0;

  for (int i = 0; i < size; i++) 
    ary[i] = ++value;

  std::cout << "Lista de todos los numeros: ";
  Print(ary, size);

  Sieve(ary, size);

  std::cout << "Lista de numeros primos:    ";
  Print(ary, size);

  size = fixList(ary, size);

  std::cout << "Lista de numeros primos fix:";
  Print(ary, size);

  return 0;
}