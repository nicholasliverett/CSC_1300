#ifndef HALLOWEEN_sH
#define HALLOWEEN_H

#include <iostream>
#include <string>
using namespace std;

void print_menu();
void manage_guests_or_activities(string list[6], int idk);
void print_food(string foods[6], int amount[6]);
void save_to_file(string guests[6], int idk, string activities[6], int idk2, string food[6], int amount[6]);

#endif
