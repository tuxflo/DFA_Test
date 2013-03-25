#Basic Makefiles for dfa_test
CC=g++
CFLAGS= -Wall

dfa_test:
	$(CC) $(CFLAGS) main.cpp -o dfa_test
clean:
	rm -rf *o dfa_test
