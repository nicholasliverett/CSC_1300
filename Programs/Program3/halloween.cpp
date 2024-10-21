/* 
     Title:   nliverett42_prog3.cpp 
     Author:  Nicholas Liverett
     Date:    10/20/24 
     Purpose: Program 2
*/ 
 
#include "halloween.h" 
 
int main() 
{ 
    string guests[6], activities[6], food[6];
    int menu_choice, food_amount[6];
    cout << "\n~Time to plan my awesome Halloween Party!~\n";
    do {
        print_menu();
        cin >> menu_choice;

        if (menu_choice == 1) {
            manage_guests_or_activities(guests, 1);
        } else if (menu_choice == 2) {
            manage_guests_or_activities(activities, 2);
        } else if (menu_choice == 3) {
            print_food(food, food_amount);
        } else if (menu_choice == 4) {
            //save_to_file();
        } else {

        }
    } while(menu_choice != 5);
    return 0; 
} 

void print_menu() {
    cout << "1. Manage Guest List\n";
    cout << "2. Manage Activities\n";
    cout << "3. Check Food\n";
    cout << "4. Save Part to File\n";
    cout << "5. Exit Part Planning\n";
}