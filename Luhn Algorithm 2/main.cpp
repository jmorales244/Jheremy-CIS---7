/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy Morales
 *
 * Created on March 21, 2023, 8:49 PM
 */


#include <iostream>
#include <stdlib.h>
using namespace std;
//enumeration for the credit type
enum Crdcredit{
    VISA,MASTER,AMERICAN_EXPRESS,DISCOVER
    }credits;

//We are creating credit number here
void genCC(Crdcredit credit,char * number){
    //HEre we will keep the number of digit of the card of its nature
    int actualNumber;

    //First example of card and its properties

    if(credit == MASTER){
        number[0] = '5';
        actualNumber=16;
    }
    else if(credit == DISCOVER){
        number[0] = '6';
        actualNumber=16;
    }
    else if(credit == VISA){
        number[0] = '4';
        actualNumber=16;
    }
    else if(credit == AMERICAN_EXPRESS){
        number[0] = '3';
        actualNumber=15;
    }
    
    int i;
    
    for(i=1;i<actualNumber;i++){
        //randoming generating number
        int num = rand()%10;
        number[i] = num+'0';
    }
    number[i]='\0';
}
//print the credit card
void printcredit(char * number){
    int index=0;
    while(number[index]!='\0'){
        cout<<number[index]<<"";
        index++;
    }
}
// checking the validity of card
bool validCC(char * number,Crdcredit credit){
    int nDigits;
    
    if(credit==VISA ||credit==MASTER||credit==DISCOVER ){
        nDigits=16;
    }
    else if(credit==AMERICAN_EXPRESS){
        nDigits=15;
    }
    
    int sumtotal = 0, isSecond = false;
    
    for (int i = nDigits - 1; i >= 0; i--){
        int d = number[i] - 'a';
        if (isSecond == true)
        d = d * 2;
        
        sumtotal += d / 10;
        sumtotal += d % 10;
        isSecond = !isSecond;
    }
    return (sumtotal % 10 == 0);
}
//it will flip digit from 0 to 15
void FlippingDigit(char * number){
    int num= rand()%15;
    int newNumber = rand()%10;
    number[num] = newNumber+'0';
}
int main(int argc, char** argv) {
    char credit[20];
    
    cout << "What kind of credit do you want to use?: \n1. American Express\n2. Mastercard\n3. Discover\n4. Visa\n>";
    int input; 
    cin >> input;
    
    //instance of enum
    Crdcredit typeofcredit;
    switch(input) {
        case 1: 
            typeofcredit = AMERICAN_EXPRESS;
            break;
        case 2: 
            typeofcredit = MASTER;
            break;
        case 3: 
            typeofcredit = DISCOVER;
            break;
        case 4: 
            typeofcredit = VISA;
            break;
        default: 
            cout << "Unsupported credit card!" << endl;
    }
                
    //generate credit
    genCC(typeofcredit,credit);
    //forming credit card until the validity
    while(!validCC(credit,typeofcredit)){
        genCC(typeofcredit,credit);
    }
    
    //credit credit number
    cout << "Credit number generated : ";
    printcredit(credit);
    cout << endl;
    cout << "Credit is ";
    
    if(validCC(credit,typeofcredit)){
        cout<<"Valid\n";
    }
    else{
        cout << "Invalid\n";
    }
    
    int numberOfValid=0;
    int numberOfInvalid=0;
    
    cout << "\n\n\nNow stress testing with 10000 loops:";
    
    for(int i=1;i<=10000;i++){
        FlippingDigit(credit);
        if(validCC(credit,typeofcredit)){
            numberOfValid++;
            
        }
        else{
            numberOfInvalid++;
        }
    }
    
    cout << "\nNumber of valid credit generated : " << numberOfValid;
    cout << "\nNumber of invalid credit generated : " << numberOfInvalid;
    
    return 0;
}