server: build/main.o build/connection.o build/handleClient.o ../shared/build/useful.o
	g++ -o server build/main.o build/connection.o build/handleClient.o ../shared/build/useful.o -pthread

build/main.o: src/main.cpp
	g++ -o build/main.o -c src/main.cpp

build/connection.o: src/connection.cpp
	g++ -o build/connection.o -c src/connection.cpp

build/handleClient.o: src/handleClient.cpp
	g++ -o build/handleClient.o -c src/handleClient.cpp

../shared/build/useful.o: ../shared/src/useful.cpp
	g++ -o ../shared/build/useful.o -c ../shared/src/useful.cpp

clean: