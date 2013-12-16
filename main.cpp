#include "reservation.h"
#include "restaurant.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
  string var1, var2, var3;

  cout << "First, please set up your restaurant" << endl;
  cout << "How many small tables (seat up to 2) are there? ";
  cin >> var1;
  cout << "How many medium tables (seat up to 4) are there? ";
  cin >> var2;
  cout << "How many large tables (seat up to 8) are there? ";
  cin >> var3;

    //var1 = argv[1];
    //var2 = argv[2];
    //var3 = argv[3];
    int small, medium, large;
    small = atoi(var1.c_str());
    medium = atoi(var2.c_str());
    large = atoi(var3.c_str());
    restaurant myRestaurant(small, medium, large);

  cout << "To make a reservation, type 'make'" << endl;
  cout << "To cancel a reservation, type 'cancel'" << endl;
  cout << "To view all reservations, type 'view'" << endl;
  cout << "To view reservations on a specific date, type 'date'" << endl;
  cout << "To view a list of all the commands, type 'help'" << endl;
  cout << "To exit, type 'exit'" << endl;
  string command;
  string makeDate, makeTime, makeTable, makeName;
  
  while(1)
  {
    cin >> command;
    if (command == "make") {
      bool makeSuccess = false;
      cout << "Please enter the date (month/day/year): ";
      cin >> makeDate;
      cout << "Please enter the time (hour:minute): ";
      cin >> makeTime;
      cout << "Please enter the table size (small, medium, or large): ";
      cin >> makeTable;
      cout << "Please enter the last name of the person reserving: ";
      cin >> makeName;
      makeSuccess = myRestaurant.makeReservation(makeDate, makeTime, makeTable, makeName);
      if (makeSuccess == true)
      {
        cout << "The reservation has been created" << endl;
      }
      else
      {
        cout << "The reservation could not be created" << endl;
      }
    }
    else if (command == "cancel") {
      string cancelName;
      bool canceled;
      cout << "Enter the last name of the person who wants to cancel their reservation: ";
      cin >> cancelName;
      canceled = myRestaurant.cancelReservation(cancelName);
      if (canceled == true)
      {
        cout << "The reservation has been canceled" << endl;
      }
      else
      {
        cout << "There is no reservation under that name" << endl;
      }
    }
    else if (command == "view") {
      myRestaurant.listReservations();
    }
    else if (command == "date") {
      cout << "What day would you like to look up? (month/day/year) ";
      string findDate;
      cin >> findDate;
      myRestaurant.listReservations(findDate);
    }
    else if (command == "help") {
      cout << "To make a reservation, type 'make'" << endl;
      cout << "To cancel a reservation, type 'cancel'" << endl;
      cout << "To view all reservations, type 'view'" << endl;
      cout << "To view reservations on a specific date, type 'date'" << endl;
      cout << "To view a list of all the commands, type 'help'" << endl;
      cout << "To exit, type 'exit'" << endl;
    }
    else if (command == "exit") {
      return 0;
    }
  }

};

