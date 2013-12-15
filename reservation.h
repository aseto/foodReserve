#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::stringstream;

class reservation
{
public:
    reservation();
    bool setDate(string type, int value);
    bool setTime(string type, int value);
    void setNote(string newNote);
    void setParty(int numMembers);
    void setName(string theName);

    string getDate();
    string getTimeString();
    string getNote();
    int getParty();
    string getName();

private:
    int month;
    int day;
    int year;
    int hour;
    int minute;
    int partyMembers;
    string note;
    string name;
};

#endif // RESERVATION_H

