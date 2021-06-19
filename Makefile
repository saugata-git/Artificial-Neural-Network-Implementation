CC=g++

CFLAGS= -std=c++14 -c

SOURCES= neuron.o utils.o 

build: neuron.o utils.o
	$(CC) $(SOURCES) -o build

neuron.o: neuron.cpp
	$(CC) $(CFLAGS) neuron.cpp
	
utils.o: utils.cpp
	$(CC) $(CFLAGS) utils.cpp
