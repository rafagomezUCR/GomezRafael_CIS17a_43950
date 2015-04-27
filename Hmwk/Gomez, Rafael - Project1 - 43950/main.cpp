/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 * Created on April 24, 2015, 1:02 PM
 */

#include <cstdlib>
#include <iostream>
#include "structures.h"
using namespace std;

void create(Card []);
void shuffle(Card []);
void craps(Casino);
void blckjck(Card [], Casino);
int ace(int);
void prntHnd(int, Card []);
void prtDHnd(int, Card []);
int chckWin(int, int);
int dAce(int = 0, int = 0, int = 0, int = 0, int = 0);
void clear();

int main(int argc, char** argv) {
    srand(time(0));
    Card deck[52];
    Casino casino;
    create(deck);
    casino.chips = 100;
    casino.games = 0;
    casino.loses = 0; 
    casino.wins = 0;
    cout << "This casino has two games that you will be able to bet and play"
            << endl;
    string again = "again";
    do
    {
        int game;
        cout << "Enter 1 to play craps and 2 to play blackjack ";
        cin >> game;
        switch(game)
        {
            case 1: craps(casino); 
            cout << "If you want to continue playing any of these two games "
                << "type again and then enter ";
            cin >> again;
            break;
            case 2: blckjck(deck, casino);
            cout << "If you want to continue playing any of these two games "
                << "type again and then enter ";
            cin >> again;
            break;
            default: cout << "Invalid input, please input again " << endl;
            break;
        }
    }while(again == "again");
    Casino *result = new Casino;
    result->games = casino.games;
    result->loses = casino.loses;
    result->wins = casino.wins;
    cout << "Games played is " << result->games << endl;
    cout << "Number of wins is " << result->wins << endl;
    cout << "Number of loses is " << result->loses << endl;
    return 0;
}

void create(Card deck[])
{
    int num = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            deck[num].value = j+1;
            if(deck[num].value > 10)
            {
                deck[num].value = 10;
            }
            if(i == 0)deck[num].face = 'H';
            else if(i == 1)deck[num].face = 'S';
            else if(i == 2)deck[num].face = 'C';
            else deck[num].face = 'D';
            num++;
        }
    }
}

void shuffle(Card deck[])
{
    for(int i = 0; i < 52; i++)
    {
        int r = rand()%52;
        swap(deck[i].face, deck[r].face);
        swap(deck[i].value, deck[r].value);
    }
}

void craps(Casino casino)
{
    cout << "Welcome to Craps " << endl;
    cout << "How much do you want to bet" << endl;
    int betc;
    cin >> betc;
    int die1 = rand()%6+1;
    int die2 = rand()%6+1;
    cout << "You rolled " << die1 << " and " << die2 << endl;
    int sumDie = die1 + die2;
    cout << "Sum of the die rolled is " << sumDie << endl;
    if(sumDie == 7 || sumDie == 11)
    {
        cout << "You have won " << endl;
        casino.chips += betc;
        casino.wins++;
    }
    else if(sumDie == 2 || sumDie == 3 || sumDie == 12)
    {
        cout << "You have lost " << endl;
        casino.chips -= betc;
        casino.loses++;
    }
    else
    {
        cout << "Next round will continue " << endl;          
        int scdDie1 = rand()%6+1;
        int scdDie2 = rand()%6+1;
        cout << "You rolled " << scdDie1 << " and " << scdDie2 << endl;
        int sumDie2 = scdDie1 + scdDie2;
        cout << "The sum of the two die is " << sumDie2 << endl;
        if(sumDie2 == 7)
        {
            cout << "You have lost " << endl;
            casino.chips -= betc;
            casino.loses++;
        }
        else if(sumDie2 == sumDie)
        {
            cout << "You have won " << endl;
            casino.chips += betc;
            casino.wins++;
        }
        else
        {
            cout << "You will have to continue rolling until you roll a 7(lose)"
                    << " or the roll the same as the previous die(win) "<< endl;
            int i = 0;
            do
            {
                scdDie1 = rand()%6+1;
                scdDie2 = rand()%6+1;
                cout << "You rolled " << scdDie1 << " and " << scdDie2 <<endl;
                sumDie2 = scdDie1 + scdDie2;
                cout << "The sum of the two die is " << sumDie2 << endl;
                if(sumDie2 == 7)
                {
                    cout << "You have lost ";
                    casino.chips -= betc;
                    casino.loses++;
                    i++;
                }
                else if(sumDie2 == sumDie)
                {
                    cout << "You have won ";
                    casino.chips += betc;
                    casino.wins++;
                    i++;
                }
                else
                {
                    cout << "Roll again..." << endl;
                }
                cout << endl;
            }while(i < 1);
        }
    }
    cout << "You have " << casino.chips << " left" << endl;
    casino.games++;
    clear();
}

