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

Training::Training(){
    cout << "Welcome to the training station of the mid town " << endl;
}
 
void MidTown::getOptions(){
    cout << "You can: " << endl;
    cout << "Go to the east side of town " << endl;
    cout << "Go to the west side of town " << endl;
    cout << "Go to the north side of the town " << endl;
    cout << "Go to the south part of the town " << endl;
    cout << "Go to the training station here in the mid town " << endl;
    cout << "enter d for east, a for west, w for north, s for south, and p for "
            << "the training station" << endl;
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
    cout << "Go to the inn to heal " << endl;
    cout << "Enter d to go mid town, a for west forest, and i for inn " << endl;
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

void Training::getOptions(){
    cout << "Here in the training station you can pay some gold in order"<<endl;
    cout << "to raise some of your stats"<<endl;
    cout << "You have to pay 100 gold in order to raise one of your"<<endl;
    cout <<"stats by random"<<endl;
    cout <<"Enter y to pay the 100 gold or b to leave"<<endl;
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
        Training train;
        train.getOptions();
        cin >> option;
        train.setOption(option, player);
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
    else if(o == 'i'){
        WestTown west(o);
        west.inn(player);
    }
}

void WestTown::inn(Characters *player){
    char yes;
    cout << "here you can restore you health by only paying"
            " 10 gold " << endl;
    cout << "Do you wish to pay the 10 gold " << endl;
    cout << "Enter y for yes or enter anything for no " << endl;
    cin >> yes;
    if(yes == 'y'){
        if(player->getGold() < 10){
            cout << "I am sorry but u don't have enough gold " << endl;
        }
        else{
            cout << "Current hp " << player->getHp() << endl;
            cout << "Max hp " << player->getMaxHp() << endl;
            int temp = player->getMaxHp();
            player->setHp2(temp);
            cout << "hp after " << player->getHp() << endl;
            cout << "Max hp after " << player->getMaxHp() << endl;
            player->setGold(-10);
        }
        WestTown west;
        west.getOptions();
        cin >> option;
        west.setOption(option, player);
    }
    else{
        WestTown west;
        west.getOptions();
        cin >> option;
        west.setOption(option, player);
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
        cout << "You are in the first section of the forest " << endl;
        cout << "search, go back, or continue forward" << endl;
        cout << "Type s to search, b to back, or f to continue forward" << endl;
        cout << "Searching has two possible outcomes" << endl;
        cout << "One will be that you will find a monster to battle " << endl;
        cout << "and the other will be that you will find and artifact that increases your stats" << endl;
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

void Training::setOption(char o, Characters *player){
    srand(time(0));
    if(o == 'b'){
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
    else if(o == 'y'){
        cout << "You have " << player->getGold() << " gold"<<endl;
        if(player->getGold() < 100){
            cout << endl;
            cout << "I am sorry but u don't have enough gold " << endl;
            cout << endl;
        }
        else{
            int random = rand()%4+1;
            if(random == 1){
                cout << endl;
                cout << "Your hp rose by 100" << endl;
                cout << "Your hp before is: " << player->getHp() << endl;
                player->setMaxHp(100);
                player->setHp(100);
                cout << "Your hp after is: " << player->getHp();
                cout << endl;
            }
            else if(random == 2){
                cout << endl;
                cout << "Your attack rose by 20" << endl;
                cout << "Your attack before is: " << player->getAttack() <<endl;
                player->setAttack(20);
                cout << "Your attack after is: " << player->getAttack();
                cout << endl;
            }
            else if(random == 3){
                cout << endl;
                cout << "Your defense rose by 20" << endl;
                cout << "Your defense before is: " << player->getDefense()<<endl;
                player->setDefense(20);
                cout << "Your defense after is: " << player->getDefense();
                cout << endl;
            }
            else{
                cout << endl;
                cout << "Your speed rose by 20" << endl;
                cout << "Your speed before is: " << player->getSpeed()<<endl;
                player->setSpeed(20);
                cout << "Your speed after is: " << player->getSpeed();
                cout << endl;
            }
            cout << "Thank you for the gold, see you later " << endl;
            player->setGold(-100);
            cout << "You now have " << player->getGold() << " gold"<<endl;
            cout << endl;
        }
        MidTown mid;
        mid.getOptions();
        cin >> option;
        mid.setOption(option, player);
    }
}

void Forest::getOptions(){
    cout << "You are in the first section of the forest " << endl;
    cout << "search, or go back" << endl;
    cout << "Type s to search or b to back" << endl;
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
                            " anything to return " << endl;
                    cin >> again;
                }
            }while(again == "again");
            if(player->getHp() >0){
                EastTown east;
                east.getOptions();
                cin >> option;
                east.setOption(option, player);
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
                        " anything to return " << endl;
                    cin >> again;
                }
            }while(again == "again");
            if(player->getHp() > 0){
                WestTown west;
                west.getOptions();
                cin >> option;
                west.setOption(option, player);
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
            fBoss boss;
            forest.battleB(player,boss,p);
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
                    fBoss boss;
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
                        " anything to return " << endl;
                    cin >> again;
                }
            }while(again == "again");
            if(player->getHp() > 0){
                SouthTown south;
                south.getOptions();
                cin >> option;
                south.setOption(option, player);
            }
            else{
                int x;
            }
        }
    }
}

