void Pattern::Run() {
  ReadFileImput();
  for (unsigned i = 0; i < vector_conjuntos.size(); i++) {
    std::cout << "Conjunto: " << vector_conjuntos[i] << "\t\t";
    if (TestSet(i)) {
      AutomataFinito AutomataFinitoFirst(vector_conjuntos[i], pattern, state_end);
      if (AutomataFinitoFirst.Search()) {
        vector_word_output.push_back("Si");
        std::cout << "Si" << std::endl;
      } else {
        vector_word_output.push_back("No");
        std::cout << "No" << std::endl;
      }
    } else {
      vector_word_output.push_back("Error");
      std::cout << "Error" << std::endl;
    }
  }
  WriteFileOutput();
}




Saltar a contenido principal
Ingeniería y Tecnología

    DANIEL DÓNIZ GARCÍA

COMPUTABILIDAD Y ALGORITMIA

    Página Principal
    Mis cursos
    CyA 2020-2021
    Práctica 6: Autómata reconocedor de patrones
    2020-2021 Cuestionario lenguajes regulares y autómatas finitos

Comenzado el	miércoles, 11 de noviembre de 2020, 15:37
Estado	Finalizado
Finalizado en	miércoles, 11 de noviembre de 2020, 15:45
Tiempo empleado	7 minutos 58 segundos
Calificación	3,42 de 10,00 (34%)
Pregunta 1
Parcialmente correcta
Puntúa 0,50 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

Indique las afirmaciones que sean ciertas

La ϵ
-clausura de un estado la componen aquellos estados alcanzables desde éste mediante ϵ

transiciones

Para calcular la ϵ

-clausura de un estado hay que tener en cuenta al menos un símbolo del alfabeto

La ϵ

-clausura de un estado no puede contener estados de muerte

La ϵ

-clausura de un conjunto de estados siempre contiene a dicho conjunto

La ϵ

-clausura de un estado es un conjunto de estados

La ϵ

-clausura de un estado no puede ser un conjunto vacío
Retroalimentación
Respuesta parcialmente correcta.
Ha seleccionado correctamente 2.
Las respuestas correctas son:

La ϵ

-clausura de un conjunto de estados siempre contiene a dicho conjunto
,

La ϵ

-clausura de un estado es un conjunto de estados

,

La ϵ
-clausura de un estado la componen aquellos estados alcanzables desde éste mediante ϵ

transiciones

,

La ϵ

-clausura de un estado no puede ser un conjunto vacío

Pregunta 2
Correcta
Puntúa 1,00 sobre 1,00
Marcar pregunta
Enunciado de la pregunta
Si L
es finito ⇒L
es regular
Seleccione una:
Verdadero
Falso
Retroalimentación
La respuesta correcta es 'Verdadero'
Pregunta 3
Incorrecta
Puntúa 0,00 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

Sabemos que un autómata finito es no determinista si:
Seleccione una o más de una:

Desde un estado q
con el símbolo σ
transita a un conjunto de estados T
con Card(T)>1

Tiene menos de n×m
transiciones, siendo n
el número de estados y m

el número de símbolos del alfabeto.

Tiene más de dos transiciones para un estado o más de dos transiciones etiquetadas con el mismo símbolo

No tiene estados de muerte

Tiene ϵ

-transiciones

Tiene exactamente una transición desde cada estado
Retroalimentación

Respuesta incorrecta.
Las respuestas correctas son: Tiene ϵ
-transiciones
, Tiene menos de n×m
transiciones, siendo n
el número de estados y m
el número de símbolos del alfabeto.
, Desde un estado q
con el símbolo σ
transita a un conjunto de estados T
con Card(T)>1

Pregunta 4
Incorrecta
Puntúa 0,00 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

Indique las sentencias que sean ciertas
Seleccione una o más de una:

Σ∗

es siempre un conjunto infinito

Si L
es un lenguaje no vacío, entonces L∗

