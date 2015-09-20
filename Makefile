# dinosaur simple im system makefile.

CC = clang++-3.6

ut_item:
	$(CC) --std=c++11 -Wall -g ./test/item_unittest.cc -o ./build/item.unittest.out -lgtest -lpthread

ut_document:
	$(CC) --std=c++11 -Wall -g ./test/document_unittest.cc -o ./build/document.unittest.out -lgtest -lpthread

clean:
	rm ./build/*

