/* 
     Title:   lab1.cpp 
     Author:  Nicholas Liverett
     Date:  August 29, 2024 
     Purpose: Convert Celsius to Fahrenheit 
*/ 
 
#include <iostream> 
using namespace std; 
 
int main() 
{ 
 double fahrenheit, celsius; 
 cout << "\n\nWhat is the temperature in Celsius?  "; 
 cin >> celsius; 
 fahrenheit = celsius * (9.0/5.0) + 32; 
 cout << "\nRESULT:  " << celsius << " degrees Celsius is "; 
      cout << fahrenheit << " degrees Fahrenheit.\n\n"; 
 return 0; 
} 