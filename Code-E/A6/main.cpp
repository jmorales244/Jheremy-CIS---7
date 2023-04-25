/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on March 26, 2023, 11:22 PM
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on March 26, 2023, 11:22 PM
 */

#include <iostream>//cin,cout
#include <vector> //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;
//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv){
    const int ROW=80; 
    int array[ROW][COLMAX]; //an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); 

    read(even,odd);

    prntVec(even,odd,10);

    copy(even,odd,array);

    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors

    return 0;
}

//definition of the function read
void read(vector<int> &even, vector<int> &odd){
    int n,temp; // declaring variables to read size of input and the input itself
    
    cout<<"Input the number of integers to input."<<endl; // asking for input size
    cin>>n; // input the input size
    cout<<"Input each number."<<endl; // asking the inputs
    
    for(int i=0;i<n;i++){ //for loop till the input size to get all inputs
        cin>>temp; // taking the input
        if(temp%2==0){ // checking if input is even
            even.push_back(temp); // putting input in even vector if it is even
        }
        else{ // else the input is odd
            odd.push_back(temp); // putting input in odd vector if it is odd
        }
    }
}

void prntVec(vector<int> even, vector<int> odd,int width){
    int size_even=even.size(), size_odd=odd.size(), i=0, j=0; 
    cout<<setw(width)<<"Vector"<<setw(width)<<"Even"<<setw(width)<<"Odd"<<endl; 
    
    while(i<size_even && j<size_odd){ 
        cout<<setw(width*2)<<even[i]<<setw(width)<<odd[j]<<endl;
        i++; 
        j++; 
    }
    
    while(i<size_even){ 
        cout<<setw(width*2)<<even[i]<<endl; 
        i++; 
    }
    
    while(j<size_odd){ 
        cout<<setw(width*3)<<odd[j]<<endl; 
        j++; 
    }
}


void copy(vector<int> even, vector<int> odd,int arr[][COLMAX]){
    int size_even=even.size(),size_odd=odd.size(),i=0,j=0; // all variables with initialization of counters i and j to 0
    while(i<size_even){ //even counter fill even vector size
        arr[i][0]=even[i]; //copying even values from vector to first column of array
        i++; 
    }
    
    while(j<size_odd){
        arr[j][1]=odd[j]; 
        j++; 
    }
}

void prntAry(const int arr[][COLMAX],int size_even,int size_odd,int width){
    int i=0,j=0;
    cout<<setw(width) << "Array" << setw(width) << "Even" << setw(width) << "Odd" << endl; // output the heading
    
    while(i<size_even && j<size_odd){ // while counters reach either all odd values or all even values
        cout<<setw(width*2)<<arr[i][0]<<setw(width)<<arr[j][1]<<endl; // output even and odd value
        i++; 
        j++; 
    }
    
    while(i<size_even){ // if even vector is large than odd vector then some even values will be remaining and to check that
        cout<<setw(width*2)<<arr[i][0]<<endl; 
        i++; 
    }
    
    while(j<size_odd){ 
        cout<<setw(width*3)<<arr[j][1]<<endl; 
        j++; 
    }
}
