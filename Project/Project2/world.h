/* 
 * File:   world.h
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:08 AM
 */

#ifndef WORLD_H
#define	WORLD_H

#include <iostream>

using namespace std;

class World
{
    private:
        int option;
    public:
        World()
        { cout << "Welcome to the rpg game " << endl; }
        void setOption(int);
};

class MidTown
{
    private:
        int option;
    public:
        MidTown()
        { cout << "Welcome to the middle of the town, what do you wish to do " 
                << endl; }
        void getOptions();
        void setOption(int);
};

class Shop
{
    private:
        int option;
    public:
        Shop()
        { cout << "Welcome to the shop of the mid town " << endl; }
        void getOptions();
        void setOption(int);
};

class EastTown
{
    private:
        int option;
    public:
        EastTown()
        { cout << "Welcome to the east part of the town " << endl; }
        void getOptions();
        void setOption(int);
};

class WestTown
{
    private:
        int option;
    public:
        WestTown()
        { cout << "Welcome to the west part of the town " << endl; }
        void getOptions();
        void setOption(int);
};

class NorthTown
{
    private:
        int option;
    public:
        NorthTown()
        { cout << "Welcome to the north part of the town " << endl; }
        void getOptions();
        void setOption(int);
};

class SouthTown
{
    private:
        int option;
    public:
        SouthTown()
        { cout << "Welcome to the south part of the town " << endl; }
        void getOptions();
        void setOption(int);
};

class Forest
{
    private:
        int option;
    public:
        Forest(int);
        void setOption(int);
};
#endif	/* WORLD_H */

