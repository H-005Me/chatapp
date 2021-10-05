client: build/main.o build/connection.o
	g++ -o client build/main.o build/connection.o

build/main.o: src/main.cpp
	g++ -o build/main.o -c src/main.cpp

build/connection.o: src/connection.cpp
	g++ -o build/connection.o -c src/connection.cpp
