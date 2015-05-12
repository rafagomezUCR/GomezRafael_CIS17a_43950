/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 *
 * Created on May 11, 2015, 3:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
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
void prblm6();
void prblm7();
void prblm8();
void prblm9();
void prblm10();

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
            case 6: prblm6(); break;
            case 7: prblm7(); break;
            case 8: prblm8(); break;
            case 9: prblm9(); break;
            case 10: prblm10(); break;
        }
        cout << "If you want to run program again, type yes " << endl;
        cin >> again;
    }while(again == "yes");
    return 0;
}

void prblm1()
{
    Date date;
    int month, day, year;
    cout << "What day is it " << endl;
    cin >> day;
    cout << "What month is it " << endl;
    cin >> month;
    cout << "What year is it " << endl;
    cin >> year;
    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);
    cout << "The date is " << endl;
    cout << date.getMonth1() << "/" << date.getDay() << "/" << date.getYear();
    cout << endl;
    cout << date.getMonth() << " " << date.getDay() << ", " << date.getYear();
    cout << endl;
    cout << date.getDay() << " " << date.getMonth() << " " << date.getYear();
    cout << endl;
}
void prblm2()
{
    int id;
    string name, dprt, pst;
    const int SIZE = 3;
    Employee employee[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        cout << "What is the name of the " <<i+1<< " st/nd/rd employee "<< endl;
        cin >> name;
        employee[i].setName(name);
        cout << "What is the idNum of the "<<i+1<< " st/nd/rd employee "<< endl;
        cin >> id;
        employee[i].setNum(id);
        cout<<"What is the department of the "<<i+1<<" st/nd/rd employee "<< endl;
        cin.ignore();
        getline(cin, dprt);
        employee[i].setDprt(dprt);
        cout<<"What is the position of the "<<i+1<<" st/nd/rd employee "<< endl;
        cin.ignore();
        getline(cin, pst);
        employee[i].setPst(pst);
    }
    cout << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << "The " << i+1 << " st/nd/rd employee " << endl;
        cout << "Name: " << employee[i].getName() << endl;
        cout << "idNumber: " << employee[i].getNum() << endl;
        cout << "Department: " << employee[i].getDprt() << endl;
        cout << "Position: " << employee[i].getPst() << endl;
    }
    cout << endl;
}
void prblm3()
{
    int y;
    string m;
    cout << "What is the year model of the car " << endl;
    cin >> y;
    cout << "What is the make of the car " << endl;
    cin >> m;
    Car car(y, m);
    cout << "The cars initial acceleration is " << car.getSpeed() << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "It accelerates by 5... " << endl;
        car.acceleration();
        cout << "And now the speed is " << car.getSpeed() << endl;
    }
    cout << "The car begins to brake " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "It slows down by 5... " << endl;
        car.brake();
        cout << "The speed is " << car.getSpeed() << endl;
    }
    cout << endl;
}
void prblm4()
{
    Info me;
    Info friends;
    Info family;
    string n, a, p, family1;
    int num;
    cout << "What is your name " << endl;
    cin >> n;
    me.setName(n);
    cout << "What is your address " << endl;
    cin.ignore();
    getline(cin, a);
    me.setAdrs(a);
    cout << "What is your age " << endl;
    cin >> num;
    me.setAge(num);
    cout << "What is your phone number " << endl;
    cin >> p;
    me.setPhn(p);
    cout << "What is your friends name " << endl;
    cin >> n;
    friends.setName(n);
    cout << "What is your friends address " << endl;
    cin.ignore();
    getline(cin, a);
    friends.setAdrs(a);
    cout << "What is your friends age " << endl;
    cin >> num;
    friends.setAge(num);
    cout << "What is your friends phone number " << endl;
    cin >> p;
    friends.setPhn(p);
    cout << "What family member will you input data for ";
    cin >> family1;
    cout << "What is your " << family1 << "'s name " << endl;
    cin >> n;
    family.setName(n);
    cout << "What is your " << family1 << "'s address " << endl;
    cin.ignore();
    getline(cin, a);
    family.setAdrs(a);
    cout << "What is your " << family1 << "'s age " << endl;
    cin >> num;
    family.setAge(num);
    cout << "What is your " << family1 << "'s phone number " << endl;
    cin >> p;
    family.setPhn(p);
    cout << endl << endl;
    cout << "This is your info " << endl;
    cout << "Name: " << me.getName() << endl;
    cout << "Address: " << me.getAdrs() << endl;
    cout << "Age: " << me.getAge() << endl;
    cout << "Phone: " << me.getPhn() << endl;
    cout << "This is your friends info " << endl;
    cout << "Name: " << friends.getName() << endl;
    cout << "Address: " << friends.getAdrs() << endl;
    cout << "Age: " << friends.getAge() << endl;
    cout << "Phone: " << friends.getPhn() << endl;
    cout << "Your " << family1 << "'s info is " << endl;
    cout << "Name: " << family.getName() << endl;
    cout << "Address: " << family.getAdrs() << endl;
    cout << "Age: " << family.getAge() << endl;
    cout << "Phone: " << family.getPhn() << endl;
}
void prblm5()
{
    int u1, u2, u3, p1, p2, p3;
    string d1, d2, d3;
    d1 = "jacket", d2 = "Designer Jeans", d3 = "Shirt";
    u1 = 12, u2 = 40, u3 = 20, p1 = 59.95, p2 = 34.95, p3 = 24.95;
    RetailItem item1(d1, u1, p1);
    RetailItem item2(d2, u2, p2);
    RetailItem item3(d3, u3, p3);
    cout << "Itme #1 " << endl;
    cout << "Description: " << item1.getDscprt() << endl;
    cout << "Units on Hand: " << item1.getUOH() << endl;
    cout << "Price: " << item1.getPrc() << endl;
    cout << "Itme #2 " << endl;
    cout << "Description: " << item2.getDscprt() << endl;
    cout << "Units on Hand: " << item2.getUOH() << endl;
    cout << "Price: " << item2.getPrc() << endl;
    cout << "Itme #3 " << endl;
    cout << "Description: " << item3.getDscprt() << endl;
    cout << "Units on Hand: " << item3.getUOH() << endl;
    cout << "Price: " << item3.getPrc() << endl;
}
void prblm6()
{
    int num;
    cout << "Enter a number " << endl;
    do
    {
        cin >> num;
        if(num > 9999 || num < 1)
        {
            cout << "Invalid input, input again " << endl;
        }
    }while(num > 9999 || num < 1);
    Numbers numbers(num);
    numbers.prnt(num);
    cout << endl;
}
void prblm7()
{
    int num;
    cout << "Enter a day " << endl;
    do
    {
        cin >> num;
        if(num > 365 || num < 1)
        {
            cout << "Invalid input, input again " << endl;
        }
    }while(num > 365 || num < 1);
    DateOfYear date(num);
    date.prnt(num);
    cout << endl;
}
void prblm8()
{
    cout << "Have not completed an 8th problem" << endl;
}
void prblm9()
{
    cout << "Have not completed a 9th problem" << endl;
}
void prblm10()
{
    cout << "Have not completed a 10th problem" << endl;
}