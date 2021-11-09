CC=gcc
CFLAGS=-Wall -g

.PHONY: all clean

all: bin bin/driver 

bin:
	mkdir -p bin
	
bin/driver: bin/driver.o bin/bst.o
	${CC} ${CFLAGS} bin/driver.o bin/bst.o -o bin/driver
	
bin/driver.o: src/driver.c 
	${CC} ${CFLAGS} -c src/driver.c -o bin/driver.o
	
bin/bst.o: src/bst.c include/bst.h
	${CC} ${CFLAGS} -c src/bst.c -o bin/bst.o
	
clean:
	rm -rf bin/*.o bin/driver