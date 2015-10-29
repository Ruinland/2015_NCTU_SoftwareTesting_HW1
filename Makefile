all:
	g++ -lgtest -o test ./test.cpp next_date.cpp
	./test

.PHONY: clean
clean:
	rm -rf ./test
