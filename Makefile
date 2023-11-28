all: mlab2.o rlab2.o
	gcc rlab2.o mlab2.o
mlab2.o: mlab2.c
	gcc -c mlab2.c
rlab2.c:
	gcc -c rlab2.c
clean:
	rm *.o
