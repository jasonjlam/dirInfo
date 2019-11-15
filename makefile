all: dir.o main.o
	gcc -o program dir.o main.o

main.o: dir.h main.c
	gcc -c -g main.c


dir.o: dir.c
	gcc -c -g dir.c

run:
	./program

clean:
	rm *.o
