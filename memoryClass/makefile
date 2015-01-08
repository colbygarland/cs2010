#makefile for the memory management lab for cs2010
#written by Colby Garland

CC = g++
OBJ = memory.o driver.o

prog: $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean:
	rm *.o prog


