/* 
     Title:   mod9a.cpp 
     Author:  Nicholas Liverett
     Date:    11/13/24 
     Purpose: In-Class Practice 1
*/ 
 
#include <iostream> 
using namespace std; 
 
int main() 
{ 
    double var1 = 7.25;
    double *ptr;
    ptr = &var1;
    cout << "The value of var1 is " << *ptr << endl;
    return 0; 
} 