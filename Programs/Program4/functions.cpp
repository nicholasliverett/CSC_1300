/*****************************************************************
 *****************************************************************
	Title: 			functions.cpp
	Authors: 		April Crockett and Nicholas Liverett
	Date Created: 	11/1/2024
	Last Updateed: 	11/13/2024 (KEEP UPDATING THIS DATE AS YOU WORK ON THIS FILE)
	Purpose: 		Creature Fight Game - functions
******************************************************************
******************************************************************/

#include "program4.h"

string lineOfStars = "********************************************************************************";

/******************************************************************
	Function name: fight()
	Function purpose:
	
		The fight function will allow two dinosaurs to fight.
		The user gets to select the two dinos. 
*******************************************************************/
int fight(int numCreatures, Creatures* creatureList)
{
	int random, first, second, numRounds;
	int hitter, victim, hitterHP, victimHP;
	
	int f1Hit, f2Hit;
	
	cout << endl << lineOfStars <<endl;
	cout << "---------- FIGHT! FIGHT! FIGHT! ----------\n\n";
	
	//if there are no creatures, tell the user and then exit this function
	if(numCreatures == 0)
	{
		cout << "Oh no! There are no creatures in the arena!\n";
		return numCreatures;
	}
	
	//print the creatures
	cout << "Here is the list of creatures who are eligible to fight:\n";
	for(int i=0; i<numCreatures; i++)
	{
		cout << i+1 << ") " << creatureList[i].name << ", HIT: " 
		     << creatureList[i].stats.dmg << ", HEALTH: "
			 << creatureList[i].stats.hp << endl;
	}
	
	//get the first creature fighter
	cout << "\nFIRST FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
	cin >> first;
	//validate the user's input
	while(!cin || first < 1 || first > numCreatures)
	{
		
		if(!cin)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Oops! That wasn't an integer.\n";
		}
		else
			cout << "Oops! That number wasn't in the correct range.\n";	
		cout << "FIRST FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
		cin >> first;
	}
	
	//Get the second creature figher
	cout << "SECOND FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
	cin >> second;
	//validate the user's input
	while(!cin || second<1 || second>numCreatures || second == first)
	{
		if(!cin)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Oops! That wasn't an integer.\n";
		}
		else if(second<1 || second>numCreatures)
			cout << "Oops! That number wasn't in the correct range.\n";
		else
			cout << "Oops! " << creatureList[second-1].name 
		         << " can't fight itself!!\n";
		cout << "SECOND FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
		cin >> second;
	}
	//Since the numbers in first & second are the element numbers, we
	//need to change them to the index values, so I am decrementing both
	first--;
	second--;
	
	//FIGHT UNTIL DEATH
	numRounds = 0;
	
	//While both fighting creatures are not dead (don't have health points of 0 or less), keep fighting
	while(creatureList[first].stats.hp > 0 && creatureList[second].stats.hp > 0)
	{
		//Random Number to see who hits who first
		random = rand()%(2-1+1)+1;
		
		//calculate hit modifier for both creatures
		calculateModifier(first, creatureList, f1Hit);
		calculateModifier(second, creatureList, f2Hit);
		
		if(random == 1) //first hits second
		{
			hitter = first;
			hitterHP = f1Hit;
			victim = second;
		}
		else //second hits first
		{
			hitter = second;
			hitterHP = f2Hit;
			victim = first;
		}
		
		numRounds++;
		cout << "\n>>>>>>>>>> ROUND " << numRounds << " <<<<<<<<<<\n";
		cout << creatureList[hitter].name << " hits " 
		     << creatureList[victim].name << " with "
			 << hitterHP << " hit points!\n";
		
		//update creature's health points
		creatureList[victim].stats.hp -= hitterHP;
		cout << creatureList[victim].name << " now has " 
		<< creatureList[victim].stats.hp
			 << " health points.\n";
	
		//is the creature's health points at or below 0? if so, it is dead, 
		// so remove it from array, decrement the number of creatures, and
		// break from the loop
		if(creatureList[victim].stats.hp <= 0)
		{
			cout << creatureList[victim].name << "'s body is being removed from the arena.\n";
			cout << creatureList[hitter].name << " IS THE WINNER!!!\n\n";
			moveArrayElements(creatureList[victim].name, numCreatures, creatureList);
			numCreatures--;
			break;
		}
	}//end of fight loop	
	
	//return the updated number of creatures because one creature died
	return numCreatures;
}//end of fight()

/******************************************************************
	Function name: calculateModifier()
	Function purpose:
	
		The calculateModifier function will accept the index value
		of the creature that will have its hit points modified
		by the special bonus modifier. This function also accepts
		the creature array and an integer that is passed by reference
		that will hold the updated hit points for this creature
*******************************************************************/
void calculateModifier(int i, Creatures* creatureList, int& fHit)
{
	int randomNum = rand()%(11-7+1)+7;
	if(strncmp(creatureList[i].stats.special,"1",1) == 0)	//hit modification
		fHit = (creatureList[i].stats.special[1]-'0') * randomNum + creatureList[i].stats.dmg;
	else  //no special modifications
		fHit = creatureList[i].stats.dmg;
}

