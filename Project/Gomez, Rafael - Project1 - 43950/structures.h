/* 
 * File:   structures.h
 * Author: User
 *
 * Created on April 24, 2015, 2:20 PM
 */

#ifndef STRUCTURES_H
#define	STRUCTURES_H

struct Card
{
    int value;
    char face;
};

struct Casino
{
    int chips = 100;
    int games = 0;
    int wins = 0;
    int loses = 0;
    int *result;
};

#endif	/* STRUCTURES_H */

