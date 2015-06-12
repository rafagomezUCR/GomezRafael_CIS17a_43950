/* 
 * File:   world.h
 * Author: Rafael Gomez
 *
 * Created on May 28, 2015, 8:08 AM
 */

#ifndef WORLD_H
#define	WORLD_H

#include <iostream>
#include "characters.h"

using namespace std;

class World
{
    private:
        char option;
    public:
        World();
        void setOption(int, Characters *);
};

class MidTown
{
    private:
        char option;
    public:
        MidTown()
        { cout << "Welcome to the middle of the town, what do you wish to do " 
                << endl; }
        void getOptions();
        void setOption(char, Characters *);
};

class Training
{
    private:
        char option;
    public:
        Training();
        void getOptions();
        void setOption(char, Characters *);
};

class EastTown
{
    private:
        char option;
    public:
        EastTown()
        { cout << "Welcome to the east part of the town " << endl; }
        void getOptions();
        void setOption(char, Characters *);
};

class WestTown
{
    private:
        char option;
    public:
        WestTown()
        { cout << "Welcome to the west part of the town " << endl; }
        WestTown(char i)
        { cout << "Welcome to the inn " << endl; }
        void inn(Characters *);
        void getOptions();
        void setOption(char, Characters *);
};

class NorthTown
{
    private:
        char option;
    public:
        NorthTown()
        { cout << "Welcome to the north part of the town " << endl; }
        void getOptions();
        void setOption(char, Characters *);
};

class SouthTown
{
    private:
        char option;
    public:
        SouthTown()
        { cout << "Welcome to the south part of the town " << endl; }
        void getOptions();
        void setOption(char, Characters *);
};

class Forest
{
    private:
        char option;
    public:
        Forest();
        Forest(char);
        void getOptions();
        void battleB(Characters *, Characters &, char);
        void battle(Characters *, char);
        int battleR(Characters *, int, int, int, int, int);
        void setOption(char, Characters *, char);
        void search(Characters *, char);
};
#endif	/* WORLD_H */