//allows user to enter creatures via a file or manually
//returns number of creatures - will be the same as input if maxxed out or file could not be opened
int enterCreatures(int num_creatures, int max_creatures, Creatures* creatures_arr) {
	int file_or_man, i=num_creatures, count=0;
	string file_name, temp;
	cout << endl << lineOfStars << endl;
	cout << "---------- ENTER CREATURES! ----------\n";

	if (num_creatures == max_creatures) {
		cout << "\nSorry! You are already at the maximum capacity of " << max_creatures << " creatures.\n";
		return num_creatures;
	}

	cout << "Would you like to (1)Load my creatures from a text file or (2)Enter one creature manually?\n\n";
	cout << "CHOOSE 1 or 2: ";
	while (!(cin >> file_or_man) || (file_or_man != 1 && file_or_man != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong. Try Again (1-2): ";
    }

	if (file_or_man == 1) {
		cout << "What is the name of the file with your list of creatures? (ex: filename.txt)\n";
		cout << "FILENAME: ";
		cin >> file_name;

		ifstream creatures_file(file_name);
		if (!creatures_file.is_open()) {
			cout << "Could not open file.\n";
			return num_creatures;
		}
		
		while(getline(creatures_file, temp, '#') && i < max_creatures) {
			//name ^
			creatures_arr[i].name = temp;
			//description
			getline(creatures_file, creatures_arr[i].description, '#');
			//length
			getline(creatures_file, temp, '#');
			creatures_arr[i].length = stof(temp);
			//height
			getline(creatures_file, temp, '#');
			creatures_arr[i].height = stof(temp);
			//location
			getline(creatures_file, creatures_arr[i].location, '#');
			//danger
			getline(creatures_file, temp, '#');
			if (temp == "0")
				creatures_arr[i].danger = false;
			else if (temp == "1")
				creatures_arr[i].danger = true;
			//damage
			getline(creatures_file, temp, '#');
			creatures_arr[i].stats.dmg = stoi(temp);
			//health
			getline(creatures_file, temp, '#');
			creatures_arr[i].stats.hp = stoi(temp);
			//special mod 
			getline(creatures_file, temp, '#');
			creatures_arr[i].stats.special[0] = temp[0];
			creatures_arr[i].stats.special[1] = temp[1];
			
			num_creatures++;
			i++;
			count++;
		}

		cout << endl << endl << count << " creatures from " << file_name << " have been added to the program!\n";

		creatures_file.close();
		
	} else if (file_or_man == 2) {
		char add_more;
		do {
			i = num_creatures;
			//name
			cout << "\nNAME: ";
			cin.ignore();
			getline(cin, creatures_arr[i].name);
			//description
			cout << "DESCRIPTION: ";
			getline(cin, creatures_arr[i].description);
			//length
			cout << "AVERAGE LENGTH (in feet): ";
			cin >> creatures_arr[i].length;
			//height
			cout << "AVERAGE HEIGHT (in feet): ";
			cin >> creatures_arr[i].height;
			//location
			cout << "LOCATION: ";
			cin.ignore();
			getline(cin, creatures_arr[i].location);
			//danger
			cout << "IS IT A DANGEROUS CREATURE (y or n): ";
			cin >> temp;
			if (temp == "y")
				creatures_arr[i].danger = true;
			else if (temp == "n")
				creatures_arr[i].danger = false;
			//dmg
			cout << "HIT POINTS: ";
			cin >> creatures_arr[i].stats.dmg;
			//hp
			cout << "HEALTH POINTS: ";
			cin >> creatures_arr[i].stats.hp;
			//special if y set to 1# | if n set to 00
			cout << "HIT SPECIAL MODIFIER? (y or n): ";
			cin >> temp;
			if (temp == "y") {
				creatures_arr[i].stats.special[0] = '1';
				cout << "HIT MODIFIER (0-9): ";
				cin >> creatures_arr[i].stats.special[1];
			} else if (temp == "n") {
				creatures_arr[i].stats.special[0] = '0';
				creatures_arr[i].stats.special[1] = '0';
			}
			
			cout << endl << creatures_arr[i].name << " has been added!\n\n";

			num_creatures++;
			i++;

			if (i < max_creatures) {
				cout << "Want to add more creatures (y or n)? ";
				while (!(cin >> add_more) || (add_more != 'y' && add_more != 'n')) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Wrong. Try Again (y/n): ";
				}
			}

		} while (add_more != 'n' && i < max_creatures);
	}
	return num_creatures;
}

