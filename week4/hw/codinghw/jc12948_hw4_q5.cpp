/*
Question 5:
Write a program that asks the user to input a positive integer n, and prints a textual image of an
hourglass made of 2n lines with asterisks.
For example if n=4, the program should print:
*******
 *****
  ***
   * 
   *
  ***
 *****
*******
*/
#include <iostream>
using namespace std;

int main() {

    int input;

    cout<<"Please inter a positive integer: "<<endl;
    cin>>input;

    for(int i = 1; i <= input; i ++) {
        for(int j = 1; j <= i; j++) {
            cout<<" ";
        }
        for(int j = i; j <= input-1; j++) {
            cout<<"*";
        }
        for(int j = i; j <= input; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = 1; i <= input; i++) {

        for(int j = i; j <= input; j++) {
            cout<<" ";
        }
        for(int j = 1; j <= i-1; j++) {
            cout<<"*";
        }
         for(int j = 1; j <= i; j++) {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}