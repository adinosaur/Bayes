# dinosaur simple im system makefile.

CC = clang++-3.6

all: dictionary document items Training 
	$(CC) --std=c++11 -Wall -g ./build/dictionary.o ./build/document.o ./build/item.o ./build/training.o ./src/main.cc -o ./build/main.out

dictionary:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Dictionary.cc -o ./build/dictionary.o

document:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Document.cc -o ./build/document.o

items:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Items.cc -o ./build/item.o

Training:
	$(CC) --std=c++11 -Wall -g -c ./include/bayes/Training.cc -o ./build/training.o

ut_item:
	$(CC) --std=c++11 -Wall -g ./test/item_unittest.cc -o ./build/item.unittest.out -lgtest -lpthread

ut_document:
	$(CC) --std=c++11 -Wall -g ./test/document_unittest.cc -o ./build/document.unittest.out -lgtest -lpthread

clean:
	rm ./build/*