void blckjck(Card deck[], Casino casino)
{
    cout << "Welcome to Blackjack " << endl;
    cout << "How much do you want to bet ";
    string answer;
    string play;
    int betb, numHnd, numHnd2, sumHnd, sumHnd2;
    cin >> betb;
    shuffle(deck);
    cout << "The cards have been shuffled and now will be dealt... " << endl;
    cout << "Your cards are " << endl;
    cout << deck[0].value << " " << deck[0].face;
    cout << "  " << deck[1].value << " " << deck[1].face << endl;  
    cout << "And one of the dealers cards are " << endl;
    cout << deck[2].value << " " << deck[2].face << " "; 
    cout << "and a face down card " << endl;
    if(deck[0].value == 1)deck[0].value  = ace(deck[0].value);
    if(deck[1].value == 1)deck[1].value = ace(deck[1].value);
    if(deck[2].value == 1)deck[1].value = dAce(deck[2].value, deck[3].value);
    if(deck[3].value == 1)deck[1].value = dAce(deck[3].value, deck[2].value);
    if(deck[0].value + deck[1].value == 21 && deck[2].value + deck[3].value !=
            21)
    {
        cout << "You have 21, you win! " << endl;
        casino.chips += betb;
        casino.wins++;
    }
    else if(deck[0].value + deck[1].value == 21 && deck[2].value + deck[3].value
            == 21)
    {
        cout << "Both you and dealer have 21, its a draw " << endl;
    }
    else
    {
        numHnd = 2;
        sumHnd = deck[0].value + deck[1].value;
        cout << "Hit or stay " << endl;
        cout << "Type h to hit or anything to stay " << endl;
        cin >> play;
        if(play == "h")
        {
            cout << "Your new hand is " << endl;
            for(int i = 0; i < 4; i++)
            {
                if(i == 2)i=4;
                cout << deck[i].value << " " << deck[i].face << "  ";
            }
            if(deck[4].value == 1)
            {
                deck[4].value = ace(deck[4].value);
            }
            numHnd = 3;
            sumHnd = deck[0].value + deck[1].value + deck[4].value;
            cout << "Hit or stay " << endl;
            cin >> play;
            if(play == "h")
            {
                cout << "Your new hand is " << endl;
                for(int i = 0; i < 6; i++)
                {
                    if(i == 2)i=4;
                    cout << deck[i].value << " " << deck[i].face << "  ";
                }
                if(deck[5].value == 1)
                {
                    deck[5].value = ace(deck[5].value);
                }
                numHnd = 4;
                sumHnd = deck[0].value + deck[1].value + deck[4].value +
                        deck[5].value;
                cout << "Hit or stay " << endl;
                cin >> play;
                if(play == "h")
                {
                    cout << "Your new hand is " << endl;
                    for(int i = 0; i < 7; i++)
                    {
                        if(i == 2)i=4;
                        cout << deck[i].value << " " << deck[i].face << "  ";
                    }
                    if(deck[6].value == 1)
                    {
                        deck[6].value = ace(deck[6].value);
                    }
                    numHnd = 5;
                    sumHnd = deck[0].value + deck[1].value + deck[4].value +
                        deck[5].value + deck[6].value;
                }
            }
        }
        cout << "Now its the dealers turn " << endl;
        if(deck[2].value + deck[3].value >= 17)
        {
            sumHnd2 = deck[2].value + deck[3].value;
            cout << "The dealer does  not choose to get another card"<<endl;
            cout << "Your hand is " << endl;
            prntHnd(numHnd, deck);
            cout << "And the dealers hand is " << endl;
            cout << deck[2].value << " " << deck[2].face << "  ";
            cout << deck[3].value << " " << deck[3].face << endl;
            if(chckWin(sumHnd, sumHnd2) == 0)casino.chips-=betb, casino.loses++;
            else if(chckWin(sumHnd, sumHnd2) == 1)casino.chips+=betb, casino.wins++;
        }
        else
        {
            numHnd2 = 3;
            cout << "The dealer gets a new card and his hand is now " << endl;
            cout << deck[2].value << " " << deck[2].face << "  ";
            cout << deck[3].value << " " << deck[3].face << " ";
            cout << "and a face down card " << endl;
            if(deck[7].value == 1)deck[1].value = dAce(deck[7].value, 
                    deck[2].value, deck[3].value);
            sumHnd2 = deck[2].value + deck[3].value + deck[7].value;
            if(sumHnd2 >= 17)
            {
                cout << "The dealer does  not choose to get another card"<<endl;
                cout << "Your hand is " << endl;
                prntHnd(numHnd, deck);
                cout << "And the dealers hand is " << endl;
                prtDHnd(numHnd2, deck);
                if(chckWin(sumHnd, sumHnd2) == 0)casino.chips-=betb, casino.loses++;
                else if(chckWin(sumHnd, sumHnd2) == 1)casino.chips+=betb, casino.wins++;
            }
            else
            {
                numHnd2 = 4;
                cout << "The dealer gets a new card and his hand is now " << endl;
                cout << deck[2].value << " " << deck[2].face << "  ";
                cout << deck[3].value << " " << deck[3].face << "  ";
                cout << deck[7].value << " " << deck[7].face << " ";
                cout << "and a face down card " << endl;
                if(deck[8].value == 1)deck[8].value = dAce(deck[8].value, 
                    deck[2].value, deck[3].value, deck[7].value);
                sumHnd2 = deck[2].value + deck[3].value + deck[7].value
                        + deck[8].value;
                if(sumHnd2 >= 17)
                {
                    cout<<"The dealer does  not choose to get another card"<<endl;
                    cout << "Your hand is " << endl;
                    prntHnd(numHnd, deck);
                    cout << "And the dealers hand is " << endl;
                    prtDHnd(numHnd2, deck);
                    if(chckWin(sumHnd, sumHnd2) == 0)casino.chips-=betb, casino.loses++;
                    else if(chckWin(sumHnd, sumHnd2) == 1)casino.chips+=betb, casino.wins++;
                }
                else
                {
                    numHnd2 = 5;
                    cout<<"The dealer gets a new card and his hand is now "<<endl;
                    cout << deck[2].value << " " << deck[2].face << "  ";
                    cout << deck[3].value << " " << deck[3].face << "  ";
                    cout << deck[7].value << " " << deck[7].face << "  ";
                    cout << deck[8].value << " " << deck[8].face << " ";
                    cout << "and a face down card " << endl;
                    if(deck[9].value == 1)deck[9].value = dAce(deck[9].value, 
                        deck[2].value, deck[3].value, deck[7].value,
                            deck[8].value);
                    sumHnd2 = deck[2].value + deck[3].value + deck[7].value
                            + deck[8].value + deck[9].value;
                    cout << "The dealer now has 5 cards " << endl;
                    cout << "Your hand is " << endl;
                    prntHnd(numHnd, deck);
                    cout << "And the dealers hand is " << endl;
                    prtDHnd(numHnd2, deck);
                    if(chckWin(sumHnd, sumHnd2) == 0)casino.chips-=betb, casino.loses++;
                    else if(chckWin(sumHnd, sumHnd2) == 1)casino.chips+=betb, casino.wins++;
                }
            }
        }
    }
    cout << "You have " << casino.chips << " left" << endl;
    casino.games++;
    clear();
}

