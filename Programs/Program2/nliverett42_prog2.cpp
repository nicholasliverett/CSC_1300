/* 
     Title:   nliverett42.cpp 
     Author:  Nicholas Liverett
     Date:    9/27/24 
     Purpose: Basic Pet Store Management System, discovering why maps are a thing, and how easy it is to overcomplicate things
*/ 
 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std; 
 
int main() 
{
    fstream animaldb;
    ofstream temp;
    int menu_input, sell_input, num_of_lines, i;
    string animal_type, animal_name, entry, entry_delete;

    /*
    
    Assuming animals.txt is a file with no extra lines, i.e. no empty lines at the end of all the entries/lines

    */

    cout << "\nWelcome to the Pet Store Management System!\n\n";

    do {
        // Open and verify animals
        animaldb.open("animals.txt", ios::app | ios::in);
        if (!animaldb.is_open()) {
            cout << "Error opening file.";
            return 1;
        }
        
        // Output menu
        cout << "Choose from the following options:\n";
        cout << "1. Add a new animal\n";
        cout << "2. Display all animals\n";
        cout << "3. Sell an animal\n";
        cout << "4. Exit\n\n";

        // Query user for menu option
        cout << "Please choose an option: ";
        cin >> menu_input;

        // Validate int input and requery if invalid
        while (menu_input < 1 || menu_input > 4) {
            cin.clear(); // Lovely
            cin.ignore(); // Avoid infinite loop if you input a non character, such as a string, 'Cat' or whatever
            cout << "Oops! That option doesn't exist. Please choose 1, 2, 3, or 4.\n";
            cout << "Please choose an option: ";
            cin >> menu_input;
        } 

        // Menu Logic 1, 2, and 3 input
        if (menu_input == 1) {

            // Query user for new animal info
            cin.ignore();
            cout << "\nEnter the animal type: ";
            getline(cin, animal_type);
            cout << "Enter the animal's name: ";
            getline(cin, animal_name);

            // Add endl before  entry unless file is empty
            animaldb.clear(); // I don't like this grandpa
            animaldb.seekg(0); 
            getline(animaldb, entry);
             if (entry.find(':') != string::npos) { // 
                animaldb.clear(); // I hate c++
                animaldb << endl;
            }
            
            // Append animals.txt with new animal entry
            animaldb.clear(); // right...
            animaldb << animal_type << ":" << animal_name;

            cout << animal_name << " was added successfully!\n\n";
            animaldb.close();

        } else if (menu_input == 2) {

            // Output animals in store - could be a function
            cout << "\nAnimals currently in the pet store:\n";
            animaldb.clear(); // mmhmm..
            animaldb.seekg(0);
            i = 1;
            while (getline(animaldb, entry) ) {
                // Output name and animal type based on ":", create substr yada yada
                cout << i << ". " << entry.substr(0,entry.find(":")) << " named " << entry.substr(entry.find(":")+1) << endl;
                i++;
            }
            cout << "\n";
            animaldb.close();

        } else if (menu_input == 3) {

            // Makes sure there are animals to sell
            animaldb.clear(); // for sure
            animaldb.seekg(0);
            getline(animaldb, entry);
            if (entry.find(':') == string::npos) {
                cout << "There are no animals to sell!\n\n";
            } else {

                // Open and validate temp - why not use a map :(
                temp.open("temp.txt"); 
                if (!temp.is_open()) { 
                    cout << "Error opening file."; 
                    return 1;
                }

                // Output animals in store - should be a function
                cout << "\nAnimals currently in the pet store:\n";
                num_of_lines = 0;
                animaldb.clear(); // for sure for sure
                animaldb.seekg(0);
                i = 1;
                while (getline(animaldb, entry) ) {
                    // Output name and animal type based on ":", create substr yada yada
                    cout << i << ". " << entry.substr(0,entry.find(":")) << " named " << entry.substr(entry.find(":")+1) << endl;
                    i++;
                    num_of_lines++;
                }

                // Query user for sold animal
                cout << "Enter the number of the animal that sold: ";
                cin >> sell_input;

                // Validate user input
                while (sell_input < 1 || sell_input > num_of_lines) {
                    cout << "Oops! There is no animal with number " << sell_input << ". Select an animal between 1 and " << num_of_lines << ".\n";
                    cout << "Enter the number of the animal that sold: ";
                    cin >> sell_input;
                }

                // Output new list, without entry to be sold, to temp file
                animaldb.clear(); // no fs
                animaldb.seekg(0);
                i = 1;
                while (getline(animaldb,entry)) {
                    if (i != sell_input) {
                        temp << entry;

                        /*
                        Do not output an endl if:
                        A) We are outputting the last entry (doing so would result in an empty line at the end of the file)
                        or
                        B) The entry to be deleted is the last one and we are outputting the "new" last entry (or the old second to last entry)
                        */
                        if (num_of_lines == sell_input) {
                            if (i != sell_input-1) {
                                temp << endl;
                            }
                        } else if (i != num_of_lines) {
                            temp << endl;
                        }
                    }
                    cout << i << " " << num_of_lines << " " << sell_input << endl;
                    i++;
                }
                cout << "The animal has been removed from the file.\n\n";

                animaldb.close();
                temp.close();

                // Replace existing animals with temp that has updated list
                remove("animals.txt");
                rename("temp.txt", "animals.txt");
            }

        }

    } while (menu_input != 4);

    cout << "\nGoodbye!\n\n";

    return 0; 
} 