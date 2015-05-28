/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 *
 * Created on May 21, 2015, 7:58 PM
 */

#include <cstdlib>
#include <iostream>
#include "classes.h"
using namespace std;

/*
 * 
 */
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();

int main(int argc, char** argv) {
    string again;
    do
    {
        int num;
        cout << "Type in the problem you wish to test " << endl;
        cin >> num;
        switch(num)
        {
            case 1: prblm1(); break;
            case 2: prblm2(); break;
            case 3: prblm3(); break;
            case 4: prblm4(); break;
            case 5: prblm5(); break;
        }
        cout << "If you want to run program again, type yes " << endl;
        cin >> again;
    }while(again == "yes");
    return 0;
}

void prblm1()
{
    ProductionWorker one(1, 12);
    string name, date;
    int num;
    cout << "Enter the workers name " << endl;
    cin >> name;
    one.setName(name);
    cout << "Enter the employees number " << endl;
    cin >> num;
    one.setNum(num);
    cout << "Enter the employees date of hire " << endl;
    cin >> date;
    one.setHireDate(date);
    cout << one.getName() << "'s shift is ";
    if(one.getShift() == 1){
        cout << "day " << endl;
    }
    else if(one.getShift() == 2){
        cout << "night " << endl;
    }
    cout << "and " << one.getName() << "'s pay rate is " << one.getPayRate()
            << " dollars an hour " << endl;
}

void prblm2()
{
    ShiftSupervisor one(50000, 5000);
    string name, date;
    int num;
    cout << "Enter the workers name " << endl;
    cin >> name;
    one.setName(name);
    cout << "Enter the employees number " << endl;
    cin >> num;
    one.setNum(num);
    cout << "Enter the employees date of hire " << endl;
    cin >> date;
    one.setHireDate(date);
    cout << one.getName() << "'s yearly salary is " << one.getASalary()
            << " dollars, and " << one.getName() << "'s yearly bonus is " 
            << one.getYBnous() << " dollars " << endl;
}

void prblm3()
{
    TeamLeader one(1000, 40, 20);
    string name, date;
    int num;
    cout << "Enter the workers name " << endl;
    cin >> name;
    one.setName(name);
    cout << "Enter the employees number " << endl;
    cin >> num;
    one.setNum(num);
    cout << "Enter the employees date of hire " << endl;
    cin >> date;
    one.setHireDate(date);
    cout << one.getName() << "'s monthly bonus is " << one.getMBonus()
            << " dollars. " << one.getName() << " has to do a total of "
            << one.getTraining() << " hours of training done, and has " 
            << one.getTrainingD() << " hours done so far " << endl;
}

void prblm4()
{
    MilTime one(2350, 0);
    int num, num1;
    cout << "Example of military hours to standard time with 2350 hours "<<endl;
    one.getMHour();
    one.getStandHr();
    cout << "Input a military hour to convert to standard " << endl;
    do{
        cin >> num;
        if(num >= 2400 || num < 0){
            cout << "Invalid input, please try again " << endl;
        }
    }while(num >= 2400 || num < 0);
    cout << "Now input the seconds " << endl;
    do{
        cin >> num1;
        if(num1 > 59 || num1 < 0){
            cout << "Invalid input, please try again " << endl;
        }
    }while(num1 > 59 || num1 < 0);
    one.setTime(num, num1);
    cout << "This the military input you provided: " << endl;
    one.getMHour();
    cout << "Now converted its this: " << endl;
    one.getStandHr();
}

void prblm5()
{
    TimeClock one;
    one.setResult(2300, 1950);
    int num, num1;
    cout << "This is an example of time passed between two military times, "
            << "2300 hours and 1950 hours" << endl; 
    cout << "Hours passed " << one.getResultH() << endl;
    cout << "minutes passed " << one.getResultM() << endl;
    cout << "Input two military hours to see the time elapsed " << endl;
    do{
        cout << "First time: ";
        cin >> num;
        if(num >= 2400 || num < 0){
            cout << "Invalid input, please try again " << endl;
        }
        else{
            do{
                cout << "Second time: ";
                cin >> num1;
                if(num1 >= 2400 || num1 < 0){
                    cout << "Invalid input, please try again " << endl;
                }
            }while(num1 >= 2400 || num1 < 0);
        }
    }while(num >= 2400 || num < 0);
    one.setResult(num, num1);
    cout << "Hours passed " << one.getResultH() << endl;
    cout << "minutes passed " << one.getResultM() << endl;
}

