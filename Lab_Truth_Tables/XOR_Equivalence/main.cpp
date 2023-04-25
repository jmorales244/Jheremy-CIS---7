/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on March 8, 2023, 9:36 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //We must prove that (p&&q)||~(p||q) = !(p^q) and (p||q)&&~(p&&q)=p^q
    bool p, q;
    cout << "Enter values for p and q (0 or 1): ";
    cin >> p >> q;

    bool case1_1 = (p && q) || !(p || q);
    bool case1_2 = !(p && q);
    cout << "(p && q) || !(p || q) =" << case1_1 << endl;
    cout << "! (p && q) = " << case1_2 << endl;
    
    bool case2_1 = (p || q) && !(p && q);
    bool case2_2 = (p || q);
    cout << endl << "(p || q) && ~(p && q) =" << case1_1 << endl;
    cout << " (p && q) = " << case1_2 << endl;
    
    if(case1_1 == case1_2 || case2_1 == case2_2){
        cout << "The logic is true." << endl;
    }
    else {
        cout << "The logic is false." << endl;
    }
    return 0;
}

