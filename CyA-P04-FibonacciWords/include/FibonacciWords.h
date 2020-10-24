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

bool ArgumentConditionError(int argc, char* argv[]);
std::vector<std::string> ReadFileImput(
    std::vector<std::string> ary_string_input, std::string input_file_name);
void Print(std::vector<std::string> ary_string_input);
std::vector<std::string> CreateFibonacciAry(
    std::vector<std::string> ary_string_fibonacci, unsigned ary_size);
void CompareAndWriteFileOutput(std::vector<std::string> ary_string_fibonacci,
                               std::vector<std::string> ary_string_input,
                               std::string output_file_name);