server: build/main.o build/connection.o build/handleClient.o ../shared/build/useful.o ../shared/build/inout.o
	g++ -o server build/main.o build/connection.o build/handleClient.o ../shared/build/useful.o ../shared/build/inout.o -pthread

build/main.o: src/main.cpp
	g++ -o build/main.o -c src/main.cpp

build/connection.o: src/connection.cpp
	g++ -o build/connection.o -c src/connection.cpp

build/handleClient.o: src/handleClient.cpp
	g++ -o build/handleClient.o -c src/handleClient.cpp

../shared/build/useful.o: ../shared/src/useful.cpp
	g++ -o ../shared/build/useful.o -c ../shared/src/useful.cpp

../shared/build/inout.o: ../shared/src/inout.cpp
	g++ -o ../shared/build/inout.o -c ../shared/src/inout.cpp

clean:
	rm build/*.o
	rm ../shared/build/*.o