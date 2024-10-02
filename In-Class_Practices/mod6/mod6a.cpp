/* 
     Title:   mod6a.cpp 
     Author:  Nicholas Liverett
     Date:    9/30/24 
     Purpose: Output to file practice
*/ 
 
#include <iostream> 
#include <fstream>
#include <string>
using namespace std; 
 
int main() 
{ 
    ofstream fout("mod6a.txt");
    string nickname, rand_fact;
    int grad_date;


    cout << "Input Nickname: ";
    getline(cin, nickname);

    cout << "Input Graduation Date: ";
    cin >> grad_date;

    cout << "Input random fact no one knows: ";
    cin.ignore();
    getline(cin, rand_fact);

    // Output to file stream
    fout << nickname << endl << grad_date << endl << rand_fact;

    fout.close();
    cout << "Done writing to file.";

    return 0; 
} 