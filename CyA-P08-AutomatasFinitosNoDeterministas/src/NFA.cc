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

#include "../lib/NFA.h"

// Constructor.
NFA::NFA() {}

// Destructor.
NFA::~NFA() {}

// Compruebo si el NFA que recibe desde el fichero es correcto, si es así lo
// almaceno, de lo contrario cierro el programa.
bool NFA::ReadFileNFA(const std::string& nfa_file_name) {
  std::string line;
  std::ifstream nfa_file_program(nfa_file_name);

  getline(nfa_file_program, line, '\n');
  numero_de_estados = stoi(line);

  getline(nfa_file_program, line, '\n');
  if (line.size() == 1) {
    estado_inicial = line.at(0);
  } else {
    nfa_file_program.close();
    return false;                                             // DFA solo 1 estado inicial.
  }

  for (unsigned i = 0; i < numero_de_estados;
       ++i) {
    getline(nfa_file_program, line, '\n');
    unsigned j = 0;
    char numero_id_estado = line[j];
    j = j + 2;
    char numero_trans_estado = line[j];
    j = j + 2;
    unsigned transition_number = line[j];
    j = j + 2;

    Estado transicion(numero_id_estado, numero_trans_estado);
    for (unsigned k = j; k < line.length(); k += 4) {
      transicion.SetTransicion(line[k], line[k + 2]);         // Add simbolo y destino
    }
    if (transicion.GetConjuntoTransiciones().size() ==
        (transition_number - '0')) {
      conjunto_estados.insert(transicion);
    } else {
      nfa_file_program.close();
      return false;                                           // DFA numero de transiciones erroneos
    }
  }
  if (numero_de_estados == conjunto_estados.size()) {
    nfa_file_program.close();
    return true;
  } else {
    nfa_file_program.close();
    return false;                                             // DFA estados erroneos
  }
  nfa_file_program.close();
  return false;                                               // Error al abrir el fichero.
}

// Llamo a la función ReadFileImput(), la cual devulve un vector de cadenas.
// Recorro el vector de cadenas y compruebo si cada cadena pertenece al lenguaje
// del NFA, si no pertenece escribo No en el fichero de salida. A continuación
// analizo la cadena y compruebo si se acepta la cadena (TRUE) o no (FALSE). Si
// devuelve TRUE escribo Si en el fichero de salida, si devuelve FALSE escribo
// No en el fichero de salida. Finalmente llamo al método WriteFileOutput(), el
// cual escribirá los resultados obtenidos.
void NFA::Run(const std::string& infile_name, const std::string& outfile_name) {
  ReadFileImput(infile_name);
  for (unsigned i = 0; i < vector_cadenas.size(); i++) {
    std::cout << "Conjunto: " << std::setw(10) << std::left << vector_cadenas[i]
              << " -- " << std::setw(6) << std::left;
    if (AnalizarCadena(vector_cadenas[i])) {
      vector_word_output.push_back("Si");
      std::cout << "Si" << std::endl;
    } else {
      vector_word_output.push_back("No");
      std::cout << "No" << std::endl;
    }
  }
  WriteFileOutput(outfile_name);
}

// Guarda el contenido del fichero de entrada en un vector de cadenas.
void NFA::ReadFileImput(const std::string& infile_name) {
  vector_cadenas.clear();
  std::string line;
  std::ifstream input_file_program(infile_name);
  while (getline(input_file_program, line, '\n')) {
    if (line.size() != 0) 
      vector_cadenas.push_back(line);
  }
  input_file_program.close();
}

// Escribe en el fichero de salida el contenido de un vector de cadenas el cual
// almacena los resultados obtenidos.
void NFA::WriteFileOutput(const std::string& outfile_name) {
  std::ofstream output_file_program(outfile_name);
  for (unsigned i = 0; i < vector_word_output.size(); ++i)
    output_file_program << std::setw(10) << std::left << vector_cadenas[i]
                        << " -- " << std::setw(6) << std::left
                        << vector_word_output[i] << std::endl;
  output_file_program.close();
}

// Comprueba si la cadena pasada es aceptada por el NFA. Extrae el primer
// simbolo de la cadena y recorre los estados del NFA, en el momento en el que
// se termine la cadena, se encuentre en el estado final y este sea de
// aceptación, devuelve TRUE. De lo contrario devuelve FALSE.
bool NFA::AnalizarCadena(const std::string& cadena) {
  char cadena_vacia = char(126);
  std::vector<char> estado_vector_cadena;
  std::vector<std::string> vector_cadena;
  estado_vector_cadena.push_back(estado_inicial);
  vector_cadena.push_back(cadena);
  while (estado_vector_cadena.size() > 0) {
    char numero_estado_actual =
        estado_vector_cadena.at(estado_vector_cadena.size() - 1);
    std::string simbolo = vector_cadena.at(vector_cadena.size() - 1);
    if (simbolo == "") {
      std::set<Estado>::iterator i = conjunto_estados.begin();
      for (unsigned j = 0; j < numero_de_estados; ++j) {
        Estado estado_actual = *i;
        if (estado_actual.GetIdEstado() == numero_estado_actual)
          if (estado_actual.GetEstadoFinal() == true) 
            return true;
        i++;
      }
    }
    estado_vector_cadena.pop_back();
    vector_cadena.pop_back();
    std::set<Estado>::iterator i = conjunto_estados.begin();
    for (unsigned j = 0; j < numero_de_estados; ++j) {
      Estado estado_actual = *i;
      char numero_id_estado = estado_actual.GetIdEstado();
      if (numero_id_estado == numero_estado_actual) {
        std::set<transition> transicion_estado_actual =
            estado_actual.GetConjuntoTransiciones();
        std::set<transition>::iterator k = transicion_estado_actual.begin();
        for (int l = 0; l < estado_actual.GetNumeroTransiciones(); ++l) {
          transition transicion_actual = *k;
          if (simbolo.front() == transicion_actual.GetSimboloActual() ||
              simbolo.front() == cadena_vacia) {
            estado_vector_cadena.push_back(
                transicion_actual.GetEstadoSiguiente());
            vector_cadena.push_back(simbolo.substr(1));
          }
          k++;
        }
        j = numero_de_estados;
      } else {
        i++;
      }
    }
  }
  return false;
}