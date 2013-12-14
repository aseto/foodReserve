#include "reservation.h"

reservation::reservation()
{

}

bool reservation::setDate(string type, int value)
{
    if (type == "month") {
      this->month = value;
      return true;
    }
    else if (type == "day") {
      this->day = value;
      return true;
    }
    if (type == "year") {
      this->year = value;
      return true;
    }
    else {
      return false;
    }
}

bool reservation::setTime(string type, int value)
{
    if (type == "hour") {
      this->hour = value;
      return true;
    }
    else if (type == "minute") {
      this->minute = value;
      return true;
    }
    else {
      return false;
    }
}

void reservation::setParty(int numMembers)
{
    partyMembers = numMembers;
}

void reservation::setNote(string newNote)
{
    note = newNote;
}

string reservation::getDate()
{
    std::stringstream dateStream;
    dateStream << this->month << "/" << this->day << "/" << this->year;
    return dateStream.str();
}

string reservation::getTimeString()
{
    std::stringstream timeStream;
    timeStream << this->hour << ":" << this->minute;
    return timeStream.str();
}

string reservation::getNote()
{
    return note;
}

int reservation::getParty()
{
    return partyMembers;
}
