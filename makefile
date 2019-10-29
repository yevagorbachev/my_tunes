ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc

objects: main.o album.o songlist.o

all: $(objects)
	$(CC) -o my_tunes $(objects)

main.o: main.c album.c songlist.c album.h songlist.h
	$(CC) -c main.c

album.o: album.c songlist.c album.h songlist.h
	$(CC) -c album.c

songlist.o: songlist.c songlist.h
	$(CC) -c songlist.c

leak: run
	valgrind --leak-check=yes ./program

run:
	./program

clean:
	rm *.o
	rm *.gch