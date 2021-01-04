CC=gcc
AR=ar
CFLAGS=-Wall
all: isort txtfind

isort: isort.c
	$(CC) $(CFLAGS) isort.c -o isort

txtfind: txtfind.c
	$(CC) $(CFLAGS) txtfind.c -o txtfind

.PHONY: clean all

clean:
	rm -f *.o *.a *.so isort txtfind