/*
	Title:  	lab2a.cpp
	Author:		Nicholas Liverett & Julian Barry
	Date:		9/12/24	
	Purpose:	This program is written for waiters & waitresses at
				TGI Fridays so that they can calculate total cost
				of hot wings for their customers.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//define your variables here
    const double wing_price = 0.99;
    const double sales_tax = 0.085;
    int wings_amt;
    double total_bill;
	
	/* 	the line below will allow floating point amounts to display
		two numbers after the decimal point.  (it will make amounts pretty) 
	*/
	cout <<	setprecision(2) << fixed << showpoint; 
	cout << "\n\nPlease input the number of hot wings purchased:  ";
	
	//	Fill in the	input statement to bring in	the	quantity of hot wings.
	cin >> wings_amt;
	//	Fill in the assignment statement to determine the total bill.
	total_bill = (wings_amt * wing_price) * (1 + sales_tax);
	//	Fill in	the	output statement to print total	bill as shown in sample output
	cout << "Total Bill: $" << total_bill;
	return 0;
}
