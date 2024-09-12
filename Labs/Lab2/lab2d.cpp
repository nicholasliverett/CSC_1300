/*
	Title:  	lab2d.cpp
	Author:		Nicholas Liveret & Julian Barry
	Date:		9/12/24	
	Purpose:	Calculate dog jail time via stolen bones
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int stolen_bones, days_imprisoned;
    double years_imprisoned;

    cout << "\n\nHow many bones have been stolen? ";
    cin >> stolen_bones;

    days_imprisoned = stolen_bones * 83;
    years_imprisoned = days_imprisoned / 365.0;

    cout << "You must go to prison for " << days_imprisoned << " days, which is " << years_imprisoned << " years.\n\n";

	return 0;
}