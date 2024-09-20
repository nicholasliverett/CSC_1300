/*
	Title:  mod4_messedUpG.cpp
	Purpose: In class practice for debugging
	Date:  7/27/2022 modified 9/20/24
	Author: April Crockett modified by Nicholas Liverett
*/

#include <iostream>
using namespace std;

int main()
{
	int hungerLevel;
	char answer1, answer2, answer3;
	int choice;
	
	cout << "\n\nSHOULD YOU EAT IT?\n\n";
	cout << "\nOn a scale from 1 to 5 with 1 being not hungry ";
	cout << "at all and 5 being starving, how hungry are you?\n";
	cin >> hungerLevel;
	
	if(hungerLevel = 1)
		cout << "\nDon\'t eat it.\n";
	if(hungerLevel = 5)
		cout << "\nEat it no matter what.\n";
	else {
		cout << "Has a dog licked it? (y or n)\n";
		cin >> answer1;
		cout << "Is it on someone else's plate? (y or n)\n";
		cin >> answer2;
		cout << "Is if food? (y or n)\n";
		cin >> answer3;
	}

	if ((answer1 ==  'y' || answer2 == 'y') && answer3 == 'y')
		cout << "\nEat it anyway. At least it is food.\n";
	else if ((answer2 == 'y' || answer3 == 'y') & answer1 == 'y')
		cout << "\nEat it anyway. Maybe you didn\'t really see the dog lick it.\n";
	else
		cout << "\nBetter not eat it.\n";

	cout << "\nSHOULD YOU RIDE A HORSE?\n";
	cout << "Select from the following scenarios the one that best represents you today.\n";
	cout << "1. I am tired.\n";
	cout << "2. I get dizzy easily.\n";
	cout << "3. I hate animals.\n";
	cout << "CHOOSE 1-3: ";
	cin >> choice;
	
	switch(choice) {
		case 1: cout << "\nYes!  That horse will walk for you.\n"; break;
		case 2: cout << "\nNo, you may fall off the horse.\n"; break;
		case 3: cout << "\nNo, the horse may bite you.\n"; break;
		default:  cout << "\nError, you didn't select 1, 2, or 3.\n"; break;
	}

	return 0;
}