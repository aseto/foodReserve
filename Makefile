all: reserve

reserve: main.o reservation.o restaurant.o
	g++ main.o reservation.o restaurant.o -o reserve

main.o: main.cpp
	g++ -c main.cpp

restaurant.o: restaurant.cpp
	g++ -c restaurant.cpp restaurant.h

reservation.o: reservation.cpp
	g++ -c reservation.cpp reservation.h

clean:
	rm -rf *o reserve
