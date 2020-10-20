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