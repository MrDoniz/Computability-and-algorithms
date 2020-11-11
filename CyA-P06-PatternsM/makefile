CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = main.cc
F2 = pattern_search.cc
F3 = automata_finito.cc

ODIR = src/

PROGRAM = pattern_search

all: $(PROGRAM)
$(PROGRAM): $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3)
	$(CC) $(CFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf outfile.txt