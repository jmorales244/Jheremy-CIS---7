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

#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

// **Needs to fix U/I**

//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Search for 1 occurrence
int srch1(const char sentence[],const char pattern[],int start_index){
    int patternLength = strlen(pattern);
    int sentenceLength = strlen(sentence);
    int j;
    for ( j = 0; j < sentenceLength; j++){
    ///check every char in pattern is in sentence
    if (sentence[start_index + j] != pattern[j])
    break;
    }
    if (j == patternLength) // if all character in pattern is also found in sentence
    {
    return start_index; ///return start_index from where pattern starts
    }
    else
    return -1; ///not found
}

//srchAll Input->sentence, pattern Output->position array
void srchAll(const char sentence[],const char pattern[],int array[81]){//Search for all occurrences

    int patternLength = strlen(pattern);
    int sentenceLength = strlen(sentence);
    int cnt=0;
    /// iterate through sentence
    for(int i=0;i<sentenceLength-patternLength;i++){
        ///search foe every start_index as i
        int index=srch1(sentence,pattern,i);
        if(index!=-1){ /// if pattern found
            array[cnt++]=index; ///add into match array
        }
    }

    // return cnt; //to return no of elements inserted into array that will be useful to pass to array_print
}///srchall


void print(const int array[]){ //Print the array of indexes where the pattern found
    cout << " ";
    int cnt=0;
    
    while(array[cnt]!=-1){
        cout<<array[cnt++]<<" ";
    }

}

// Driver Code
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81; //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE]; //Index array where pattern was found

    //initialized match array with -1
    for(int i=0;i<LINE;i++)
    match[i]=-1;


    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);

    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);

    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);

    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    //print(sntnce);
    cout<<sntnce<<" " << endl;
    cout<<pattern<<" " << endl;

    //print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    if(match[0]==-1)
        cout << "None" << endl;
    else
        print(match);

    //Exit
    return 0;
}
