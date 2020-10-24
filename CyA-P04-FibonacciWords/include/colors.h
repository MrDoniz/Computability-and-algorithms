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
std::ostream& kBoldOff(std::ostream& os) { return os << "\e[0m"; }

std::ostream& kBoldOn(std::ostream& os) { return os << "\e[1m"; }

std::ostream& kWhite(std::ostream& os) { return os << "\033[0;37m"; }

std::ostream& kCyan(std::ostream& os) { return os << "\033[0;36m"; }

std::ostream& kGreen(std::ostream& os) { return os << "\033[0;32m"; }

std::ostream& kRed(std::ostream& os) { return os << "\033[0;31m"; }

std::ostream& kYellow(std::ostream& os) { return os << "\033[0;33m"; }
