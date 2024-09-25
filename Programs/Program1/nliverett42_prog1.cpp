/* 
    Title:   nliverett42_prog1.cpp 
    Author:  Nicholas Liverett
    Date:    September 25, 2024 
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
    cout << endl << endl << "****************************" << endl; // I don't like setw or fill
    cout << "*  ALIEN BLASTER SHOWDOWN  *" << endl;
    cout << "****************************" << endl << endl; // sue me

    // Enter Game Master name
    string game_master_name;
    cout << "Enter your name as the Game Master: ";
    getline(cin, game_master_name);
    cout << endl << endl << "Welcome, Game Master " << game_master_name << ", to the Alien Blaster Showdown!" << endl;

    // Vars setup for loop, intercept calculations, and y/n input
    char saucer_incoming = 'y';
    int saucer_distance, saucer_speed, tracked_saucers = 0, saucers_blasted = 0;
    double saucer_intercept_time;

    // Loop until player inputs 'n'
    while (saucer_incoming == 'y' || saucer_incoming == 'Y') {

        // Get distance and speed to calculate saucer intercept time
        cout << "Enter the distance of the alien saucer in meters: ";
        cin >> saucer_distance;
        cout << "Enter the speed of the alien saucer in meters per second: ";
        cin >> saucer_speed;
        saucer_intercept_time = static_cast<double>(saucer_distance)/saucer_speed; // love me some static_cast
        cout << "Alien saucer detected! Time until it reaches the crowd: " << fixed << setprecision(2) << saucer_intercept_time << " seconds." << endl;
        
        // Change output based on intercept time to audience.
        if (saucer_intercept_time < 5) {
            cout << "Blast it with foam cannons! It's zooming in too fast!";
            saucers_blasted++;
        } else if (saucer_intercept_time <= 15) {
            cout << "Hold fire! Let's cheer for the saucer as it zooms by!";
        } else if (saucer_intercept_time > 15) {
            cout << "No need to worry, it's just hovering around. Keep enjoying the show!";
        }
        
        // Query player for input y/n to continue shooting or not
        cout << endl << endl << "Is there another saucer approaching? (y/n): ";
        cin >> saucer_incoming;
        cout << endl;
        
        tracked_saucers++;
    }

    // Output end of game stats
    cout << "The Alien Blaster Showdown has ended! You tracked " << tracked_saucers << " saucers." << endl;
    cout << "You blasted " << saucers_blasted << " saucer(s) out of the air! Great job!" << endl;

    // Change end message based on amount of blasted saucers
    if (saucers_blasted > 7) {
        cout << "That was intense! The crowd loved it-10/10 entertainment!" << endl;
    } else {
        cout << "What a peaceful show! Everyone left with smiles on their faces." << endl;
    }
    
    return 0;
}