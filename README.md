foodReserve
===========

Restaurant reservations                                  

Restaurant Reservation System

contributors: aseto
url: https://github.com/aseto/foodReserve

To set up this program, first enter
$make clean
In order to make a clean state.  Then enter
$make
to create the executable for the reservation system.

To start the reservation system, type ./reserve followed by 3 numbers.
- The first number is how many small tables (seat up to 2 people) are in the restaurant
- The second number is how many medium tables (seat up to 4 people) are in the restaurant
- The third number is how many large tables (seat up to 8 people) are in the restaurant

If you do not add the three arguements, the program will not run.

So for example to run the program if you have a restaurant with 12 small tables,
8 medium tables, and 2 large tables, enter:

$./reserve 12 8 2

---

This project will be used to set and look at reservations for a restaurant.
This will be done through command line arguements.  The user will be able to
tell the program certain information about the reservation such as what day it
will be and what time, how many people are in the party, and any special notes.
The user can also see the list of all the reservations that were made already.
This project will show Unix design philosophy by having seperate classes that
handle the specific jobs in order to create good separation and modularity if
it needs to be changed in the future.  This also helps make the program more
simplicity and makes the program easier to extend if more things need to be
added to the reservation system.


