CC=g++
CFLAGS=-c -Wall -Werror -Wextra
SOURCES=deixtra.cpp
EXECUTABLE=main

all: $(EXECUTABLE) run
	
$(EXECUTABLE):
	$(CC) -o $@ $(SOURCES)

run:
	./$(EXECUTABLE)
	
clean:
	rm -rf *.o $(EXECUTABLE)
	
re: clean all run