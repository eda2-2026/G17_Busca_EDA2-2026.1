CC=gcc
CFLAGS=-Wall -Wextra -g

all: tarefas

tarefas: main.o tarefas.o
	$(CC) $(CFLAGS) -o tarefas main.o tarefas.o

main.o: main.c tarefas.h
	$(CC) $(CFLAGS) -c main.c

tarefas.o: tarefas.c tarefas.h
	$(CC) $(CFLAGS) -c tarefas.c

clean:
	rm -f *.o tarefas
