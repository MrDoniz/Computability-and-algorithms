/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 8
 *
 * @tittle: Transición
 *
 * @author: Dóniz García Daniel
 * @date:   19 Nov 2020
 * @email:  alu0101217277@ull.edu.es
 * @brief:  Esta clase es implementada para crear la transición de un estado en
 * un NFA. Formado por el símbolo de la cadena que lee el autómata y el
 * siguiente estado del autómata. También se definen los getters para acceder al
 * caracter y al estado siguiente. Finalmente 3 sobrearga de operadores
 * necesarios para utilizar los contenedores std::set.
 *
 */

#include "../lib/transicion.h"

// Constructor
transition::transition(const char& simbolo, const char& estado) {
  simbolo_actual = simbolo;
  estado_siguiente = estado;
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
transition& transition::operator=(const transition& segundo_termino) {
  this->estado_siguiente = segundo_termino.estado_siguiente;
  this->simbolo_actual = segundo_termino.simbolo_actual;
  return *this;
}

// Sobrecarga del operador ==
int transition::operator==(const transition& segundo_termino) const {
  if (this->estado_siguiente != segundo_termino.estado_siguiente) 
    return 0;
  if (this->simbolo_actual != segundo_termino.simbolo_actual) 
    return 0;
  return 1;
}

// Sobrecargadel operador <
int transition::operator<(const transition& segundo_termino) const {
  if (this->simbolo_actual < segundo_termino.simbolo_actual) 
    return 1;
  if (this->simbolo_actual == segundo_termino.simbolo_actual &&
      this->estado_siguiente < segundo_termino.estado_siguiente)
    return 1;
  return 0;
}