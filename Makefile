
main: main.o binary_search.o
	g++ -o main main.o binary_search.o
main.o: main.cc binary_search.h
	g++ -c main.cc binary_search.h -include binary_search.h
binary_search.o: binary_search.cc binary_search.h
	g++ -c binary_search.cc -include binary_search.h
clean:
	rm -f main main.o binary_search.o
