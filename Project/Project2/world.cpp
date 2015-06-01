/* 
 * File:   world.cpp
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:08 AM
 */

#include <iostream>
#include "world.h"
#include "characters.h"

using namespace std;

void MidTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to the east side of town " << endl;
    cout << "Go to the west side of town " << endl;
    cout << "Go to the north side of the town " << endl;
    cout << "Go to the south part of the town " << endl;
    cout << "Go to the shop here in the mid town " << endl;
    cout << "enter d for east, a for west, w for north, s for south, and p for "
            << "shop " << endl;
}

void EastTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to mid town " << endl;
    cout << "Go east to forest " << endl;
    cout << "Enter a to go mid town, d for east forest " << endl;
}

void WestTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to mid Town " << endl;
    cout << "Go west to forest " << endl;
    cout << "Enter d to go mid town, a for west forest " << endl;
}

void NorthTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to mid Town " << endl;
    cout << "Go north to forest " << endl;
    cout << "Enter s to go mid town, w for north forest " << endl;
}

void SouthTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to mid Town " << endl;
    cout << "Go south to forest " << endl;
    cout << "Enter w to go mid town, s for south forest " << endl;
}

void Shop::getOptions(){
    cout << "You can: " << endl;
    cout << "Buy " << endl;
    cout << "Sell " << endl;
    cout << "Go back to mid town " << endl;
    cout << "Enter b to go back to midtown " << endl;
}

Forest::Forest(char f){
    if(f == 'd'){
        cout << "Welcome to the east forest " << endl;
    }
    else if(f == 'a'){
        cout << "Welcome to the west forest " << endl;
    }
    else if(f == 's'){
        cout << "Welcome to the south forest " << endl;
    }
    else if(f == 'w'){
        cout << "Welcome to the north forest " << endl;
    }
}

Forest::Forest(char o, char p){
    if(o == 'f' && p == 'e'){
        cout << "Welcome to the second section of the east forest" << endl;
    }
    else if(o == 'f' && p == 'w'){
        cout << "Welcome to the second section of the west forest" << endl;
    }
    else if(o == 'f' && p == 'n'){
        cout << "Welcome to the second section of the north forest" << endl;
    }
    else if(o == 'f' && p == 's'){
        cout << "Welcome tot he second section of the south forest" << endl;
    }
}

World::World(){
    cout << "Welcome to the rpg game " << endl;
    cout << "Please choose one of the three heroes" << endl;
    cout << "1: Rogue " << endl;
    cout << "2: Mage " << endl;
    cout << "3: Warrior " << endl;
    cout << "Enter 1 for Rogue, 2 for Mage, 3 for Warrior " << endl;
}

