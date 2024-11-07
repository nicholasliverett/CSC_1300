/*****************************************************************
 *****************************************************************
	Title: 			functions.cpp
	Authors: 		April Crockett and PUT YOUR NAME HERE
	Date Created: 	11/1/2024
	Last Updateed: 	11/1/2024 (KEEP UPDATING THIS DATE AS YOU WORK ON THIS FILE)
	Purpose: 		Creature Fight Game
******************************************************************
******************************************************************/

#include "program4.h"


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
		cout << "Oh no! There are no creatures in the arena!\n\n";
		return numCreatures;
	}
	
	//print the creatures
	cout << "Here is the list of creatures who are eligible to fight:\n";
	for(int i=0; i<numCreatures; i++)
	{
		cout << i+1 << ") " << creatureList[i].name << ", HIT: " 
		     << creatureList[i].creStats.hitPoints << ", HEALTH: "
			 << creatureList[i].creStats.healthPoints << endl;
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
	while(creatureList[first].creStats.healthPoints > 0 && creatureList[second].creStats.healthPoints > 0)
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
		creatureList[victim].creStats.healthPoints -= hitterHP;
		cout << creatureList[victim].name << " now has " 
		<< creatureList[victim].creStats.healthPoints
			 << " health points.\n";
	
		//is the creature's health points at or below 0? if so, it is dead, 
		// so remove it from array, decrement the number of creatures, and
		// break from the loop
		if(creatureList[victim].creStats.healthPoints <= 0)
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
	if(strncmp(creatureList[i].creStats.special,"1",1) == 0)	//hit modification
		fHit = (creatureList[i].creStats.special[1]-'0') * randomNum + creatureList[i].creStats.hitPoints;
	else  //no special modifications
		fHit = creatureList[i].creStats.hitPoints;
}