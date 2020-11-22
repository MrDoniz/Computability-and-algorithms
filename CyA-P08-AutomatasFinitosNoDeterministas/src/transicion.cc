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
 * @brief:  
 *
 */

#include "../lib/transicion.h"

// Constructor
transition::transition(const char& character, const char& nextState) {
  simbolo_actual = character;
  estado_siguiente = nextState;   
}

// Destructor
transition::~transition() {}

// Devulve el simbolo leído.
char transition::GetSimboloActual() {
  return simbolo_actual;
}

// Devuelve el siguiente estado leído.
char transition::GetEstadoSiguiente() {
  return estado_siguiente;
}

// Sobrecarga del operador =
transition& transition::operator=(const transition& rhs) {
  this->simbolo_actual = rhs.simbolo_actual;
  this->estado_siguiente = rhs.estado_siguiente;
  return *this;
}

// Sobrecarga del operador ==
int transition::operator==(const transition& rhs) const {
  if (this->simbolo_actual != rhs.simbolo_actual) 
    return 0;
  if (this->estado_siguiente != rhs.estado_siguiente) 
    return 0;
  return 1;
}

// Sobrecargadel operador <
int transition::operator<(const transition& rhs) const {
  if (this->simbolo_actual== rhs.simbolo_actual && this->estado_siguiente < rhs.estado_siguiente) 
    return 1;
  if (this->simbolo_actual < rhs.simbolo_actual) 
    return 1;
  return 0;
}