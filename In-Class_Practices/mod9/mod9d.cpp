/* 
     Title:   mod9d.cpp 
     Author:  Nicholas Liverett
     Date:    11/13/24 
     Purpose: In-Class Practice 4
*/ 
 
#include <iostream>
#include <string> 
using namespace std; 
 
int main() 
{ 
    int num_dogs;

    cout << "How many dogs can you adopt? ";
    cin >> num_dogs;

    string* dogName = new string[num_dogs];
    string* dogBreed = new string[num_dogs];
    int* dogAge = new int[num_dogs];

    cout << "\n**************************\n"; 
    cout << "Enter the dog data:\n"; 
    for (int i=0;i<num_dogs;i++) {
        cout << "*****DOG " << i+1 << "*****\n";
        cout << "NAME:\t";
        cin.ignore();
        getline(cin, dogName[i]);
        cout << "BREED: \t";
        getline(cin, dogBreed[i]);
        cout << "AGE: \t";
        cin >> dogAge[i];
    }
    cout << "\n**************************\n";
    cout << "Print the dogs:\n";
    for (int i=0;i<num_dogs;i++) {
        cout << "*****DOG " << i+1 << "*****\n";
        cout << "NAME:\t" << dogName[i] << endl;
        cout << "BREED:\t" << dogBreed[i] << endl;
        cout << "AGE:\t" << dogAge[i] << endl;
    }


    delete [] dogName;
    delete [] dogBreed;
    delete [] dogAge;
    return 0; 
} 