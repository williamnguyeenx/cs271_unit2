CXXFLAGS = -std=c++11

usecase: test_minqueue.o
	g++ $(CXXFLAGS) -o usecase test_minqueue.o

test_minqueue.o: test_minqueue.cpp minqueue.h
	g++ $(CXXFLAGS) -c test_minqueue.cpp