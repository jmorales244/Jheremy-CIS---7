/* 
 * File:   main.cpp
 * Author: Jheremy
 *
 * Created on March 8, 2023, 6:06 PM
 */

#include <iostream>
#include <string>
using namespace std;

bool isValidCreditCard(string number) {
    int sum = 0;
    int length = number.length();
    int parity = length % 2;
    for (int i = length - 1; i >= 0; i--) {
        int digit = number[i] - '0';
        if (i % 2 == parity) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
    }
    return (sum % 10 == 0);
}

int solveForLastDigit(string number) {
    int length = number.length();
    int parity = length % 2;
    int sum = 0;
    for (int i = length - 1; i >= 0; i--) {
        int digit = number[i] - '0';
        if (i % 2 == parity) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
    }
    int missingdigit = 0;
    while ((sum + missingdigit) % 10 != 0) {
        missingdigit++;
    }
    return missingdigit;
}

int main() {
    string creditcardnumber;
    cout << "Enter credit card number: ";
    cin >> creditcardnumber;

    if (isValidCreditCard(creditcardnumber)) {
        cout << "Credit card number is valid." << endl;
    } else {
        int missingdigit = solveForLastDigit(creditcardnumber);
        cout << "Missing digit is: " << missingdigit << endl;
        cout << "Valid credit card number is: " << creditcardnumber << missingdigit << endl;
    }

    return 0;
}