/* 
     Title:   mod7c.cpp 
     Author:  Nicholas Liverett
     Date:    10/21/24 
     Purpose: Practice 3
*/ 
 
#include "luckyguess.h"

int main() 
{ 
    string name, food;
    int num;
    bool check;

    get_user_data(name, food, num);

    check = lucky_guess(num);

    cout << "\n\n";

    if (check == true)
        cout << name << ", you will get a lifetime supply of " << food << "!";
    else
        cout << name << ", sorry, you get no " << food << "!";

    return 0; 
} 