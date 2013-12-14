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
    string dateString;
    dateString = this->month.toString();
    dateString.append("/");
    dateString.append(this->day.toString());
    dateString.append("/");
    dateString.append(this->year.toString());
    return dateString;
}

string reservation::getTimeString()
{
    string timeString;
    timeString = this->hour.toString();
    timeString.append(":");
    timeString.append(this->minute.toString());
    return timeString;
}

string reservation::getNote()
{
    return note;
}

int reservation::getParty()
{
    return partyMembers;
}
