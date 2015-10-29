all:
	g++ -lgtest -std=c++11 -o test ./test.cpp next_date.cpp
	./test

.PHONY: clean
clean:
	rm -rf ./test
