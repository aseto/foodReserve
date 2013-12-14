#ifndef INTERFACE_H
#define INTERFACE_H

#include "reservation.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class interface
{
  public:
    interface();
    reservation parseLine(string line);
    string createLine(reservation theReservation);
  private:

};

#endif // INTERFACE_H
