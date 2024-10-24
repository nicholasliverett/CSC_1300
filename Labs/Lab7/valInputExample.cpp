/*
	Title: valInputExample.cpp
	Author:  Crockett
	Date:  10/16/2024
	Purpose:  To demonstrate how to handle when a 
	          user enters in a string instead of an integer.
			  
	Note: this is just example code to help you with lab 7
*/

#include <iostream>
#include <limits> //required to use max function
using namespace std;

int main() 
{
	int num;

	cout << "Enter a number betwen 7 and 77: " << endl;
	cin  >> num; // User enters "seven" - stream error state entered here.
	if(!cin || num < 7 || num > 77)
	{
		cin.clear(); //clears the error state
		//line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nThat was wrong.  Enter in an integer between 7 and 77: ";
		cin >> num;
	}

	return 0;
}