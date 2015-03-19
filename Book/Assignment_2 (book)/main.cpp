/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on March 18, 2015, 5:35 PM
 */

#include <cstdlib>
#include <iostream>
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
        cout << "enter which problem you want to see 1-5 ";
        cin >> num;
        switch(num)
        {
            case 1: prblm1();
            break;
            case 2: prblm2();
            break;
            case 3: prblm3();
            break;
            case 4: prblm4();
            break;
            case 5: prblm5();
            break;
            default: cout << "Invalid number" << endl;
        }
        cout << "If you want to run again type yes ";
        cin >> again;
    }while(tolower(again[0] == 'y'));
    return 0;
}

void prblm1()
{
    int num;
    cout << "Enter a number ";
    cin >> num;
    cout << "The address of that number is: " << (&num) << endl;
}

void prblm2()
{
    cout << "this problem asks me to write a pointer definition " << endl
    << "float x = 2.5; " << endl
    << "float *fltPtr; " << endl
    << "fltPtr = &x; " << endl
    << "cout << x << endl; " << endl
    << "cout << fltPtr << endl; " << endl;
}

void prblm3()
{
    cout << "Rewrite the following using pointer notation " << endl;
    cout << "for(int i = 0; i < 100; i++)" << endl
            << "cout << arr[x] << endl; " << endl;
    cout << "Answer: " << endl;
    cout << "for(int i = 0; i < 100; i++)" << endl
            << "cout << *(arry + i) << endl; " << endl;
}

void prblm4()
{
    cout << "Assume ptr is pointer to int and holds address 12000 " 
            << ". On a system with 4-byte integers. What address "
            << "will be in ptr after ptr += 10 " << endl;
    cout << "Answer: 12040 becuase i have to add 4 bytes 10 times " << endl;
}

void prblm5()
{
    cout << "Which of these is valide, of those who arent " 
            << "why arent they " << endl;
    cout << "pint is a pointer variable " << endl;
    cout << "pint++ " << endl
            << "--pint" << endl
            << "pint /= 2" << endl
            << "pint *= 4" << endl
            << "pint += x" << endl;
    cout << "Answer: You can add and subtract pointers, but you cant "
            << "divide and multiply them, therefore 3 and 4 arent possible "
            << endl;
}