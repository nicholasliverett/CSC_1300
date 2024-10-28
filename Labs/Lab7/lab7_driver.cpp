/*
   Title:    lab7_driver.cpp
   Author:   April R Crockett - Nicholas Liverett
   Date:  	 10/24/24
   Purpose:  Generate the Future
*/

#include "lab7_header.h"

using namespace std;

int main()
{
	char mainChoice;
	int fileRandomInt, randomInt;
	string dwelling, person, location, car;
	string jobTitle1, jobTitle2, jobTitle3;
	string place1, place2, place3;
	int nums[3];
	double sals[3];
	ifstream inFile;
	
	srand(time(0));  //seed the random number generator
	
	do
	{	
		cout << "\nI will predict your future!\n";
		cout << "First, I need just a little information.\n";
		
		//GET USER INPUT

		//number of children
		get_num_children(nums);
		
		//job title
		cout << "\nEnter in an awesome job title: ";
		getline(cin, jobTitle1);
		cout << "Enter in another awesome job title: ";
		getline(cin, jobTitle2);
		cout << "Enter in the worst job title ever: ";
		getline(cin, jobTitle3);

		//place of employment
		cout << "\nEnter a company, organization, or restaurant you like: ";
		getline(cin, place1);
		cout << "Enter another company, organization, or restaurant you like: ";
		getline(cin, place2);
		cout << "Enter a company, organization, or restaurant you hate: ";
		getline(cin, place3);

		cout << endl;

		//salary
		get_salary(sals);

		cout << endl << endl;				
		
		//Retrieve information from files
		fileRandomInt = generate_random_int(1, 15); //generate a random number between 1 and 15
		inFile.open("DWELLINGS.txt");
		for(int i=1; i<=fileRandomInt; i++)
		{
			getline(inFile, dwelling);
		}
		inFile.close();
		fileRandomInt = generate_random_int(1, 15); //generate a random number between 1 and 15
		inFile.open("PEOPLE.txt");
		for(int i=1; i<=fileRandomInt; i++)
		{
			getline(inFile, person);
		}				
		inFile.close();
		fileRandomInt = generate_random_int(1, 15); //generate a random number between 1 and 15
		inFile.open("LOCATIONS.txt");
		for(int i=1; i<=fileRandomInt; i++)
		{
			getline(inFile, location);
		}				
		inFile.close();
		fileRandomInt = generate_random_int(1, 15); //generate a random number between 1 and 15
		inFile.open("CARS.txt");
		for(int i=1; i<=fileRandomInt; i++)
		{
			getline(inFile, car);
		}				
		inFile.close();				
		
		//OUTPUT RESULTS
		cout << "******  YOUR FUTURE  ******\n";
		cout << "You and your spouse, " << person;
		cout << " will live in a " << dwelling << " in ";
		cout << location << " and drive a " << car << ".\n";
		
		randomInt = generate_random_int(0, 2);//generate a random number between 1 and 3
		cout << "You and your spouse will have ";
		cout << nums[randomInt] << " children.\n";

		randomInt = generate_random_int(1, 3);//generate a random number between 1 and 3
		cout << "You will work at ";
		if(randomInt == 1)
			cout << place1 << " as a " << jobTitle1 << " making ";
		else if(randomInt == 2)
			cout << place2 << " as a " << jobTitle2 << " making ";
		else
			cout << place3 << " as a " << jobTitle3 << " making ";

		randomInt = generate_random_int(0, 2);//generate a random number between 1 and 3
		// Integrate rand with array
		cout << "$" << sals[randomInt] << " a year.\n";		
		
		cout << "\nWould you like to play Future Predictor again? (y/n)";
		cin >> mainChoice;
	}while(tolower(mainChoice) == 'y');
	
	cout << "\n\nGoodbye!\n\n";

	return 0;
}