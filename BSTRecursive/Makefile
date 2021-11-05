CC=gcc
CFLAGS=-Wall -g

.PHONY: all clean

all: bin bin/driver 

bin:
	mkdir -p bin
	
bin/driver: bin/driver.o
	${CC} ${CFLAGS} bin/driver.o -o bin/driver
	
bin/driver.o: src/driver.c 
	${CC} ${CFLAGS} -c src/driver.c -o bin/driver.o
	
clean:
	rm -rf bin/*.o bin/driver