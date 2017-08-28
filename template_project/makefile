CC=gcc
CFLAGS=-I.
DEPS = p1.h 
OBJ = p1.o

%.o: %.c $(DEPS)
	$(CC) -Wall -Wstrict-prototypes -Wconversion -ansi -pedantic -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	gcc -Wall -Wstrict-prototypes -Wconversion -ansi -pedantic -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)