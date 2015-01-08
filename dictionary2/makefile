#makefile for the second dictionary program
#written by Colby Garland

CC = g++
OBJ = main.o dictionary.o

prog: $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean:
	rm *.o prog


