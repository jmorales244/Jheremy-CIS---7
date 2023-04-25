/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 */

#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()

using namespace std;

const int COLMAX=80;//Only 20 required, and 1 for null terminator

int read(char [][COLMAX],int &);
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
int strcmp(char [],char [],const char [],const char []);//Replace sort order

int main(int argc, char** argv) {

    const int ROW=30;
    char array[ROW][COLMAX];
    int colIn,colDet,rowIn,rowDet;
    char replace[COLMAX],with[COLMAX];

    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;

    cout<<"With the following characters"<<endl;
    cin>>with;

    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;

    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;

    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;

    rowDet=rowIn;

    cout<<"Now input the array."<<endl;

    colDet=read(array,rowDet);
    sort(array,rowIn,colIn,replace,with);

    cout<<"The Sorted Array"<<endl;

    print(array,rowIn,colIn);

    return 0;

}

// Define the read function().

int read(char input_array[][COLMAX],int &rows){

    // Define a variable to store
    // the maximum column length
    // among the input strings.
    int cols = 0;

    // Read the strings
    // from the input.
    for(int i=0; i<rows; i++){
        cin >> input_array[i];

        // If the length of the current
        // string is greater than the
        // current value of cols,
        // set the length of the current
        // string as the value of cols.
        if(strlen(input_array[i])>cols)
        {
            cols = strlen(input_array[i]);
        }
    }

    // Return the value of cols.
    return cols;

}

// Define the sort() function.

void sort(char array_to_sort[][COLMAX],int rows,int cols,const char replace[],const char with[]){

    // Define a temporary
    // array to sort 2 characters.

    char * temp = new char[cols];
    // Run the loop to
    // sort the strings.

    for(int i=0; i<rows-1; i++){
        for(int j=i+1; j<rows; j++){

        // Use the strcmp() function
        // defined below, to sort the
        // strings based on the new ordering.

        if(strcmp(array_to_sort[i], array_to_sort[j], replace, with) > 0){
                strcpy(temp, array_to_sort[i]);
                strcpy(array_to_sort[i], array_to_sort[j]);
                strcpy(array_to_sort[j], temp);
            }
        }
    }
}

//Define the print() function.

void print(const char array_to_print[][COLMAX],int rows,int cols){
    // Run the loop to print the array.
    for(int i=0; i<rows; i++){
        // Display the current string.
        cout << array_to_print[i] << endl;
    }
}

// Define the strcmp() function.

int strcmp(char string1[],char string2[],const char replace[],const char with[]){

    // Define two strings.
    char *copystring1;
    char *copystring2;

    copystring1 = new char[strlen(string1)+1];
    copystring2 = new char[strlen(string2) + 1];

    // Copy the strings to be compared
    // into two newly defined strings.
    for(int i=0; i<strlen(string1); i++){
        copystring1[i] = string1[i];
    }

    copystring1[strlen(string1)] = '\0';

    for(int i=0; i<strlen(string2); i++){
        copystring2[i] = string2[i];
    }

    copystring2[strlen(string2)] = '\0';

    // Replace the characters in the
    // newly formed strings as per
    // the sort order.
    for(int j=0; j<strlen(replace); j++){
        for(int i=0; i<strlen(string1); i++){
            if(string1[i] == replace[j]){
                copystring1[i] = with[j];
            }
        }

        for(int i=0; i<strlen(string2); i++){
            if(string2[i] == replace[j])
            {
                copystring2[i] = with[j];
            }
        }
    }

    // Compare the strings and
    // return the obtained value.
    return strcmp(copystring1, copystring2);
}
