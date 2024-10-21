#include "luckyguess.h"

bool lucky_guess(int input) {
    srand(time(0));
    int rand_num = rand() % 100 + 1;
    cout << "\nRandom number: " << rand_num;
    if ((rand_num - input) <= 25)
        return true;
    else
        return false;
}

void get_user_data(string& name, string& food, int& num) {
    cout << "Name? ";
    getline(cin, name);
    cout << "Favorite Food? ";
    getline(cin, food);
    cout << "Favorite Number? ";
    cin.ignore();
    cin >> num;
}