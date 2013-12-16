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
  myRestaurant << "Date / Time / Table Type / Name \n";
  myRestaurant.close();
}

// Creates a reservation and adds it to the list
bool restaurant::makeReservation(string date, string time, string table, string name)
{
  fstream myRestaurant("reservations.txt", fstream::out | fstream::app);
  myRestaurant << date << " " << time << " " << table << " " << name << "\n";
  return true;
}

// Removes a reservation if the name exists in the reservation list
bool restaurant::cancelReservation(string cancelName) 
{
  fstream myRestaurant("reservations.txt", fstream::in);
  stringstream good;
  string date, time, type, name;
  bool exists = false;

  string testLine;
  string title;
  getline (myRestaurant, title);
  while (!myRestaurant.eof())
  {
    getline (myRestaurant, testLine);
    stringstream stream(testLine);
    stream >> date >> time >> type >> name;

    if (name == cancelName)
    {
      exists = true;
    }
    else
    {
      good << date << " " << time << " " << type << " " << name << "\n";
    }
  }
  myRestaurant.close();


  if (exists) {
    fstream updatedList("reservations.txt", fstream::out);
    updatedList << "Date / Time / Table Type / Name \n";
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

// Determines whether or not the table is available
// A table is taken if there is already a reservation with 
// the same date and hour.
bool restaurant::tableFree(string type, string date, string time)
{
  int tablesLeft;

  if (type == "small")
  {
    tablesLeft = this->smallTables;
  }
  else if (type == "medium") 
  {
    tablesLeft = this->mediumTables;
  }
  else //type == large
  {
    tablesLeft = this->largeTables;
  }

  fstream myRestaurant("reservations.txt", fstream::in);
  string dummy;
  string testTime;
  string testLine;
  string currentLine;
  myRestaurant >> testLine;
  while (myRestaurant)
  {
    if (date == testLine)
    {
      getline(myRestaurant, currentLine);
      stringstream stream(currentLine);
      stream >> dummy >> testTime;
      if (testTime.at(4) == time.at(4) && testTime.at(3) == time.at(3))
      {
        tablesLeft = tablesLeft - 1;
      }
    }
    myRestaurant >> testLine;
  }
  
  if (tablesLeft > 0)
  {
    return true;
  }
  else 
  { 
    return false;
  }

}
