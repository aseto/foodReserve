all: reserve

reserve: main.o reservation.o interface.o
	g++ main.o reservation.o interface.o -o reserve

main.o: main.cpp
	g++ -c main.cpp

reservation.o: reservation.cpp
	g++ -c reservation.cpp reservation.h

interface.o: interface.cpp
	g++ -c interface.cpp interface.h

clean:
	rm -rf *o reserve
