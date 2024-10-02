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
    string file_name;

    cout << "What is the filename? (example.txt): ";
    cin >> file_name;

    ifstream movie_file (file_name);
    if (!movie_file.is_open()) {
        cout << "Sorry, " << file_name << " was unable to be opened.";
        return 1;
    }


    return 0; 
} 