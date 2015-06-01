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
        int option1;
        char option;
    public:
        World();
        void setOption(int, Characters &);
};

class MidTown
{
    private:
        int option1;
        char option;
    public:
        MidTown()
        { cout << "Welcome to the middle of the town, what do you wish to do " 
                << endl; }
        void getOptions();
        void setOption(char, Characters &);
};

class Shop
{
    private:
        int option1;
        char option;
    public:
        Shop()
        { cout << "Welcome to the shop of the mid town " << endl; }
        void getOptions();
        void setOption(char, Characters &);
};

class EastTown
{
    private:
        int option1;
        char option;
    public:
        EastTown()
        { cout << "Welcome to the east part of the town " << endl; }
        void getOptions();
        void setOption(char, Characters &);
};

class WestTown
{
    private:
        int option1;
        char option;
    public:
        WestTown()
        { cout << "Welcome to the west part of the town " << endl; }
        void getOptions();
        void setOption(char, Characters &);
};

class NorthTown
{
    private:
        int option1;
        char option;
    public:
        NorthTown()
        { cout << "Welcome to the north part of the town " << endl; }
        void getOptions();
        void setOption(char, Characters &);
};

class SouthTown
{
    private:
        int option1;
        char option;
    public:
        SouthTown()
        { cout << "Welcome to the south part of the town " << endl; }
        void getOptions();
        void setOption(char, Characters &);
};

class Forest
{
    private:
        int option1;
        char option;
    public:
        Forest(char);
        Forest(char, char);
        void getOptions();
        void getOptions2();
        //I havent applied the to battle please do so
        void battleB(Characters &, Characters &, char);
        void battle(Characters &, Characters &, char);
        void setOption(char, Characters &, char);
        void setOption2(char, Characters &, char);
        //I havent applied these two functions so do it please
        void search(Characters &, char);
        void search2(Characters &, char);
};
#endif	/* WORLD_H */

