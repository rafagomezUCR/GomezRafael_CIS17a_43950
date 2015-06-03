/* 
 * File:   heroes.h
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:04 AM
 */

#ifndef HEROES_H
#define	HEROES_H

#include <iostream>

using namespace std;

class Characters{
    protected:
        int sizeI;
        int sizeE;
        int hp;
        int maxhp;
        int attack;
        int speed;
        int defense;
        string *inventory;
        string *equipment;
        int level;
        int iCounter;
        int eCounter;
        int exp;
        int gold;
        string character;
    public:
        Characters();
        ~Characters();
        void setGold(int g)
        { gold = g; }
        void setLevel()
        { level++; }
        void setExp(int, int);
        void setHp(int h)
        { hp += h; }
        void setMaxHp(int h)
        { maxhp += h; }
        void setHpB(int, int);
        void setAttack(int a)
        { attack += a; }
        void setSpeed(int s)
        { speed += s; }
        void setDefense(int d)
        { defense += d; }
        int getLevel() const
        { return level; }
        int getAttack() const
        { return attack; }
        int getDefense() const
        { return defense; }
        int getHp() const 
        { return hp; }
        int getSpeed() const
        { return speed; }
        int getExp() const
        { return exp; }
        int getGold() const
        { return gold; }
        void setInventory(string);
        void setEquipment(string);
        void getInventory();
        void getEquipment();
        void Special(){;}
        string getCharacter()
        { return character; }
};

class Rogue:public Characters{
    public:
        Rogue();
        void Special();     
};

class Mage:public Characters{
    public:
        Mage();
        void Special();
};

class Warrior:public Characters{
    public:
        Warrior();
        void Special();
};



class Boss:public Characters{
    private:
        int bHealth1;
        int bAttack1;
        int bDefense1;
        int bSpeed1;
        int bHealth2;
        int bAttack2;
        int bDefense2;
        int bSpeed2;
        int bHealth3;
        int bAttack3;
        int bDefense3;
        int bSpeed3;
        int bHealth4;
        int bAttack4;
        int bDefense4;
        int bSpeed4;
    public:
        void setBHealth1(int h)
        { bHealth1 = h; }
        void setBHealth2(int h)
        { bHealth2 = h; }
        void setBHealth3(int h)
        { bHealth3 = h; }
        void setBHealth4(int h)
        { bHealth4 = h; }
        void setBDefense1(int d)
        { bDefense1 = d; }
        void setBDefense2(int d)
        { bDefense2 = d; }
        void setBDefense3(int d)
        { bDefense3 = d; }
        void setBDefense4(int d)
        { bDefense4 = d; }
        void setBAttack1(int a)
        { bAttack1 = a; }
        void setBAttack2(int a)
        { bAttack2 = a; }
        void setBAttack3(int a)
        { bAttack3 = a; }
        void setBAttack4(int a)
        { bAttack4 = a; }
        void setBSpeed1(int s)
        { bSpeed1 = s; }
        void setBSpeed2(int s)
        { bSpeed2 = s; }
        void setBSpeed3(int s)
        { bSpeed3 = s; }
        void setBSpeed4(int s)
        { bSpeed4 = s; }
        int getBHealth1()
        { return bHealth1; }
        int getBHealth2()
        { return bHealth2; }
        int getBHealth3()
        { return bHealth3; }
        int getBHealth4()
        { return bHealth4; }
        int getBDefense1()
        { return bDefense1; }
        int getBDefense2()
        { return bDefense2; }
        int getBDefense3()
        { return bDefense3; }
        int getBDefense4()
        { return bDefense4; }
        int getBAttack1()
        { return bAttack1; }
        int getBAttack2()
        { return bAttack2; }
        int getBAttack3()
        { return bAttack3; }
        int getBAttack4()
        { return bAttack4; }
        int getBSpeed1()
        { return bSpeed1; }
        int getBSpeed2()
        { return bSpeed2; }
        int getBSpeed3()
        { return bSpeed3; }
        int getBSpeed4()
        { return bSpeed4; }
};
#endif	/* HEROES_H */

