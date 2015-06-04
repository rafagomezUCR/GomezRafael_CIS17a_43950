/* 
 * File:   world.cpp
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:08 AM
 */

#include <iostream>
#include <cstdlib>
#include "world.h"
#include "characters.h"

using namespace std;

Shop::Shop(){
    cout << "Welcome to the shop of the mid town " << endl;
    items = new int[36];
    for(int i = 0; i < 36; i++){
        items[i] = i;
    }
}

Shop::~Shop(){
    delete []items;
}
 
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
    cout << "Here in the shop you can buy items or go back to town " << endl;
    cout << "Enter b to go back to midtown " << endl;
    cout << "Or pick one of these items to buy " << endl;
    cout << "                         |Mage|                 " << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "1.stick             2.robe top              3.robe bottom" << endl;
    cout << "4.wand              5.blessed robe top      6.blessed robe bottom" << endl;
    cout << "7.sapphire ball     8.ancestrial robe top   9.ancestrial robe bottom" << endl;
    cout << "10.enchanted staff  11.archmage robe top    12.archmage robe bottom" << endl;
    cout << endl;
    cout << "                        |Warrior|              " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "13.wood sword    14.bronze chainmail   15.bronze chainlegs " << endl;
    cout << "16.silver sword  17.silver chainmail   18.silver chainlegs"<<endl;
    cout << "19.Gold sword    20.gold chestplate    21.gold platelegs" << endl;
    cout << "22.dragin sword  23.dragon chestplate  24.dragon platelegs" << endl;
    cout << endl;
    cout << "                     |Rogue|               " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "25.dagger          26.leather top  27.leather legs" << endl;
    cout << "28.shank           29.ripper tux   30.ripper bottom " << endl;
    cout << "31.ornate dagger   32.joker top    33.joker bottom " << endl;
    cout << "34.crystal dagger  35.cpo suit     36.cpo bottom" << endl;
}

Forest::Forest(){;}

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

World::World(){
    cout << "Welcome to the rpg game " << endl;
    cout << "Please choose one of the three heroes" << endl;
    cout << "1: Rogue " << endl;
    cout << "2: Mage " << endl;
    cout << "3: Warrior " << endl;
    cout << "Enter 1 for Rogue, 2 for Mage, 3 for Warrior " << endl;
}

