/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on April 7, 2023, 11:25 PM
 */
//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
#include <cmath>      //Math Library
#include <iomanip>    //Format Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);

//Functions you are to write and use to show the Theorem
float logAM(int [],int);//Log of the Arithmetic Mean
float logGM(int [],int);//Log of the Geometric Mean

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    const int SIZE=1000;
    int array[SIZE];
    int perLine=40;
    
    //Initialize variables here
    for(int i=10;i<=SIZE;i*=10){
        fillAry(array,i);
    
        //Display the results
        prntAry(array,i,perLine);
    
        //Map inputs to outputs here, i.e. the process
        cout<<fixed<<setprecision(6)<<showpoint<<endl;
        cout<<i<<" elements [10,99]"<<endl;
        cout<<"Log(Average) = "<<exp(logAM(array,i))<<" >= ";
        cout<<"Average Logsum() = "<<exp(logGM(array,i))<<endl;
    }

    return 0;
}

float logAM(int a[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    float mean = (sum)/n; 
    float logMean = log(mean);
    
    return logMean;
}

float logGM(int a[],int n){
    float product = 0.0;
    for (int i = 0; i < n; i++) {
        product += log(a[i]);
    }
    float geometricMean = (product / n);
    return geometricMean;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    cout<<"Print array size = "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10,99]
    }
}