void World::setOption(int o, Characters &player){
    if(o == 0){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
}

void MidTown::setOption(char o, Characters &player){
    if(o == 'd'){
        EastTown east;
        east.getOptions();
        cin >> option;
        east.setOption(option, player);
    }
    else if(o == 'a'){
        WestTown west;
        west.getOptions();
        cin >> option;
        west.setOption(option, player);
    }
    else if(o == 'w'){
        NorthTown north;
        north.getOptions();
        cin >> option;
        north.setOption(option, player);
    }
    else if(o == 's'){
        SouthTown south;
        south.getOptions();
        cin >> option;
        south.setOption(option, player);
    }
    else if(o == 'p'){
        Shop shop;
        shop.getOptions();
        cin >> option;
        shop.setOption(option, player);
    }
}

void EastTown::setOption(char o, Characters &player){
    char p = 'e';
    if(o == 'a'){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
    else if(o == 'd'){
        Forest forest(o);
        forest.getOptions();
        cin >> option;
        forest.setOption(option, player, p);
    }
}

void WestTown::setOption(char o, Characters &player){
    char p = 'w';
    if(o == 'd'){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
    else if(o == 'a'){
        Forest forest(o);
        forest.getOptions();
        cin >> option;
        forest.setOption(option, player, p);
    }
}

void NorthTown::setOption(char o, Characters &player){
    char p = 'n';
    if(o == 's'){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
    else if(o == 'w'){
        Forest forest(o);
        forest.getOptions();
        cin >> option;
        forest.setOption(option, player, p);
    }
}

void SouthTown::setOption(char o, Characters &player){
    char p = 's';
    if(o == 'w'){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
    else if(o == 's'){
        Forest forest(o);
        forest.getOptions();
        cin >> option;
        forest.setOption(option, player, p);
    }
}

void Shop::setOption(char o, Characters &player){
    if(o == 'b'){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
    else if(o == 10){
        int x;
    }
}

void Forest::getOptions(){
    cout << "Here you can continue forward, search, or go back" << endl;
    cout << "Type f to continue or s to search or b to back" << endl;
    cout << "Searching has to possible outcomes" << endl;
    cout << "1: Find a monster to battle " << endl;
    cout << "2: Find some loot" << endl;
}

void Forest::getOptions2(){
    cout << "Here you can continue to the final stage, search, or go back" << endl;
    cout << "Type f to continue or s to search or b to back" << endl;
}

void Forest::setOption(char o, Characters &player, char p){
    if(p == 'e'){
        if(o == 'b'){
            EastTown east;
            east.getOptions();
            cin >> option;
            east.setOption(option, player);
        }
        else if(o == 'f'){
            Forest forest(o, p);
            forest.getOptions2();
            cin >> option;
            forest.setOption2(option, player, p);
        }
        else if(o == 's'){
            
        }
    }
    else if(p == 'w'){
        if(o == 'b'){
            WestTown west;
            west.getOptions();
            cin >> option;
            west.setOption(option, player);
        }
        else if(o == 'f'){
            Forest forest(o, p);
            forest.getOptions2();
            cin >> option;
            forest.setOption2(option, player, p);
        }
        else if(o == 's'){
            
        }
    }
    else if(p == 'n'){
        if(o == 'b'){
            NorthTown north;
            north.getOptions();
            cin >> option;
            north.setOption(option, player);
        }
        else if(o == 'f'){
            Forest forest(o, p);
            forest.getOptions2();
            cin >> option;
            forest.setOption2(option, player, p);
        }
        else if(o == 's'){
            
        }
    }
    else if(p == 's'){
        if(o == 'b'){
            SouthTown south;
            south.getOptions();
            cin >> option;
            south.setOption(option, player);
        }
        else if(o == 'f'){
            Forest forest(o, p);
            forest.getOptions2();
            cin >> option;
            forest.setOption2(option, player, p);
        }
        else if(o == 's'){
            
        }
    }
}

void Forest::setOption2(char o, Characters &player, char p){
    if(p == 'e'){
        if(o == 'b'){
            Forest forest('d');
            forest.getOptions();
            cin >> option;
            forest.setOption(option, player, p);
        }
        else if(o == 'f'){
            Boss boss;
            battleB(player, boss, p);
        }
        else if(o == 's'){
            
        }
    }
    else if(p == 'w'){
        if(o == 'b'){
            Forest forest('a');
            forest.getOptions();
            cin >> option;
            forest.setOption(option, player, p);
        }
        else if(o == 'f'){
            Boss boss;
            battleB(player, boss, p);
        }
        else if(o == 's'){
            
        }
    }
    else if(p == 'n'){
        if(o == 'b'){
            Forest forest('w');
            forest.getOptions();
            cin >> option;
            forest.setOption(option, player, p);
        }
        else if(o == 'f'){
            Boss boss;
            battleB(player, boss, p);
        }
        else if(o == 's'){
            
        }
    }
    else if(p == 's'){
        if(o == 'b'){
            Forest forest('s');
            forest.getOptions();
            cin >> option;
            forest.setOption(option, player, p);
        }
        else if(o == 'f'){
            Boss boss;
            battleB(player, boss, p);
        }
        else if(o == 's'){
            
        }
    }
}

void Forest::battleB(Characters &player, Characters &enemy, char p){
    if(p == 'w'){
        cout << "Welcome to the first boss battle" << endl;
    }
    else if(p == 's'){
        cout << "Welcome to the second boss battle" << endl;
    }
    else if(p == 'e'){
        cout << "Welcome to the third boss battle" << endl;
    }
    else if(p == 'n'){
        cout << "Welcome to the final boss battle" << endl;
    }
}