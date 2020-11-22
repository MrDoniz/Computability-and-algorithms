class transition {
  public:
    transition(const char& character, const char& nextState);
    ~transition();

    char GetSimboloActual();
    char GetEstadoSiguiente();

    int  operator<(const transition& rhs) const;
    int operator==(const transition& rhs) const;
    transition& operator=(const transition& rhs);

  private:
    char simbolo_actual;
    char estado_siguiente;
};