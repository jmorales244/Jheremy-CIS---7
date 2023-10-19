/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on May 10, 2023, 2:49 PM
 */

#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>

using namespace std;

void generateCodeAI(string &code);
void testAllGuesses(string code);
bool checkDuplicate(string input);
void generateCodeGame(int code[], int codeLength, bool allowDuplicates = false); 
void countPegs(int code[], int guess[], int codeLength, int &redPegs, int &whitePegs);

int main(int argc, char** argv) {
    string code;
    generateCodeAI(code);

    cout << "Welcome to Project 1a: Mastermind Modified.\nPlease select an option:\n1. Mastermind User\n2. Mastermind CPU\n>";
    int choice;
    cin >> choice;

    if (choice == 1) {
        int codeLength;
        bool allowDuplicates;
        string duplicateInput;
        
        cout << "Enter the length of the code (4, 6, or 8): ";
        cin >> codeLength;
        if (codeLength != 4 && codeLength != 6 && codeLength != 8) {
            cout << "Invalid code length. Please enter 4, 6, or 8." << endl;
            return 0;
        }
        cout << "Allow duplicates? [Type Yes or No] \n>";
        cin >> duplicateInput;

        allowDuplicates = checkDuplicate(duplicateInput);
    
        int code[codeLength];
        generateCodeGame(code, codeLength, allowDuplicates);
    
        cout << "Welcome to Mastermind!" << endl;
        cout << "Guess the " << codeLength << "-digit code using the numbers 1-8." << endl;
        cout << "Duplicates " << (allowDuplicates ? "allowed." : "not allowed.") << endl;
    
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
    
        if (guesses == 10) {
            cout << "You ran out of guesses! The code was ";
            for (int i = 0; i < codeLength; i++) {
            cout << code[i] << " ";
            }
            cout << endl;
        }
    } else if (choice == 2) {
        testAllGuesses(code);
    } else {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
        return 0;
    }

    return 0;
}


void generateCodeAI(string &code) {
    srand(time(NULL));
    int codeInt = rand() % 10000;
    stringstream ss;
    ss << setw(4) << setfill('0') << codeInt;
    code = ss.str();
}
void testAllGuesses(string code) {
    cout << "Code\tGuess\t#right\t#right in wrong spot\tSum" << endl;
    for (int i = 0; i < 10000; i++) {
        stringstream ss;
        ss << setw(4) << setfill('0') << i;
        string guess = ss.str();

        int right = 0;
        int rightInWrongSpot = 0;
        for (int j = 0; j < 4; j++) {
            if (code[j] == guess[j]) {
                right++;
            } else if (code.find(guess[j]) != string::npos) {
                rightInWrongSpot++;
            }
        }
        int sum = right + rightInWrongSpot;

        cout << code << "\t" << guess << "\t" << right << "\t" << rightInWrongSpot << "\t" << sum << endl;
    }
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
void generateCodeGame(int code[], int codeLength, bool allowDuplicates) {
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

