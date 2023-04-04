#include <iostream>
using namespace std;



/******************************************************
** Program: fractal.cpp
** Author: Ayush Singh
** Date: 3/10/2023
** Description: creating X fractal pattern using recurssion
** Input: none
** Output: none
******************************************************/




void pattern(int n, int col) {
    if (n < 0) return;

    // Print the top part of the pattern
    for (int i = 0; i < col; i++) cout << " ";
    cout << "*";
    if (n > 0) {
        for (int i = 0; i < n * 2 - 1; i++) cout << " ";
        cout << "*";
    }
    cout << endl;

    pattern(n - 1, col + 1); //pattern call 

    // Print the bottom part of the pattern
    if (n > 0) {
        for (int i = 0; i < col; i++) cout << " ";
        cout << "*";
        if (n >= 1) {
            for (int i = 0; i < n * 2 - 1; i++) cout << " ";
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n, col;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of col: ";
    cin >> col;

    pattern(n , col);
    return 0;
}




