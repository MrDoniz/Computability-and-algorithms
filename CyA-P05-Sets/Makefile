# Makefile

### Variables ###

CC			:= g++ -g -Wall -Wextra -std=c++17
CCO			:= g++ -g -Wall -Wextra -std=c++17 -c

MAIN.C		:= src/set_test.cc
MAIN.E		:= set_test.out

PALIND.H	:= src/Set.h
PALIND.C	:= src/Set.cc
PALIND.O	:= src/Set.o
 



### Functions ###

all: $(MAIN.C) $(PALIND.O)
	$(CC) $(MAIN.C) $(PALIND.O) -o $(MAIN.E)

$(PALIND.O): $(PALIND.C) $(PALIND.H)
	$(CCO) $(PALIND.C) -o $(PALIND.O)

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.out" -type f -delete
