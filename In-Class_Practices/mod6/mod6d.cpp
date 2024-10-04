/* 
     Title:   mod6c.cpp 
     Author:  Nicholas Liverett
     Date:    10/1/24 
     Purpose: Reading files with delimiters and file stream errors
*/ 
 
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
 
int main() 
{ 
    string file_name, entry, title, year, rating;
    int first, second, i = 1;
    // Query for filename
    cout << "What is the filename? (example.txt): ";
    cin >> file_name;

    // Setup file if able, otherwise return
    ifstream movie_file (file_name);
    if (!movie_file.is_open()) {
        cout << "Sorry, " << file_name << " was unable to be opened.";
        return 1;
    }
    while(getline(movie_file,entry, '#')) { 
        if (i % 3 == 1)
            title = entry; // Could getline() 2 more times instead of this
        if (i % 3 == 2)
            year = entry; // I'm a rebel >:)
        if (i % 3 == 0)
            rating = entry;

        // Output movie data
        if (i % 3 == 0)
            cout << " " << i/3 << ") Title: " << title << ", Year: " << year << ", Rotten Tomatoes Score: " << rating << "\n";
        //movie_file.ignore();
        i++;
    }
    cout << endl;
    movie_file.close();


    return 0; 
} 