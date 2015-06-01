/* 
 * File:   heroes.cpp
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:04 AM
 */

#include "characters.h"
#include <iostream>

using namespace std;

Characters::Characters(){
    attack = 0;
    speed = 0;
    defense = 0;
    hp = 0;
    sizeI = 0;
    sizeE = 0;
    level = 0;
    iCounter = 0;
    eCounter = 10;
    exp = 0;
    gold = 0;
    inventory = new string[sizeI];
    equipment = new string[sizeE];
    for(int i = 0; i < sizeI; i++){
        inventory[i] = " ";
    }
    for(int i = 0; i < sizeE; i++){
        equipment[i] = " ";
    }
}

Characters::~Characters(){
    delete []inventory;
    delete []equipment;
}

void Characters::setInventory(string i){
    inventory[iCounter] = i;
    iCounter++;
}

void Characters::setEquipment(string e){
    equipment[eCounter] = e;
    eCounter++;
}

void Characters::getInventory(){
    for(int i = 0; i < iCounter; i++){
        cout << inventory[i];
    }
}

void Characters::getEquipment(){
    for(int i = 0; i < eCounter; i++){
        cout << equipment[i];
    }
}

void Characters::setExp(int enemyL, int youL){
    int remain = enemyL - youL;
    if(remain == 0){
        exp += 10;
    }
    if(remain > 0){
        exp = remain * 10;
    }
    if(remain < 0){
        remain *= -1;
        if(remain == 1){
            exp += 5;
        }
        else if(remain == 2){
            exp += 2;
        }
        else if(remain == 3){
            exp += 1;
        }
        else{
            exp += 0;
        }
    }
    if(exp == 100 && level < 13){
        cout << "You leveled up! " << endl;
        setLevel();
        exp = 0;
    }
}
       
Rogue::Rogue(){
    hp = 1000;
    speed = 120;
    defense = 80;
    attack = 90;
    sizeI = 30;
    sizeE = 5;
    level = 1;
    iCounter = 0;
    eCounter = 0;
    exp = 0;
    gold = 0;
}

Mage::Mage(){
    hp = 1000;
    speed = 100;
    defense = 60;
    attack = 150;
    sizeI = 30;
    sizeE = 5;
    level = 1;
    iCounter = 0;
    eCounter = 0;
    exp = 0;
    gold = 0;
}

Warrior::Warrior(){
    hp = 2000;
    speed = 80;
    defense = 100;
    attack = 120;
    sizeI = 30;
    sizeE = 5;
    level = 1;
    iCounter = 0;
    eCounter = 0;
    exp = 0;
    gold = 0;
}

