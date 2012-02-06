## simple make file for C Ex 1
CC     = gcc
CFLAGS =  -ansi -Wall -g

all: TrieTest

TrieTest: trie.o main.o
	$(CC) $(CFLAGS) -o TrieTest trie.o main.o

main.o: main.c 
	$(CC) $(CFLAGS) -g  -c main.c


trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -g  -c trie.c


##This is not the best way to do this
clean: 
	rm -f trie.o TrieTest main.o  *~

