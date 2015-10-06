# dinosaur simple im system makefile.

CC = clang++-3.6

all: dictionary document items Training 
	$(CC) --std=c++11 -Wall -g ./build/dictionary.o ./build/document.o ./build/item.o ./build/training.o ./src/bayes1.cc -o ./build/bayes1.out
	$(CC) --std=c++11 -Wall -g ./build/dictionary.o ./build/document.o ./build/item.o ./build/training.o ./src/bayes2.cc -o ./build/bayes2.out

dictionary:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Dictionary.cc -o ./build/dictionary.o

document:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Document.cc -o ./build/document.o

items:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Items.cc -o ./build/item.o

Training:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Training.cc -o ./build/training.o

dictionary_unittest: dictionary
	$(CC) --std=c++11 -Wall -g ./test/dictionary_unittest.cc ./build/dictionary.o -o ./build/dictionary.unittest.out -lgtest -lpthread

items_unittest: items
	$(CC) --std=c++11 -Wall -g ./test/item_unittest.cc ./build/item.o -o ./build/item.unittest.out -lgtest -lpthread

document_unittest: document items dictionary
	$(CC) --std=c++11 -Wall -g ./test/document_unittest.cc ./build/dictionary.o ./build/document.o ./build/item.o -o ./build/document.unittest.out -lgtest -lpthread

trainingData_unittest:
	$(CC) --std=c++11 -Wall -g ./test/trainingData_unittest.cc ./include/tools/TrainingData.cc -o ./build/trainingData.unittest.out -lgtest -lpthread

clean:
	rm ./build/*

