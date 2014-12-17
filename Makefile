CFLAGS= -c -std=c99
CC=gcc

all: test
test: kvlib.o speedtest.o
	$(CC) kvlib.o speedtest.o -o test
kvlib.o: kvlib.h kvlib.c
	$(CC) kvlib.c $(CFLAGS)
speedtest.o: kvlib.h speedtest.c
	$(CC) speedtest.c $(CFLAGS)
clean:
	rm *.o test
