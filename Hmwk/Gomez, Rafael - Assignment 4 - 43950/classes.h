/* 
 * File:   classes.h
 * Author: Rafael Gomez
 *
 * Created on May 11, 2015, 3:33 PM
 */
using namespace std;

#ifndef CLASSES_H
#define	CLASSES_H

class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        Date();
        void setMonth(int);
        void setDay(int);
        void setYear(int y)
        { year = y; }
        string getMonth() const;
        int getMonth1() const
        { return month; }
        int getDay() const
        { return day; }
        int getYear() const
        { return year; }
};

class Employee
{
    private:
        string name;
        int idNumber;
        string department;
        string position;
    public:
        Employee(string, int, string, string);
        Employee(string, int);
        Employee();
        void setName(string n)
        { name = n; }
        void setNum(int num)
        { idNumber = num; }
        void setDprt(string d)
        { department = d; }
        void setPst(string p)
        { position = p; }
        string getName() const
        { return name; }
        int getNum() const
        { return idNumber; }
        string getDprt() const
        { return department; }
        string getPst() const
        { return position; }
};

class Car
{
    private:
        int yearModel;
        string make;
        int speed;
    public:
        Car(int, string);
        void setYMdl(int y)
        { yearModel = y; }
        void setMake(string m)
        { make = m; }
        int getYMdl() const
        { return yearModel; }
        string getMake() const
        { return make; }
        int getSpeed() const
        { return speed; }
        void acceleration()
        { speed += 5; }
        void brake()
        { speed -= 5; }
};

class Info
{
    private:
        string name;
        string address;
        int age;
        string phone;
    public:
        Info();
        void setName(string n)
        { name = n; }
        void setAdrs(string a)
        { address = a; }
        void setAge(int num)
        { age = num; }
        void setPhn(string p)
        { phone = p; }
        string getName() const
        { return name; }
        string getAdrs() const 
        { return address; }
        int getAge() const 
        { return age; }
        string getPhn() const
        { return phone; }
};

class RetailItem
{
    private:
        string description;
        int unitsOnHand;
        float price;
    public:
        RetailItem(string, int, float);
        string getDscprt() const
        { return description; }
        int getUOH() const
        { return unitsOnHand; }
        float getPrc() const
        { return price; }
};

class Numbers
{
    private:
        int number;
        static string lessThan20[20];
        static string tens[10];
        static string hundred;
        static string thousand;
    public:
        Numbers(int n)
        { number = n; }
        void prnt(int);
};
   
class DateOfYear
{
    private:
        int number;
        static string months[12];
        string month;
    public:
        DateOfYear(int n)
        { number = n; }
        void prnt(int);
};
    

#endif	/* CLASSES_H */

