/* 
 * File:   main.cpp
 * Author: Rafael Gomez
 *
 * Created on March 18, 2015, 3:34 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

float mean(int [], int);
float median(int [], int);
int *mode(int [], int);
void bubble(int [], int);
void fillA(int [], int);
int sizeA(int [], int);

int main(int argc, char** argv) {
    srand(time(0));
    int size;
    cout << "Enter the number you want the size of the array to be ";
    cin >> size;
    int arry[size];
    fillA(arry, size);
    cout << "The array is filled with random one digit numbers "
            << "and it looks like this " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl;
    bubble(arry, size);
    cout << "The array is now sorted and looks like this " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl;
    cout << "The mean of the array is: ";
    cout << mean(arry, size) << endl;
    cout << "The median of the array is: ";
    cout << median(arry, size) << endl;
    int newSize = sizeA(arry, size);
    int *arry2 = mode(arry, size);
    cout << "The mode is done in a dynamic array, where the first position "
            << "is the mode, the second position is the frequency, and "
            << "the last positions are which numbers are the mode " << endl;
    for(int i = 0; i < newSize + 2; i++)
    {
        cout << arry2[i] << " ";
    }
    delete []arry2;
    return 0;
}

void fillA(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        a[i] = rand()%9+1;
    }
}

void bubble(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}

float mean(int a[], int size)
{
    float avrg;
    for(int i = 0; i < size; i++)
    {
        avrg += a[i];
    }
    avrg /= size;
    return avrg;
}

float median(int a[], int size)
{
    float middle = 0;
    if(size % 2 == 0)
    {
        middle = (a[(size/2)-1] + a[size/2]); 
        return middle / 2;
    }
    else
    {
        middle = a[size/2];
        return middle;
    }
}

int *mode(int arry[], int size)
{
    //countmax is for the frequency
    //count is to find the frequency
    //count2 is to find the number of modes
    //loc if for the location of the mode
    int count = 1, countmax = 1, loc = 0, count2 = 0;
    //this for loop is to find the mode
    for(int i = 0; i < size; i++)
    {
        if(arry[i] == arry[i+1])
        {
            count++;
            if(count >= countmax)
            {
                countmax = count;
            }
        }
        else if(arry[i] != arry[i+1])
        {
            count = 1;
        }
    }
    count = 1;
    //this for loop is to find how many modes
    for(int i = 0; i < size; i++)
    {
        if(arry[i] == arry[i+1])
        {
            count++;
            if(count == countmax)
            {
                count2++;
            }
        }
        else
        {
            count = 1;
        }
    }
    //arry2 is the dynamic array and the size is 2 plus all the mode numbers
    int *arry2 = new int[2+count2];
    arry2[0] = countmax;
    arry2[1] = count2;
    int countarry = 0;
    //this for loop is to find the location of the modes
    for(int i = 0; i < size; i++)
    {
        if(arry[i] == arry[i+1])
        {
            count++;
            if(count == countmax)
            {
                loc = arry[i];
                arry2[countarry+2] = loc;
                countarry++;
            }
        }
        else
        {
            count = 1;
        }
    }
    return arry2;
}

int sizeA(int arry[], int size)
{
    int count = 1, countmax = 1, count2 = 0;
    for(int i = 0; i < size; i++)
    {
        if(arry[i] == arry[i+1])
        {
            count++;
            if(count >= countmax)
            {
                countmax = count;
            }
        }
        else if(arry[i] != arry[i+1])
        {
            count = 1;
        }
    }
    count = 1;
    for(int i = 0; i < size; i++)
    {
        if(arry[i] == arry[i+1])
        {
            count++;
            if(count == countmax)
            {
                count2++;
            }
        }
        else
        {
            count = 1;
        }
    }
    return count2;
}
