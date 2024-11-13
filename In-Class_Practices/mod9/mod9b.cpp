/* 
     Title:   mod9b.cpp 
     Author:  Nicholas Liverett
     Date:    11/13/24 
     Purpose: In-Class Practice 2
*/ 
 
#include <iostream>
#include <string> 
using namespace std; 
 
int main() 
{ 
    string foods[10];
    string *foodptr = foods;

    cout << "Enter your favorite foods!\n";
    for (int i=0;i<10;i++) {
        cout << "FAVORITE FOOD " << i+1 << ": ";
        getline(cin, *(foodptr + i));
    }

    cout << "\nGreat, here is your list:\n";
    for (int i=0;i<10;i++) {
        cout << foods[i] << endl;
    }
    return 0; 
} 