void Forest::battleB(Characters *player, Characters &enemy, char p){
    cout << "Welcome to the final boss battle" << endl;
    cout << "Entering the final room you the " << player->getCharacter()
            << " has unlocked a special " << endl;
    if(player->getCharacter() == "Mage"){
        cout << "You can now heal yourself instead of attacking "<<endl;
    }
    else if(player->getCharacter() == "Rogue"){
        cout << "You can now attack twice"<<endl;
    }
    else if(player->getCharacter() == "Warrior"){
        cout << "You can lower your speed by a bit to increase your attack"
                << " greatly permanently" << endl;
    }
    string go;
    float damage;
    int result;
    string wAnswer = "no";
    string mAnswer = "no";
    do{
        cout << "His hp is " << enemy.getHp() << endl;
        cout << "Your hp is " << player->getHp() << endl;
        if(player->getSpeed() > enemy.getSpeed()){
            cout << "You attacked first " << endl;
            if(player->getCharacter() == "Rogue"){
                cout << "You attacked twice " << endl;
                damage = (((((2*player->getLevel())+10)/250.0)*(static_cast<float>(player->getAttack())/enemy.getDefense())*90)+100)*4;
                result = (enemy.getHp() - static_cast<int>(damage));
                enemy.setHp2(result);
            }
            else if(player->getCharacter() == "Warrior"){
                if(wAnswer != "y"){
                    cout << "Do you wish to permanently raise you attack and lower ur speed " << endl;
                    cout << "Enter y for yes or anything else for no " << endl;
                    cin >> wAnswer;
                    if(wAnswer == "y"){
                        player->setAttack(player->getAttack()+1500);
                        player->setSpeed(-100);
                    }
                }
                damage = (((((2*player->getLevel())+10)/250.0)*(static_cast<float>(player->getAttack())/enemy.getDefense())*90)+100)*2;
                result = (enemy.getHp() - static_cast<int>(damage));
                enemy.setHp2(result);
            }
            else if(player->getCharacter() == "Mage"){
                cout << "Do you wish to heal or attack " << endl;
                cout << "Enter h to heal or anything else to attack" << endl;
                cin >> mAnswer;
                if(mAnswer == "h"){
                    int restored = player->getHp() / 2;
                    if(restored + player->getHp() >= player->getMaxHp()){
                        player->setHp2(player->getMaxHp());
                    }
                    else{
                        player->setHp(restored);
                    }
                    cout << "Your hp now is: " << player->getHp() << endl;
                }
                else{
                    damage = (((((2*player->getLevel())+10)/250.0)*(static_cast<float>(player->getAttack())/enemy.getDefense())*90)+100)*2;
                    result = (enemy.getHp() - static_cast<int>(damage));
                    enemy.setHp2(result);
                }
            }
            if(enemy.getHp() <= 0){
                cout << "Enemy has died" << endl;
            }
            else{
                cout << "Enemies hp is: " << enemy.getHp() << endl;
                cout << "Now the Boss attacks " << endl;
                damage = (((((2*enemy.getLevel())+10)/250.0)*(static_cast<float>(enemy.getAttack())/player->getDefense())*90)+100)*2;
                result = (player->getHp() - static_cast<int>(damage));
                player->setHp2(result);
            }
            if(player->getHp() <= 0){
                cout << "Your hp went to 0" << endl;
            }
            else{
                cout << "Your hp is: " << player->getHp() << endl;
            } 
            cout << "Type anything to continue " << endl;
            cin >> go;
        }
        else if(player->getSpeed() < enemy.getSpeed()){
            cout << "Enemy attacked first " << endl;
            damage = (((((2*enemy.getLevel())+10)/250.0)*(static_cast<float>(enemy.getAttack())/player->getDefense())*90)+100)*2;
            result = (player->getHp() - static_cast<int>(damage));
            player->setHp2(result);
            if(player->getHp() <= 0){
                cout << "Your hp went to 0" << endl;
            }
            else{
                cout << "Your hp is: " << player->getHp() << endl;
                cout << "Now you attack" << endl;
                if(player->getCharacter() == "Rogue"){
                    cout << "You attacked twice " << endl;
                    damage = (((((2*player->getLevel())+10)/250.0)*(static_cast<float>(player->getAttack())/enemy.getDefense())*90)+100)*4;
                    result = (enemy.getHp() - static_cast<int>(damage));
                    enemy.setHp2(result);
                }
                else if(player->getCharacter() == "Warrior"){
                    if(wAnswer != "y"){
                        cout << "Do you wish to permanently raise you attack and lower ur speed " << endl;
                        cout << "Enter y for yes or anything else for no " << endl;
                        cin >> wAnswer;
                        if(wAnswer == "y"){
                            player->setAttack(player->getAttack()+1500);
                            player->setSpeed(-100);
                        }
                    }
                    damage = (((((2*player->getLevel())+10)/250.0)*(static_cast<float>(player->getAttack())/enemy.getDefense())*90)+100)*2;
                    result = (enemy.getHp() - static_cast<int>(damage));
                    enemy.setHp2(result);
                }
                else if(player->getCharacter() == "Mage"){
                    cout << "Do you wish to heal or attack " << endl;
                    cout << "Enter h to heal or anything else to attack" << endl;
                    cin >> mAnswer;
                    if(mAnswer == "h"){
                        int restored = player->getHp() / 2;
                        if(restored + player->getHp() >= player->getMaxHp()){
                            player->setHp2(player->getMaxHp());
                        }
                        else{
                            player->setHp(restored);
                        }
                        cout << "Your hp now is: " << player->getHp() << endl;
                    }
                    else{
                        damage = (((((2*player->getLevel())+10)/250.0)*(static_cast<float>(player->getAttack())/enemy.getDefense())*90)+100)*2;
                        result = (enemy.getHp() - static_cast<int>(damage));
                        enemy.setHp2(result);
                    }
                }
            }
            if(enemy.getHp() <= 0){
                cout << "Enemy has died" << endl;
            }
            else{
                cout << "Enemies hp is: " << enemy.getHp() << endl;
            }
            cout << "Type anything to continue " << endl;
            cin >> go;
        }
    }while(enemy.getHp() > 0 && player->getHp() > 0);
    if(player->getHp() > 0){
        cout << "Your health at the end of the battle is " << player->getHp() << endl;
    }
    if(enemy.getHp() <= 0){
        cout << "Congratulations you have defeated the final boss" << endl;
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
                eHealth = eHealth - ((player->getAttack() - eDefense)*4);
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
                    eHealth = eHealth - ((player->getAttack() - eDefense)*4);
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