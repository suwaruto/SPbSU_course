CC = gcc
LNK = gcc
CCFLAGS = -g
OBJ = arrayio.o main.o timecheck.o sort.o

clean:   
	rm *.o

cleanall: clean
	rm prog.out

%.o: %.c
	$(CC) -c $(CCFLAGS) -o $@ $<

prog.out: $(OBJ) 
	$(LNK) -o $@ $?

all: prog.out
