# makefile for the craps program

CC = g++
OBJ = craps.o

prog: $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean:
	rm *.o prog
