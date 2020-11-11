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


AutomataFinito::AutomataFinito(std::string conjunto, std::string pattern, int state_end) {
  conjunto_af  = conjunto;
  pattern_af   = pattern;
  state_end_af = state_end;
}

AutomataFinito::~AutomataFinito() {}

bool AutomataFinito::Search() {
  int automata_finito[pattern_af.size() + 1][NO_OF_CHARS];
  RunAutomataFinito(automata_finito);
  unsigned state = 0; 
  for (unsigned i = 0; i < conjunto_af.size(); i++) {
    state = automata_finito[state][(unsigned char) conjunto_af[i]];
    if (state == pattern_af.size())
      return true; 
  }
  return false;
}

void AutomataFinito::RunAutomataFinito(int automata_finito[][NO_OF_CHARS]) { 
  int state, x;
  for (state = 0; state <= state_end_af; ++state)  
    for (x = 0; x < NO_OF_CHARS; ++x)  
      automata_finito[state][x] = getNextState(state, x);
}

int AutomataFinito::getNextState(int state, int x) {
  if (state < state_end_af && x == pattern_af[state])  
    return state + 1;
  int i;
  for (int ns = state; ns > 0; ns--)
    if (pattern_af[ns-1] == x) {  
      for ( i = 0; i < ns-1; i++)  
        if (pattern_af[i] != pattern_af[state-ns+1+i])  
          break;  
      if (i == ns-1)  
        return ns;  
    }
  return 0;  
}