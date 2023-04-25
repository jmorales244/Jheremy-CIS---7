/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on April 23, 2023, 12:04 AM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

// Function to generate a random combination of four colors
void generateCode(int code[], int codeLength, bool allowDuplicates = false) {
    int colors[] = {1, 2, 3, 4, 5, 6, 7, 8};
    srand(time(NULL));
    set<int> usedColors;

    for (int i = 0; i < codeLength; i++) {
        int index;
        if (allowDuplicates) {
            index = rand() % 8;
        } else {
            do {
                index = rand() % 8;
            } while (usedColors.count(index) > 0);
            usedColors.insert(index);
        }
        code[i] = colors[index];
    }
}



// Function to get the user's guess
void getGuess(int guess[], int codeLength)
{
    cout << "Enter your guess : ";
    for (int i = 0; i < codeLength; i++) {
        cin >> guess[i];
    }
}

// Function to check the user's guess and return the number of red and white pegs
void checkGuess(int code[], int guess[], int length, int &redPegs, int &whitePegs)
{
    redPegs = 0;
    whitePegs = 0;
    int codeCount[6] = {0};
    int guessCount[6] = {0};
    for (int i = 0; i < length; i++) {
        if (guess[i] == code[i]) {
            redPegs++;
        } else {
            codeCount[code[i] - 1]++;
            guessCount[guess[i] - 1]++;
        }
    }
    for (int i = 0; i < 8; i++) {
        whitePegs += min(codeCount[i], guessCount[i]);
    }
}

bool checkDuplicate(string input){
    bool x;
    if(tolower(input[0]) == 't')
        x = true;
        else if(tolower(input[0]) == 'f')
            x = false;
            else{
                cout << "INVALID INPUT" << endl;
                return 0;
            }
    return x;
}

int main(int argc, char** argv)
{
    
    
    cout << "Welcome to Mastermind!\n";
    
    cout << "How long would you like your code to be? (OPTIONS: 4, 6, 8) >";
    int codeSize;
    cin >> codeSize;
    
    cout << "Would you like duplicates in your code? >"; 
   
    string duplicate;
    cin >> duplicate;
    bool check = checkDuplicate(duplicate);
    cout << "DEBUG: " << check << endl;
    
    int code[codeSize];
    generateCode(code, check);
    int guesses = 0;
    int redPegs, whitePegs;
    
    cout << "You have 10 guesses to crack the code.\n";
    while (guesses < 10) {
        int guess[codeSize];
        getGuess(guess, codeSize);
        checkGuess(code, guess, codeSize, redPegs, whitePegs);
        if (redPegs == codeSize) {
            cout << "Congratulations! You guessed the code in " << guesses + 1 << " guesses.\n";
            return 0;
        } else {
            cout << "Red pegs: " << redPegs << ", \nWhite pegs: " << whitePegs << endl;
            guesses++;
        }
    }
    cout << "Sorry, you did not guess the code in 10 guesses.\n";
    //cout << "The code was " << code[0] << code[1] << code[2] << code[3] << endl;
    return 0;
}