es infinito

La cadena vacía (ϵ
) siempre pertenece a L+
para todo lenguaje L

Para todo lenguaje L
,  siempre L∗
es distinto de L+

 

∅0={ϵ}

Retroalimentación

Respuesta incorrecta.
Las respuestas correctas son: ∅0={ϵ}

, Σ∗
es siempre un conjunto infinito
Pregunta 5
Correcta
Puntúa 1,00 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

El algoritmo de minimización de estados
Seleccione una o más de una:

Se puede aplicar a cualquier autómata finito

Da como resultado un DFA equivalente con mínimo número de estados

Detecta estados con transiciones idénticas

Se puede aplicar antes de aplicar el algoritmo de construcción de subconjuntos

Se puede aplicar a cualquier DFA

Detecta conjuntos de estados que rechazan y aceptan exactamente las mismas cadenas
Retroalimentación

Respuesta correcta
Las respuestas correctas son: Se puede aplicar a cualquier DFA, Da como resultado un DFA equivalente con mínimo número de estados, Detecta conjuntos de estados que rechazan y aceptan exactamente las mismas cadenas
Pregunta 6
Incorrecta
Puntúa 0,00 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

Un DFA puede tener
Seleccione una o más de una:
Ningún estado de arranque y varios estados de aceptación
Varios estados de aceptación
Ningún estado de aceptación
Un único estado de arranque y ningún estado de aceptación
Un único estado inicial y un único estado de aceptación
Más de un estado de arranque
Retroalimentación
Las respuestas correctas son: Un único estado inicial y un único estado de aceptación, Un único estado de arranque y ningún estado de aceptación, Ningún estado de aceptación, Varios estados de aceptación
Pregunta 7
Parcialmente correcta
Puntúa 0,25 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

Dos autómatas finitos son equivalentes si:
Seleccione una o más de una:

Ambos reconocen el mismo lenguaje

Ambos son deterministas o si, por el contrario, ambos son no deterministas

Todas las cadenas rechazadas por uno, son rechazadas también por el otro

Ambos tienen el mismo número de estados y de transiciones

Ambos tienen un mismo DFA equivalente mínimo

Ambos tienen la misma función de transición
Retroalimentación

Respuesta parcialmente correcta.
Ha seleccionado correctamente 1.
Las respuestas correctas son: Ambos tienen un mismo DFA equivalente mínimo, Ambos reconocen el mismo lenguaje
Pregunta 8
Incorrecta
Puntúa 0,00 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

Los estados importantes de un NFA
Seleccione una o más de una:
Son los estados que tienen ϵ
-transiciones hacia otro estado
Son los estados desde los que no sale ninguna transición
Son únicamente los estados de aceptación

Son únicamente aquellos estados que tienen alguna transición etiquetada con algún símbolo del alfabeto
Ninguna de las otras respuestas es correcta

Son los estados de muerte
Retroalimentación
La respuesta correcta es: Ninguna de las otras respuestas es correcta
Pregunta 9
Parcialmente correcta
Puntúa 0,17 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

Indique las sentencias que sean ciertas
Seleccione una o más de una:

{ϵ}∗=∅

{ϵ}∗={ϵ}

$$  \emptyset^n =  \emptyset \: \forall n \geq 1$$

$$  \emptyset^0 = \{ \epsilon \} $$

$$  \emptyset^0 = \emptyset $$
Retroalimentación

Respuesta parcialmente correcta.
Ha seleccionado correctamente 2.
Las respuestas correctas son: $$ \{ \epsilon \} ^* = \{ \epsilon \} $$
, $$  \emptyset^0 = \{ \epsilon \} $$
, $$  \emptyset^n =  \emptyset \: \forall n \geq 1$$
Pregunta 10
Parcialmente correcta
Puntúa 0,50 sobre 1,00
Marcar pregunta
Enunciado de la pregunta

