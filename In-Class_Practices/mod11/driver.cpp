/* 
     Title:   IceCream.cpp
     Author:  Nicholas Liverett
     Date:    12/2/24 
     Purpose: In class practice 4 - new driver
*/ 

#include "IceCream.h"

int main() {
    int num;
    double price;
    string temp;

    cout << "\nHow many ice creams would you like? ";
    cin >> num;

    IceCream * arr = new IceCream[num];

    for (int i=0;i<num;++i) {
        cout << "\nEnter data for ice cream " << i+1 << ":\n\n";
        cout << "Type of cone:\t\t";
        cin.ignore();
        getline(cin, temp);
        arr[i].get_cone(temp);
        cout << "What flavor? \t\t";
        getline(cin, temp);
        arr[i].get_flavor(temp);
        cout << "What topping? \t\t";
        getline(cin, temp);
        arr[i].get_topping(temp);
        cout << "Price \t\t\t$";
        cin >> price;
        arr[i].get_price(price);
    }

    cout << "\n\n*************************************YOUR ICE CREAM ORDER:\n\n";
    
    for (int i=0;i<num;++i) {
        cout << "Ice cream number " << i+1 << endl;
        arr[i].print_ice_cream();
        cout << endl << endl;
    }
    delete [] arr;


    return 0;
}