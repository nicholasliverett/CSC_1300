/*
	 Title:   driver.cpp
	 Author:  Nicholas Liverett
	 Date:    11/21/24   
	 Purpose: Lab 10 - functions
*/

#include "lab10.h"

int main() {
    char profit_again;
    int amt_months;
    double total, max_profit, min_profit;
    string max_date, min_date;
    string line_dashes = "----------------------------------------------------------------------------------------------------";


    cout << endl << line_dashes << endl << "\t\t\t\tTurkey Town Theme Park Profit Calc\n" << line_dashes << endl << endl;


    do {
        //get num of months and validate num/int
        cout << "How many months of profits do you wish to enter?\t";
        while (!(cin >> amt_months) || (amt_months <= 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong. Try Again (positive int.):\t\t\t";
        }

        string *date = new string[amt_months];
        double *profit = new double[amt_months];

        cout << "\n\nLet's enter some profits!\nWhen you enter in the date, enter in the month & year like this: 'April 2024'.\n\n";

        get_profit(date, profit, amt_months);

        total = get_total(profit, amt_months);

        get_max(date, profit, amt_months, max_date, max_profit);
        get_min(date, profit, amt_months, min_date, min_profit);

        cout << endl << line_dashes << endl << line_dashes << endl;

        cout << setw(40) << "TOTAL PROFITS:\t\t$" << setw(16) << fixed << setprecision(2) << total << endl;
        cout << setw(40) << "AVERAGE PROFIT:\t\t$" << setw(16) << fixed << setprecision(2) << total/amt_months << endl;
        cout << setw(40) << "DATE WITH LARGEST PROFIT:\t\t" << max_date << " totaling $" << fixed << setprecision(2) << max_profit << endl;
        cout << setw(40) << "DATE WITH SMALLEST PROFIT:\t\t" << min_date << " totaling $" << fixed << setprecision(2) << min_profit;

        cout << endl << line_dashes << endl << line_dashes << endl;

        cout << "Would you like to run the program again? (Y/N)\n";
        while (!(cin >> profit_again) || (profit_again != 'Y' && profit_again != 'N')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong. Try Again (Y/N): ";
        }


        delete [] date;
        delete [] profit;
    } while(profit_again != 'N');


    return 0;
}