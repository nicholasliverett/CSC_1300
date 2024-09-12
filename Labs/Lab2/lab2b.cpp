/*
	Title:  	lab2b.cpp
	Author:		Nicholas Liverett & Julian Barry
	Date:		9/12/24	
	Purpose:	Convenience store calculator, for only 2 items, including sales tax
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    string first_item, second_item;
    int first_item_amt, second_item_amt;
    double first_item_price, second_item_price, total_bill, sales_tax = 0.0975;

    cout << "Please input the name of the first item: ";
    getline(cin, first_item);
    cout << "Please input the number of " << first_item << " bought: ";
    cin >> first_item_amt;
    cout << "Please input the price of " << first_item << ": $";
    cin >> first_item_price;

    cin.ignore();

    cout << "\n\nPlease input the name of the second item: ";
    getline(cin, second_item);
    cout << "Please input the number of " << second_item << " bought: ";
    cin >> second_item_amt;
    cout << "Please input the price of " << second_item << ": $";
    cin >> second_item_price;

    total_bill = ((first_item_price * first_item_amt) + (second_item_price * second_item_amt)) * (1 + sales_tax);


    cout << setprecision(2) << fixed << "The total bill is $" << total_bill << ".";
	return 0;
}