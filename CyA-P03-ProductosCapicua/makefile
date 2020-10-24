CC = g++
CFLAGS = -std=c++14 -g -Wall
OBJFILES = palindrome_prod.cc
TARGET = palindrome_prod

all: $(TARGET)
$(TARGET): src/$(OBJFILES)
	$(CC) $(CFLAGS) -o build/$(TARGET) src/$(OBJFILES) $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf build/*


g++ ../src/FibonacciWords.cc ../src/main.cc

/////////////////////////////////

# "all" is the name of the default target, running "make" without params would use it
all: executable1

# for C++, replace CC (c compiler) with CXX (c++ compiler) which is used as default linker
CC=$(CXX)

# tell which files should be used, .cpp -> .o make would do automatically
executable1: file1.o file2.o

CC=g++
CFLAGS=-I$(IDIR)

IDIR =../include
ODIR=../src
LDIR =../lib

LIBS=-lm

_DEPS = FibonacciWords.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = FibonacciWords.o FibonacciWords.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

FibonacciWords: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 



CC=gcc

DEPS = hello.h
OBJ = hello.o
INC=-I. -I../lib/StanfordCPPLib

%.o: %.cpp $(DEPS)
    $(CC) $(INC) -c $<

hellomake: $(OBJ)
    g++ -o $@ $^



.POSIX:

include config.mk

# Sources
CXXSRC = $(shell find src -name *.cpp)
CCSRC  = $(shell find src -name *.cc)

# Objects
CXXOBJ = $(CXXSRC:.cpp=.o)
CCOBJ  = $(CCSRC:.cc=.o)
OBJ    = $(CXXOBJ) $(CCOBJ)

# Dependency files
DEPS   = $(OBJ:.o=.d)

all: $(NAME)

# Compilation
.cpp.o:
	$(CXX) $(COMMON_FLAGS) $(CXXFLAGS) -MMD -c -o $@ $<
.cc.o:
	$(CC) $(COMMON_FLAGS) $(CCFLAGS) -MMD -c -o $@ $<

# Linking
$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

# Dependencies
-include $(DEPS)

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS  += -DDEBUG -g
debug: $(NAME)

clean:
	rm -f $(NAME) $(OBJ) $(DEPS)

run: $(NAME)
	./$(NAME)

dump: $(NAME)
	objdump -dC $(NAME) > $(NAME).asm

.PHONY: all clean


