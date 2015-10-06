# dinosaur simple im system makefile.

CC = clang++-3.6

all: dictionary items modeling 
	$(CC) --std=c++11 -Wall -g ./build/dictionary.o ./build/item.o ./build/modeling.o ./src/bayes1.cc -o ./build/bayes1.out
	$(CC) --std=c++11 -Wall -g ./build/dictionary.o ./build/item.o ./build/modeling.o ./src/bayes2.cc -o ./build/bayes2.out

modeling:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Modeling.cc -o ./build/modeling.o

dictionary:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Dictionary.cc -o ./build/dictionary.o

items:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Items.cc -o ./build/item.o

dictionary_unittest: dictionary
	$(CC) --std=c++11 -Wall -g ./test/dictionary_unittest.cc ./build/dictionary.o -o ./build/dictionary.unittest.out -lgtest -lpthread

items_unittest: items
	$(CC) --std=c++11 -Wall -g ./test/item_unittest.cc ./build/item.o -o ./build/item.unittest.out -lgtest -lpthread

document_unittest: items dictionary
	$(CC) --std=c++11 -Wall -g ./test/document_unittest.cc ./build/dictionary.o ./build/document.o ./build/item.o -o ./build/document.unittest.out -lgtest -lpthread

trainingData_unittest:
	$(CC) --std=c++11 -Wall -g ./test/trainingData_unittest.cc ./include/tools/TrainingData.cc -o ./build/trainingData.unittest.out -lgtest -lpthread

clean:
	rm ./build/*

