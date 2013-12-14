#include "reservation.h"
#include "interface.h"
#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;

int main(int argc, char *argv[])
{
  cout << "To view reservations, type 'view'" << endl;
  cout << "To make a reservation, type 'make'" << endl;
  cout << "To cancel a reservation, type 'cancel'" << endl;
  cout << "To view a list of all the commands, type 'help'" << endl;
  cout << "To exit, type 'exit'" << endl;

  ofstream reserve;
  reserve.open(argv[1]);
  while (reserve.is_open())
  {
    string command;
    cin >> command;

    if (command == "make") {
    }
    else if (command == "view") {

    }
    else if (command == "cancel") {

    }
    else if (command == "help") {
      cout << "To view reservations, type 'view'" << endl;
      cout << "To make a reservation, type 'make'" << endl;
      cout << "To cancel a reservation, type 'cancel'" << endl;
      cout << "To view a list of all the commands, type 'help'" << endl;
      cout << "To exit, type 'exit'" << endl;
    }
    else if (command == "exit") {
      reserve.close();
      return 0;
    }
    else {
      cout << "You have entered an invalid command, please try again" << endl;
    }
  }

  reserve.close();
  return 0;
}
