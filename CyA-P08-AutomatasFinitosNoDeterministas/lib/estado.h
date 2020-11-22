#include <set>

#include "transicion.h"

class Estado {
    public:
    Estado(const char& id, const char& isFinalState);

    void SetTransicion(const char& character, const char& nextState);

    int    operator==(const Estado& rhs) const;
    int     operator<(const Estado& rhs) const;
    Estado& operator=(const Estado& rhs);

    char GetIdEstado();
    bool GetEstadoFinal();
    int  GetNumeroTransiciones(); 
    std::set<transition> GetConjuntoTransiciones();

  private:
    char id_estado;
    bool estado_aceptacion;
    std::set<transition> conjunto_transiciones;
};