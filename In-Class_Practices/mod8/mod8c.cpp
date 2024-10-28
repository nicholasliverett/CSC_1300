/* 
     Title:   mod8c.cpp 
     Author:  Nicholas Liverett
     Date:    10/28/24 
     Purpose: In Class Practice 3
*/ 
 
#include <iostream>
#include <string>
#include <cstring>
using namespace std; 
 
int main() 
{ 
    char name1[30] = "Nicholas";
    string name2 = "Bob";
    cout << "name1: " << name1 << endl;
    cout << "name2: " << name2 << endl << endl;

    cout << "What is your full name? ";
    cin.getline(name1, 30);
    cout << "What is your friend's full name? ";
    getline(cin, name2);

    cout << "\n\nname1: " << name1;
    cout << "\nname2: " << name2 << endl << endl;

    strcpy(name1, "SCOUT");
    name2 = "JACK";

    for (int i=0;i<strlen(name1);i++) {
        cout << name1[i] << "*";
    }
    cout << endl;
    for (int i=0;i<4;i++) {
        cout << name2[i] << "*";
    }


    return 0; 
} 