#ifndef HALLOWEEN_H
#define HALLOWEEN_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Declare funcs
void print_menu();
int manage_guests_or_activities(string[], size_t&, int);
void print_food(string[], int[]);
void save_to_file(string[], size_t, string[], size_t, string[], int[]);

#endif
