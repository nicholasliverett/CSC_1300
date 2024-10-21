/*
     Title:   mod7a.cpp 
     Author:  Nicholas Liverett
     Date:    10/21/24 
     Purpose: Practice
*/

#include <iostream> 
#include <string>
#include <cctype>
using namespace std; 

void countCharacters(string the_string, int choice) {
    int digits=0, not_digits=0;
    for (int i=0; i<the_string.length(); i++) {
        if (isdigit(the_string[i])) {
            digits++;
        } else if (!isalpha(the_string[i]) && !isspace(the_string[i])) {
            not_digits++;
        }
    }
    if (choice == 1) {
        cout << "\n\nThe number of digits is " << digits << endl;
    } else if (choice == 2) {
        cout << "\nThe number of characters other than a space, letter, or digit is " << not_digits << endl;
    }
}

int main() 
{ 
    string the_string;
    cout << "Enter in a string: ";
    getline(cin, the_string);
    countCharacters(the_string, 1);
    countCharacters(the_string, 2);

    return 0; 
}