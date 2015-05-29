/* 
 * File:   world.cpp
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:08 AM
 */

#include <iostream>
#include "world.h"

using namespace std;

void MidTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to the east side of town " << endl;
    cout << "Go to the west side of town " << endl;
    cout << "Go to the north side of the town " << endl;
    cout << "Go to the south part of the town " << endl;
    cout << "Go to the shop here in the mid town " << endl;
    cout << "enter 1 for east, 2 for west, 3 for north, 4 for south, and 5 for "
            << "shop " << endl;
}

void EastTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to mid town " << endl;
    cout << "Go east to forest " << endl;
    cout << "Enter 1 to go mid town, 6 for east forest " << endl;
}

void WestTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to mid Town " << endl;
    cout << "Go west to forest " << endl;
    cout << "Enter 1 to go mid town, 7 for west forest " << endl;
}

void NorthTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to mid Town " << endl;
    cout << "Go north to forest " << endl;
    cout << "Enter 1 to go mid town, 9 for north forest " << endl;
}

void SouthTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to mid Town " << endl;
    cout << "Go south to forest " << endl;
    cout << "Enter 1 to go mid town, 8 for south forest " << endl;
}

void Shop::getOptions(){
    cout << "You can: " << endl;
    cout << "Buy " << endl;
    cout << "Sell " << endl;
    cout << "Go back to mid town " << endl;
}

Forest::Forest(int f){
    if(f == 6){
        cout << "Welcome to the east forest " << endl;
        cout << "You can: " << endl;
        cout << "Go to east town " << endl;
        cout << "Continue moving forward " << endl;
        cout << "Fight " << endl;
        cout << "Search " << endl;
    }
    else if(f == 7){
        cout << "Welcome to the west forest " << endl;
        cout << "You can: " << endl;
        cout << "Go to west town " << endl;
        cout << "Continue moving forward " << endl;
        cout << "Fight " << endl;
        cout << "Search " << endl;
    }
    else if(f == 8){
        cout << "Welcome to the south forest " << endl;
        cout << "You can: " << endl;
        cout << "Go to south town " << endl;
        cout << "Continue moving forward " << endl;
        cout << "Fight " << endl;
        cout << "Search " << endl;
    }
    else if(f == 9){
        cout << "Welcome to the north forest " << endl;
        cout << "You can: " << endl;
        cout << "Go to north town " << endl;
        cout << "Continue moving forward " << endl;
        cout << "Fight " << endl;
        cout << "Search " << endl;
    }
}

void World::setOption(int o){
    if(o == 0){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option);
    }
}

void MidTown::setOption(int o){
    if(o == 1){
        EastTown east;
        east.getOptions();
        cin >> option;
        east.setOption(option);
    }
    else if(o == 2){
        WestTown west;
        west.getOptions();
        cin >> option;
        west.setOption(option);
    }
    else if(o == 3){
        NorthTown north;
        north.getOptions();
        cin >> option;
        north.setOption(option);
    }
    else if(o == 4){
        SouthTown south;
        south.getOptions();
        cin >> option;
        south.setOption(option);
    }
    else if(o == 5){
        Shop shop;
        shop.getOptions();
        cin >> option;
        shop.setOption(option);
    }
}

void EastTown::setOption(int o){
    if(o == 0){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option);
    }
    else if(o == 6){
        Forest forest(o);
        cin >> option;
        forest.setOption(option);
    }
}

void WestTown::setOption(int o){
    if(o == 0){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option);
    }
    else if(o == 7){
        Forest forest(o);
        cin >> option;
        forest.setOption(option);
    }
}

void NorthTown::setOption(int o){
    if(o == 0){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option);
    }
    else if(o == 9){
        Forest forest(o);
        cin >> option;
        forest.setOption(option);
    }
}

void SouthTown::setOption(int o){
    if(o == 0){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option);
    }
    else if(o == 8){
        Forest forest(o);
        cin >> option;
        forest.setOption(option);
    }
}

void Shop::setOption(int o){
    if(o == 0){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option);
    }
    else if(o == 10){
        int x;
    }
}

void Forest::setOption(int o){
    
}