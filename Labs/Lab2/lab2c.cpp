/*
	Title:  	lab2c.cpp
	Author:		Nicholas Liverett & Julian Barry
	Date:		9/12/24	
	Purpose:	This program is written to translate characters into Ceasars Cipher to decode.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    char one, two, three, four, five, six, seven;
    int shiftVariable;

	cout << "Enter in seven characters and I will use a modified Caesar Cipher to decode it." << endl;
    
	cout << "First character: ";
    
    cin >> (one);
    cout << "Second character: ";

    cin >> (two);
    cout << "Third character: ";
    
    cin >> (three);
	cout << "Fourth character: ";
    
    cin >> (four);
    cout << "Fifth character: ";

    cin >> (five);
    cout << "Sixth character: ";

    cin >> (six);
    cout << "Seventh character: ";

    cin >> (seven);

    cout << "You entered: " << one << two << three << four << five << six << seven << endl;
    cout << "What integer should I use for the shift variable: ";
    cin >> (shiftVariable);

    one += shiftVariable;
    two += shiftVariable;
    three += shiftVariable;
    four += shiftVariable;
    five += shiftVariable;
    six += shiftVariable;
    seven += shiftVariable;

    string deciphered_text;
    deciphered_text += one;
    deciphered_text += two;
    deciphered_text += three;
    deciphered_text += four;
    deciphered_text += five;
    deciphered_text += six;
    deciphered_text += seven;

    cout << "The text deciphered is: " << deciphered_text;


	return 0;
}