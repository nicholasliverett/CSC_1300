/* 
     Title:   lab4b.cpp 
     Author:  Nicholas Liverett
     Date:    9/24/24
     Purpose: Testing Time
*/ 
 
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
using namespace std; 
 
int main() 
{ 
    cout << "\n***Testing Soon***\n";

    int menu_option, labs = 0, ohours = 0;
    char mine_option;

    // Loop menu until user wants to take test
    do {
        cout << "\n\n";
        cout << "1. Go to Lab\n";
        cout << "2. Go to Officer Hours\n";
        cout << "3. Take the test\n";

        // Query and validiate user input option 1-3
        cout << "Please choose an option 1-3: ";
        cin >> menu_option;
        while (menu_option < 1 || menu_option > 3) {
            cout << "That's not an option, you silly goose. Enter 1-3: ";
            cin >> menu_option;
        }

        // Change ouputs based on menu option
        if (menu_option == 1){
            cout << "Did you play minesweeper all of lab? (y/n): ";
            cin >> mine_option;
            if (tolower(mine_option) == 'y')
                cout << "Negative aura..tsk tsk";
            else
                cout << "Your TAs are proud.";
            labs++;
        } else if (menu_option == 2) {
            cout << "You chose to go to office hours. Very demure";
            ohours++;
        }
    } while (tolower(menu_option) != 3);

    // Output luck message and end stats
    cout << "\nGood luck soldier o7\n";
    
    cout << "\nLabs: " << labs;
    cout << "\nOffice hours: " << ohours;
    cout << endl;

    // Change output based on end stats
    if (labs >= 3 || ohours >= 3)
        cout << "You passed the test without even trying. Good job!";
    else if (labs >= 1 || ohours >= 1)
        cout << "You attendance paid off.";
    else
        cout << "Risky, risky...";

    return 0; 
} 