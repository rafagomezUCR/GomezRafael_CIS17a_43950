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
    srand(time(0));
    int option, character;
    bool again;
    World world;
    Characters first;
    cin >> character;
    if(character == 1){
        Rogue player;
        Characters *ptr=&player;
        world.setOption(0, ptr);
    }
    else if(character == 2){
        Mage player;
        Characters *ptr = &player;
        world.setOption(0, ptr);
    }
    else if(character == 3){
        Warrior player;
        Characters *ptr = &player;
        world.setOption(0, ptr);
    }
    cout << "Your hp went to 0, I am sorry but you have died" << endl;
    return 0;
}
