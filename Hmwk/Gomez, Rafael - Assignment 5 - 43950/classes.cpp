/* 
 * File:   classes.h
 * Author: Rafael Gomez
 *
 * Created on May 21, 2015, 7:59 PM
 */

#include "classes.h"

Employee::Employee()
{
    cout << "Base class constructor " << endl;
    num = 0;
    hireDate = " ";
    name = " ";
}

MilTime::MilTime(int h, int s)
{
    milHours = h, milSeconds = s;
    if(milHours >= 1300 && milHours <= 2359){
        hour = (milHours - 1200)/100;
        min = (milHours - 100)%100;
    }
    else if(milHours == 1200 || milHours == 0000){
        hour =  12;
        min = 0;
    }
    else{
        hour = milHours / 100;
        min = milHours & 100;
    }
    sec = milSeconds;
}

void MilTime::setTime(int h1, int s1)
{
    milHours = h1, milSeconds = s1;
    if(milHours >= 1300 && milHours <= 2359){
        hour = (milHours - 1200)/100;
        min = (milHours - 100)%100;
    }
    else if(milHours == 1200 || milHours == 0000){
        hour =  12;
        min = 0;
    }
    else{
        hour = milHours / 100;
        min = milHours & 100;
    }
    sec = milSeconds;
}

void MilTime::getMHour() const
{
    cout << "military hours is " << milHours << " hours, and "
            << milSeconds << " seconds " << endl;
}

void MilTime::getStandHr() const
{
    if(hour == 12 && milHours == 0000){
        cout << "Its midnight" << endl;
    }
    else if(hour == 12 && milHours == 1200){
        cout << "Its noon" << endl;
    }
    else{
    cout << "Standard time is " << hour << " hours, " << min << " minutes, "
            << "and " << sec << " seconds " << endl;
    }
}

TimeClock::TimeClock(int one, int two)
{
    if(one < two){
        resultH = (one - two) / 100;
        if(resultH < 0){
            resultH *= -1;
        }
        resultM = (one - two) % 100;
        if(resultM < 0){
            resultM *= -1;
        }
    }
    else if(one == two){
        resultH = 0;
        resultM = 0;
    }
    else{
        resultH = 2400 -(one - two);
        resultM = (one%100) - (two%100);
        if(resultM < 0){
            resultM *= -1;
        }
    }
}

void TimeClock::setResult(int one, int two)
{
    if(one < two){
        resultH = (one - two) / 100;
        if(resultH < 0){
            resultH *= -1;
        }
        resultM = (one&100) - (two&100);
        if(resultM < 0){
            resultM *= -1;
        }
    }
    else if(one == two){
        resultH = 0;
        resultM = 0;
    }
    else{
        resultH = (2400 -(one - two)) / 100;
        resultM = (one%100) - (two%100);
        if(resultM < 0){
            resultM *= -1;
        }
    }
}