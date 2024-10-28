/* 
     Title:   mod8a.cpp 
     Author:  Nicholas Liverett
     Date:    10/28/24 
     Purpose: In Class Practice 1
*/ 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

 
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
    return 0; 
} 