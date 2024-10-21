#ifndef HALLOWEEN_H
#define HALLOWEEN_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Declare funcs
void print_menu();
int manage_guests_or_activities(string list[], size_t& list_size, int gues_act);
void print_food(string food[], int amount[]);
void save_to_file(string guests[], size_t guests_size, string activities[], size_t activities_size, string food[], int amount[]);

#endif
