CXX=g++
CXXFLAGS=-std=c++11

# For the test executable
TEST_OBJS=minqueue.o test_minqueue.o
TEST_EXEC=test

# For the usecase executable
USECASE_OBJS=minqueue.o main.o
USECASE_EXEC=usecase

all: $(TEST_EXEC) $(USECASE_EXEC)

$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJS)

$(USECASE_EXEC): $(USECASE_OBJS)
	$(CXX) $(CXXFLAGS) -o $(USECASE_EXEC) $(USECASE_OBJS)

minqueue.o: minqueue.cpp minqueue.h
	$(CXX) $(CXXFLAGS) -c minqueue.cpp

test_minqueue.o: test_minqueue.cpp minqueue.h
	$(CXX) $(CXXFLAGS) -c test_minqueue.cpp

main.o: main.cpp minqueue.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(TEST_OBJS) $(USECASE_OBJS) $(TEST_EXEC) $(USECASE_EXEC)
