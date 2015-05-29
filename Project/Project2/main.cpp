/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:04 AM
 */

#include <cstdlib>
#include <iostream>
#include "heroes.h"
#include "world.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int option, character;
    bool again;
    World world;
    Characters first;
    cout << "1: Rogue " << endl;
    cout << "2: Mage " << endl;
    cout << "3: Warrior " << endl;
    cout << "Enter 1 for Rogue, 2 for Mage, 3 for Warrior " << endl;
    Rogue player;
    world.setOption(0);
    cout << "Your hp went to 0, I am sorry but you have died" << endl;
    return 0;
}