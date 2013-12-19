#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "reservation.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <string>

class restaurant
{
  public:
    restaurant();
    //restaurant(int small, int medium, int large);
    bool makeReservation(string date, string time, string table, string name);
    bool cancelReservation(string cancelName);
    string listReservations();
    void listReservations(string date);
    bool isNew();
    void saveRestaurantInfo();
    void inputInformation(string name, int numSmallTables, int numMediumTables, int numLargeTables);
    string getRestaurantName();
    int getNumSmallTables();
    int getNumMedTables();
    int getNumLargeTables();
    void deleteRecords();
  private:
    // A restaurant can have 3 types of tables
    // Small tables can seat up to 2 people
    // Medium tables can seat up to 4 people
    // Large tables can seat up to 8 people
    int smallTables;
    int mediumTables;
    int largeTables;
    string restaurantName;
    bool newRestaurant;
    bool tableFree(string type, string date, string time);
};


#endif
