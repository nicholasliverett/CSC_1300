/* 
     Title:   IceCream.cpp
     Author:  Nicholas Liverett
     Date:    12/2/24 
     Purpose: In class practice 2 - funcs
*/ 

#include "IceCream.h"

IceCream::IceCream() {
    cone = "";
    flavor = "";
    topping = "";
    price = 0.00;
}

IceCream::IceCream(string cone, string flavor, string topping, double price) {
    this->cone = cone;
    this->flavor = flavor;
    this->topping = topping;
    this->price = price;
}

IceCream::~IceCream() {
    cout << "The " << flavor << " in a " << cone << " with " << topping << " has been destroyed(eaten).\n\n";
}

void IceCream::get_cone(string cone) {
    this->cone = cone;
}

void IceCream::get_flavor(string flavor) {
    this->flavor = flavor;
}

void IceCream::get_topping(string topping) {
    this->topping = topping;
}

void IceCream::get_price(double price) {
    this->price = price;
}

void IceCream::print_ice_cream() {
    cout << "Cone: " << cone << endl;
    cout << "Flavor: " << flavor << endl;
    cout << "Topping: " << topping << endl;
    cout << "Price: $" << price << endl;
}

