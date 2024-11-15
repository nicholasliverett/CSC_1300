/* 
     Title:   creaturefight.cpp 
     Author:  Nicholas Liverett
     Date:    11/15/24 
     Purpose: Creature fight game - main
*/ 
 
#include "program4.h"
using namespace std; 
 
int main() 
{ 
    int num_creatures=0, main_menu, max_creatures;
    char save_file;
    string file_name, lineOfStars = "********************************************************************************";

    cout << endl << lineOfStars << endl;
    cout << setw(30) << "CREATURE FIGHT!\n";
    cout << lineOfStars << endl;

    //query for arr max size and validate input
    cout << "\nWhat is the maximum number of creatures that can fit in your arena?\n";
    cout << "MAX NUM OF CREATURES (positive int.): ";
    while (!(cin >> max_creatures) || max_creatures <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong. Try Again (positive int.): ";
    }

    //dynamically allocate creatures arr
    Creatures *creatures_arr = new Creatures[max_creatures];

    //main menu loop
    do {
        //output menu and query for user decision and validate
        cout << "\nWhat would you like to do?\n";
        cout << "\t1. Enter some creatures\n";
        cout << "\t2. Fight!\n";
        cout << "\t3. Delete a creature\n";
        cout << "\t4. Print creatures\n";
        cout << "\t5. Print creature stats\n";
        cout << "\t6. End Program\n";
        cout << "ENTER 1-6: ";
        while (!(cin >> main_menu) || main_menu <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong. Try Again (1-6): ";
        }

        //branching menu choice
        if (main_menu == 1)
            num_creatures = enterCreatures(num_creatures, max_creatures, creatures_arr);
        else if (main_menu == 2)
            num_creatures = fight(num_creatures, creatures_arr);
        else if (main_menu == 3)
            num_creatures = deleteCreature(num_creatures, creatures_arr);
        else if (main_menu == 4)
            printCreatures(num_creatures, creatures_arr);
        else if (main_menu == 5)
            printStats(num_creatures, creatures_arr);
        
    } while (main_menu != 6);

    //query user for output file and validate choice
    cout << "Would you like to save your creature list to a file? (y/n) ";
    while (!(cin >> save_file) || (save_file != 'y' && save_file != 'n')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong. Try Again (y/n): ";
    }
    //save file
    if (save_file == 'y')
        saveCreaturesToFile(num_creatures, creatures_arr);

    //bye bye
    cout << "\nGOODBYE!\n\n";


    return 0; 
} 