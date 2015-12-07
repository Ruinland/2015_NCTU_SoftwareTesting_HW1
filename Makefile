CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -fprofile-arcs -ftest-coverage
LDFLAGS = -lgtest

all: unittest

run: test.out
	./test.out

coverage: run
	gcov -brac triangle.cpp
	cat ./triangle.cpp.gcov | c++filt > ./triangle.cpp.gcov.filt

## b : branch, r : relative only, a : show basic block, c : show count


unittest: CXXFLAGS += -D__UNIT_TEST__
unittest: test.out

test.out: test.cpp triangle.cpp
	$(CXX) -o test.out $(CXXFLAGS) $(LDFLAGS) ./test.cpp ./triangle.cpp

clean:
	rm -f *.out
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.filt

.PHONY: clean all