El algoritmo de construcción de subconjuntos
Seleccione una o más de una:
Permite hallar un NFA equivalente a un DFA dado
Permite hallar un DFA equivalente a un NFA dado
Permite minimizar el número de estados de un NFA
Partiendo de un NFA, permite hallar una expresión regular que representa al lenguaje que el NFA reconoce
Partiendo de un DFA, permite hallar una expresión regular que representa al lenguaje que el NFA reconoce

Permite hallar un DFA mínimo equivalente a un NFA dado
Permite minimizar el número de estados de un DFA
Partiendo de una expresión regular (ER), permite hallar un NFA que reconoce el lenguaje al que la ER representa
Retroalimentación
La respuesta correcta es: Permite hallar un DFA equivalente a un NFA dado
Finalizar revisión
Ir a...
Saltar <span id="mod_quiz_navblock_title">Navegación por el cuestionario</span>
Navegación por el cuestionario
Finalizar revisión

    Universidad de La Laguna
    Pabellón de Gobierno, C/ Padre Herrera s/n. | 38200 | Apartado Postal 456 | San Cristóbal de La Laguna | España | (+34) 922 31 90 00





void removeDupWord(string str)
{
    string word = "";
    for (auto x : line) 
    {
        if (x == ' ')
        {
            vector_conjuntos.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    vector_conjuntos.push_back(word);
}
 
// Driver code
int main()
{
    string str = "Geeks for Geeks";
    removeDupWord(str);
    return 0;
}






// CPP program for Finite Automata Pattern searching 
// Algorithm 
#include <bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 

int getNextState(string pat, int M, int state, int x) 
{ 
	// If the character c is same as next character 
	// in pattern,then simply increment state 
	if (state < M && x == pat[state]) 
		return state+1; 

	// ns stores the result which is next state 
	int ns, i; 

	// ns finally contains the longest prefix 
	// which is also suffix in "pat[0..state-1]c" 

	// Start from the largest possible value 
	// and stop when you find a prefix which 
	// is also suffix 
	for (ns = state; ns > 0; ns--) 
	{ 
		if (pat[ns-1] == x) 
		{ 
			for (i = 0; i < ns-1; i++) 
				if (pat[i] != pat[state-ns+1+i]) 
					break; 
			if (i == ns-1) 
				return ns; 
		} 
	} 

	return 0; 
} 

/* This function builds the TF table which represents4 
	Finite Automata for a given pattern */
void computeTF(string pat, int M, int TF[][NO_OF_CHARS]) 
{ 
	int state, x; 
	for (state = 0; state <= M; ++state) 
		for (x = 0; x < NO_OF_CHARS; ++x) 
			TF[state][x] = getNextState(pat, M, state, x); 
} 

/* Prints all occurrences of pat in txt */
void search(string pat, string txt) 
{ 
	int M = pat.size(); 
	int N = txt.size(); 

	int TF[M+1][NO_OF_CHARS]; 

	computeTF(pat, M, TF); 

	// Process txt over FA. 
	int i, state=0; 
	for (i = 0; i < N; i++) 
	{ 
		state = TF[state][txt[i]]; 
		if (state == M) 
			cout<<" Pattern found at index "<< i-M+1<<endl; 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	string txt = "AABAACAADAABAAABAA"; 
	string pat = "AABA"; 
	search(pat, txt); 
	return 0; 
} 

//This code is contributed by rathbhupendra 



Expresiónón regular
	Construcción de Thompson
NFA
	Algoritmo de transformación de subconjuntos.
DFA
	Algoritmo de minimización de estados.
DFA mínimo

Leguajes regulares
¿Cierto lenguaje es regular?
Eso lo sabemos con el Expresión Regular, DFA, NFA y Gramática regular

Si es un lenguaje es finito, la manera de demostrarlo es con la expresión regular.


Que hace el no se q de un subconjunto

Que somo hay una correcta y es la corta q dice construye un dfa a partir de un nfa dado

Y una q es verdadera

L=> L