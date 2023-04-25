/* 
 * File:   main.cpp
 * Author: Jheremy Morales
 * Created on: 3/1/2023
 * Purpose:  To see how each operator affects a boolean variable
    PLEASE READ: Because how this is set up, I need to know before
    hand how many rows it is needed in order for the loop to know how
    many rows to create. I tried doing it how it is asked but I thought 
    that this would be a better solution. 
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void truthTable(bool x, bool y);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int input;
    cout << "How many would you like to input: ";
    cin >> input;
    
    int t[input][2];
    int c = 0;
    int m = input;
    //Based on the amount of inputs the user wants to place, it will save the input
    //inside of a 2D array, similar to a point plot
    while(input>0){
        cin >> t[c][0] >> t[c][1];
        c++; //counts the amount of true inputs
        input--; //for every input placed, decrease the input amount to stop the loop
    }
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    c = 0;
    while(m>0){
        truthTable(t[c][0], t[c][1]);
        cout << "\n";
        c++;
        m--;
    }
         
    //Exit
    return 0;
}


void truthTable(bool x, bool y){
    int i;
    cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"  "
        <<(!x?'T':'F')<<"  "
        <<(!y?'T':'F')<<"   "
        <<(x&&y?'T':'F')<<"    "
        <<(x||y?'T':'F')<<"   "
        <<(x^y? 'T':'F')<<"    "
        <<(x^y^x? 'T':'F')<<"     "
        <<(x^y^y? 'T':'F')<<"       "
        <<(!(x&&y)? 'T':'F')<<"      "
        <<(!x||!y? 'T':'F')<<"        "
        <<(!(x||y)? 'T':'F')<<"      "
        <<(!x&&!y? 'T':'F')
        <<endl;
}