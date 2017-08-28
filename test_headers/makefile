CC=gcc
CFLAGS=-I.
DEPS = testerJ8-19.h 
OBJ = testerJ8-19.o  extern1.o murky.o 

%.o: %.c $(DEPS)
	$(CC) -Wall -Wstrict-prototypes -Wconversion -ansi -pedantic -c -o $@ $< $(CFLAGS)

testerJ8-19: $(OBJ)
	gcc -Wall -Wstrict-prototypes -Wconversion -ansi -pedantic -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ)