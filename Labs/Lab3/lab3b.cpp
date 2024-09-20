/* 
     Title:   lab3b.cpp 
     Author:  Nicholas Liverett
     Date:  9/19/24 
     Purpose: something something pigs? eating?
*/ 
 
#include <iostream>
#include <ctime>
using namespace std; 
 
int main() 
{ 
    srand(time(0));
    // Setup
    int rand_food = rand() % 3 + 1;
    char eat_decision;
    string maybe_food;

    cout << "\nYour pig is going on a picnic in the mountains!\n";

    // assign rand food to it's respective string / type of food
    if (rand_food == 1)
        maybe_food = "apple";
    else if (rand_food == 2)
        maybe_food = "mud";
    else 
        maybe_food = "corn";

    // Query user for decision
    cout << "The pig found an " << maybe_food << "! should it eat it (e) or leave it (l)? ";
    cin >> eat_decision;

    // Nest some ifs to determine the pigs reaction to user decision
    if (eat_decision == 'e') {
        if (rand_food == 1 || rand_food == 3)
            cout << "Yum! The pig enjoyed the food.";
        else 
            cout << "Yuck! The pig got sick from eating the mud.";
    } else if (eat_decision == 'l')
        cout << "The pig decided to leave the food and continue the picnic.";
    else 
        cout << "Invalid choice! The pig decided to walk away.";
    
    cout << endl << endl;
        

    return 0; 
} 