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

#define NO_OF_CHARS 125  

class AutomataFinito {
 public:
    AutomataFinito(std::string conjunto, std::string pattern, int state_end);
    ~AutomataFinito();

    bool Search();
    void RunAutomataFinito(int TF[][NO_OF_CHARS]);
    int getNextState(int state, int x);

 private:
    std::string pattern_af;
    std::string conjunto_af;
    int state_end_af;
};
