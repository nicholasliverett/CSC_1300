/*
	Title:  messedUp.cpp
	Author:
	Date:
	Purpose:  Debugging code that contains loops
*/

#include <iostream>
using namespace std;

int main()
{	
	int total;
	bool skip = false;
	char response;
	
	do {
	total = 0;
		//add every-other odd number from 1 to 100	
		for(int num = 1; num <= 100; num++) {
			if((num % 2) != 0) {
				if(skip == false) {
					total += num;
					skip = true;
				}else
					skip = false;
			}	
		}
			
		cout << "\nThe total of adding every-other odd number from " << "1 to 100 is " << total << endl;
			 
		cout << "\nWould you like to run again? (y or n): ";
		cin >> response;
	}
	while(response == 'y' || response == 'Y');
		
	cout << endl;	
	return 0;
}