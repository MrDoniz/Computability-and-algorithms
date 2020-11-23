/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 8
 *
 * @tittle: NFA Simulation
 *
 * @author: Dóniz García Daniel
 * @date:   19 Nov 2020
 * @email:  alu0101217277@ull.edu.es
 * @brief:  Esta clase implementa un NFA, formado por un conjunto de estados,
 * uno de ellos final y un conjunto de estados de aceptación, el cual utiliza un
 * alfabeto y una función de transición.
 *
 */

#include <fstream>
#include <iomanip>  // std::setw
#include <iostream>
#include <string>
#include <vector>

#include "estado.h"

/** @brief Esta clase es implemenada para los estados del NFA. Formado por un
 * identificado del estado comprobando si es de acpetación o no.
 */
class NFA {
 public:
  /** @brief Crea un NFA.
   */
  NFA();
  /** @brief Destruye el estado creado.
   */
  ~NFA();

  /** @brief Compruebo si el NFA que recibe desde el fichero es correcto, si es
   * así lo almaceno, de lo contrario cierro el programa.
   * @param nfa_file_name
   * @returns True si no ha ocurrido algún error, False si ha ocurrido algún
   * error.
   */
  bool ReadFileNFA(const std::string& nfa_file_name);

  /** @brief Comprueba si la cadena pasada es aceptada por el NFA y analiza si
   * la cadena llega al estado de aceptación
   * @param cadena
   * @returns True si llega al estado de aceptación, False si no llega al estado
   * de aceptación. error.
   */
  bool AnalizarCadena(const std::string& cadena);

  /** @brief Lee las cadenas que están en el archivo de entrada
   * @param infile_name
   * @param outfile_name
   */
  void Run(const std::string& infile_name, const std::string& outfile_name);
  /** @brief Lee las cadenas que están en el archivo de entrada
   * @param infile_name
   */
  void ReadFileImput(const std::string& infile_name);
  /** @brief Lee las cadenas que están en el archivo de entrada
   * @param outfile_name
   */
  void WriteFileOutput(const std::string& outfile_name);

 private:
  unsigned numero_de_estados;
  char estado_inicial;
  std::set<char> alfabeto;
  std::set<Estado> conjunto_estados;
  std::vector<std::string> vector_cadenas;
  std::vector<std::string> vector_word_output;
};