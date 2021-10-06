client: build/main.o build/connection.o ../shared/build/inout.o
	g++ -o client build/main.o build/connection.o ../shared/build/inout.o

build/main.o: src/main.cpp
	g++ -o build/main.o -c src/main.cpp

build/connection.o: src/connection.cpp
	g++ -o build/connection.o -c src/connection.cpp

../shared/build/inout.o: ../shared/src/inout.cpp
	g++ -o ../shared/build/inout.o -c ../shared/src/inout.cpp

clean:
	rm build/*.o
	rm ../shared/build/*.o