/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jheremy Morales
 * Created on
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */
// System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80; //Max Columns much larger than needed.

//Function Prototypes Here
void read(int[][COLMAX], int &, int &);//Prompt for size then table
void sum(const int[][COLMAX], int, int, int[][COLMAX]);//Sum rows,col,grand total
void print(const int[][COLMAX], int, int, int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
//Declare all Variables Here
const int ROW = 80; //Max Rows much larger than needed
int array[ROW][COLMAX] = {}; //Declare original array
int augAry[ROW][COLMAX] = {}; //Actual augmented table row+1, col+1
int row, col;

//Input the original table
read(array, row, col);

//Augment the original table by the sums
sum(array, row, col, augAry);

//Output the original array
cout << endl << "The Original Array" << endl;
print(array, row, col, 10);//setw(10)

//Output the augmented array
cout << endl << "The Augmented Array" << endl;
print(augAry, row + 1, col + 1, 10);//setw(10)

//Exit
return 0;
}

//Prompt for size then table
void read(int array[][COLMAX], int &row, int &col)
{
// prompt for number of rows and cols
cout << "Input a table and output the Augment row,col and total sums." << endl;
cout << "First input the number of rows and cols. <20 for each" << endl;

// input number of rows & cols
cin >> row >> col;

// prompt for table
cout << "Now input the table." << endl;

// input the table values
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++)
{
cin >> array[i][j];
}
}
}

//Augment the original table by the sums
void sum(const int array[][COLMAX], int row, int col, int augAry[][COLMAX])
{
int rowSum; // to calculate the row sum
int colSum; // to calculate the col sum
int grandTotal = 0; // to calculate the grand total

// augment the column of augArray
for (int i = 0; i < row; i++)
{
rowSum = 0; // set rowSum to 0

// calculate the sum of row and put augmented col
for (int j = 0; j < col; j++)
{
rowSum += array[i][j];
augAry[i][j] = array[i][j];
}

// augment the row sum
augAry[i][col] = rowSum;

// add sum to grand total
grandTotal += rowSum;
}

// augment the row of augArray
for (int i = 0; i < col; i++)
{
colSum = 0; // set colSum to 0
// calculate the column sum
for (int j = 0; j < row; j++)
{
colSum += array[j][i];
}

// augment the col sum
augAry[row][i] = colSum;
}

// finally put the grand total
augAry[row][col] = grandTotal;
}

// print the table
void print(const int array[][COLMAX], int row, int col, int width)
{
// iterate through row and cols
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++)
{
// print the element
cout << setw(width) << array[i][j];
}
cout << endl;
}
}