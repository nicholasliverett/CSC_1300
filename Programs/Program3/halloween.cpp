/* 
     Title:   nliverett42_prog3.cpp 
     Author:  Nicholas Liverett
     Date:    10/20/24 
     Purpose: Program 2
*/ 
 
#include "halloween.h" 
 
int main() 
{ 
    // Array and var setup
    size_t guests_size = 5, activities_size = 5;
    string guests[6] = {"Dracula", "Steve Jobs", "Ms. Loch Ness", "Jeff", "Dr. Gannod"};
    string activities[6] = {"Apple Bobbing", "Costume Contest", "Pumpkin Carving", "Ghost Stories", "Pin the tail on the ghoul"};
    string food[] = {"Witch Finger Cookies", "Zombie Meatloaf", "Eyeball Punch", "Spider Web Cupcakes"};
    int food_amount[] = {7, 6, 12, 15};
    int menu_choice=1;
    cout << "\n~Time to plan my awesome Halloween Party!~\n";
    do {
        // Menu1
        if (menu_choice != 1 && menu_choice != 2 && menu_choice != 3 && menu_choice != 4)
            cout << "\nYou must enter in a choice between 1 and 5.\nCHOOSE 1-5: ";
        else
            print_menu();
        cin >> menu_choice;

        // Branch based on user menu1 choice
        if (menu_choice == 1) {
            if (manage_guests_or_activities(guests, guests_size, 1) != 0) // Output error if func returns non-zero
                cout << "There was an unexpected error!\n";
        } else if (menu_choice == 2) {
            if (manage_guests_or_activities(activities, activities_size, 2) != 0) // Output error if func returns non-zero
                cout << "There was an unexpected error!\n";
        } else if (menu_choice == 3) {
            print_food(food, food_amount);
        } else if (menu_choice == 4) {
            save_to_file(guests, guests_size, activities, activities_size, food, food_amount);
        }
            
    } while(menu_choice != 5);
    return 0; 
} 

void print_menu() {
    cout << "\n1. Manage Guest List\n";
    cout << "2. Manage Activities\n";
    cout << "3. Check Food\n";
    cout << "4. Save Party to File\n";
    cout << "5. Exit Party Planning\n    ";
}

int manage_guests_or_activities(string list[], size_t& list_size, int gues_act) {
    // Var setup
    string guest_or_activity, name;
    int menu_choice=1, menu_choice2=1;

    // Change based on which list we are managing
    if (gues_act == 1) 
        guest_or_activity = "Guest";
    else if (gues_act == 2)
        guest_or_activity = "Activity";

    do {
        // Output list content and main menu
        if (menu_choice < 1 || menu_choice > 4) {
            cout << "\nYou must enter in a choice between 1 and 4.\nCHOOSE 1-4: ";
            cin >> menu_choice;
        } else {
            cout << endl << guest_or_activity << " list:\n";    
            for (int i=0; i<list_size; i++) 
                cout << "   " << i+1 << ". " << list[i] << endl;
            cout << "1. Add " << guest_or_activity << "\n";
            cout << "2. Remove " << guest_or_activity << "\n";
            cout << "3. Modify " << guest_or_activity << "\n";
            cout << "4. Exit " << guest_or_activity << " List\n    ";
            cin >> menu_choice;
        }

        if (menu_choice == 1) {
            // Check if array full
            if (list_size == 6) {
                cout << "The " << guest_or_activity << " list is full!\n";
                return -1; // "Throw" error
            }

            // Query for name to add
            cout << "Enter the " << guest_or_activity << "'s name.\n    ";
            cin.ignore();
            getline(cin, name);

            // Add to end of array
            list[list_size] = name;
            list_size++;
            
        } else if (menu_choice == 2) {
            // Check if array empty
            if (list_size == 0) {
                cout << "The " << guest_or_activity << " list is empty!\n";
                return -1; // "Throw" error
            }
            
            // Query for guest/act to remove
            cout << "Enter the " << guest_or_activity << " you want to remove.\n    ";
            cin >> menu_choice2;

            //validate guest/act choice
            while (menu_choice2 < 1 || menu_choice2 > list_size) {
                cout << "You must enter a number between 1 and " << list_size << ": ";
                cin >> menu_choice2; 
            }
            for (int i=menu_choice2-1;i<list_size;i++) {
                // Shift guests/acts aslong as i is not the last element of array
                if (i != 5)
                    list[i] = list[i+1];
                else // If last then make it blank
                    list[i] = "";
            }
            list_size--;
            
        } else if (menu_choice == 3) {
            // Check if array empty
            if (list_size == 0) {
                cout << "The " << guest_or_activity << "list is empty!\n";
                return -1; // "Throw" error
            }

            // Query for guest/act to modify and what to modfiy with
            cout << "Enter the " << guest_or_activity << " you want to modify.\n    ";
            cin >> menu_choice2;

            //validate guest/act choice
            while (menu_choice2 < 1 || menu_choice2 > list_size) {
                cout << "You must enter a number between 1 and " << list_size << ": ";
                cin >> menu_choice2; 
            }

            cout << "Enter the new " << guest_or_activity << "'s name.\n    ";
            cin.ignore();
            getline(cin, name);
            // Modify array entry/element
            list[menu_choice2-1] = name;
                
        }
    } while (menu_choice != 4);
    return 0;
}

void print_food(string food[], int food_amount[]) {
    cout << "\n";
    // Iterate through food array and output
    for (int i=0;i<4;i++) 
        cout << food[i] << " has " << food_amount[i] << " servings prepared.\n";
}

void save_to_file(string guests[], size_t guests_size, string activities[], size_t activities_size, string food[], int food_amount[]) {
    // Open output
    ofstream output("output.txt");
    // Output guest list
    output << "Guest List:\n";
    for (int i=0;i<guests_size;i++)
        output << "    " << guests[i] << "\n";
    // Output activities list
    output << "Planned Activities:\n";
    for (int i=0;i<activities_size;i++)
        output << "    " << activities[i] << "\n";
    // Output food and amount
    output << "Food:\n";
    for (int i=0;i<4;i++)
        output << "    " << food[i] << ": " << food_amount[i] << "\n";
    output.close();
}