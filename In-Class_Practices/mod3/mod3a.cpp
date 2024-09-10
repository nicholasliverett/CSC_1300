/* 
    Title:   mod3.cpp 
    Author:  Nicholas Liverett
    Date:  September 9, 2024 
    Purpose: Participate in class
*/ 

#include <iostream> 
#include <iomanip>
#include <cstdlib>
using namespace std; 

int main() 
{ 
    int result, randomNum;
    srand(time(0));
    double moreMoney = 0.75;
    result = 6 - 3 * 2 + 7 - 1 + 17 % 2;
    cout << "result is " << result << endl;
    result = result * moreMoney;
    cout << "result is " << result << endl;
    result = (6-3) * 2 + (7-1) + 17 % 2;
    cout << "result is " << result << endl;
    moreMoney = moreMoney * result;
    cout << fixed;
    cout << setprecision(4) << "moreMoney is " << moreMoney << endl;
    randomNum = rand() % 21 + 5;
    cout << "randomNum is " << randomNum << endl;
    
    return 0; 
} 