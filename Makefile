CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -fprofile-arcs -ftest-coverage
LDFLAGS = -lgtest

all: unittest

run: test.out
	./test.out

coverage: run
	gcov -brac next_date.cpp
	cat ./next_date.cpp.gcov | c++filt > ./next_date.cpp.gcov.filt

## b : branch, r : relative only, a : show basic block, c : show count


unittest: CXXFLAGS += -D__UNIT_TEST__
unittest: test.out

test.out: test.cpp next_date.cpp
	$(CXX) -o test.out $(CXXFLAGS) $(LDFLAGS) ./test.cpp ./next_date.cpp

clean:
	rm -f *.out
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.filt

.PHONY: clean all
