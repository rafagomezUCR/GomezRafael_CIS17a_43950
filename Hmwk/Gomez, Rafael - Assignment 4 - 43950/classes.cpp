#include <cstdlib>
#include <iostream>
#include "classes.h"

using namespace std;

Date::Date()
{
    month = 0;
    day = 0; 
    year = 0;
}

void Date::setDay(int d)
{
    if(d > 31 || d < 1)
    {
        cout << "Invalid input";
    }
    else
    {
        day = d;
    }
}

void Date::setMonth(int m)
{
    if(m > 12 || m < 1)
    {
        cout << "Invalid input";
    }
    else 
    {
        month = m;
    }
}

string Date::getMonth() const
{
    string monthA;
    if(month == 1){
        monthA = "January";
    }
    if(month == 2){
        monthA = "February";
    }
    if(month == 3){
        monthA = "March";
    }
    if(month == 4){
        monthA = "April";
    }
    if(month == 5){
        monthA = "May";
    }
    if(month == 6){
        monthA = "June";
    }
    if(month == 7){
        monthA = "July";
    }
    if(month == 8){
        monthA = "August";
    }
    if(month == 9){
        monthA = "September";
    }
    if(month == 10){
        monthA = "October";
    }
    if(month == 11){
        monthA = "November";
    }
    if(month == 12){
        monthA = "December";
    }
    return monthA;
}

Employee::Employee(string n, int num, string d, string p)
{
    name = n;
    idNumber = num;
    department = d;
    position = p;
}

Employee::Employee(string n, int num)
{
    name = n;
    idNumber = num;
    department  = " ";
    position = " ";
}

Employee::Employee()
{
    name = " ";
    idNumber = 0;
    department = " ";
    position = " ";
}

Car::Car(int y, string m)
{
    yearModel = y;
    make = m;
    speed = 0;
}

Info::Info()
{
    name = "You didn't input a name ";
    address = "You didn't input an address";
    age = 0;
    phone = "You didn't input a phone";
}

RetailItem::RetailItem(string d, int u, float p)
{
    description = d;
    unitsOnHand = u;
    price = p;
}

string Numbers::lessThan20[20] = {"zero","one","two","three","four","five",
    "six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen","nineteen"};

string Numbers::tens[10] = {"","ten","twenty","thirty","forty","fifty","sixty",
    "seventy","eighty","ninety"};

string Numbers::hundred = "hundred";

string Numbers::thousand = "thousand";

void Numbers::prnt(int n)
{
    if(n >= 1000)
    {
        cout << lessThan20[n / 1000] << " ";
        cout << thousand;
        if(n % 1000)
        {
            if(n % 1000 < 100)
            {
                cout << " and";
                cout << " ";
                cout << tens[(n % 1000) / 10] << " ";
                cout << lessThan20[(n % 1000) % 10];
            }
            else
            {
                cout << " and ";
                cout << lessThan20[(n % 1000) / 100] << " ";
                cout << hundred;
                if((n % 1000) % 100)
                {
                    cout << " and ";
                    if(n % 100 >= 20)
                    {
                        cout << tens[(n % 100) / 10];
                        if(n % 10)
                        {
                            cout << " ";
                            cout << lessThan20[n % 10];
                        }
                    }
                    else
                    {
                        cout << lessThan20[n % 100];
                    }
                }
            }
        }
    }
    else if(n >= 100)
    {
        cout << lessThan20[n / 100] << " ";
        cout << hundred;
        if(n % 100)
        {
            cout << " and ";
            if(n % 100 >= 20)
            {
                cout << tens[(n % 100) / 10];
                if(n % 10)
                {
                    cout << " ";
                    cout << lessThan20[n % 10];
                }
            }
            else
            {
                cout << lessThan20[n % 100];
            }
        }
    }
    else if(n >= 20)
    {
        cout << tens[n/10];
        if(n % 10)
        {
            cout << " ";
            cout << lessThan20[n % 10];
        }
    }
    else
    {
        cout << lessThan20[number];
    }
    return;
}

string DateOfYear::months[12] = {"January","February","March","April","May",
    "June","July","August","September","October","November","December"};

void DateOfYear::prnt(int n)
{
    if(n <= 31)
    {
        cout << months[0] << " " << n;
    }
    else if(n > 31 && n <= 59)
    {
        cout << months[1] << " " << n - 31;
    }
    else if(n > 59 && n <= 90)
    {
        cout << months[2] << " " << n - 59;
    }
    else if(n > 90 && n <= 120)
    {
        cout << months[3] << " " << n - 90;
    }
    else if(n > 120 && n <= 151)
    {
        cout << months[4] << " " << n - 120;
    }
    else if(n > 151 && n <= 181)
    {
        cout << months[5] << " " << n - 151;
    }
    else if(n > 181 && n <= 212)
    {
        cout << months[6] << " " << n - 181;
    }
    else if(n > 212 && n <= 243)
    {
        cout << months[7] << " " << n - 212;
    }
    else if(n > 243 && n <= 273)
    {
        cout << months[8] << " " << n - 243;
    }
    else if(n > 273 && n <= 304)
    {
        cout << months[9] << " " << n - 273;
    }
    else if(n > 304 && n <= 334)
    {
        cout << months[10] << " " << n - 304;
    }
    else if(n > 334 && n <= 365)
    {
        cout << months[11] << " " << n - 334;
    }
}