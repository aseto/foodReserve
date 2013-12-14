all: reserve

reserve: main.o reservation.o
	g++ main.o reservation.o -o reserve

main.o: main.cpp
	g++ -c main.cpp

reservation.o: reservation.cpp
	g++ -c reservation.cpp reservation.h

clean:
	rm -rf *o reserve
