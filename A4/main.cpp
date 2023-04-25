/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy Morales
 * Created on March 6, 2023
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX], int, int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
int strcmp(char[], char[], const char[], const char[]);	//Replace sort order


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //sort(array,rowIn,colIn, replace, with);
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}


int read(char input_array[][COLMAX], int &rows)
{
    // Define a variable to store
    // the maximum column length
    // among the input strings.
    int cols = 0;
    // Read the strings
    // from the input.
    for (int i = 0; i < rows; i++){
    // If the length of the current
    // string is greater than the
    // current value of cols,
    // set the length of the current
    // string as the value of cols.
        cin >> input_array[i];
        if (strlen (input_array[i]) > cols){
            cols = strlen (input_array[i]);
        }
    }
    // Return the value of cols.
      return cols;
}

// Define the sort() function.
void sort(char array_to_sort[][COLMAX], int rows, int cols)
{
    // Define a temporary
    // array to sort 2 characters.
    char *temp = new char[cols];
    // Run the loop to
    // sort the strings.
    for (int i = 0; i < rows - 1; i++){
        for (int j = i + 1; j < rows; j++){
            // Use the strcmp() function
            // defined below, to sort the
            // strings based on the new ordering.
    	    if (strcmp (array_to_sort[i], array_to_sort[j]) > 0){
    	      strcpy (temp, array_to_sort[i]);
    	      strcpy (array_to_sort[i], array_to_sort[j]);
    	      strcpy (array_to_sort[j], temp);
            }
    	}
    }
}

// Define the print() function.
void print(const char array_to_print[][COLMAX], int rows, int cols){
    // Run the loop to print the array.
    for (int i = 0; i < rows; i++){
        // Display the current string.
        cout << array_to_print[i] << endl;
    }
}

// Define the strcmp() function.
int strcmp(char string1[], char string2[])
{
    // Define two strings.
      char *copystring1;
      char *copystring2;
      copystring1 = new char[strlen (string1) + 1];
      copystring2 = new char[strlen (string2) + 1];

    // Copy the strings to be compared
    // into two newly defined strings.
    for (int i = 0; i < strlen (string1); i++){
      copystring1[i] = string1[i];
    }
    
    copystring1[strlen (string1)] = '\0';
    
    for (int i = 0; i < strlen (string2); i++){
        copystring2[i] = string2[i];
    }
    
    copystring2[strlen (string2)] = '\0';
    
    return strcmp (copystring1, copystring2);
}
