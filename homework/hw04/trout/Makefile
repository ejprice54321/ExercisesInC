trout.o: trout.h trout.c
	gcc -c trout.c

util.o: util.h util.c
	gcc -c util.c

main: trout.o util.o main.c
	gcc trout.o util.o main.c -o main
