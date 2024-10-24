/* 
     Title:   lab7_functions.cpp 
     Author:  Nicholas Liverett
     Date:    10/24/24 
     Purpose: Generate the future
*/ 

#include "lab7_header.h"

// take min(p1) and max(p2) parameters to create range for random int
int generate_random_int(int p1, int p2) {
	srand(time(0));
	p2 = p2 - p1;
	return rand() % p2 + p1;
}

// get three nums of childs; validate input for type and min max value
void get_num_children(int nums[]) {
    for (int i=0;i<3;i++) {
        cout << "Enter a number between 1 and 100: ";
        while (!(cin >> nums[i]) || nums[i] < 1 || nums[i] > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong.\nTry again: ";
        }
    }
    cin.ignore();
}

// get three nums of salarys; validate input for type and min max value
void get_salary(double sals[]) {
    for (int i=0;i<3;i++) {
        cout << "Enter a number between 10,000 and 500,000: ";
        while (!(cin >> sals[i]) || sals[i] < 10000 || sals[i] > 500000) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong.\nTry again: ";
        }
    }
    cin.ignore();
}