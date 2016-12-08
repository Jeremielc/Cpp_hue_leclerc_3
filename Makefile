all : Main run clear


Exception :
	@g++ -c src/Exception.cpp -W -Wall -ansi -pedantic -o obj/Exception.o

Matrix : Exception
	@g++ -c src/Matrix.cpp -W -Wall -ansi -pedantic -o obj/Matrix.o

Main : Matrix
	@g++ -c src/Main.cpp -W -Wall -ansi -pedantic -o obj/Main.o
	@g++ obj/*.o -o bin/matrix

run :
	@./bin/matrix

clear :
	@rm -rf obj/*.o bin/*
