ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

objects = main.o library.o songlist.o

all: $(objects)
	$(CC) -o my_tunes $(objects)

main.o: main.c library.c songlist.c library.h songlist.h
	$(CC) -c main.c

library.o: library.c songlist.c library.h songlist.h
	$(CC) -c library.c

songlist.o: songlist.c songlist.h
	$(CC) -c songlist.c

leak: run
	valgrind --leak-check=yes ./my_tunes

run:
	./my_tunes

clean:
	rm *.o