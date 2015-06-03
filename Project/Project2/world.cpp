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
    else if(o == 10){
        int x;
    }
}

void Forest::getOptions(){
    cout << "You are in the first section of the forest " << endl;
    cout << "Here you can continue forward, search, or go back" << endl;
    cout << "Type f to continue or s to search or b to back" << endl;
    cout << "Searching has two possible outcomes" << endl;
    cout << "1: Find a monster to battle " << endl;
    cout << "2: Find and artifact that increases your stats" << endl;
}

void Forest::getOptions2(){
    cout << "Here you can continue to the final stage, search, or go back" << endl;
    cout << "Type f to continue or s to search or b to back" << endl;
}

void Forest::setOption(char o, Characters *player, char p){
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
            string again;
            do{
                Forest forest;
                forest.search(player, p);
                cout << "Do you want to search again " << endl;
                cout << "If you do please type again, and if not then type"
                        " anything to continue moving forward " << endl;
                cin >> again;
            }while(again == "again");
            Forest forest(o, p);
            forest.getOptions2();
            cin >> option;
            forest.setOption2(option, player, p);
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
            string again;
            do{
                Forest forest;
                forest.search(player, p);
                cout << "Do you want to search again " << endl;
                cout << "If you do please type again, and if not then type"
                        " anything to continue moving forward " << endl;
                cin >> again;
            }while(again == "again");
            Forest forest(o, p);
            forest.getOptions2();
            cin >> option;
            forest.setOption2(option, player, p);
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
                            " anything to continue moving forward " << endl;
                    cin >> again;
                }
            }while(again == "again");
            if(player->getHp() < 0){
                int x;
            }
            else{
                Forest forest(o, p);
                forest.getOptions2();
                cin >> option;
                forest.setOption2(option, player, p);
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
            Forest forest(o, p);
            forest.getOptions2();
            cin >> option;
            forest.setOption2(option, player, p);
        }
        else if(o == 's'){
            string again;
            do{
                Forest forest;
                forest.search(player, p);
                cout << "Do you want to search again " << endl;
                cout << "If you do please type again, and if not then type"
                        " anything to continue moving forward " << endl;
                cin >> again;
            }while(again == "again");
            Forest forest(o, p);
            forest.getOptions2();
            cin >> option;
            forest.setOption2(option, player, p);
        }
    }
}

void Forest::setOption2(char o, Characters *player, char p){
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
            player->setMaxHp(5);
            cout << "You attack is now " << player->getAttack() << endl;
        }
        else if(a == 3){
            cout << "You found an artifact that increases your defense by 5 " << endl;
            player->setDefense(5);
            player->setMaxHp(5);
            cout << "Your defense is now " << player->getDefense() << endl;
        }
        else if(a == 4){
            cout << "You found an artifact that increases your speed by 5 " << endl;
            player->setSpeed(5);
            player->setMaxHp(5);
            cout << "Your speed is now " << player->getSpeed() << endl;
        }
    }
}

void Forest::battle(Characters *player, char p){
    srand(time(0));
    int attack = 1;
    int run = 2;
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
        cout << "1: Attack " << endl;
        cout << "2: Run " << endl;
        cout << "Running will take you back to town " << endl;
        cout << "Enter 1 to attack and 2 to run " << endl;
        cin >> choice;
        if(choice == 1){
            cout << "The enemies level you found is " << lvl << endl;
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
            cout << "Your health at the end of the battle is " << player->getHp() << endl;
            if(eHealth <= 0){
                player->setExp(lvl, player->getLevel());
            }
        }
        else if(choice == 2){
            Forest forest;
            cout << player->getCharacter() << endl;
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
        cout << "1: Attack " << endl;
        cout << "2: Run " << endl;
        cout << "Running will take you back to town " << endl;
        cout << "Enter 1 to attack and 2 to run " << endl;
        cin >> choice;
        if(choice == 1){
            cout << "The enemies level you found is " << lvl << endl;
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
            cout << "Your health at the end of the battle is " << player->getHp() << endl;
            if(eHealth <= 0){
                player->setExp(lvl, player->getLevel());
            }
        }
        else if(choice == 2){
            Forest forest;
            cout << player->getCharacter() << endl;
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
        cout << "1: Attack " << endl;
        cout << "2: Run " << endl;
        cout << "Running will take you back to town " << endl;
        cout << "Enter 1 to attack and 2 to run " << endl;
        cin >> choice;
        if(choice == 1){
            cout << "The enemies level you found is " << lvl << endl;
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
            cout << "Your health at the end of the battle is " << player->getHp() << endl;
            if(eHealth <= 0){
                player->setExp(lvl, player->getLevel());
            }
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
        cout << "1: Attack " << endl;
        cout << "2: Run " << endl;
        cout << "Running will take you back to town " << endl;
        cout << "Enter 1 to attack and 2 to run " << endl;
        cin >> choice;
        if(choice == 1){
            cout << "The enemies level you found is " << lvl << endl;
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
            cout << "Your health at the end of the battle is 0" << endl;
            if(eHealth <= 0){
                player->setExp(lvl, player->getLevel());
            }
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