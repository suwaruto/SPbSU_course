CC = gcc
LNK = gcc
CCFLAGS = -g

clean:   
	rm *.o

cleanall: clean
	rm prog.out

%.o: %.c
	$(CC) -c $(CCFLAGS) -o $@ $<

prog.out: arrayio.o main.o timecheck.o sort.o
	$(LNK) -o $@ $?

all: prog.out
