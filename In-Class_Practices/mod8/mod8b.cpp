/* 
     Title:   mod8b.cpp 
     Author:  Nicholas Liverett
     Date:    10/28/24 
     Purpose: In Class Practice 2
*/ 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

int find_highest(double prices[]) {
    int max = 0;
    for (int i=1;i<10;i++) {
        if (prices[i] > prices[max])
            max = i;
    }
    return max;
}

int find_lowest(double prices[]) {
    int min = 0;
    for (int i=1;i<10;i++) {
        if (prices[i] < prices[min])
            min = i;
    }
    return min;
}

double find_average(double prices[]) {
    double total;
    for (int i=0;i<10;i++) {
        total += prices[i];
    }
    return total/10;
}

int main() 
{ 
    string things[10];
    double prices[10];
    cout << "\nTell me 10 useful things and their price:\n";
    for (int i=0;i<10;i++) {
        cout << "Thing " << i+1 << ": ";
        getline(cin, things[i]);
        cout << "Price for Thing " << i+1 << ": ";
        cin >> prices[i];
        cin.ignore();
    }
    cout << "Your list of useful items include:\n";
    for (int i=0;i<10;i++) {
        cout << fixed << setprecision(2) << things[i] << ", $" << prices[i] << endl;
    }

    int h = find_highest(prices), l = find_lowest(prices);
    double a = find_average(prices);

    cout << "\n\n****RESULTS****";
    cout << "\nHighest Price: " << things[h] << " $" << prices[h];
    cout << "\nLowest Price: " << things[l] << " $" << prices[l];
    cout << "\nAverage Price: $" << a;


    return 0; 
} 