CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -fprofile-arcs -ftest-coverage 
LDFLAGS = -lgtest

all: unittest

run: test.out
	./test.out

coverage: run
	gcov -brac next_date.cpp
	cat ./next_date.cpp.gcov | c++filt > ./next_date.cpp.gcov.filt

## b : branch, r : relative only, a : show basic block, c : show count

klee-test: test.cpp next_date.cpp
	clang++ -std=c++11 -D__KLEE__ -I/home/klee/klee_src/include -emit-llvm -c -g next_date.cpp
	#llvm-link ./klee_next_date.bc ./next_date.bc -o ./klee_test.bc

unittest: CXXFLAGS += -D__UNIT_TEST__
unittest: test.out

test.out: test.cpp next_date.cpp
	$(CXX) -o test.out $(CXXFLAGS) ./test.cpp ./next_date.cpp $(LDFLAGS) 

clean:
	rm -f *.out
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.filt
	rm -f *.bc
	rm -rf klee-*

.PHONY: clean all
