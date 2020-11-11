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

#include <iostream>
#include <vector>

const unsigned kNumeroAlfabeto = 122;

/** @brief Diseño de un automata finito
 *
 * Algoritmo de busqueda de subcadenas haciendo uso de un Automata Finito
 */
class AutomataFinito {
 public:
  /** @brief Creo un nuevo automata en el cual almaceno en variables privadas
   * los argumentos pasados.
   *  @param conjunto Conjunto a analizar
   *  @param pattern Patron a utilizar
   *  @param state_end Número de estados
   */
  AutomataFinito(std::string conjunto, std::string pattern, int state_end);
  /** @brief Destruye el automata creado.
   */
  ~AutomataFinito();

  /** @brief Comprueba si el conjunto contiene una subcadena
   *  @returns True si contiene subcadena y False ssino tiene alguna subcadena.
   */
  bool Search();
  /** @brief Recorre el conjunto junto al pattern.
   */
  void RunAutomataFinito(int TF[][kNumeroAlfabeto]);
  /** @brief Comprueba el estado en el que se encuentra y los valores que se encuentra en cada array.
   *  @returns Devulve un valor el cual será el estado siguiente.
   */
  int SiguienteEstado(int state, int value);

 private:
  std::string pattern_af;
  std::string conjunto_af;
  int state_end_af;
};
