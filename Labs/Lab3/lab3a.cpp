/*************************************************************
 * Filename: lab3.cpp
 * Author: April Crockett, modified by Nicholas Liverett
 * Date: 9/19/24
 * Purpose: Umm alphabatize a list of fav foods?
**************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	string food1, food2, food3;
	
	/*
		The code below will print cool ASCII Art of the word "FOOD".
		Notice I had to excape all the backslash characters so that
		every time you see \\ in the code, only one \ gets printed to 
		the screen.
	*/
	cout << "________ ________  ________  ________      \n";
	cout << "|\\  _____\\\\   __  \\|\\   __  \\|\\   ___ \\    \n";
	cout << "\\ \\  \\__/\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\_|\\ \\   \n";
	cout << " \\ \\   __\\\\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\ \\\\ \\  \n";
	cout << "  \\ \\  \\_| \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\_\\\\ \\ \n";
	cout << "   \\ \\__\\   \\ \\_______\\ \\_______\\ \\_______\\\n";
	cout << "    \\|__|    \\|_______|\\|_______|\\|_______|\n";
	
	cout << "\n\nWhat is your top three favorite foods?";
	cout << "\nFOOD 1: ";
	getline(cin, food1);
	cout << "\nFOOD 2: ";
	getline(cin, food2);
	cout << "\nFOOD 3: ";
	getline(cin, food3);
	
	//capitalize first letter of all their foods (if it isn't already)
	food1[0] = toupper(food1[0]);
	food2[0] = toupper(food2[0]);
	food3[0] = toupper(food3[0]);
	
	if ((food1 == "Spaghetti") || (food2 == "Spaghetti") || (food3 == "Spaghetti"))
		cout << "\nSpaghetti is one of my favorite foods, too!\n\n";
	else
		cout << "\nI can't believe that Spaghetti isn't one of your favorite foods!\n\n";
	cout << "Here are your favorite foods in alphabetical order:\n";
	
	/*
		The algorithm for the code below, which alphabatizes the foods
		in ascending order, can be figured out if you
		think about all the possible combinations of ordering the three
		foods in alphabetical order.  There are 3 foods and so to figure 
		out the number of combinations, you do 3 factorial = 3! = 6.
		So, there are 6 possible combinations:
		1 2 3
		1 3 2
		2 1 3
		2 3 1
		3 1 2
		3 2 1
		
		Note, we are taking advantage of the fact that we can
		compare strings using relational operators. 
	*/



	//Respectfully the most horrid thing I have ever seen

	if (food1[0] < food2[0] && food1[0] < food3[0] && food2[0] < food3[0]) 	//food1 food2 food3
		cout << food1 << endl << food2 << endl << food3;
	else if (food1[0] < food2[0] && food1[0] < food3[0] && food3[0] < food2[0]) //food1 food3 food2
		cout << food1 << endl << food3 << endl << food2;
	else if (food2[0] < food1[0] && food2[0] < food3[0] && food1[0] < food3[0])	//food2 food1 food3
		cout << food2 << endl << food1 << endl << food3;
	else if (food2[0] < food1[0] && food2[0] < food3[0] && food3[0] < food1[0]) //food2 food3 food1
		cout << food2 << endl << food3 << endl << food1;
	else if (food3[0] < food1[0] && food3[0] < food2[0] && food1[0] < food2[0])	//food3 food1 food2
		cout << food3 << endl << food1 << endl << food2;
	else 													//food3 food2 food1
		cout << food3 << endl << food2 << endl << food1;
	
	cout << endl << endl;
	
	return 0;
}