#include "restaurant.h"
#include <cstdlib>

using namespace std;

// Default constructor checks to see if there already is a restaurant saved or if you
//want to start a new one.
restaurant::restaurant()
{
	fstream myRestaurant("restaurant.txt", fstream::in);
	string l;
	getline(myRestaurant, l);
	if(l.size() < 1){
		newRestaurant = true;
		smallTables = 0;
		mediumTables = 0;
		largeTables = 0;
	}
	else{
		newRestaurant = false;
		string line;
		string nR, sT, mT, lT;
		int lineCount = 0;
		while(getline(myRestaurant, line)){
			switch(lineCount){
			case 0:
				nR = line;
				break;
			case 1:
				sT = line;
				break;
			case 2:
				mT = line;
				break;
			case 3:
				lT = line;
				break;
			default:
				cout << "error in the switch case restaurant constructor";
				break;
			}
			lineCount++;
		}
		restaurantName = nR;
		smallTables = atoi(sT.c_str());
		mediumTables = atoi(mT.c_str());
		largeTables = atoi(lT.c_str());
		cout << "pulling from res file: " << nR << sT << mT << lT << endl;

	}
	myRestaurant.close();

	fstream myReservations("reservations.txt", fstream::in );
	string line;
	bool headerExists = false;
	getline(myReservations, line);
	//cout << "this is the 'line':" << line.at(0) << endl;
	if(line.size() > 0){
		if(line.at(0) == 'D'){
			//cout << "header already exists =]" << endl;
			headerExists = true;
		}
	}

	// if reservations.txt is empty go ahead and create header.
	if(!headerExists){
		// Creating a table header
		fstream myReservations("reservations.txt", fstream::out);
		myReservations << "Date / Time / Table Type / Name \n";
		myReservations.close();
	}

	// if reservations.txt is not empty leave the current contents.

}

/**
// Constructor when given arguements (the number of each type of table in the restaurant)
restaurant::restaurant(int small, int medium, int large)
{
  // Setting up the tables that the restaurant has
  smallTables = small;
  mediumTables = medium;
  largeTables = large;

}
 */
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
	getline (myRestaurant, testLine);
	while (!myRestaurant.eof())
	{
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
		getline (myRestaurant, testLine);
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
string restaurant::listReservations()
{
	fstream myRestaurant("reservations.txt", fstream::in);
	string currentLine;
	string list;
	while (!myRestaurant.eof())
	{
		getline(myRestaurant, currentLine);
		// cout << currentLine << endl;
		list += currentLine;
		list += '\n';
	}
	return list;
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
/**
 * saves restaurant info to a file.
 */
void restaurant::saveRestaurantInfo() {
	fstream myRestaurant("restaurant.txt", fstream::out);
	myRestaurant << "restaurant save file" << '\n'
			<< restaurantName << '\n'
			<< smallTables << "\n" << mediumTables << "\n" << largeTables << "\n" << endl;
	myRestaurant.close();
}
/**
 * setts restaurant name and number of tables in each of the three categories
 */
void restaurant::inputInformation(string name, int numSmallTables,
		int numMediumTables, int numLargeTables) {
	restaurantName = name;
	smallTables = numSmallTables;
	mediumTables = numMediumTables;
	largeTables = numLargeTables;
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
/**
 * returns the name of the restaurant
 */
string restaurant::getRestaurantName(){
	return restaurantName;
}
/**
 * returns the number of small tables
 */
int restaurant::getNumSmallTables(){
	return smallTables;
}
/**
 * returns the number of medium tables
 */
int restaurant::getNumMedTables(){
	return mediumTables;
}
/**
 * returns the number of large tables
 */
int restaurant::getNumLargeTables(){
	return largeTables;
}
/**
 * Getter for state of restaurant
 * @return true if the restaurant is new false if it previously existed
 */
bool restaurant::isNew(){
	return newRestaurant;
}
/**
 * Deletes reservation and restaurant data storage files and remakes them. Resets all variables.
 */
void restaurant::deleteRecords(){
	remove("reservations.txt");
	remove("restaurant.txt");
	newRestaurant = true;
	smallTables = 0;
	mediumTables = 0;
	largeTables = 0;
	// Creating a table header
	fstream myReservations("reservations.txt", fstream::out);
	myReservations << "Date / Time / Table Type / Name \n";
	myReservations.close();
}
