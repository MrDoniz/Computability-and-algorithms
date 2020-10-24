CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = main.cc
F2 = FibonacciWords.cc

IDIR = ../include/
ODIR = ../src/
LDIR = ../lib/

PROGRAM = FibonacciWords

all: $(PROGRAM)
$(PROGRAM): $(ODIR)$(F1) $(ODIR)$(F2)
	$(CC) $(CFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)