//allows user to delete a creature
int deleteCreature(int num_creatures, Creatures* creatures_arr) {
	string removie;

	cout << endl << lineOfStars << endl;
	cout << "---------- DELETE CREATURE ----------\n";

	//check if any creatures - return if none
	if (num_creatures == 0) {
		cout << "\nOh no! There are no creatures in the arena!\n";
		return num_creatures;
	}

	//output list of creatures
	cout << "The following is a list of all the creatures: \n";
	for (int i=0;i<num_creatures;i++) 
		cout << creatures_arr[i].name << endl;
	
	cout << "\nWhat creature do you wish to remove?\n";
	cout << "CREATURE NAME: ";
	cin.ignore();
	getline(cin, removie);

	if(moveArrayElements(removie, num_creatures, creatures_arr)) {
		cout << endl << "You have removed " << removie << ".\n";
		num_creatures--;
	} else 
		cout << "\nSorry, a creature by the name " << removie << " could not be found.\n";

	return num_creatures;
}

bool moveArrayElements(string removie, int num_creatures, Creatures* creatures_arr) {
	bool result;
	int removie_index;
	for (int i=0;i<num_creatures;i++) {
		if (creatures_arr[i].name == removie) {
			result = true;
			removie_index = i;
		}
	}

	if (result == false)
		return false;

	//remove
	for (int i=removie_index;i<num_creatures-1;i++) 
		creatures_arr[i] = creatures_arr[i+1];
	return true;
}

void printCreatures(int num_creatures, Creatures* creatures_arr) {

	cout << endl << lineOfStars << endl;
	cout << "---------- PRINT CREATURES ----------\n";
	
	if (num_creatures == 0)
		cout << "\nOh no! There are no creatures in the arena!\n";
	else {
		cout << "\nHere is a detailed list of all the creatures who are eligible to fight:\n\n";
		for (int i=0;i<num_creatures;i++) {
			cout << "---------- CREATURE " << i+1 << " ----------\n";
			cout << "Name:\t\t" << creatures_arr[i].name << endl;
			cout << "Description:\n\t"<< creatures_arr[i].description << endl;
			cout << "Length:\t\t"<< creatures_arr[i].length << endl;
			cout << "Height:\t\t"<< creatures_arr[i].height << endl;
			cout << "Location:\t"<< creatures_arr[i].location << endl;
			cout << "Dangerous?\t";
			if (creatures_arr[i].danger == true)
				cout << "yes\n";
			else if (creatures_arr[i].danger == false)
				cout << "no\n";
			cout << "Hit Points:\t"<< creatures_arr[i].stats.dmg << endl;
			cout << "Health Points:\t"<< creatures_arr[i].stats.hp << endl;
			cout << "Special Bonus:\t";
			if (creatures_arr[i].stats.special[0] == '0')
				cout << "No hit modifier\n\n";
			else if (creatures_arr[i].stats.special[0] == '1')
				cout << "Hit modifier of " << creatures_arr[i].stats.special[1] << endl << endl;
		}
	}

}

void printStats(int num_creatures, Creatures* creatures_arr) {
	
	cout << endl << lineOfStars << endl;
	cout << "---------- PRINT CREATURE STATISTICS ----------\n";

	if (num_creatures == 0)
		cout << "\nOh no! There are no creatures in the arean!\n";
	else {
		cout << "Here are the current stats of each creature:\n\n";
		cout << setw(25) << left << "CREATURE" << right << "HIT PTS" << setw(12) << "HEALTH PTS" << "  SPECIAL BONUS" << endl;
		cout << "--------------------------------------------------------------------------------\n";
		for (int i=0;i<num_creatures;i++) {
			cout << setw(25) << left << creatures_arr[i].name << setw(7) << right << creatures_arr[i].stats.dmg << setw(12) << creatures_arr[i].stats.hp;
			if (creatures_arr[i].stats.special[0] == '0')
				cout << "  No hit modifier\n";
			else if (creatures_arr[i].stats.special[0] == '1')
				cout << "  Hit modifier of " << creatures_arr[i].stats.special[1] << endl;
		}
	}
}

void saveCreaturesToFile(int num_creatures, Creatures* creatures_arr) {
	string file_name;

	cout << endl << lineOfStars << endl;
	cout << "---------- SAVE CREATURES TO FILE ----------\n\n";

	cout << "What is the name of the file you want to save your creatures to?\n";
	cout << "FILENAME: ";
	cin >> file_name;
	ofstream creatures_file;
	creatures_file.open(file_name);

	for (int i=0;i<num_creatures;i++) {
		cout << endl << creatures_arr[i].name << " was saved to file.";
		creatures_file << creatures_arr[i].name << "#" << creatures_arr[i].description << "#"
		<< creatures_arr[i].length << "#" << creatures_arr[i].height << "#"
		<< creatures_arr[i].location << "#" << creatures_arr[i].danger << "#"
		<< creatures_arr[i].stats.dmg << "#" << creatures_arr[i].stats.hp << "#"
		<< creatures_arr[i].stats.special[0] << creatures_arr[i].stats.special[1] << "#";
	}

	cout << endl << num_creatures << " creatures were successfully saved to the " << file_name << " file.\n";

	creatures_file.close();
}