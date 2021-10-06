client: build/main.o build/connection.o build/drawui.o ../shared/build/inout.o ../lib/textblock.o
	g++ -o client build/main.o build/connection.o build/drawui.o ../shared/build/inout.o ../lib/textblock.o

build/main.o: src/main.cpp
	g++ -o build/main.o -c src/main.cpp

build/connection.o: src/connection.cpp
	g++ -o build/connection.o -c src/connection.cpp

build/drawui.o: src/drawui.cpp
	g++ -o build/drawui.o -c src/drawui.cpp

../shared/build/inout.o: ../shared/src/inout.cpp
	g++ -o ../shared/build/inout.o -c ../shared/src/inout.cpp

clean:
	rm build/*.o
	rm ../shared/build/*.o