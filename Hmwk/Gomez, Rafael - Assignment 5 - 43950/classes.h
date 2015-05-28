/* 
 * File:   classes.h
 * Author: Rafael Gomez
 *
 * Created on May 21, 2015, 7:59 PM
 */

#ifndef CLASSES_H
#define	CLASSES_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Employee
{
    protected:
        string name;
        int num;
        string hireDate;
    public:
        Employee();
        ~Employee()
        { cout << "Base class destructor " << endl; }
        void setName(string n)
        { name = n; }
        void setNum(int n)
        { num = n; }
        void setHireDate(string n)
        { hireDate = n; }
        int getNum() const
        { return num; }
        string getHireDate() const
        { return hireDate; }
        string getName() const
        { return name; }
};

class ProductionWorker: public Employee
{
    private:
        int shift;
        float payRate;
    public:
        ProductionWorker()
        { shift = 0, payRate = 0; 
        cout << "Derived ProductionWorker constructor " << endl;}
        ProductionWorker(int s, float p)
        { shift = s, payRate = p;
        cout << "Derived ProductionWorker constructor " << endl; }
        ~ProductionWorker()
        { cout << "Derived ProductionWorker destructor " << endl; }
        void setShift(int s)
        { shift = s; }
        void setPayRate(float p)
        { payRate = p; }
        int getShift() const
        { return shift; }
        float getPayRate() const
        { return payRate; }
};

class ShiftSupervisor: public Employee
{
private:
    int aSalary;
    int yBonus;
public:
    ShiftSupervisor()
    { aSalary = 0, yBonus = 0; 
    cout << "Derived ShiftSupervisor constructor " << endl; }
    ShiftSupervisor(int a, int y)
    { aSalary = a, yBonus = y; 
    cout << "Derived ShiftSupervisor constructor " << endl; }
    ~ShiftSupervisor()
    { cout << "Derived ShiftSupervisor destructor " << endl; }
    int getASalary() const
    { return aSalary; }
    int getYBnous() const
    { return yBonus; }
};

class TeamLeader: public ProductionWorker
{
    private:
        int mBonus;
        int training;
        int trainingD;
    public:
        TeamLeader()
        { mBonus = 0, training = 0; trainingD = 0; 
        cout << "Derived TeamLeader constructor " << endl; }
        TeamLeader(int m, int t, int d)
        { mBonus = m, training = t, trainingD = d; 
        cout << "Derived TeamLeader constructor " << endl; }
        ~TeamLeader()
        { cout << "Derived TeamLeader destructor " << endl; }
        void setMBonus(int m)
        { mBonus = m; }
        void setTraining(int t)
        { training = t; }
        void setTrainingD(int d)
        { trainingD = d; }
        int getMBonus() const
        { return mBonus; }
        int getTraining() const
        { return training; }
        int getTrainingD() const
        { return trainingD; }
};

class Time
{
    protected:
        int hour;
        int min;
        int sec;
    public:
        Time()
        { hour = 0, min = 0, sec = 0; 
        cout << "Base class Time constructor " << endl; }
        Time(int h, int m, int s)
        { hour = h, min = m, sec = s; 
        cout << "Base class Time constructor " << endl; }
        ~Time()
        { cout << "Base class Time destructor " << endl; }
        void setHour(int h)
        { hour = h; }
        void setMin(int m)
        { min = m; }
        void setSec(int s)
        { sec = s; }
        int getHour() const
        { return hour; }
        int getMin() const
        { return min; }
        int getSec() const
        { return sec; }
};

class MilTime: public Time
{
    protected:
        int milHours;
        int milSeconds;
    public:
        MilTime()
        { milHours = 0, milSeconds = 0; }
        MilTime(int, int);
        void setTime(int, int);
        void getMHour() const;
        void getStandHr() const;
};

class TimeClock: public MilTime
{
private:
    int resultH;
    int resultM;
public:
    TimeClock()
    { resultH = 0, resultM = 0; }
    TimeClock(int, int);
    void setResult(int, int);
    int getResultH() const
    { return resultH; }
    int getResultM() const 
    { return resultM; }
};
#endif	/* CLASSES_H */

