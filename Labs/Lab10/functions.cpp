/*
	 Title:   functions.cpp
	 Author:  Nicholas Liverett
	 Date:    11/21/24   
	 Purpose: Lab 10 - functions
*/

#include "lab10.h"

void get_profit(string* date, double* profit, int amt_months) {
    for (int i=0;i<amt_months;++i) {

        cout << "DATE:\t";
        cin.ignore();
        getline(cin, *(date + i));

        cout << "PROFIT:\t$";
        while (!(cin >> *(profit + i)) || (*(profit + i) <= 0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong. Try Again (positive num.): ";
        }
    }
}

double get_total(double* profit, int amt_months) {
    double total = 0;
    for (int i=0;i<amt_months;++i) {
        total += *(profit + i);
    }
    return total;
}

void get_max(string* date, double* profit, int amt_months, string& max_date, double& max_profit) {
    max_date = *(date);
    max_profit = *(profit);
    for (int i=0;i<amt_months;++i) {
        if (*(profit + i) > max_profit) {
            max_date = *(date + i);
            max_profit = *(profit + i);
        }
    }
}

void get_min(string* date, double* profit, int amt_months, string& min_date, double& min_profit) {
    min_date = *(date);
    min_profit = *(profit);
    for (int i=0;i<amt_months;++i) {
        if (*(profit + i) < min_profit) {
            min_date = *(date + i);
            min_profit = *(profit + i);
        }
    }
}

