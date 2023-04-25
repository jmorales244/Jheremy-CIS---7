/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy Morales
 * Created on March 1, 2023
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>     //system libraries are included here
#include <cstring>
using namespace std;

int read(char s[])      //function to read the array of characters
{   
    int size;       //variable to store the size of array
    cin >> size;    //reads the size
    cin >> s;       //reads the input array of characters into s
    return size;    //size is returned
}
void sort(char s[], int size)   //function to sort the array s
{
    //here we can use bubble sort to sort the array of characters
    for (int i = 0; i < size - 1; i++)  //loop repeats for size-1 no.of times
        for (int j = 0; j < size - i - 1; j++)   // the last i elements are already in correct places
            if (s[j] > s[j + 1])    //if s[j] greater than s[j+1]
            {
                char temp = s[j];   //s[j] is copied into temp
                s[j] = s[j+1];      //s[j] is changed to s[j+1]
                s[j+1] = temp;      //s[j+1] is changed to temp
            }
}
void print(const char s[], int size)    //function to print the array
{
    for(int i = 0; i < size; i++)       //loop through each character in the array s
        cout << s[i];       //displays s[i] to the screen
}
int main()      //main function
{
    char s[20];     //declares an array of characters of size 20
    int size = read(s);     //calls read function and returned value is taken into size
    cout << "Read in a 1 dimensional array of characters and sort" << endl;
    cout << "Input the array size where size <= 20" << endl << "Now read the Array\n";
    if(size < strlen(s))    //if size is less than length of s
        cout << "Input size greater than specified.\n";   //larger is printed
    else if(size > strlen(s))   //else if size is greater than length of s
        cout << "Input size smaller than specified";      //smaller is printed
    else        //else
    {
        sort(s, size);  //calls sort function to sort the array
        print(s, size); //calls print function to sort the array
        cout << endl;
    }
}
