/* 
     Title:   lab6.cpp 
     Author:  Nicholas Liverett
     Date:    10/10/24 
     Purpose: Halloween Town - Monster Toys
*/ 
 
#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

// Func declarations
void monstertoys();
int somethingcool(int display_count);
int mainmenu();
 
int main() { 
    int menu_input = 0, display_count;

    cout << "\nWELCOME TOO HALLOWEEN TOWN!";

    // Main loop call functions, and switch case based on menu input
    do {
        menu_input = mainmenu();

        switch(menu_input) {
        case 1: 
            monstertoys();
            break;
        case 2:
            display_count = somethingcool(display_count);
            break;
        case 3:
            cout << "\n\nYou chose to display the cool message " << display_count << " times.\n";
            cout << "\nBye!\n";
            break;
    }   

    } while (menu_input != 3);
    return 0; 
} 

int mainmenu() {
    int menu_input;
    // Output main menu and query user for choice
    cout << "\nPlease choose one of the following options:\n";
    cout << "   1 - Enter number of Monster toys\n";
    cout << "   2 - Display Something Cool\n";
    cout << "   3 - End the Program\n\n";
    cout << "CHOICE: ";
    cin >> menu_input;

    // Validate input otherwise requery for valid input
    while (menu_input < 1 || menu_input > 3) {
        cout << "Invalid choice. Please choose 1-3.\n";
        cout << "CHOICE: ";
        cin >> menu_input;
    }

    return menu_input;
}

void monstertoys() {
    ofstream monsters("monsters.txt");
    int num_monsters, toys, toys_total = 0;

    // Query user for amount of monsters that worked
    cout << "How many monsters worked on toys in Halloween Town during each of the last three years?\n";
    cin >> num_monsters;

    // Go through each monster and for each monster query user for each year's production
    for (int i=1;i<=num_monsters;i++) {
        for (int j=1;j<=3;j++) {
            cout << "How many toys did Monster " << i << " make, during year " << j << " ?\n";
            cin >> toys;

            // Output to monsters.txt
            monsters << "Monster " << i << ", year " << j << ": " << toys << " toys." << endl;
            toys_total += toys;
        }
    }

    // Output to terminal and monsters.txt
    cout << "The " << num_monsters << " Monsters made a total of " << toys_total << " toys during the last 3 years\n";
    monsters << "The " << num_monsters << " Monsters made a total of " << toys_total << " toys during the last 3 years\n";
}

int somethingcool(int display_count) {
    string input_file, line;
    
    // Query user for file to display
    cout << "What is the name of the text file with the ASCII image? ";
    cin.ignore();
    getline(cin, input_file);

    // Check if file is valid, otherwise count this as displaying cool message
    ifstream image_file(input_file);
    if (!image_file.is_open()) 
        cout << "Oh no! Looks like this file could not be opened\n"; 
    else 
        display_count++;

    // get each line, aslong as the file exists and there are lines to get
    while(getline(image_file, line)) 
        cout << line << endl;
    
    cout << endl;
    return display_count;
}