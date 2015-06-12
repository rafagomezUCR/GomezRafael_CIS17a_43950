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
    level = 0;
    exp = 0;
    gold = 0;
}

Characters::~Characters(){
    
}

void Characters::setExp(int enemyL, int youL){
    int remain = enemyL - youL;
    if(remain == 0){
        exp += 10;
    }
    else if(remain > 0){
        exp += (remain * 10);
    }
    else if(remain < 0){
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
    if(exp >= 100 && level < 12){
        cout << endl;
        cout << "***************" << endl;
        cout << "You leveled up! " << endl;
        cout << "***************" << endl;
        cout << endl;
        setLevel();
        cout << "All your stats increased by 5"<< endl;
        cout << "And health increased by 50"<<endl;
        setMaxHp(200);
        setHp(200);
        setAttack(20);
        setDefense(20);
        setSpeed(20);
        exp = 0;
    }
    if(level >= 12){
        exp = 100;
    }
}

void Characters::setHpB(int playerDf, int eAttk){
    int x;
    x = hp - ((eAttk - playerDf)*2);
    if(x > hp){
        hp += 0;
    }
    else{
        hp = x;
    }
}
     
Rogue::Rogue(){
    maxhp = 4300;//1000;
    hp = 4300;//1000;
    speed = 500;//120;
    defense = 450;//80;
    attack = 470;//90;
    level = 12;//1;
    exp = 0;
    gold = 120;
    character="Rogue";
}

Mage::Mage(){
    maxhp = 1000;
    hp = 1000;
    speed = 100;
    defense = 60;
    attack = 150;
    level = 1;
    exp = 0;
    gold = 0;
    character = "Mage";
}

Warrior::Warrior(){
    maxhp = 2000;
    hp = 2000;
    speed = 80;
    defense = 100;
    attack = 120;
    level = 1;
    exp = 0;
    gold = 0;
    character = "Warrior";
}

fBoss::fBoss(){
    maxhp = 6000;
    hp = 6000;
    speed = 400;
    defense = 400;
    attack = 500;
    level = 12;
    exp = 0;
    gold = 0;
    character = "Eukithor";
}

string Rogue::getCharacter() const{
    { return character; }
}

string Mage::getCharacter() const{
    { return character; }
}

string Warrior::getCharacter() const{
    { return character; }
}

string fBoss::getCharacter() const{
    { return character; }
}
