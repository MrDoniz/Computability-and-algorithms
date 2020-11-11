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

#include "automata_finito.h"

// Constructor, guardo en variables privadas los argumentos pasados, un
// conjunto, el pattern y el número de estados.
AutomataFinito::AutomataFinito(const std::string& conjunto, std::string pattern, 
    int state_end) {
  conjunto_af  = conjunto;
  pattern_af   = pattern;
  state_end_af = state_end;
}

// Destructor.
AutomataFinito::~AutomataFinito() {}

// Comienzo creando un una matriz que contiene state_end_af + 1 estados y el
// número total de caracteres posibles en el pattern y en el texto. Continuo
// llamando al método que construye el Automata Finito enviandole los datos que
// requiere el automata (número de estados y el número total de caracteres).
// Continuo recorriendo la matriz y analizando los resultados obtenidos
// previamente con el método RunAutomataFinito(), si se obtiene una subcadena
// devulve TRUE, de lo contrario FALSE.
bool AutomataFinito::Search() {
  int automata_finito[state_end_af + 1][kNumeroAlfabeto];
  RunAutomataFinito(automata_finito);
  int state = 0; 
  for (unsigned i = 0; i < conjunto_af.size(); i++) {
    state = automata_finito[state][(unsigned char) conjunto_af[i]];
    if (state == state_end_af)
      return true; 
  }
  return false;
}

// Recorro la matriz automata_finito y llamo al método SiguienteEstado() el cual
// irá rellenando la matriz con los resultados obtenidos.
void AutomataFinito::RunAutomataFinito(int automata_finito[][kNumeroAlfabeto]) { 
  unsigned value;
  for (int state = 0; state <= state_end_af; ++state)  
    for (value = 0; value < kNumeroAlfabeto; ++value)  
      automata_finito[state][value] = SiguienteEstado(state, value);
}

// Compruebo que el número del estado en el que se encuentra sea menor que el
// estado final y que el caracter de value sea el mismo que el mismo caracter de
// la posición del estado, si se cumple avanza al siguiente estado.
int AutomataFinito::SiguienteEstado(int state, int value) {
  if (state < state_end_af && value == pattern_af[state])  
    return state + 1;
  int i;
  for (int j = state; j > 0; --j)
    if (pattern_af[j - 1] == value) {  
      for (i = 0; i < j - 1; ++i)  
        if (pattern_af[i] != pattern_af[state - j + 1 + i])  
          break;  
      if (i == j - 1)  
        return j;  
    }
  return 0;  
}