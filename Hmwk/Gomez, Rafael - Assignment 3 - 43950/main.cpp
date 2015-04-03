/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 *
 * Created on March 18, 2015, 3:48 PM
 */

//System libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//function prototypes
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

//execution starts
int main(int argc, char** argv) {
    string again;
    //loop in order to run and try a different problem
    //uses string input from user and checks if yes 
    do
    {
        int num;
        cout << "Enter which problem you want to see. " << endl;
        cout << "problem 1 is 10.4, "
                "problem 2 is 10.6, "
                "problem 3 is  11.9, "
                "problem 4 is 12.7, "
                "problem 5 is 12.8, " << endl;
        cout << "problem 6 is 12.11, ";
        cout << "problem 7 is 12.10, "
                "problem 8 is 11.1, "
                "problem 9 is 11.2, "
                "problem 10 is 10.2 " << endl;
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
        cout << endl;
        cout << "If you want to run the program again to check another"
                << " problem, type yes " << endl;
        cin >> again;
    }while(tolower(again[0] == 'y'));
    return 0;
}

void prblm1()
{
    cout << "Problem 10.4 " << endl;
    cout << "What is the output of cout << toupper(tolower('A'))? " << endl;
    cout << "Well tolower('A') will get the ascii representation of " 
            << "little a but then toupper turns it back to big A " << endl;
    cout << "which would output the ascii representation of big A" << endl;
}

void prblm2()
{
    cout << "Problem 10.6 " << endl;
    cout << "Write short description " << endl;
    cout << "strlen: Helps find the length of the string" << endl;;
    cout << "strcat: Takes two char arrays and appends them to each other"
            << endl;
    cout << "strcpy: Copies one string to another string " << endl;
    cout << "strncat: Same as strcat but has a third argumetn to only "
            << "allow a certain amount of characters to pass" << endl;
    cout << "strncpy: Same as strcpy but has a third argument that "
            << "allows you to only copy a certain amount you want " << endl;
    cout << "strcmp: compares two strings and returns either 0 "
            << "a positive, number or a negative number " << endl;
    cout << "strstr: Will search for a string inside a string " << endl;
}

void prblm3()
{
    cout << "Problem 11.9 " << endl;
    cout << "struct Measurement " << endl
            << "{ " << endl
            << "     int miles; " << endl
            << "     long int meters; " << endl
            << "}; " << endl;
    cout << "struct Destination " << endl
            << "{ " << endl
            << "     char city[35]; " << endl
            << "     Measurement distance; " << endl
            << "}; " << endl;
    cout << "Destination where; " << endl;
}

void prblm4()
{
    cout << "Problem 12.7 " << endl;
    cout << "input.txt contains " << endl
            << "Run Spot run " << endl
            << "See Spot run " << endl;
    cout << "What will the program display " << endl;
    cout << "const int SIZE = 81; " << endl
            << "fstream inFile('input.txt', ios::in);" << endl
            << "char item[SIZE];" << endl
            << "inFile >> item;" << endl
            << "while(!inFile.eof())" << endl
            << "{ " << endl
            << "     cout << item << endl; " << endl
            << "     inFile >> iten; " << endl
            << "}" << endl
            << "inFile.close(); " << endl;
    cout << "The program will display: " 
            << "RunSpotrunSeeSpotrun" << endl;
}

void prblm5()
{
    cout << "Problem 12.8 " << endl;
    cout << "Describe difference between reading a file with >> and getline "
            << endl;
    cout << "Answer: the >> operator does not read spaces because it counts "
            << "them as a delimiter, whereas getline does not " << endl;
}

void prblm6()
{
    cout << "Problem 12.11 " << endl;
    cout << "Describe difference between tellp and tellg " << endl;
    cout << "Answer: tellp and tellg both return the current byte of where "
            << "you are in the file, the difference being in that "
            << "tellp returns the byte form where you were writing to " 
            << "and tellg returns the byte from where you were reading "
            << endl;
}

void prblm7()
{
    cout << "Problem 12.10 " << endl;
    cout << "Describe the difference between seekg and seekp " << endl;
    cout << "Answer: seekg and seekp are both used to seek a certain "
            << "position in the file and the difference is that "
            << "seekp is to seek the position of where to put information "
            << "and seekg is to seek the position of where to get information"
            << endl;
}

void prblm8()
{
    cout << "Problem 11.1 " << endl;
    cout << "Write structure declaration " << endl;
    cout << "struct SavAcnt" << endl
            << "{ " << endl
            << "     char accNum[15]; " << endl
            << "     double accBlnc; " << endl
            << "     double itrsRt; " << endl
            << "     double avgMnBl " << endl
            << "}; " << endl;
}

void prblm9()
{
    cout << "Problem 11.2 " << endl;
    cout << "Write definition statement for a variable from problem"
            << " 11.1 " << endl;
    cout << "SavAcnt Jay = {'ACZ42137-B12-7', 4512.59, 4, 4217.07}" << endl;
}

void prblm10()
{
    cout << "Problem 10.2 " << endl;
    cout << "convert char variable big to lowercase " << endl;
    cout << "char little = 'A';" << endl;
    cout << "cout << static_cast<char>(tolower(little)); " << endl;
}