int ace(int ace)
{
    cout << "Do you want to switch the value of the ace to 11, yes or no"<<endl;
    string answer;
    cin >> answer;
    if(answer == "yes")
    {
        ace = 11;
        return ace;
    }
    else
    {
        ace = 1;
        return ace;
    }
}

void prntHnd(int numHnd, Card deck[])
{
    if(numHnd == 2)
    {
        cout << deck[0].value << " " << deck[0].face << "  ";
        cout << deck[1].value << " " << deck[1].face << "  ";
    }
    else if(numHnd == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            if(i == 2)i=4;
            cout << deck[i].value << " " << deck[i].face << "  ";
        }
    }
    else
    {
        for(int i = 0; i < numHnd + 2; i++)
        {
            if(i == 2)i=4;
            cout << deck[i].value << " " << deck[i].face << "  ";
        }
    }
}

void prtDHnd(int num, Card deck[])
{
    if(num == 2)
    {
        cout << deck[2].value << " " << deck[2].face << "  ";
        cout << deck[3].value << " " << deck[3].face << "  ";
    }
    else if(num == 3)
    {
        for(int i = 2; i < 8; i++)
        {
            if(i == 4)i=7;
            cout << deck[i].value << " " << deck[i].face << "  ";
        }
    }
    else
    {
        for(int i = 2; i < num + 5; i++)
        {
            if(i == 4)i=7;
            cout << deck[i].value << " " << deck[i].face << "  ";
        }
    }
}

int chckWin(int sumHnd, int sumHnd2)
{
    int win;
    if(sumHnd <= 21 && sumHnd2 <= 21)
    {
        if(sumHnd < sumHnd2)
        {
            cout << "Dealer wins! " << endl;
            win = 0;
        }
        else if(sumHnd == sumHnd2)
        {
            cout << "Draw " << endl;
            win = 2;
        }
        else
        {
            cout << "You lost! " << endl; 
            win = 0;
        }
    }
    if(sumHnd > 21 && sumHnd2 <= 21)
    {
        cout << "Dealer win! " << endl;
        win = 0;
    }
    if(sumHnd <= 21 && sumHnd2 > 21)
    {
        cout << "You win! " << endl;
        win = 1;
    }
    if(sumHnd > 21 && sumHnd2 > 21)
    {
        cout << "You lost!" << endl; 
        win = 0;
    }
    return win;
}

int dAce(int num, int num2, int num3, int num4, int num5)
{
    num = 11;
    if(num + num2 + num3 + num4 + num5 == 21)
    {
        num = 11;
        return num;
    }
    else num = 1; return num;
}

void clear()
{
    for(int i = 0; i < 2; i++)
    {
        cout << endl;
    }
}
