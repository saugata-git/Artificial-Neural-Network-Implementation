CC=g++

CFLAGS= -std=c++14 -c -w

SOURCES= neuron.o instance.o utils.o

# Compile with tester main file
build: neuron.o instance.o utils.o 
	$(CC) $(SOURCES) -o build

neuron.o: neuron.cpp
	$(CC) $(CFLAGS) neuron.cpp
	
instance.o: instance.cpp
	$(CC) $(CFLAGS) instance.cpp
	
utils.o: utils.cpp
	$(CC) $(CFLAGS) utils.cpp
