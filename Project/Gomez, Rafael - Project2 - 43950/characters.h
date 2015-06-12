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
        int hp;
        int maxhp;
        int attack;
        int speed;
        int defense;
        int level;
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

class fBoss:public Characters{
    public:
        fBoss();
        virtual string getCharacter() const;
};

#endif	/* HEROES_H */

