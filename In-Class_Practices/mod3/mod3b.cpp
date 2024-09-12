/*
	Given file: mod3b_messedup.cpp
	
	Module 3 In-Class Practice 2
	Title:   mod3b.cpp 
    Author:  Nicholas Liverett
    Date:  September 9, 2024 
    Purpose: Participate in class 2
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	//variable definitions
	double total = 1098;
	char letter = 'X';
	int num1 = 5, num2 = 3, age, userMin;
	string name;
	int randomNumber;
	
	srand(time(0)); //seed the random number generator
	
	//get user input
	cout << "\nWhat is your age?  ";
	cin >> age;
	cin.ignore();
	cout << "What is your name?  ";
	getline(cin, name);	
	cout << "What is your favorite letter in the alphabet?  ";
	cin >> letter;
	
	//output and practice with arithmetic expressions, random numbers, and the math library
	cout << name << ", who is " << age << ", loves the letter " << letter << "!\n";
	cout << "5/3 is " << static_cast<double>(num1)/num2 << endl;
	
	//Add num1 + num2 to what is already in total and then assign the result to total
	total = num1 + num2 + total;
	cout << "total + num1 + num2 is " << total << endl;
	
	cout << "\nI am going to generate a random number between your minimum number and 150.  Please enter your minimum number, which should be below 150.\n";
	cin >> userMin;
	randomNumber = (rand()%(150-userMin))+userMin;
	cout << "\nThe random number is " << randomNumber << endl;
	cout << "7.5 to the power of " << userMin << " is " << pow(7.5, userMin) << endl;
	
	return 0;
}