#include "reservation.h"
#include "restaurant.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
using namespace std;

void newRestaurant(restaurant *aRestaurant);
void helpPrompt();

int main(int argc, char *argv[])
{
	//string var1, var2, var3, var4;
	//var1 = argv[1];
	//var2 = argv[2];
	//var3 = argv[3];

	restaurant myRestaurant;
	// Checking if the restaurant is new
	if(myRestaurant.isNew()){
		newRestaurant(&myRestaurant);
	}
	// Otherwise assume the last restaurant
	else{
		cout << "Welcome back to " << myRestaurant.getRestaurantName() << " reservation system." << endl;
		cout << "You have " << myRestaurant.getNumSmallTables() << " small tables," << endl;
		cout << " " << myRestaurant.getNumMedTables() << " medium tables," << endl;
		cout << " and " << myRestaurant.getNumLargeTables() << " large tables." << endl;
		cout << " " << endl;

	}

	helpPrompt();
	string command;
	string makeDate, makeTime, makeTable, makeName;

	// Keep the user in the program
	while(1)
	{
		cin >> command;
		if (command == "make") {
			bool makeSuccess = false;
			cout << "Please enter the date (month/day/year): ";
			cin >> makeDate;
			cout << "Please enter the time (hour:minute): ";
			cin >> makeTime;
			cout << "Please enter the table size (small, medium, or large): ";
			cin >> makeTable;
			cout << "Please enter the last name of the person reserving: ";
			cin >> makeName;
			makeSuccess = myRestaurant.makeReservation(makeDate, makeTime, makeTable, makeName);
			if (makeSuccess == true)
			{
				cout << "The reservation has been created" << endl;
			}
			else
			{
				cout << "The reservation could not be created" << endl;
			}
		}
		else if (command == "cancel") {
			string cancelName;
			bool canceled;
			cout << "Enter the last name of the person who wants to cancel their reservation: ";
			cin >> cancelName;
			canceled = myRestaurant.cancelReservation(cancelName);
			if (canceled == true)
			{
				cout << "The reservation has been canceled" << endl;
			}
			else
			{
				cout << "There is no reservation under that name" << endl;
			}
		}
		else if (command == "view") {
			string revs =  myRestaurant.listReservations();
			cout << revs << endl;
		}
		else if (command == "date") {
			cout << "What day would you like to look up? (month/day/year) ";
			string findDate;
			cin >> findDate;
			myRestaurant.listReservations(findDate);
		}
		else if(command == "new"){
			cout << "Are you sure?  This action will delete " << myRestaurant.getRestaurantName() << endl;
			cout << " and all of the associate reservations. Enter Y to continue or N to cancel" << endl;
			string response;
			cin >> response;
			if(response == "Y" || response == "y"){
				myRestaurant.deleteRecords();
				cout << "Restaurant successfully deleted" << endl;
				cout << "Would you like to start a new restaurant? [Y/N]" << endl;
				string response2;
				cin >> response2;
				if(response2 == "Y" || response2 == "y"){
					newRestaurant(&myRestaurant);
					helpPrompt();
				}
				else if(response2 == "N" || response2 == "n"){
					cout << "Thank you for using our reservation system" << endl;
					return 0;
				}
				else{
					cout << "Would you like to start a new restaurant? [Y/N]" << endl;
				}
			}
			else{
				cout << "enter 'help' for further assistance" << endl;
			}
		}
		else if (command == "help") {
			helpPrompt();
		}
		// Implementing saving status to text file so dates aren't lost
		// on new launch
		else if (command == "exit") {
			string revs = myRestaurant.listReservations();
			//cout << revs << endl; //test line it works =]
			// now we need to open a file and write to it.
			myRestaurant.saveRestaurantInfo();
			return 0;
		}
		else {
			cout << "You have not entered a correct command" << endl;
			cout << "For a list of commands, type 'help'" << endl;
		}
	}

};
/**
 * Prompts the user to enter information needed to create a new restaurant reservation system
 */
void newRestaurant(restaurant *aRestaurant){
	string var1, var2, var3, var4;
	cout << "First, please set up your restaurant" << endl;
	cout << "What is the name of your restaurant? ";
	getline(cin, var4);
	cout << "How many small tables (seat up to 2) are there? " ;
	cin >> var1;
	cout << "How many medium tables (seat up to 4) are there? ";
	cin >> var2;
	cout << "How many large tables (seat up to 8) are there? ";
	cin >> var3;

	int small, medium, large;
	small = atoi(var1.c_str());
	medium = atoi(var2.c_str());
	large = atoi(var3.c_str());
	aRestaurant->inputInformation(var4, small, medium, large);
}
/**
 * prompts the user with command options
 */
void helpPrompt(){
	cout << "To make a reservation, type 'make'" << endl;
	cout << "To cancel a reservation, type 'cancel'" << endl;
	cout << "To view all reservations, type 'view'" << endl;
	cout << "To view reservations on a specific date, type 'date'" << endl;
	cout << "To delete this restaurant and start a new one type 'new'" << endl;
	cout << "To view a list of all the commands, type 'help'" << endl;
	cout << "To exit, type 'exit'" << endl;
}
