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

#include <set>

#include "transicion.h"

/** @brief Esta clase es implemenada para los estados del NFA. Formado por un
 * identificado del estado comprobando si es de acpetación o no.
 */
class Estado {
  public:
    /** @brief Crea un estado.
     *  @param id Número identificativo del estado.
     *  @param aceptacion Bool que identifica si es un estado de aceptación.
     */
    Estado(const char& id, const char& aceptacion);
    /** @brief Destruye el estado creado.
     */
    ~Estado();

    /** @brief Getter, permite obtener el identificador del estado.
     *  @returns devuelve el identificador del estado.
     */
    char GetIdEstado();
    /** @brief Getter, permite obtener si es el estado es de aceptación.
     *  @returns TRUE si es un estado de aceptación, de o contrario FALSE.
     */
    bool GetEstadoFinal();
    /** @brief Getter, permite obtener el numero de transiciones del estado.
     *  @returns devuelve el número de transiciones del estado.
     */
    int GetNumeroTransiciones();
    /** @brief Getter, permite obtener el conjunto de transiciones de un estado.
     *  @returns devuelve el conjunto de transiciones del estado.
     */
    std::set<transition> GetConjuntoTransiciones();
    /** @brief Setter, permite añadir una transición al estado.
     *  @param simbolo del alfabeto del alfabeto con el que se produce la transición.
     *  @param estado destino de la transición.
     */
    void SetTransicion(const char& simbolo, const char& estado);

    /** @brief Sobrecarga del operador de asignación para el estado.
     * @param segundo_termino Segundo término de la operación.
     * @returns Un puntero donde almacenar el segundo termino.
     */
    Estado& operator=(const Estado& segundo_termino);
    /** @brief Sobrecarga del operador de igualdad para el estado.
     * @param segundo_termino Segundo término de la operación.
     * @returns Si se cumple la condición 1, de lo contrario 0.
     */
    int operator==(const Estado& segundo_termino) const;
      /** @brief Sobrecarga del operador de menor que para el estado.
       * @param segundo_termino Segundo término de la operación.
       * @returns Si se cumple la condición 1, de lo contrario 0.
       */
    int operator<(const Estado& segundo_termino) const;

  private:
    char id_estado;
    bool estado_aceptacion;
    std::set<transition> conjunto_transiciones;
};