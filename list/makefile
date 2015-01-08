#makefile for the stack, queue and driver program.
#written by Colby Garland

CC = g++
OBJ = stack.o queue.o main.o

prog: $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean:
	rm *.o prog
