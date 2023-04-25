/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on April 22, 2023, 10:16 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>

using namespace std;

enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    BROWN,
    ORANGE,
    BLACK,
    WHITE
};

string getRandomColors(int numColors, bool allowDuplicates = false) {
    srand(time(NULL)); // seed the random number generator with current time
    string colors = "";
    set<int> usedColors;

    for(int i = 0; i < numColors; i++) {
        int randomNum;
        do {
            randomNum = rand() % 8; // generate a random integer between 0 and 7
        } while (!allowDuplicates && usedColors.count(randomNum) > 0);
        
        usedColors.insert(randomNum);
        
        switch(randomNum) {
            case 0:
                colors += "red ";
                break;
            case 1:
                colors += "green ";
                break;
            case 2:
                colors += "blue ";
                break;
            case 3:
                colors += "yellow ";
                break;
            case 4:
                colors += "brown ";
                break;
            case 5:
                colors += "orange ";
                break;
            case 6:
                colors += "black ";
                break;
            case 7:
                colors += "white ";
                break;
        }
    }

    return colors;
}

int main() {
    
    int input;
    
    cout << "How long would you like your code to be? (OPTIONS: 4, 6, 8) >";
    cin >> input;
    
    bool isDuplicate;
    cout << "Would you like to have duplicates (1 OR 0): ";
    cin >> isDuplicate;
    
    string randomColors = getRandomColors(input, isDuplicate); // generate a string of 5 random colors
    if(input == 4 || input == 6 || input == 8){
        cout << "ANSWER: " << randomColors << endl;
    }
    else{
        cout << "INVALID OPTION PLEASE TRY AGAIN";
    }

    return 0;
}

