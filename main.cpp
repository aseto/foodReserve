#include "reservation.h"
#include "interface.h"
#include <iostream>
#include <fstream>
#include "restaurant.h"
#include <string> 
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    string var1, var2, var3;
    var1 = argv[1];
    var2 = argv[2];
    var3 = argv[3];
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

}

/*
  interface reserveInterface;
  cout << "To view reservations, type 'view'" << endl;
  cout << "To make a reservation, type 'make'" << endl;
  cout << "To cancel a reservation, type 'cancel'" << endl;
  cout << "To view a list of all the commands, type 'help'" << endl;
  cout << "To exit, type 'exit'" << endl;

  string command;
  cin >> command;

  if (command == "make") {
    ofstream reserve;
    reserve.open("reservations.txt");
      string name, notes;
      string party, date, time;
      cout << "Please enter a name for the reservation to be under: ";
      cin >> name;
      cout << "What day is the reservation for? (month/day/year) ";
      cin >> date;
      cout << "At what time? (hour:minute) ";
      cin >> time;
      cout << "For how many people? ";
      cin >> party;
      cout << "Any special notes? ";
      cin >> notes;

      reserve << "Name: " << name << endl;
      reserve << "Date: " << date << endl;
      reserve << "Time: " << time << endl;
      reserve << "Party: " << party << endl;
      reserve << "Notes: " << notes << endl << endl;

      cout << "The reservation has been made" << endl;
      reserve.close();
  }
  else if (command == "view") {
    string currentLine;
    ifstream myFile ("reservations.txt");
    while (getline (myFile, currentLine) ) {
      cout << currentLine << endl;
    }
    myFile.close();
  }
  else if (command == "cancel") {
    string name;
    cout << "Enter the name of the person who wants to cancel their reservation: ";
    cin >> name;
  }
  else if (command == "help") {
    cout << "To view reservations, type 'view'" << endl;
    cout << "To make a reservation, type 'make'" << endl;
    cout << "To cancel a reservation, type 'cancel'" << endl;
    cout << "To view a list of all the commands, type 'help'" << endl;
    cout << "To exit, type 'exit'" << endl;
  }
  else if (command == "exit") {
    return 0;
  }
  else {
    cout << "You have entered an invalid command, please try again" << endl;
  }

  return 0;
}*/;