void World::setOption(int o, Characters *player){
    if(o == 0){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
}

void MidTown::setOption(char o, Characters *player){
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

void EastTown::setOption(char o, Characters *player){
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

void WestTown::setOption(char o, Characters *player){
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

void NorthTown::setOption(char o, Characters *player){
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

void SouthTown::setOption(char o, Characters *player){
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

void Shop::setOption(char o, Characters *player){
    if(o == 'b'){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
    
}

void Forest::getOptions(){
    cout << "You are in the first section of the forest " << endl;
    cout << "Here you can continue forward, search, or go back" << endl;
    cout << "Type f to continue or s to search or b to back" << endl;
    cout << "Searching has two possible outcomes" << endl;
    cout << "One will be that you will find a monster to battle " << endl;
    cout << "and the other will be that you will find and artifact that increases your stats" << endl;
}

void Forest::setOption(char o, Characters *player, char p){
    char choice;
    if(p == 'e'){
        if(o == 'b'){
            EastTown east;
            east.getOptions();
            cin >> option;
            east.setOption(option, player);
        }
        else if(o == 'f'){
            Forest forest;
            Boss1 boss;
            forest.battleB(player, boss, p);
        }
        else if(o == 's'){
            string again;
            do{
                Forest forest;
                forest.search(player, p);
                if(player->getHp() <= 0){
                    again = "y";
                }
                else{
                    cout << "Do you want to search again " << endl;
                    cout << "If you do please type again, and if not then type"
                            " anything for further options " << endl;
                    cin >> again;
                }
            }while(again == "again");
            if(player->getHp() >0){
                cout << "Do you wish to continue forward or go back to town " << endl;
                cout << "Type f for forward or b for back " << endl;
                cin >> choice;
                if(choice == 'f'){
                    Forest forest;
                    Boss1 boss;
                    forest.battleB(player, boss, p);
                }
                else if(choice == 'b'){
                    EastTown east;
                    east.getOptions();
                    cin >> option;
                    east.setOption(option, player);
                }
            }
            else{
                int t;
            }
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
            Forest forest;
            Boss1 boss;
            forest.battleB(player, boss, p);
        }
        else if(o == 's'){
            string again;
            do{
                Forest forest;
                forest.search(player, p);
                if(player->getHp() <= 0){
                    again = "y";
                }
                else{
                    cout << "Do you want to search again " << endl;
                    cout << "If you do please type again, and if not then type"
                        " anything for further options " << endl;
                    cin >> again;
                }
            }while(again == "again");
            if(player->getHp() > 0){
                cout << "Do you wish to continue forward or go back to town " << endl;
                cout << "Type f for forward or b for back " << endl;
                cin >> choice;
                if(choice == 'f'){
                    Forest forest;
                    Boss1 boss;
                    forest.battleB(player, boss, p);
                }
                else if(choice == 'b'){
                    WestTown west;
                    west.getOptions();
                    cin >> option;
                    west.setOption(option, player);
                }
            }
            else{
                int x;
            }
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
            Forest forest;
            Boss1 boss;
            forest.battleB(player, boss, p);
        }
        else if(o == 's'){
            string again;
            do{
                Forest forest;
                forest.search(player, p);
                if(player->getHp() < 0){
                    again = "y";
                }
                else{
                    cout << "Do you want to search again " << endl;
                    cout << "If you do please type again, and if not then type"
                        " anything for further options " << endl;
                    cin >> again;
                }
            }while(again == "again");
            if(player->getHp() > 0){
                cout << "Do you wish to continue forward or go back to town " << endl;
                cout << "Type f for forward or b for back " << endl;
                cin >> choice;
                if(choice == 'f'){
                    Forest forest;
                    Boss1 boss;
                    forest.battleB(player, boss, p);
                }
                else if(choice == 'b'){
                    NorthTown north;
                    north.getOptions();
                    cin >> option;
                    north.setOption(option, player);
                }
            }
            else{
                int x;
            }
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
            Forest forest;
            Boss1 boss;
            forest.battleB(player, boss, p);
        }
        else if(o == 's'){
            string again;
            do{
                Forest forest;
                forest.search(player, p);
                if(player->getHp() < 0){
                    again = "y";
                }
                else{
                    cout << "Do you want to search again " << endl;
                    cout << "If you do please type again, and if not then type"
                        " anything for further options " << endl;
                    cin >> again;
                }
            }while(again == "again");
            if(player->getHp() > 0){
                cout << "Do you wish to continue forward or go back to town " << endl;
                cout << "Type f for forward or b for back " << endl;
                cin >> choice;
                if(choice == 'f'){
                    Forest forest;
                    Boss1 boss;
                    forest.battleB(player, boss, p);
                }
                else if(choice == 'b'){
                    SouthTown south;
                    south.getOptions();
                    cin >> option;
                    south.setOption(option, player);
                }
            }
            else{
                int x;
            }
        }
    }
}

void Forest::battleB(Characters *player, Characters &enemy, char p){
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

void Forest::search(Characters *player, char p){
    srand(time(0));
    int n = rand()%2+1;
    if(n == 1){
        Forest forest;
        forest.battle(player, p);
    }
    if(n == 2){
        int a = rand()%4+1;
        if(a == 1){
            cout << "You found an artifact that increases your hp by 5" << endl;
            player->setHp(5);
            player->setMaxHp(5);
            cout << "You hp is now " << player->getHp() << endl;
        }
        else if(a == 2){
            cout << "You found an artifact that increases your attack by 5 " << endl;
            player->setAttack(5);
            cout << "You attack is now " << player->getAttack() << endl;
        }
        else if(a == 3){
            cout << "You found an artifact that increases your defense by 5 " << endl;
            player->setDefense(5);
            cout << "Your defense is now " << player->getDefense() << endl;
        }
        else if(a == 4){
            cout << "You found an artifact that increases your speed by 5 " << endl;
            player->setSpeed(5);
            cout << "Your speed is now " << player->getSpeed() << endl;
        }
    }
}

void Forest::battle(Characters *player, char p){
    srand(time(0));
    int choice;
    if(p == 'w'){
        int lvl = player->getLevel();
        if(lvl > 4){
            lvl = 4;
        }
        int eAttack = 90+((lvl-1)*30);
        int eDefense = 60+((lvl-1)*30);
        int eSpeed = 80+((lvl-1)*30);
        int eHealth = 1000+((lvl-1)*300);
        string go;
        cout << "You are in battle with a minion"<< endl;
        cout << "What do you wish to do " << endl;
        cout << "1: Battle " << endl;
        cout << "2: Run " << endl;
        cout << "Running will return you to the forest " << endl;
        cout << "Enter 1 to battle and 2 to run " << endl;
        cin >> choice;
        if(choice == 1){
            cout << "The enemies level you found is " << lvl << endl;
            Forest forest;
            int h = player->getHp();
            h = forest.battleR(player,eHealth,eAttack,eDefense,eSpeed,lvl);
            player->setHp2(h);
        }
        else if(choice == 2){
            Forest forest;
            forest.getOptions();
            cin >> option;
            forest.setOption(option, player, p);
        }
    }
    else if(p == 's'){
        int lvl = player->getLevel();
        if(lvl < 4){
            lvl = rand()%3+4;
        }
        int eAttack = 90+((lvl-1)*30);
        int eDefense = 60+((lvl-1)*30);
        int eSpeed = 80+((lvl-1)*30);
        int eHealth = 1000+((lvl-1)*300);
        string go;
        cout << "You are in battle with a minion"<< endl;
        cout << "What do you wish to do " << endl;
        cout << "1: Battle " << endl;
        cout << "2: Run " << endl;
        cout << "Running will return you to the forest " << endl;
        cout << "Enter 1 to battle and 2 to run " << endl;
        cin >> choice;
        if(choice == 1){
            cout << "The enemies level you found is " << lvl << endl;
            Forest forest;
            int h = player->getHp();
            h = forest.battleR(player,eHealth,eAttack,eDefense,eSpeed,lvl);
            player->setHp2(h);
        }
        else if(choice == 2){
            Forest forest;
            forest.getOptions();
            cin >> option;
            forest.setOption(option, player, p);
        }
    }
    else if(p == 'e'){
        int lvl = player->getLevel();
        if(lvl < 4){
            lvl = rand()%3+7;
        }
        int eAttack = 90+((lvl-1)*30);
        int eDefense = 60+((lvl-1)*30);
        int eSpeed = 80+((lvl-1)*30);
        int eHealth = 1000+((lvl-1)*300);
        string go;
        cout << "You are in battle with a minion"<< endl;
        cout << "What do you wish to do " << endl;
        cout << "1: Battle " << endl;
        cout << "2: Run " << endl;
        cout << "Running will return you to the forest " << endl;
        cout << "Enter 1 to battle and 2 to run " << endl;
        cin >> choice;
        if(choice == 1){
            cout << "The enemies level you found is " << lvl << endl;
            Forest forest;
            int h = player->getHp();
            h = forest.battleR(player,eHealth,eAttack,eDefense,eSpeed,lvl);
            player->setHp2(h);
        }
        else if(choice == 2){
            Forest forest;
            cout << player->getCharacter() << endl;
            forest.getOptions();
            cin >> option;
            forest.setOption(option, player, p);
        }
    }
    else if(p == 'n'){
        int lvl = player->getLevel();
        if(lvl < 4){
            lvl = rand()%3+10;
        }
        int eAttack = 90+((lvl-1)*30);
        int eDefense = 60+((lvl-1)*30);
        int eSpeed = 80+((lvl-1)*30);
        int eHealth = 1000+((lvl-1)*300);
        string go;
        cout << "You are in battle with a minion"<< endl;
        cout << "What do you wish to do " << endl;
        cout << "1: Battle " << endl;
        cout << "2: Run " << endl;
        cout << "Running will return you to the forest " << endl;
        cout << "Enter 1 to battle and 2 to run " << endl;
        cin >> choice;
        if(choice == 1){
            cout << "The enemies level you found is " << lvl << endl;
            Forest forest;
            int h = player->getHp();
            h = forest.battleR(player,eHealth,eAttack,eDefense,eSpeed,lvl);
            player->setHp2(h);
        }
        else if(choice == 2){
            Forest forest;
            cout << player->getCharacter() << endl;
            forest.getOptions();
            cin >> option;
            forest.setOption(option, player, p);
        }
    }
}

int Forest::battleR(Characters *player, int eHealth, int eAttack, int eDefense, int eSpeed, int lvl){
    string go;
    do{
        cout << "His hp is " << eHealth << endl;
        cout << "Your hp is " << player->getHp() << endl;
        if(player->getSpeed() > eSpeed){
            cout << "You attacked first " << endl;
            if(player->getAttack() < eDefense){
                cout << "You did no damage " << endl;
                cout << "Enemy now attacks " << endl;
                player->setHpB(player->getDefense(), eAttack);
                if(eHealth > 0){
                    cout << "Enemies health is " << eHealth << endl;
                }
                else if(eHealth <= 0){
                    cout << "Enemy died " << endl;
                }
                if(player->getHp() <= 0){
                    cout << "You have died" << endl;
                    cout << "Your hp is 0 " << endl;
                }
                else if(player->getHp() > 0){
                    cout << "Your hp is " << player->getHp() << endl;
                }
            }
            else{
                eHealth = eHealth - (player->getAttack() - eDefense);
                if(eHealth > 0){
                    cout << "Enemies health is " << eHealth << endl;
                }
                else if(eHealth <= 0){
                    cout << "Enemy died " << endl;
                }
                if(player->getHp() <= 0){
                    cout << "You have died" << endl;
                    cout << "Your hp is 0 " << endl;
                }
                else if(player->getHp() > 0){
                    cout << "Your hp is " << player->getHp() << endl;
                }
                if(eHealth > 0){
                    cout << "Enemy now attacks " << endl;
                    player->setHpB(player->getDefense(), eAttack);
                    if(eHealth > 0){
                        cout << "Enemies health is " << eHealth << endl;
                    }
                    else if(eHealth <= 0){
                        cout << "Enemy died " << endl;
                    }
                    if(player->getHp() <= 0){
                        cout << "You have died" << endl;
                        cout << "Your hp is 0 " << endl;
                    }
                    else if(player->getHp() > 0){
                        cout << "Your hp is " << player->getHp() << endl;
                    }
                }
            }
            cout << "Type anything to continue " << endl;
            cin >> go;
        }
        else if(player->getSpeed() < eSpeed){
            cout << "Enemy attacked first " << endl;
            player->setHpB(player->getDefense(), eAttack);
            if(eHealth > 0){
                cout << "Enemies health is " << eHealth << endl;
            }
            else if(eHealth <= 0){
                cout << "Enemy died " << endl;
            }
            if(player->getHp() <= 0){
                cout << "You have died" << endl;
                cout << "Your hp is 0 " << endl;
            }
            else if(player->getHp() > 0){
                cout << "Your hp is " << player->getHp() << endl;
            }
            if(player->getHp() > 0){
                cout << "You now attack " << endl;
                if(player->getAttack() < eDefense){
                    cout << "You did no damage " << endl;
                }
                else{
                    eHealth = eHealth - (player->getAttack() - eDefense);
                    if(eHealth > 0){
                        cout << "Enemies health is " << eHealth << endl;
                    }
                    else if(eHealth <= 0){
                        cout << "Enemy died " << endl;
                    }
                    if(player->getHp() <= 0){
                        cout << "You have died" << endl;
                        cout << "Your hp is 0 " << endl;
                    }
                    else if(player->getHp() > 0){
                        cout << "Your hp is " << player->getHp() << endl;
                    }
                }
            }
            cout << "Type anything to continue " << endl;
            cin >> go;
        }
    }while(eHealth > 0 && player->getHp() > 0);
    if(player->getHp() > 0){
        cout << "Your health at the end of the battle is " << player->getHp() << endl;
    }
    if(eHealth <= 0){
        player->setExp(lvl, player->getLevel());
        int g = rand()%300+201;
        player->setGold(g);
    }
    return player->getHp();
}