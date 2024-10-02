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
    while(getline(movie_file,entry, '%')) { // Pretty sure instructions are supposed to say delimit by '%' as there is no other characters in the file

        // Get title line from entry
        first = entry.find('\n');
        title = entry.substr(0, first);
        first++;

        // Get year line from entry by starting find at the end of the title line
        second = entry.find('\n', first);
        year = entry.substr(first, second - first); // start at first and only go for 4 lines

        // Same logic here, get rating line from entry by starting find at the end of the year line
        rating = entry.substr(second+1);

        // Output movie data
        cout << " " << i << ") Title: " << title << ", Year: " << year << ", Rotten Tomatoes Score: " << rating << "%\n";
        movie_file.ignore();
        i++;
    }
    cout << endl;
    movie_file.close();


    return 0; 
} 

// Easier way to do using istringstream - don't know if can use, did not see in lecture - like so much easier

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// using namespace std; 
 
// int main() 
// { 
//     string file_name, entry, title, year, rating;
//     int i = 1;

//     cout << "What is the filename? (example.txt): ";
//     cin >> file_name;

//     ifstream movie_file (file_name);
//     if (!movie_file.is_open()) {
//         cout << "Sorry, " << file_name << " was unable to be opened.";
//         return 1;
//     }
//     while(getline(movie_file,entry, '%')) {

//         istringstream entry_stream(entry);

//         getline(entry_stream, title);
//         getline(entry_stream, year);
//         getline(entry_stream, rating);
//         cout << " " << i << ") Title: " << title << ", Year: " << year << ", Rotten Tomatoes Score: " << rating << "%\n";
//         movie_file.ignore();
//         i++;
//     }
//     cout << endl;