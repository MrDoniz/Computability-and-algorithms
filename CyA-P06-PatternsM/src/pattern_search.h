/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 6
 *
 * @tittle: Patterm Search
 *
 * @author: Dóniz García Daniel
 * @date:   3 Nov 2020
 * @email:  alu0101217277@ull.edu.es
 * @brief:  Esta aplicación es utilizada para buscar subcadenas de cadenas
 * introducidas en un archivo de entrada. La subcadena de busqueda introducida
 * debe contener caracteres que sean letras minúsculas (sin incluir la ñ).
 * @see:    https://github.com/garamira/CyA-P06-Patterns
 *
 * @folder:      cd Computability-and-algorithms/CyA-P06-Patterns
 * @compilation: make
 * @removebuild: make clean
 * @execution:   ./pattern_search pattern infile.txt outfile.txt
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

/** @brief Trabaja con el pattern y los conjuntos.
 *
 * Proporciona métodos para analizar las cadenas de entrada.
 */
class Pattern {
  public:
  /** @brief Almaceno en variables los argumentos pasados por línea de comandos.
   *  @param argc
   *  @param argv
   */
  Pattern(int argc, char* argv[]);
  /** @brief Destruye el patron creado.
   */
  ~Pattern();

  /** @brief Recorre el vector de conjuntos para posteriormente trabajar con los
   * conjuntos.
   */
  void Run();
  /** @brief Lee las cadenas que están en el archivo de entrada
   */
  void ReadFileImput();
  /** @brief Escribe el resultado en el archivo de salida.
  */
  void WriteFileOutput();

  /** @brief Comprueba si el conjunto pertenece al lenguaje.
   *  @returns True si no ha ocurrido ningún error y False si ha ocurrido algun
   * error.
   */
  bool TestSet(int i);
  /** @brief Comprueba si el pattern pertenece al lenguaje.
   *  @returns True si no ha ocurrido ningún error y False si ha ocurrido algun
   * error.
   */
  bool TestPattern();

  /** @brief Método que permite acceder al pattern.
   * @returns Cadena que contiene el patron.
   */
  std::string GetPattern(void);
  /** @brief Método que permite acceder al número de estados.
   * @returns Entero que contiene el número de estados.
   */
  int GetStateEnd(void);

 private:
  std::vector<std::string> vector_conjuntos;
  std::string pattern;
  std::vector<std::string> vector_word_output;
  std::string infile_name;
  std::string outfile_name;
  int state_end;
};
