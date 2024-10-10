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

void monstertoys();
void somethingcool();
int display_count;
 
int main() 
{ 
    int menu_input = 0;

    cout << "\nWELCOME TOO HALLOWEEN TOWN!\n";

    do {

        cout << "\nPlease choose one of the following options:\n";
        cout << "   1 - Enter number of Monster toys\n";
        cout << "   2 - Display Something Cool\n";
        cout << "   3 - End the Program\n\n";
        cout << "CHOICE: ";
        cin >> menu_input;

        while (menu_input < 1 || menu_input > 3) {
            cout << "Invalid choice. Please choose 1-3.\n";
            cout << "CHOICE: ";
            cin >> menu_input;
        }

        switch(menu_input) {
            case 1: 
                monstertoys();
                break;
            case 2:
                somethingcool();
                break;
            case 3:
                cout << "\n\nYou chose to display the cool message " << display_count << " times.\n";
                cout << "\nBye!\n";
                break;
        }   

    } while (menu_input != 3);
    return 0; 
} 

void monstertoys() {
    ofstream monsters("monsters.txt");
    int num_monsters, toys, toys_total = 0;
    cout << "How many monsters worked on toys in Halloween Town during each of the last three years?\n";
    cin >> num_monsters;
    for (int i=1;i<=num_monsters;i++) {
        for (int j=1;j<=3;j++) {
            cout << "How many toys did Monster " << i << " make, during year " << j << " ?\n";
            cin >> toys;
            monsters << "Monster " << i << ", year " << j << ": " << toys << " toys.";
            toys_total += toys;
        }
    }
    cout << "The " << num_monsters << " Monsters made a total of " << toys_total << " toys during the last 3 years\n";
}

void somethingcool() {
    string input_file, line;
    cout << "What is the name of the text file with the ASCII image? ";
    cin.ignore();
    getline(cin, input_file);

    ifstream image_file(input_file);
    if (!image_file.is_open()) 
        cout << "Oh no! Looks like this file could not be opened\n"; 
    else 
        display_count++;

    while(getline(image_file, line)) 
        cout << line << endl;
    
    cout << endl;
}