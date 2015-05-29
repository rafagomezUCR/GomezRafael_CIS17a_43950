/* 
 * File:   heroes.h
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:04 AM
 */

#ifndef HEROES_H
#define	HEROES_H

class Characters{
    protected:
        int sizeI;
        int sizeE;
        int hp;
        int attack;
        int speed;
        int defense;
        int *inventory;
        int *equipment;
        int level;
        int iCounter;
        int eCounter;
        int exp;
        int gold;
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
        void setInventory(int);
        void setEquipment(int);
        void getInventory();
        void getEquipment();
};

class Rogue:public Characters{
    public:
        Rogue();
        void rSpecial();
};

class Mage:public Characters{
    public:
        Mage();
        void mSpecial();
};

class Warrior:public Characters{
    public:
        Warrior();
        void wSpecial();
};

class Enemy:public Characters{
    
};

class Boss:public Characters{
    
};
#endif	/* HEROES_H */

