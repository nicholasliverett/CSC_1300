/* 
     Title:   mod7b.cpp 
     Author:  Nicholas Liverett
     Date:    10/21/24 
     Purpose: Practice 2
*/ 
 
#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

bool lucky_guess(int input) {
    srand(time(0));
    int rand_num = rand() % 100 + 1;
    cout << "\nRandom number: " << rand_num;
    if ((rand_num - input) <= 25)
        return true;
    else
        return false;
}
 
int main() 
{ 
    string name, food;
    int num;
    bool check;
    cout << "Name? ";
    getline(cin, name);
    cout << "Favorite Food? ";
    getline(cin, food);
    cout << "Favorite Number? ";
    cin.ignore();
    cin >> num;

    check = lucky_guess(num);

    cout << "\n\n";

    if (check == true)
        cout << name << ", you will get a lifetime supply of " << food << "!";
    else
        cout << name << ", sorry, you get no " << food << "!";

    return 0; 
} 