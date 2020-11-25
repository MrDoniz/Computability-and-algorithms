/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº: 8
 *
 * @tittle: Estado
 *
 * @author: Dóniz García Daniel
 * @date:   19 Nov 2020
 * @email:  alu0101217277@ull.edu.es
 * @brief:  Esta clase es implemenada para los estados del NFA. Formado por un
 identificado del estado comprobando si es de acpetación o no. Además clase
 aporta la obtención de el identificador de estado, si es de aceptación, el
 cojunto de estados y el conjunto de transiciones. También se define un método
 paraañadir transiciones al estado y finalmente 3 sobrearga de operadores
 necesarios para utilizar los contenedores std::set.
 *
 */

#include "../lib/estado.h"

// Constructor
Estado::Estado(const char& id, const char& aceptacion) {
  id_estado = id;
  if (aceptacion == '1')
    estado_aceptacion = true;
  else
    estado_aceptacion = false;
}

// Destruye el estado creado.
Estado::~Estado() {}

// Devulve el identificador del estado.
char Estado::GetIdEstado() { 
  return id_estado; 
}

// Devulve TRUE si es un estado de aceptación, de o contrario FALSE.
bool Estado::GetEstadoFinal() { 
  return estado_aceptacion; 
}

// Devulve el número de transiciones del estado.
int Estado::GetNumeroTransiciones() { 
  return conjunto_transiciones.size(); 
}

// Devuelve un conjunto de transiciones.
std::set<transition> Estado::GetConjuntoTransiciones() {
  return conjunto_transiciones;
}

// Añade una transición al estado.
void Estado::SetTransicion(const char& simbolo, const char& estado) {
  transition temp(simbolo, estado);
  conjunto_transiciones.insert(temp);
}

// Sobrecarga del operador =
Estado& Estado::operator=(const Estado& segundo_termino) {
  this->id_estado = segundo_termino.id_estado;
  this->estado_aceptacion = segundo_termino.estado_aceptacion;
  this->conjunto_transiciones = segundo_termino.conjunto_transiciones;
  return *this;
}

// Sobrecarga del operador ==
int Estado::operator==(const Estado& segundo_termino) const {
  if (this->id_estado != segundo_termino.id_estado) 
    return 0;
  if (this->estado_aceptacion != segundo_termino.estado_aceptacion) 
    return 0;
  return 1;
}

// Sobrecargadel operador <
int Estado::operator<(const Estado& segundo_termino) const {
  if (this->id_estado < segundo_termino.id_estado) 
    return 1;
  return 0;
}