text0 = 
text1 = Se procedera a compilar la práctica...
text2 = Modo de empleo:
text3 = ./
text4 = Se ha eliminado el fichero ejecutable.
text5 = Se ha eliminado el fichero de salida.

F1 = main.cc
F2 = NFA.cc
F3 = estado.cc
F4 = transicion.cc
ODIR = src/
CXXFLAGS= g++ -std=c++14 -g -Wall
PROGRAM = nfa_simulation

all: CYA

Inicio:
	@echo $(text1)

CYA: $(F) Inicio
	$(CXXFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) -o $(PROGRAM)
	@echo $(text0)
	@echo $(text2) $(text3)$(PROGRAM)
clean:
	rm -rf $(PROGRAM)
	rm -rf output.txt
	@echo $(text0)
	@echo $(text4)
	@echo $(text5)