#include "restaurant.h"
#include <cstdlib>

using namespace std;

// Default constructor = no tables
restaurant::restaurant()
{
  smallTables = 0;
  mediumTables = 0;
  largeTables = 0;
}

// Constructor when given arguements (the number of each type of table in the restaurant)
restaurant::restaurant(int small, int medium, int large)
{
  // Setting up the tables that the restaurant has
  smallTables = small;
  mediumTables = medium;
  largeTables = large;

  // Creating a table header
  fstream myRestaurant("reservations.txt", fstream::out);
  myRestaurant << "Date / Time / Table Type / Name";
  myRestaurant.close();
}

// Creates a reservation and adds it to the list
bool restaurant::makeReservation(string date, string time, string table, string name)
{
  fstream myRestaurant("reservations.txt", fstream::app);
  myRestaurant << date << " " << time << " " << table << " " << name << endl;
  return true;
}

// Removes a reservation if the name exists in the reservation list
bool restaurant::cancelReservation(string cancelName) 
{
  fstream myRestaurant("reservations.txt", fstream::in);
  stringstream good;
  string date, time, type, name;
  bool exists = false;

  while (!myRestaurant.eof())
  {
    myRestaurant >> date >> time >> type >> name;
    if (name == cancelName)
    {
      exists == true;
      continue;
    }
    good << date << time << type << name;
  }
  myRestaurant.close();

  if (exists) {
    fstream updatedList("reservations.txt", fstream::out);
    updatedList << good.str();
    return true;
  }
  else {
    return false;
  }
}

// To display all the reservations
void restaurant::listReservations()
{
  fstream myRestaurant("reservations.txt", fstream::in);
  string currentLine;
  while (!myRestaurant.eof())
  {
    getline(myRestaurant, currentLine);
    cout << currentLine << endl;
  }
}

// To display reservations only for a specific date
void restaurant::listReservations(string date)
{
  fstream myRestaurant("reservations.txt", fstream::in);
  string testLine;
  string currentLine;
  myRestaurant >> testLine;
  while (myRestaurant)
  {
    if (date == testLine)
    {
      getline(myRestaurant, currentLine);
      cout << currentLine << endl;  
    }
    myRestaurant >> testLine;
  }
}
