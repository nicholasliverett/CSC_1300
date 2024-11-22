/* 
     Title:   lab10.h 
     Author:  Nicholas Liverett
     Date:    11/21/24 
     Purpose: Lab 10 - header
*/ 
#ifndef LAB10_H
#define LAB10_H

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

//declare funcs
void get_profit(string*, double*, int);
double get_total(double*, int);
void get_max(string*, double*, int, string&, double&);
void get_min(string*, double*, int, string&, double&);

#endif