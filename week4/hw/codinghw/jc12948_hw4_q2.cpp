/*
Question 2:
Your program should interact with the user exactly as it shows in the following example: Enter decimal number:
147
147 is CXXXXVII
In this question we will use a simplified version of the Roman Numerals System to represent
positive integers.
The digits in this system are I, V, X, L, C, D and M. Each digit corresponds to a decimal value, as
showed in the following table:
A number in the simplified Roman numerals system is a sequence of Roman digits, which follow
these 2 rules:
The digits form a monotonically non-increasing sequence. That is the value of each digit is
less than or equal to the value of the digit that came before it.
For example, DLXXVI is a monotonically non-increasing sequence of Roman digits, but XIV is
There is no limit on the number of times that ‘M’ can appear in the number.
‘D’, ‘L’ and ‘V’ can each appear at most one time in the number.
‘C’, ‘X’ and ‘I’ can each appear at most four times in the number.
For example: IIII, XVII and MMMMMMDCCLXXXXVII are legal numbers in our simplified Roman
numeral system, but IIIII, XIV, VVI and CCXLIII are not.
Write a program that reads from the user a (decimal) number, and prints it’s representation in
the simplified Roman numerals system.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    int input, temp;
    string romanNum;

    cout<<"Enter decimal number: "<<endl;
    cin>>input;

    temp = input;
    while (temp > 0) {
        if(temp >= 1000) {
            romanNum += "M";
            temp -= 1000;
        }
        else if(temp >= 500) {
            romanNum += "D";
            temp -= 500;
        }
        else if (temp >= 100) {
            romanNum += "C";
            temp -= 100;
        }
        else if (temp >= 50) {
            romanNum += "L";
            temp -= 50;
        }
        else if (temp >= 10) {
            romanNum += "X";
            temp -= 10;
        }
        else if (temp >= 5) {
            romanNum += "V";
            temp -= 5;
        }
        else {
            romanNum += "I";
            temp -= 1;
        }
    }
    cout<<input<<" is "<<romanNum<<endl;
    return 0;
}