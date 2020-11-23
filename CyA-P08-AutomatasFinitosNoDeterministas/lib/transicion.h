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

class transition {
  public:
    /** @brief Crea una transición.
     * @param simbolo Simbolo actual de la transición
     * @param estado Estado siguiente de la transición.
     */
    transition(const char& simbolo, const char& estado);
    /** @brief Destruye el estado creado.
     */
    ~transition();

    /** @brief Obtiene el símbolo de la transición.
     * @returns Devuelve el simbolo leído.
     */
    char GetSimboloActual();
    /** @brief Obtiene el estado siguiente de la transición.
     * @returns Devuelve el siguiente estado leído.
     */
    char GetEstadoSiguiente();

    /** @brief Sobrecarga del operador de asignación para la transición.
     * @param segundo_termino Segundo término de la operación.
     * @returns Un puntero donde almacenar el segundo termino.
     */
    transition& operator=(const transition& segundo_termino);
    /** @brief Sobrecarga del operador de igualdad para la transición.
     * @param segundo_termino Segundo término de la operación.
     * @returns Si se cumple la condición 1, de lo contrario 0.
     */
    int operator==(const transition& segundo_termino) const;
    /** @brief Sobrecarga del operador de menor que para la transición.
     * @param segundo_termino Segundo término de la operación.
     * @returns Si se cumple la condición 1, de lo contrario 0.
     */
    int operator<(const transition& segundo_termino) const;

  private:
    char simbolo_actual;
    char estado_siguiente;
};