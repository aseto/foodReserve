#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class reservation
{
public:
    reservation();
    bool setDate(string type, int value);
    bool setTime(string type, int value);
    void setNote(string newNote);
    void setParty(int numMembers);

    string getDate();
    string getTimeString();
    string getNote();
    int getParty();

private:
    int month;
    int day;
    int year;
    int hour;
    int minute;
    int partyMembers;
    string note;
};

#endif // RESERVATION_H

