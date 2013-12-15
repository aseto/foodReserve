#include "reservation.h"
#include "interface.h"
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int main(int argc, char *argv[])
{
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
    reserve.open(argv[1]);
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
    ifstream myFile (argv[1]);
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
}
