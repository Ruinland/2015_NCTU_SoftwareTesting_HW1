all:
	g++ -lgtest -o test ./test.cpp triangle.cpp
	./test

.PHONY: clean
clean:
	rm -rf ./test
