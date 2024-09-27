/* 
     Title:   lab4c.cpp 
     Author:  Nicholas Liverett
     Date:    9/26/24 
     Purpose: Random Number Guessing Game
*/ 
 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std; 
 
int main() 
{ 
    char user_yn;
    int user_num;
    srand(time(0));

    // Initial ask user to play
    cout << "Would you like to play a game? ";
    cin >> user_yn;

    // Validate char input y/n
    user_yn = tolower(user_yn);
    while (user_yn != 'y' && user_yn != 'n') {
        cout << "\n Not a valid input\n";
        cout << "Enter a 'y' or 'n': ";
        cin >> user_yn;
        user_yn = tolower(user_yn);
    }

    // Main while including guessing rand num
    while (user_yn == 'y') {
        cout << "Guess a random number between 1-50: ";
        cin >> user_num;
        
        // Validate int input 1-50
        while (user_num < 1 || user_num > 50) {
            cout << "That's not in the guessing range. Try again: ";
            cin >> user_num;
        }
        int rand_num = 1 + rand() % 50;

        // Change output based on user guess
        if (rand_num == user_num) {
            cout << "\nGOOD JOB!";
        } else {
            cout << "\nThe number was " << rand_num;
            cout << "\nYou can always try again :)\n";
        }

        // Query user to play again 
        cout << "Play again? (y/n): ";
        cin >> user_yn;

        // Validate char input y/n
        user_yn = tolower(user_yn);
        while (user_yn != 'y' && user_yn != 'n') {
            cout << "\nNot a valid input\n";
            cout << "Enter a 'y' or 'n': ";
            cin >> user_yn;
            user_yn = tolower(user_yn);
        }
    }
    
    cout << "\nBYE BYE";

    return 0; 
} 