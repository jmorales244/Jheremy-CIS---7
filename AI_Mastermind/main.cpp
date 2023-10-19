/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/*
    Dr. Mark E. Lehr & Jheremy Morales
    CSC 7 Template for Mastermind AI
    May 11th, 2021
 */

//System Libraries
#include <iostream> //I/O Library command line 
#include <ctime> //Set random number seed 
#include <string> //used to take in the user input as a string 
#include <cstdlib> //Library for random function 
#include <iomanip> //Library for random function 
using namespace std;

//Function Prototypes
string AI(char,char);
bool eval(string,string,char &,char &);
string set();

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    //Initialize Values
    nGuess=0;
    code=set();
    rr=rw=0;
    cout << "Code Generated: " << code << endl << endl;
    cout << "     AI Attempt Hint" << endl;
    //Loop until solved and count to find solution
    do{
       nGuess++;
       guess=AI(rr,rw);
    }while(eval(code,guess,rr,rw) && nGuess<20);
    //Check evaluation
    guess=AI(rr,rw);
    //Exit the program
    return 0;
}
string AI(char rr,char rw){
    void (*print)(string [],char[],char[],int,string,string)=
        [] (string g[],char r[],char w[],int guess, string digits,string wGuess){ 
            cout<<"Attempt #"<<guess<<": "<<g[guess]<<" "
                <<static_cast<int>(r[guess])<<" "
                <<static_cast<int>(w[guess])<<endl;
    };

    void (*firstDigit)(string&,string&,string&,int[],bool[],int,char) =
        [] (string &sGuess,string &wGuess,string &digits,int counters[],bool steps[],int guess,char rr){
            sGuess[0] = (guess + '0');
            sGuess[1] = (guess + '0');
            sGuess[2] = (guess + '0');
            sGuess[3] = (guess + '0');
            
            //Save the correct previous digits 
            if (rr > 0 && guess != 0){
                for (int i = 0; i < rr; i++){
                    digits[counters[0]] = ((guess-1) + '0');
                    counters[0]++;
                }
            }
            //Save incorrect digits for guessing
            if (rr == 0 && guess != 0 && guess < 10){
                for (int i = 0; i < 4; i++){
                    wGuess[i] = ((guess-1) + '0');
                }
            }
            if (counters[0] == 4 or guess == 9) steps[0] = true;
    };
    //Step 2: Find position of the first digit
    void (*secondDigit)(string&,string&,string&,int[],bool[],char) =
    [] (string &sGuess,string &wGuess,string &digits,int counters[],bool steps[],char rr){
        sGuess = wGuess;
        //Check for RR == 1 while counter != 0
        if (rr == 1 && counters[1] != 0){
            wGuess[counters[1]-1] = digits[0];
            steps[1] = true;
        }
        //Fill each position until step is true
        if (counters[1] == 0 && !steps[1]){
            //Set to first possible position
            sGuess[0] = digits[0];
            counters[1]++;
        }else if (counters[1] == 1 && !steps[1]){
            //Set to second possible position
            sGuess[1] = digits[0];
            counters[1]++;
        }else if (counters[1] == 2 && !steps[1]){
            //Set to third possible position
            sGuess[2] = digits[0];
            counters[1]++;
        }else if (counters[1] == 3 && !steps[1]){
            //Save to fourth position and set bool to true
            wGuess[3] = digits[0];
            steps[1] = true;
            counters[1]++;
        }
    };
    //Step 3: Find position of the second digit
    void (*thirdDigit)(string&,string&,string&,int[],bool[],char) =
    [] (string &sGuess,string &wGuess,string &digits,int counters[],bool steps[],char rr){
        sGuess = wGuess;
        
        //Check for RR == 2 while counter != 0
        if (rr == 2 && counters[2] != 0){
            wGuess[counters[2]-1] = digits[1];
            steps[2] = true;
        }
        
    if (!steps[2] && counters[2] == counters[1] - 1)
    counters[2]++;
    if (counters[2] >= 0 && counters[2] < 4 && !steps[2]) {
    switch (counters[2]) {
        case 0:
            sGuess[0] = digits[1];
            break;
        case 1:
            sGuess[1] = digits[1];
            break;
        case 2:
            sGuess[2] = digits[1];
            break;
        case 3:
            sGuess[3] = digits[1];
            break;
    }
    counters[2]++;}
    };
    void (*fourthDigit)(string&,string&,string&,int[],bool[],char) =
    [] (string &sGuess,string &wGuess,string &digits,int counters[],bool steps[],char rr){
        sGuess = wGuess;
      if (rr == 3 && counters[3] != 0) {
    wGuess[counters[3] - 1] = digits[2];
    steps[3] = true;
}
if (!steps[3] && counters[3] < 4) {
    if (counters[3] == counters[1] - 1 || counters[3] == counters[2] - 1) {
        counters[3]++;
    }
    switch (counters[3]) {
        case 0:
            sGuess[0] = digits[2];
            break;
        case 1:
            sGuess[1] = digits[2];
            break;
        case 2:
            sGuess[2] = digits[2];
            break;
        case 3:
            sGuess[3] = digits[2];
            break;
    }
    counters[3]++;
    }
    };
    void (*lastDigit)(string&,string&,string&,int[],bool[],char) =
    [] (string &sGuess,string &wGuess,string &digits,int counters[],bool steps[],char rr)
    {  
    while (counters[4] == counters[1] - 1 || counters[4] == counters[2] - 1 || counters[4] == counters[3] - 1) 
    { 
    counters[4]++;
    }
    wGuess[counters[4]] = digits[3];
    sGuess = wGuess;
    };
    
    //Save the historical values of guesses and results
    static const int SIZE=20;   //How many guesses to save
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    string sGuess="0000";       //Size the guest string
    static string wGuess="9999";//Save wrong guess for testing
    
    //Variables for AI
    static int counters[5] = {0, 0, 0, 0, 0};
    static string digits = "9999";
    static bool steps[4] = {false, false, false, false};
    
    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    
    //AI Guess Process
    if (!steps[0]) firstDigit(sGuess,wGuess,digits,counters,steps,guess,rr);
    if (steps[0] && !steps[1]) secondDigit(sGuess,wGuess,digits,counters,steps,rr);
    if (steps[1] && !steps[2]) thirdDigit(sGuess,wGuess,digits,counters,steps,rr);
    if (steps[2] && !steps[3]) fourthDigit(sGuess,wGuess,digits,counters,steps,rr);
    if (steps[3]) lastDigit(sGuess,wGuess,digits,counters,steps,rr);
    //Print the results
    if (guess != 0) print(aGuess,grr,grw,guess,digits,wGuess);
    //Save the result
    aGuess[++guess]=sGuess;
    //Return the result
    return sGuess;
}
bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break; }
        }
    }
    //Found or not
    if(rr==4)return false;
    return true;
}
string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}