#makefile for the third dictionary program assignment 3
#written by Colby Garland

CC = g++
OBJ = main.o dictionary.o

prog: $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean:
	rm *.o prog


