/* 
     Title:   IceCream.h 
     Author:  Nicholas Liverett
     Date:    12/2/24 
     Purpose: In class practice 1 - header
*/ 

#ifndef ICECREAM_H
#define ICECREAM_H

#include <string>
#include <iostream>
using namespace std;

//def class
class IceCream {
    public:
        IceCream();
        IceCream(string, string, string, double);
        ~IceCream();
        void get_cone(string);
        void get_flavor(string);
        void get_topping(string);
        void get_price(double);
        void print_ice_cream();
    private:
        string cone;
        string flavor;
        string topping;
        double price;
};

//def funcs


#endif