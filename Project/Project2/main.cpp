/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:04 AM
 */

#include <cstdlib>
#include <iostream>
#include "characters.h"
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
    cin >> character;
    if(character == 1){
        Rogue player;
        world.setOption(0, player);
    }
    else if(character == 2){
        Mage player;
        world.setOption(0, player);
    }
    else if(character == 3){
        Warrior player;
        world.setOption(0, player);
    }
    cout << "Your hp went to 0, I am sorry but you have died" << endl;
    return 0;
}