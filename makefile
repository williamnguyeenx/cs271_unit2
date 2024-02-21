CXX=g++
CXXFLAGS=-std=c++11

test: test_minqueue.o
	g++ -o test test_minqueue.o

main.o: test_minqueue.cpp minqueue.h minqueue_cpp usecase.cpp main.cpp
	g++ -c test_minqueue.cpp
