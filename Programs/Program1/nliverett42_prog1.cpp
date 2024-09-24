/* 
    Title:   nliverett42_prog.cpp 
    Author:  Nicholas Liverett
    Date:  September 10, 2024 
    Purpose: Create a simple game that tracks saucers and their speed
*/ 
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
    // Display game title
    cout << endl << endl << "****************************" << endl;
    cout << "*  ALIEN BLASTER SHOWDOWN  *" << endl;
    cout << "****************************" << endl << endl;

    // Enter Game Master name
    string game_master_name;
    cout << "Enter your name as the Game Master: ";
    getline(cin, game_master_name);
    cout << endl << endl << "Welcome, Game Master " << game_master_name << ", to the Alien Blaster Showdown!" << endl;

    // Loop vars setup
    char saucer_incoming;
    int saucer_distance, saucer_speed, i = 0, saucers_blasted = 0;
    double saucer_intercept_time;

    // Loop 10 times for shoot saucer game 
    while (i < 10) {
        cout << "Enter the distance of the alien saucer in meters: ";
        cin >> saucer_distance;
        cout << "Enter the speed of the alien saucer in meters per second: ";
        cin >> saucer_speed;
        saucer_intercept_time = static_cast<double>(saucer_distance)/saucer_speed; // this works
        cout << "Alien saucer detected! Time until it reaches the crowd: " << fixed << setprecision(2) << saucer_intercept_time << " seconds." << endl;
        
        // Change output based on intercept time to audience.
        if (saucer_intercept_time <= 5) {
            cout << "Blast it with foam cannons! It's zooming in too fast!";
            saucers_blasted++;
        } else if (saucer_intercept_time <= 15) {
            cout << "Hold fire! Let's cheer for the saucer as it zooms by!";
        } else if (saucer_intercept_time > 15) {
            cout << "No need to worry-it's just hovering around. Keep enjoying the show!";
        }
        
        // End while loop if user answers n, otherwise continue as normal
        cout << endl << endl << "Is there another saucing approaching? (y/n): ";
        cin >> saucer_incoming;
        if (saucer_incoming == 'y') {

            // Break while loop if 10 saucers have been tracked
            if (i == 9) {
                break; 
            }
        } else if (saucer_incoming == 'n') {
            cout << endl;
            cout << "The Alien Blaster Showdown has ended! You tracked " << i+1 << " saucers." << endl;
            break;
        }


        i++;
    }

    cout << "You blasted " << saucers_blasted << " saucers out of the air! Great job!" << endl;
    // Change end message based on amount of blasted saucers
    if (saucers_blasted < 7) {
        cout << "What a peaceful show! Everyone left with smiles on their faces." << endl;
    } else {
        cout << "That was intense! The crowd loved it-10/10 entertainment!" << endl;
    }
    
    return 0;
}