/* 
     Title:   lab5.cpp 
     Author:  Nicholas Liverett
     Date:    10/3/24 
     Purpose: Create a Rock-Paper-Scissors type game
*/ 
 
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std; 
 
int main() 
{ 
    int num_players, total_rounds=0, total_ties=0, round_avg;
    string player_name;
    srand(time(0));

    // Query amount of contestants    
    cout << "\nHow many contestants are playing? ";
    cin >> num_players;
    // Validate query, otherwise if not above 0 then requery
    while (num_players < 1) {
        cout << "\n\nDo you not want to play :(\n";
        cout << "Please have at least 1 contestant: ";
        cin >> num_players;
    }

    // Main loop that goes for each contestant
    for (int i=1; i <= num_players; i++) {
        int player_choice, comp_choice, comp_wins=0, player_wins=0, round = 1;

        // Query for player name
        cout << "\n\nWhat's your name contestant " << i << "? ";
        cin.ignore();
        getline(cin, player_name);

        // Go through each round while player or computer hasn't wont 3 times
        do {
            
            // Get comp choice
            comp_choice = rand() % 3 +1;
            
            // Query for player choice
            cout << "Choose your weapon:\n";
            cout << "1. Boulder\n";
            cout << "2. Sheet\n";
            cout << "3. Two knives tapped together\n";
            cin >> player_choice;

            // Validate player choice, otherwise requery
            while (player_choice < 1 | player_choice > 3) {
                cout << "\nNo specialty moves. Choose option 1-3: ";
                cin >> player_choice;
            }
            
            // Boulder(1) > Knives(3), Sheet(2) > Boulder(1), Knives(3) < Sheet(2)
            // If player beats comp, if comp beats player, or else (tie)
            if ((player_choice == 1 && comp_choice == 3) || (player_choice == 2 && comp_choice == 1) || (player_choice == 3 && comp_choice == 2)) {
                cout << "\nRound " << round << ": " << player_name << " wins!!\n";
                player_wins++;
            } else if ((comp_choice == 1 && player_choice == 3) || (comp_choice == 2 && player_choice == 1) || (comp_choice == 3 && player_choice == 2)) {
                cout << "\nRound " << round << ": Computer wins :(\n";
                comp_wins++;
            } else {
                cout << "\nRound " << round << ": is a tie!!\n";
                total_ties++;
            }
            round++;
            total_rounds++;
        } while (comp_wins != 3 && player_wins != 3);
        
        // Output based on who won 3 rounds
        if (comp_wins == 3) {
            cout << "The computer wins :( womp womp\n";
        } else if (player_wins == 3) {
            cout << player_name << " wins!! So proud :)\n";
        }
    }

    // Output end data, total rounds played by all players, average round played by each player, and total ties
    cout << "\nTotal Rounds: " << total_rounds;
    cout << "\nAverage rounds per contestant: " << fixed << setprecision(1) << 1.0 * total_rounds / num_players;
    cout << "\nTotal ties: " << total_ties;

    return 0; 
} 