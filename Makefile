out: main.o bitmap.o filter.o
	g++ *.o -o out

main.o: main.cpp
	g++ -c main.cpp

bitmap.o: bitmap.cpp
	g++ -c bitmap.cpp

filter.o: filter.cpp
	g++ -c filter.cpp

clean:
	rm -f *.o
	rm -f out
