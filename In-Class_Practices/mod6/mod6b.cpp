/* 
     Title:   mod6b.cpp 
     Author:  Nicholas Liverett
     Date:    9/30/24 
     Purpose: Read from file
*/ 
 
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
 
int main() 
{ 
    ifstream fin("mod6b.txt");
    string name;
    int num;
    getline(fin, name);
    cout << name << endl;
    fin >> num;
    cout << num << endl;
    fin >> num;
    cout << num << endl;
    fin >> num;
    cout << num << endl;
    fin >> num;
    cout << num << endl;
    fin >> num;
    cout << num << endl;
    fin.close();
    return 0; 
} 