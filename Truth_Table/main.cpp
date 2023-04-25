/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy Morales
 * Created on:
 * Purpose:  To tell the Truth
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
    
    bool x,y;
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^Z X^Y^Y !(X&&Y) !X||!Y !(X||Y) !X&&!Y\n";
    while(cin>>x>>y){  
    
        truthTable(x,y);
       
    }
    cout << endl;
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

