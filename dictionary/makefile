# Colby Garland ID# 5034957
# makefile for the dictionary program

CC = g++
OBJ = dict.o

prog: $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean:
	rm *.o prog
