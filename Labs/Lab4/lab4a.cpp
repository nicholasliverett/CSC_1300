/* 
     Title:   lab4a.cpp 
     Author:  Nicholas Liverett
     Date:  9/26/2024 
     Purpose: Password Generator
*/ 
 
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std; 
 
int main() 
{ 
    string user_pass;
    srand(time(0));

    cout << "***The Password Program***\n\n";

    // Validate pass for spaces otherwise request input again
    do {
        cout << "Please enter a word with no spaces: ";
        getline(cin, user_pass);

    } while (user_pass.find(' ') != string::npos);
    
    // Capitalize random char in pass if letter and lowercase
    int rand_index = rand() % (user_pass.length() - 1);
    if (isalpha(user_pass[rand_index]) && islower(user_pass[rand_index]))
        user_pass[rand_index] = 'A' + rand() % 26;

    // Change a, g, and d to respective phonetic equivalents if a, g, d exist in str
    int aindex = user_pass.find('a');
    int gindex = user_pass.find('g');
    int dindex = user_pass.find('d');
    if (aindex != string::npos) {
        user_pass.replace(aindex, 1, "");
        user_pass.insert(aindex, "-alpha-");
    } if (gindex != string::npos) {
        user_pass.replace(gindex, 1, "");
        user_pass.insert(gindex, "-gamma-");   
    } if (dindex != string::npos) {
        user_pass.replace(dindex, 1, "");
        user_pass.insert(dindex, "-delta-");
    }

    // Append 3 digits to end of pass
    user_pass += to_string(100 + rand() % 900);

    // Output pass
    cout << "Your updated password: " << user_pass;

    // Lab instructions and examples outputs were contradictory and confusing?
    

    return 0; 
} 