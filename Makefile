## simple make file for C Ex 1
CC     = gcc
CFLAGS =  -ansi -Wall -g

all: calcdist

calcdist: trie.o GetDistance.o
	$(CC) $(CFLAGS) -o calcdist trie.o GetDistance.o

GetDistance.o: GetDistance.c 
	$(CC) $(CFLAGS) -g  -c GetDistance.c


trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -g  -c trie.c


##This is not the best way to do this
clean: 
	rm -f trie.o calcdist GetDistance.o  *~

