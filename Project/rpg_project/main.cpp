/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on May 14, 2015, 3:04 PM
 */

#include <cstdlib>
#include <iostream>
#include "heroes.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Characters first;
    Rouge one;
    Mage two;
    Warrior three;
    cout<<"Rouge"<<endl;
    cout<<"attack: "<<one.getAttack()<<endl;
    cout<<"defense: "<<one.getDefense()<<endl;
    cout<<"hp: "<<one.getHp()<<endl;
    cout<<"speed: "<<one.getSpeed()<<endl;
    cout<<"level: "<<one.getLevel()<<endl;
    cout<<endl;
    cout<<"Mage"<<endl;
    cout<<"attack: "<<two.getAttack()<<endl;
    cout<<"defense: "<<two.getDefense()<<endl;
    cout<<"hp: "<<two.getHp()<<endl;
    cout<<"speed: "<<two.getSpeed()<<endl;
    cout<<"level: "<<two.getLevel()<<endl;
    cout<<endl;
    cout<<"Warrior"<<endl;
    cout<<"attack: "<<three.getAttack()<<endl;
    cout<<"defense: "<<three.getDefense()<<endl;
    cout<<"hp: "<<three.getHp()<<endl;
    cout<<"speed: "<<three.getSpeed()<<endl;
    cout<<"level: "<<three.getLevel()<<endl;
    one.setInventory(10);
    cout<<endl;
    cout<<"sword is worth: ";
    one.getInventory();
    cout<<endl;
    cout<<"Your level is: "<<one.getLevel()<<endl;
    cout<<"Fighting enemy who is level 1 ten times"<<endl;
    for(int i = 0; i < 10; i++){
        one.setExp(1,one.getLevel());
    }
    cout<<endl;
    cout<<"Your level is: "<<one.getLevel();
    return 0;
}

