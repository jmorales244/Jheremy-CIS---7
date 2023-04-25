/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on March 8, 2023, 9:56 PM
 */

#include <iostream>

using namespace std;

void truthTable(bool x, bool y);
/*
 * 
 */
int main(int argc, char** argv) {
    
    bool p, q;
    cout << "Enter values for p and q (0 or 1): ";
    cin >> p >> q;
    
    cout<<"p q ~p ~q p&&q p||q p^q p^q^q p^q^p !(p&&q) !p||!q !(p||q) !p^!q"<<endl;
    truthTable(p, q);
    
    return 0;
}

void truthTable(bool x, bool y){
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
        <<(!x||!y? 'T':'F')<<"       "
        <<(!(x||y)? 'T':'F')<<"     "
        <<(!x&&!y? 'T':'F')
        <<endl;
}