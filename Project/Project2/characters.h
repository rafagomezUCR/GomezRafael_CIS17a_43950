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
        { gold += g; }
        void setLevel()
        { level++; }
        void setExp(int, int);
        void setHp2(int h)
        { hp = h; }
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
        int getMaxHp() const
        { return maxhp; }
        void setInventory(string);
        void setEquipment(string);
        void getInventory();
        void getEquipment();
        virtual string getCharacter() const = 0;
};

class Rogue:public Characters{
    public:
        Rogue();
        virtual string getCharacter() const;
};

class Mage:public Characters{
    public:
        Mage();
        virtual string getCharacter() const;
};

class Warrior:public Characters{
    public:
        Warrior();
        virtual string getCharacter() const;
};

class Boss1:public Characters{
    public:
        Boss1();
        virtual string getCharacter() const;
};

class Boss2:public Characters{
    public:
        Boss2();
};

class Boss3:public Characters{
    public:
        Boss3();
};

class Boss4:public Characters{
    public:
        Boss4();
};
#endif	/* HEROES_H */

