/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on April 23, 2023, 2:21 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>

using namespace std;

bool checkDuplicate(string input);

void generateCode(int code[], int codeLength, bool allowDuplicates = false);

void countPegs(int code[], int guess[], int codeLength, int &redPegs, int &whitePegs);



int main(int argc, char** argv) {
    
    int codeLength;
    bool allowDuplicates;
    string duplicateInput;
    cout << "\t***SETTINGS***\nEnter the length of the code (4, 6, or 8) \n>";
    cin >> codeLength;
    if (codeLength != 4 && codeLength != 6 && codeLength != 8) {
        cout << "Invalid code length. Please enter 4, 6, or 8." << endl;
        return 0;
    }
    cout << "Allow duplicates? [Type Yes or No] \n>";
    cin >> duplicateInput;
    
    allowDuplicates = checkDuplicate(duplicateInput);
    
    
    int code[codeLength];
    generateCode(code, codeLength, allowDuplicates);

    cout << "\n\nWelcome to Mastermind!" << endl;
    cout << "Guess the " << codeLength << "-digit code using the numbers 1-8." << endl;
    cout << "Where duplicates are " << (allowDuplicates ? "allowed." : "not allowed.") << endl;

    int guesses = 0;
    
    while (guesses < 10) {
        guesses++;
        int guess[codeLength];
        cout << "Guess #" << guesses << ": ";
        for (int i = 0; i < codeLength; i++) {
            cin >> guess[i];
        }

        int redPegs, whitePegs;
        countPegs(code, guess, codeLength, redPegs, whitePegs);

        if (redPegs == codeLength) {
            cout << "Congratulations! You guessed the code in " << guesses << " guesses." << endl;
            break;
        } else {
            cout << "Red pegs: " << redPegs << ", white pegs: " << whitePegs << endl;
        }
    }
    
    if (guesses == 10){
        cout << "You ran out guesses! The code was "; 
        for (int i = 0; i < codeLength; i++){
            cout << code[i] << " ";
        }
    }
    
    return 0;
}

bool checkDuplicate(string input){
    bool x;
    if(tolower(input[0]) == 'y')
        x = true;
        else if(tolower(input[0]) == 'n')
            x = false;
            else{
                cout << "INVALID INPUT" << endl;
                return 0;
            }
    return x;
}

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

void countPegs(int code[], int guess[], int codeLength, int &redPegs, int &whitePegs) {
    redPegs = 0;
    whitePegs = 0;

    // Count red pegs
    for (int i = 0; i < codeLength; i++) {
        if (code[i] == guess[i]) {
            redPegs++;
        }
    }

    // Count white pegs
    for (int i = 1; i <= 8; i++) {
        int codeCount = count(code, code + codeLength, i);
        int guessCount = count(guess, guess + codeLength, i);
        whitePegs += min(codeCount, guessCount);
    }
    whitePegs -= redPegs;
}

