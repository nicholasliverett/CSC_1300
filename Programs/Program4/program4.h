/* 
     Title:   program4.h 
     Author:  Nicholas Liverett
     Date:    11/15/24 
     Purpose: Creature fight game - header
*/ 
#ifndef PROGRAM4_H
#define PROGRAM4_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstring>
using namespace std;

//declare structs
struct Stats {
    int dmg;
    int hp;
    char special[3];
};

struct Creatures{
    string name;
    string description;
    double length;
    double height;
    string location;
    bool danger;
    Stats stats;
};

//declare funcs
int fight(int, Creatures*);
void calculateModifier(int, Creatures*, int&);
int enterCreatures(int, int, Creatures*);
int deleteCreature(int, Creatures*);
bool moveArrayElements(string, int, Creatures*);
void printCreatures(int, Creatures*);
void printStats(int, Creatures*);
void saveCreaturesToFile(int, Creatures*);

#endif